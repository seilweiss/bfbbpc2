#include "xAnim.h"

#include "xMemMgr.h"
#include "xString.h"
#include "xModel.h"

#include <string.h>

static xMemPool sxAnimTempTranPool;
uint32 gxAnimUseGrowAlloc = 0;

#define xAnimMemAlloc(size) (gxAnimUseGrowAlloc ? xMEMGROWALLOC((size)) : xMEMALLOC((size)))

static bool _xSingleCompare(char a, char b)
{
    switch (b)
    {
    case '?':
    case '*':
    case '+':
        return true;
    case '#':
        return (a >= '0' && a <= '9');
    }

    return (a == b);
}

static bool _xSingleCompare(char ch, const char* str)
{
    while (*str)
    {
        if (_xSingleCompare(ch, *str))
        {
            return true;
        }

        str++;
    }

    return false;
}

static bool _xCharIn(char ch, const char* str)
{
    while (*str)
    {
        if (ch == *str)
        {
            return true;
        }

        str++;
    }

    return false;
}

static bool _xCheckAnimNameInner(const char* name, const char* pattern, int32 patternSize, char* extra, int32* nameOut, int32* extraOut) WIP
{
    const char* startExtra = NULL; // r31
    char* initialExtra = extra; // r30
    int32 patternCurrent = 0; // r29
    int32 nameCurrent = 0; // r28

    while (patternCurrent < patternSize)
    {
        const char* r3 = &pattern[patternCurrent];

        switch (*r3)
        {
        case '?':
        case '+':
        {
            patternCurrent++;

            if (nameCurrent == 0)
            {
                return false;
            }

            nameCurrent++;

            if (*r3 == '?')
            {
                break;
            }
        }
        case '*':
        {
            int32 check = patternCurrent + 1; // r20
            char nextPattern[128] = {};

            nextPattern[0] = pattern[check];

            while (nextPattern[0] == '{' || nextPattern[0] == '}' ||
                nextPattern[0] == '<' || nextPattern[0] == '>')
            {
                nextPattern[0] = pattern[++check];
            }

            if (nextPattern[0] == '(')
            {
                int32 nextPatternCount = 0; // r21
                bool first = true; // r19
                int32 parenCount = 0; // r18

                while (pattern[check] != '\0' && parenCount >= 0)
                {
                    if (pattern[check] == '(')
                    {
                        parenCount++;
                    }
                    else if (pattern[check] == ')')
                    {
                        parenCount--;
                    }
                    else if (parenCount == 0)
                    {
                        const char* IGNORE_PATTERNS = "{}()<>";

                        if (pattern[check] == '|')
                        {
                            first = true;
                        }
                        else if (first && !_xCharIn(pattern[check], IGNORE_PATTERNS))
                        {
                            first = false;
                            nextPattern[nextPatternCount++] = pattern[check];
                        }
                    }

                    check++;
                }

                nextPattern[nextPatternCount] = NULL;
            }

            //const char* r16 = name + nameCurrent;

            while (name[nameCurrent] != '\0' && !_xSingleCompare(name[nameCurrent], nextPattern))
            {
                nameCurrent++;
            }

            patternCurrent++;

            break;
        }
        case '#':
        {
            if (name[nameCurrent] < '0' || name[nameCurrent] > '9')
            {
                return false;
            }

            nameCurrent++;

            while (name[nameCurrent] >= '0' && name[nameCurrent] <= '9')
            {
                nameCurrent++;
            }

            patternCurrent++;

            break;
        }
        case '{':
        {
            startExtra = name + nameCurrent;
            patternCurrent++;
            break;
        }
        case '}':
        {
            int32 length = name + nameCurrent - startExtra; // r16

            if (extra)
            {
                memcpy(extra, startExtra, length);

                extra[length] = NULL;
                extra += length + 1;
                *extra = '\1';
            }

            startExtra = NULL;
            patternCurrent++;

            break;
        }
        case '(':
        {
            patternCurrent++;

            bool done = false; // r18
            const char* current = pattern + patternCurrent; // r19
            const char* startPattern = current; // r21

            while (*current != ')' && *current != '\0')
            {
                const char* r4 = current;

                while (*current != '\0' && *current != ')' && *current != '|')
                {
                    if (*current == '(')
                    {
                        int32 pc = 1;

                        while (*current != '\0' && pc > 0)
                        {
                            if (*current == ')')
                            {
                                pc--;
                            }
                            else if (*current == '(')
                            {
                                pc++;
                            }

                            current++;
                        }

                        if (*current != '\0')
                        {
                            current++;
                        }
                    }
                    else
                    {
                        current++;
                    }
                }

                if (current != r4)
                {
                    int32 nameOut;
                    int32 extraOut;

                    bool r16 = (!done && _xCheckAnimNameInner(name + nameCurrent, r4, startPattern - r4, extra,
                        &nameOut, &extraOut));

                    if (r16)
                    {
                        done = true;
                        nameCurrent += nameOut;
                        extra += extraOut;
                    }
                    else if (extra)
                    {
                        *extra = '\1';
                    }
                }

                if (*current == '|')
                {
                    current++;
                }
            }

            if (*current != '\0')
            {
                current++;
            }

            patternCurrent += current - startPattern;

            if (!done)
            {
                return false;
            }

            break;
        }
        case '<':
        {
            patternCurrent++;

            const char* r18 = pattern + patternCurrent;
            const char* r20 = r18;
            const char* r4 = r18;

            while (*r18 != '\0' && *r18 != ';' && *r18 != '>')
            {
                r18++;
            }

            const char* r5 = r18;
            const char* r19 = NULL;
            const char* r17 = NULL;

            if (*r18 == ';')
            {
                r19 = r18++;

                while (*r18 != '\0' && *r18 != '>')
                {
                    r18++;
                }

                r17 = r18;
            }

            const char* r21 = name + nameCurrent;
            int32 nameOut;
            int32 extraOut;
            bool matched = _xCheckAnimNameInner(r21, r4, r5 - r4, extra, &nameOut, &extraOut);

            if (matched)
            {
                if (r19 && _xCheckAnimNameInner(r21, r19, r17 - r19, NULL, NULL, NULL))
                {
                    if (extra)
                    {
                        *extra = '\0';
                    }

                    matched = false;
                }
                else
                {
                    nameCurrent += nameOut;
                    extra += extraOut;
                }
            }

            if (*r18 != '\0')
            {
                r18++;
            }

            patternCurrent += r18 - r20;

            if (!matched)
            {
                return false;
            }

            break;
        }
        case '\0':
        {
            return false;
        }
        case ')':
        default:
        {
            if (name[nameCurrent] != *r3)
            {
                return false;
            }

            nameCurrent++;
            patternCurrent++;

            break;
        }
        }
    }

    if (nameOut)
    {
        *nameOut = nameCurrent;
    }

    if (extraOut)
    {
        *extraOut = extra - initialExtra;
    }

    return true;

    /*
        char* startExtra;
        char* initialExtra;
        int32 patternCurrent;
        int32 nameCurrent;
        int32 check;
        //char nextPattern[128];
        int32 nextPatternCount;
        bool first;
        int32 parenCount;
        char* IGNORE_PATTERNS;
        int32 length;
        bool done;
        char* current;
        char* startPattern;
        int32 pc;
        // int32 nameOut;
        // int32 extraOut;
        char* current;
        char* positiveEnd;
        char* negative;
        char* negativeEnd;
        // int32 nameOut;
        // int32 extraOut;
        bool matched;
    */
}

static bool _xCheckAnimName(const char* name, const char* pattern, char* extra)
{
    *extra = '\1';

    int32 patternSize = strlen(pattern);
    int32 nameOut;
    bool rc = _xCheckAnimNameInner(name, pattern, patternSize, extra, &nameOut, NULL);

    return (rc && name[nameOut] == '\0');
}

void xAnimInit()
{
    iAnimInit();
    memset(&sxAnimTempTranPool, 0, sizeof(xMemPool));
}

void xAnimTempTransitionInit(uint32 count)
{
    xMemPoolSetup(&sxAnimTempTranPool, xMEMALLOC(count * sizeof(xAnimTransition)), 0, 0, NULL, sizeof(xAnimTransition), count, count / 2);
}

static float32 CalcRecipBlendMax(uint16* r3)
{
    float32 f4 = 0.0f;

    while (r3[0] != 0xFFFF)
    {
        float32 f3;

        if (r3[1] == 0)
        {
            f3 = 0.0f;
        }
        else
        {
            f3 = 1.0f / (r3[1] / 1024.0f);
        }

        float32 f0 = r3[0] / 1024.0f + f3;

        if (f0 > f4)
        {
            f4 = f0;
        }

        r3 += 2;
    }

    return f4 == 0.0f ? 0.0f : 1.0f / f4;
}

static uint32 StateHasTransition(xAnimState* state, xAnimTransition* tran)
{
    xAnimTransitionList* curr = state->List;

    while (curr)
    {
        if (curr->T == tran)
        {
            return TRUE;
        }

        curr = curr->Next;
    }

    return FALSE;
}

static uint32 DefaultHasTransition(xAnimState* state, xAnimTransition* tran, uint32* stateCount)
{
    int32 r7 = 1;
    xAnimTransitionList* curr = state->Default;

    while (curr)
    {
        if (curr->T == tran)
        {
            return TRUE;
        }

        if (curr->T->Conditional == tran->Conditional && curr->T->UserFlags == tran->UserFlags)
        {
            r7 = 0;
        }

        curr = curr->Next;
    }

    *stateCount += r7;
    return FALSE;
}

static uint32 DefaultOverride(xAnimState* state, xAnimTransition* tran)
{
    xAnimTransitionList* curr = state->Default;

    while (curr)
    {
        if (curr->T->Conditional == tran->Conditional && curr->T->UserFlags == tran->UserFlags)
        {
            curr->T = tran;
            return TRUE;
        }

        curr = curr->Next;
    }

    return FALSE;
}

static void TransitionTimeInit(xAnimSingle* single, xAnimTransition* tran)
{
    if (tran->Flags & XANIMTRANSITION_UNK0x20)
    {
        xAnimFile* dest = tran->Dest->Data;
        xAnimFile* src = single->State->Data;

        if ((src->FileFlags ^ dest->FileFlags) & XANIMFILE_UNK0x1000)
        {
            single->Time = dest->Duration - single->Time;
        }
    }
    else
    {
        single->Time = ((tran->Dest->Flags & XANIMSTATE_UNK0x100) && tran->DestTime == 0.0f) ?
            single->State->Data->Duration * xurand() :
            tran->DestTime;
    }

    single->LastTime = single->Time;
}

xAnimFile* xAnimFileNewBilinear(void** rawData, const char* name, uint32 flags, xAnimFile** linkedList, uint32 numX, uint32 numY)
{
    int32 count, i;
    xAnimFile* afile = (xAnimFile*)xAnimMemAlloc(numX * numY * sizeof(void*) + sizeof(xAnimFile));

    if (numX > 1 || numY > 1)
    {
        flags |= XANIMFILE_UNK0x4000;
    }

    if (*(uint32*)rawData[0] == 'QSPM')
    {
        flags |= XANIMFILE_USEMORPHSEQ;
    }

    if (linkedList)
    {
        afile->Next = *linkedList;
        *linkedList = afile;
    }
    else
    {
        afile->Next = NULL;
    }

    afile->RawData = (void**)(afile + 1);

    count = numX * numY;

    for (i = 0; i < count; i++)
    {
        afile->RawData[i] = rawData[i];
    }

    afile->Name = name;
    afile->ID = xStrHash(name);
    afile->FileFlags = flags;
    afile->Duration = (afile->FileFlags & XANIMFILE_UNK0x2000) ? 2.0f * xAnimFileGetDuration(afile) : xAnimFileGetDuration(afile);
    afile->TimeOffset = 0.0f;
    afile->BoneCount = (flags & XANIMFILE_USEMORPHSEQ) ? 0 : iAnimBoneCount(rawData[0]);
    afile->NumAnims[0] = numX;
    afile->NumAnims[1] = numY;

    return afile;
}

xAnimFile* xAnimFileNew(void* rawData, const char* name, uint32 flags, xAnimFile** linkedList)
{
    return xAnimFileNewBilinear(&rawData, name, flags, linkedList, 1, 1);
}

void xAnimFileSetTime(xAnimFile* data, float32 duration, float32 timeOffset)
{
    float32 rawDuration = xAnimFileGetDuration(data);

    if (timeOffset > rawDuration - 0.1f)
    {
        timeOffset = rawDuration - 0.1f;
    }

    data->TimeOffset = timeOffset;

    if (duration > rawDuration - timeOffset)
    {
        duration = rawDuration - timeOffset;
    }

    data->Duration = (data->FileFlags & XANIMFILE_UNK0x2000) ? 2.0f * duration : duration;
}

void xAnimFileEval(xAnimFile* data, float32 time, float32* bilinear, uint32 flags, xVec3* tran, xQuat* quat, float32*) WIP
{
    int32 i;
    uint32 fileFlags = data->FileFlags;
    float32 rawTime = xAnimFileRawTime(data, xclamp(time, 0.0f, data->Duration));

    if (data->FileFlags & XANIMFILE_UNK0x8000)
    {
        return;
    }

    uint32 numBones = (flags & XANIMFILEEVAL_UNK0x1) ? 1 : data->BoneCount;

    if (flags & XANIMFILEEVAL_UNK0x2)
    {
        numBones--;
    }

    if (numBones == 0)
    {
        return;
    }

    if (bilinear && (fileFlags & XANIMFILE_UNK0x4000))
    {
        float32 bilerp[2];
        uint32 biindex[2];
        uint32 biplus[2];

        for (i = 0; i < 2; i++)
        {
            float32 f30 = xclamp(bilinear[i], 0.0f, data->NumAnims[i] - 1);
            float32 f1 = std::floorf(f30);

            bilerp[i] = f30 - f1;
            biindex[i] = (uint32)f1;
            biplus[i] = (biindex[i] + 1 < data->NumAnims[i]) ? biindex[i] + 1 : biindex[i];
        }

        xQuat* q0 = (xQuat*)(giAnimScratch + 0x1560);
        xVec3* t0 = (xVec3*)(q0 + 65);

        if (bilerp[0] != 0.0f && bilerp[1] != 0.0f)
        {
            xQuat* q1 = (xQuat*)(giAnimScratch + 0x1C80);
            xVec3* t1 = (xVec3*)(q1 + 65);

            iAnimEval(data->RawData[biindex[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, tran, quat);
            iAnimEval(data->RawData[biplus[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, t0, q0);
            iAnimBlend(bilerp[0], 1.0f, NULL, NULL, numBones, tran, quat, t0, q0, tran, quat);

            iAnimEval(data->RawData[biindex[0] + biplus[1] * data->NumAnims[0]], rawTime, flags, t0, q0);
            iAnimEval(data->RawData[biplus[0] + biplus[1] * data->NumAnims[0]], rawTime, flags, t1, q1);
            iAnimBlend(bilerp[0], 1.0f, NULL, NULL, numBones, t0, q0, t1, q1, t0, q0);

            iAnimBlend(bilerp[1], 1.0f, NULL, NULL, numBones, tran, quat, t0, q0, tran, quat);
        }
        else if (bilerp[0] != 0.0f)
        {
            iAnimEval(data->RawData[biindex[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, tran, quat);
            iAnimEval(data->RawData[biplus[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, t0, q0);
            iAnimBlend(bilerp[0], 1.0f, NULL, NULL, numBones, tran, quat, t0, q0, tran, quat);
        }
        else if (bilerp[1] != 0.0f)
        {
            iAnimEval(data->RawData[biindex[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, tran, quat);
            iAnimEval(data->RawData[biindex[0] + biplus[1] * data->NumAnims[0]], rawTime, flags, t0, q0);
            iAnimBlend(bilerp[0], 1.0f, NULL, NULL, numBones, tran, quat, t0, q0, tran, quat);
        }
        else
        {
            iAnimEval(data->RawData[biindex[0] + biindex[1] * data->NumAnims[0]], rawTime, flags, tran, quat);
        }
    }
    else
    {
        iAnimEval(data->RawData[0], rawTime, flags, tran, quat);
    }
}

xAnimEffect* xAnimStateNewEffect(xAnimState* state, uint32 flags, float32 startTime, float32 endTime, xAnimEffectCallback callback, uint32 userDataSize)
{
    xAnimEffect* curr;
    xAnimEffect** prev;
    xAnimEffect* effect = (xAnimEffect*)xAnimMemAlloc(userDataSize + sizeof(xAnimEffect));

    effect->Flags = flags;
    effect->StartTime = startTime;
    effect->EndTime = endTime;
    effect->Callback = callback;

    curr = state->Effects;
    prev = &state->Effects;

    while (curr && startTime > curr->StartTime)
    {
        prev = &curr->Next;
        curr = curr->Next;
    }

    effect->Next = curr;
    *prev = effect;

    return effect;
}

xAnimTable* xAnimTableNew(const char* name, xAnimTable** linkedList, uint32 userFlags)
{
    xAnimTable* table = (xAnimTable*)xMEMALLOC(sizeof(xAnimTable));

    if (linkedList)
    {
        table->Next = *linkedList;
        *linkedList = table;
    }
    else
    {
        table->Next = NULL;
    }

    table->Name = name;
    table->TransitionList = NULL;
    table->StateList = NULL;
    table->AnimIndex = 0;
    table->MorphIndex = 0;
    table->UserFlags = userFlags;

    return table;
}

void xAnimDefaultBeforeEnter(xAnimPlay*, xAnimState* state)
{
    if (state->MultiFile)
    {
        uint32 entry = rand() % state->MultiFile->Count;

        state->Data = state->MultiFile->Files[entry].File;
    }
}

xAnimState* xAnimTableNewState(xAnimTable* table, const char* name, uint32 flags, uint32 userFlags, float32 speed, float32* boneBlend, float32* timeSnap, float32 fadeRecip, uint16* fadeOffset, void* callbackData, xAnimBeforeEnterCallback beforeEnter, xAnimStateCallback stateCallback, xAnimBeforeAnimMatricesCallback beforeAnimMatrices) WIP
{
    xAnimState* state = (xAnimState*)xAnimMemAlloc(sizeof(xAnimState));

    if (!table->StateList)
    {
        state->Next = NULL;
        table->StateList = state;
    }
    else
    {
        state->Next = table->StateList->Next;
        table->StateList->Next = state;
    }

    state->Name = name;
    state->ID = xStrHash(name);
    state->Flags = flags;
    state->UserFlags = userFlags;
    state->Speed = speed;
    state->Data = NULL;
    state->Effects = NULL;
    state->Default = NULL;
    state->List = NULL;
    state->BoneBlend = boneBlend;
    state->TimeSnap = timeSnap;
    state->FadeRecip = fadeOffset ? CalcRecipBlendMax(fadeOffset) : fadeRecip;
    state->FadeOffset = fadeOffset;
    state->MultiFile = NULL;
    state->CallbackData = callbackData;
    state->BeforeEnter = beforeEnter;
    state->StateCallback = stateCallback;
    state->BeforeAnimMatrices = beforeAnimMatrices;

    return state;
}

static void _xAnimTableAddTransitionHelper(xAnimState* state, xAnimTransition* tran, uint32& stateCount, uint32& allocCount, xAnimState** stateList)
{
    if (tran->Flags & XANIMTRANSITION_UNK0x10)
    {
        if (!DefaultHasTransition(state, tran, &stateCount))
        {
            stateList[allocCount] = state;
            allocCount++;
        }
    }
    else
    {
        if (!StateHasTransition(state, tran))
        {
            stateList[allocCount] = state;
            allocCount++;
            stateCount++;
        }
    }
}

static void _xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source, const char* dest) WIP
{
    uint8* buffer = giAnimScratch;
	xAnimState** stateList = (xAnimState**)(giAnimScratch + 1024); // r27
    uint32 i;
    uint32 stateCount = 0;
	uint32 allocCount = 0;
    const char* stateName;
    xAnimTransitionList* tlist; // r25
    xAnimTransition* substTransitionList[32];
    uint32 substTransitionCount = 0; // r24
    bool hasSubst = false; // r23

    if (dest)
    {
        for (i = 0; dest[i] != '\0'; i++)
        {
            if (dest[i] == '@' || dest[i] == '~')
            {
                hasSubst = true;
                break;
            }
        }
    }

    stateName = xStrTokBuffer(source, " ,\t\n\r", buffer); // r26

    while (stateName)
    {
        bool isComplex = (dest != NULL); // r18

        if (!isComplex)
        {
            const char* COMPLEX_PATTERNS = "#+*?{}()<>|;"; // r19
            const char* search = stateName; // r20

            while (*search != '\0')
            {
                if (_xCharIn(*search, COMPLEX_PATTERNS))
                {
                    isComplex = true;
                    break;
                }

                search++;
            }
        }

        xAnimState* state;

        if (isComplex)
        {
            for (state = table->StateList; state != NULL; state = state->Next)
            {
                char extra[128];

                if (_xCheckAnimName(state->Name, stateName, extra))
                {
                    if (hasSubst)
                    {
                        char tempName[128];
                        char* tempIterator = tempName;
                        char* extraIterator = extra;
                        bool allowMissingState = false; // r19

                        for (int32 i = 0; dest[i] != '\0'; i++)
                        {
                            if (dest[i] == '@' || dest[i] == '~')
                            {
                                allowMissingState = (dest[i] == '~');

                                uint32 extraIteratorLength = strlen(extraIterator);

                                strcpy(tempIterator, extraIterator);

                                tempIterator += extraIteratorLength;
                                extraIterator += extraIteratorLength + 1;
                            }
                            else
                            {
                                *tempIterator = dest[i];
                                tempIterator++;
                            }
                        }

                        *tempIterator = '\0';

                        xAnimState* r19 = xAnimTableGetState(table, tempName);

                        if (allowMissingState && !r19)
                        {
                            continue;
                        }

                        if (substTransitionCount != 0)
                        {
                            xAnimTransition* duplicatedTransition = (xAnimTransition*)xAnimMemAlloc(sizeof(xAnimTransition));
                            
                            memcpy(duplicatedTransition, tran, sizeof(xAnimTransition));

                            tran = duplicatedTransition;
                        }

                        tran->Dest = r19;

                        substTransitionList[substTransitionCount++] = tran;
                    }

                    if (tran->Dest != state)
                    {
                        _xAnimTableAddTransitionHelper(state, tran, allocCount, stateCount, stateList);
                    }
                }
            }
        }
        else
        {
            state = xAnimTableGetState(table, stateName);

            if (state && tran->Dest != state)
            {
                _xAnimTableAddTransitionHelper(state, tran, allocCount, stateCount, stateList);
            }
        }

        stateName = xStrTokBuffer(NULL, " ,\t\n\r", buffer);
    }

    if (allocCount != 0)
    {
        tlist = (xAnimTransitionList*)(xAnimMemAlloc(allocCount * sizeof(xAnimTransitionList)));
    }

    // Bug: tlist might be uninitialized

    if (tran->Flags & XANIMTRANSITION_UNK0x10)
    {
        for (i = 0; i < stateCount; i++)
        {
            if (!DefaultOverride(stateList[i], tran))
            {
                if (!tran->Conditional && stateList[i]->Default)
                {
                    xAnimTransitionList* curr = stateList[i]->Default;

                    while (curr->Next)
                    {
                        curr = curr->Next;
                    }
                    
                    tlist->T = hasSubst ? substTransitionList[i] : tran;
                    tlist->Next = NULL;

                    curr->Next = tlist;

                    tlist++;
                }
                else
                {
                    tlist->T = hasSubst ? substTransitionList[i] : tran;
                    tlist->Next = stateList[i]->Default;

                    stateList[i]->Default = tlist;

                    tlist++;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < stateCount; i++)
        {
            tlist->T = hasSubst ? substTransitionList[i] : tran;
            tlist->Next = stateList[i]->List;

            stateList[i]->List = tlist;

            tlist++;
        }
    }
}

void xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source)
{
    _xAnimTableAddTransition(table, tran, source, NULL);
}

xAnimTransition* xAnimTableNewTransition(xAnimTable* table, const char* source, const char* dest, xAnimTransitionConditionalCallback conditional, xAnimTransitionCallback callback, uint32 flags, uint32 userFlags, float32 srcTime, float32 destTime, uint16 priority, uint16 queuePriority, float32 blendRecip, uint16* blendOffset)
{
    xAnimTransition* tran = (xAnimTransition*)xAnimMemAlloc(sizeof(xAnimTransition));

    if (blendRecip != 0.0f)
    {
        blendRecip = 1.0f / blendRecip;
    }

    tran->Next = table->TransitionList;
    table->TransitionList = tran;

    bool isComplex = false;

    if (!dest || dest[0] == '\0')
    {
        tran->Dest = NULL;
    }
    else
    {
        for (int32 i = 0; dest[i] != '\0'; i++)
        {
            if (dest[i] == '@' || dest[i] == '~')
            {
                isComplex = true;
                break;
            }
        }

        tran->Dest = isComplex ? NULL : xAnimTableGetState(table, dest);
    }

    tran->Conditional = conditional;
    tran->Callback = callback;
    tran->Flags = flags;
    tran->UserFlags = userFlags;
    tran->SrcTime = srcTime;
    tran->DestTime = destTime;
    tran->Priority = priority;
    tran->QueuePriority = queuePriority;
    tran->BlendRecip = blendOffset ? CalcRecipBlendMax(blendOffset) : blendRecip;
    tran->BlendOffset = blendOffset;

    _xAnimTableAddTransition(table, tran, source, isComplex ? dest : NULL);

    return tran;
}

void xAnimTableAddFile(xAnimTable* table, xAnimFile* file, const char* states)
{
    uint8* buffer = giAnimScratch;
    const char* stateName = xStrTokBuffer(states, " ,\t\n\r", buffer);

    while (stateName)
    {
        xAnimTableAddFileID(table, file, xStrHash(stateName), 0, 0);

        stateName = xStrTokBuffer(NULL, " ,\t\n\r", buffer);
    }
}

xAnimState* xAnimTableAddFileID(xAnimTable* table, xAnimFile* file, uint32 stateID, uint32 subStateID, uint32 subStateCount)
{
    xAnimState* state = xAnimTableGetStateID(table, stateID);

    if (state)
    {
        if (subStateID != 0)
        {
            if (!state->MultiFile)
            {
                state->MultiFile = (xAnimMultiFile*)xAnimMemAlloc(subStateCount * sizeof(xAnimMultiFileEntry) + sizeof(xAnimMultiFileBase));
                state->MultiFile->Count = 0;
            }

            uint32 count = state->MultiFile->Count;

            state->MultiFile->Files[count].ID = subStateID;
            state->MultiFile->Files[count].File = file;
            state->MultiFile->Count++;
        }

        state->Data = file;

        if (file->FileFlags & XANIMFILE_USEMORPHSEQ)
        {
            table->MorphIndex |= 1 << (state->Flags & XANIMSTATE_UNK0xF);
        }
        else
        {
            table->AnimIndex |= 1 << (state->Flags & XANIMSTATE_UNK0xF);
        }
    }

    return state;
}

xAnimState* xAnimTableGetStateID(xAnimTable* table, uint32 ID)
{
    xAnimState* curr = table->StateList;

    while (curr)
    {
        if (curr->ID == ID)
        {
            return curr;
        }

        curr = curr->Next;
    }

    return NULL;
}

xAnimState* xAnimTableGetState(xAnimTable* table, const char* name)
{
    return xAnimTableGetStateID(table, xStrHash(name));
}

static void EffectActiveInsert(xAnimSingle* single, xAnimActiveEffect* active)
{
    uint32 index = 0;
    uint32 count = single->ActiveCount;
    xAnimActiveEffect* alist = single->ActiveList;

    while (index < count && alist->Effect != NULL)
    {
        alist++;
        index++;
    }

    *alist = *active;

    if (index < count - 1)
    {
        (alist + 1)->Effect = NULL;
    }
}

static void EffectActiveRemove(xAnimActiveEffect* active, uint32 index, uint32 count)
{
    if (index == count - 1 || (active + 1)->Effect == NULL)
    {
        active->Effect = NULL;
    }
    else
    {
        xAnimActiveEffect* curr = active;

        while (index < count - 1 && (curr + 1)->Effect != NULL)
        {
            curr++;
            index++;
        }

        *active = *curr;
        curr->Effect = NULL;
    }
}

static uint32 EffectPlaying(xAnimSingle* single, xAnimEffect* effect)
{
    uint32 index = 0;

    while (index < single->ActiveCount && single->ActiveList[index].Effect != NULL)
    {
        if (single->ActiveList[index].Effect == effect)
        {
            return TRUE;
        }

        index++;
    }

    return FALSE;
}

static void EffectSingleStart(xAnimSingle* single)
{
    xAnimEffect* effect = single->State->Effects;
    xAnimActiveEffect tempActive;
    float32 time = single->Time;

    while (effect && effect->StartTime < time)
    {
        uint32 flags = effect->Flags;

        if (flags & XANIMEFFECT_UNK0x1)
        {
            if (flags & XANIMEFFECT_UNK0x4)
            {
                tempActive.Effect = effect;
                tempActive.Handle = effect->Callback(1, &tempActive, single, single->Play->Object);

                if (effect->Flags & XANIMEFFECT_UNK0x2)
                {
                    if (effect->EndTime <= time)
                    {
                        effect->Callback(3, &tempActive, single, single->Play->Object);
                    }
                    else
                    {
                        EffectActiveInsert(single, &tempActive);
                    }
                }
                else if (effect->Flags & XANIMEFFECT_UNK0x20)
                {
                    EffectActiveInsert(single, &tempActive);
                }
            }
            else if ((flags & XANIMEFFECT_UNK0x2) && !(flags & XANIMEFFECT_UNK0x10) && effect->EndTime > time)
            {
                tempActive.Effect = effect;
                tempActive.Handle = effect->Callback(1, &tempActive, single, single->Play->Object);

                EffectActiveInsert(single, &tempActive);
            }
        }

        effect = effect->Next;
    }

    single->Effect = effect;
}

static void EffectSingleDuration(xAnimSingle* single)
{
    float32 time = single->Time;
    xAnimActiveEffect* alist = single->ActiveList;
    uint32 index = 0;
    uint32 count = single->ActiveCount;

    while (index < count && alist->Effect != NULL)
    {
        if (!(alist->Effect->Flags & XANIMEFFECT_UNK0x20) && alist->Effect->EndTime <= time)
        {
            alist->Effect->Callback(3, alist, single, single->Play->Object);

            EffectActiveRemove(alist, index, count);
        }
        else
        {
            alist->Effect->Callback(2, alist, single, single->Play->Object);

            alist++;
            index++;
        }
    }
}

static void EffectSingleRun(xAnimSingle* single)
{
    xAnimEffect* effect = single->Effect;
    xAnimActiveEffect tempActive;
    float32 time = single->Time;

    while (effect && effect->StartTime <= time)
    {
        uint32 flags = effect->Flags;

        if ((flags & XANIMEFFECT_UNK0x1) && (!(flags & XANIMEFFECT_UNK0x20) || !EffectPlaying(single, effect)))
        {
            tempActive.Effect = effect;
            tempActive.Handle = effect->Callback(1, &tempActive, single, single->Play->Object);

            if (flags & XANIMEFFECT_UNK0x2)
            {
                if (effect->EndTime <= time)
                {
                    effect->Callback(3, &tempActive, single, single->Play->Object);
                }
                else
                {
                    EffectActiveInsert(single, &tempActive);
                }
            }
            else if (flags & XANIMEFFECT_UNK0x20)
            {
                EffectActiveInsert(single, &tempActive);
            }
        }

        effect = effect->Next;
    }

    single->Effect = effect;
}

static void EffectSingleLoop(xAnimSingle* single) WIP
{
    EffectSingleRun(single);

    xAnimActiveEffect* alist = single->ActiveList;
    uint32 index = 0;
    uint32 count = single->ActiveCount;

    while (index < count && alist->Effect != NULL)
    {
        if (!(alist->Effect->Flags & XANIMEFFECT_UNK0x20))
        {
            alist->Effect->Callback(3, alist, single, single->Play->Object);

            EffectActiveRemove(alist, index, count);
        }
        else
        {
            alist++;
            index++;
        }
    }

    xAnimEffect* effect = single->State->Effects;

    while (effect && effect->StartTime < 0.0f)
    {
        effect = effect->Next;
    }

    single->Effect = effect;
}

static void EffectSingleStop(xAnimSingle* single)
{
    if (!single->State || single->LastTime == -1.0f)
    {
        return;
    }

    uint32 i = 0;

    while (i < single->ActiveCount && single->ActiveList[i].Effect)
    {
        if (single->ActiveList[i].Effect->Flags & XANIMEFFECT_UNK0x2)
        {
            single->ActiveList[i].Effect->Callback(3, &single->ActiveList[i], single, single->Play->Object);
        }

        i++;
    }

    single->ActiveList[0].Effect = NULL;

    xAnimEffect* effect = single->Effect;

    while (effect)
    {
        if ((effect->Flags & (XANIMEFFECT_UNK0x1 | XANIMEFFECT_UNK0x8)) == (XANIMEFFECT_UNK0x1 | XANIMEFFECT_UNK0x8))
        {
            xAnimActiveEffect tempActive;

            tempActive.Effect = effect;
            tempActive.Handle = effect->Callback(1, &tempActive, single, single->Play->Object);

            if (effect->Flags & XANIMEFFECT_UNK0x2)
            {
                effect->Callback(3, &tempActive, single, single->Play->Object);
            }

            effect = effect->Next;
        }
    }

    single->Effect = NULL;
}

static void StopUpdate(xAnimSingle* single)
{
    if (single->Time > single->State->Data->Duration)
    {
        single->Time = single->State->Data->Duration;
        single->CurrentSpeed = 0.0f;
    }
}

static void LoopUpdate(xAnimSingle* single)
{
    float32 time = single->Time;
    float32 duration = single->State->Data->Duration;

    if (time > duration)
    {
        single->Time = duration;

        EffectSingleLoop(single);

        single->Time = time - duration;
    }
}

void xAnimPlaySetState(xAnimSingle* single, xAnimState* state, float32 startTime)
{
    EffectSingleStop(single);

    if (single->Blend)
    {
        EffectSingleStop(single->Blend);
        single->Blend->State = NULL;
    }

    single->State = state;

    if (state)
    {
        single->Time = ((state->Flags & XANIMSTATE_UNK0x100) && startTime == 0.0f) ? state->Data->Duration * xurand() : startTime;
        single->CurrentSpeed = state->Speed;
        single->BilinearLerp[0] = 0.0f;
        single->BilinearLerp[1] = 0.0f;
        single->Effect = NULL;

        memset(single->ActiveList, 0, single->ActiveCount * sizeof(xAnimActiveEffect));

        single->LastTime = -1.0f;
        single->Sync = NULL;

        if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
        {
            xMemPoolFree(&sxAnimTempTranPool, single->Tran);
        }

        single->Tran = NULL;
        single->BlendFactor = 0.0f;
    }
}

static void SingleUpdate(xAnimSingle* single, float32 timeDelta) WIP
{
    uint32 foundBlendstop = 0; // r30
    uint32 firstStep = TRUE; // r29
    xAnimTransition* foundTransition = NULL; // r28
    xAnimSingle* bl = NULL; // r27
    float32 tranDelta = 0.0f; // f31
    float32 blendDelta = 0.0f; // f30

    if (!single->State)
    {
        return;
    }

    void* object = single->Play->Object; // r26

    if (single->LastTime == -1.0f)
    {
        EffectSingleStart(single);
    }

    single->LastTime = single->Time;

    xAnimSingle* r25 = single->Blend;
    float32 singleTime = timeDelta * single->CurrentSpeed + single->Time; // f27

    if (r25 && r25->State)
    {
        bl = r25;

        if (r25->LastTime == -1.0f)
        {
            EffectSingleStart(r25);
        }

        r25->LastTime = r25->Time;
    }

    float32 duration = single->State->Data->Duration; // f29

    if (single->Sync)
    {
        float32 timeCmp = single->Sync->SrcTime;

        if (timeCmp != 0.0f)
        {
            if (timeCmp > duration)
            {
                timeCmp = duration;
            }

            if (single->LastTime <= timeCmp && singleTime >= timeCmp)
            {
                foundTransition = single->Sync;
                tranDelta = (singleTime - timeCmp) / single->CurrentSpeed;
                timeDelta -= tranDelta;

                if (timeDelta < 0.0f)
                {
                    timeDelta = 0.0f;
                }
            }
            else
            {
                timeCmp += duration;

                if (single->LastTime <= timeCmp && singleTime >= timeCmp)
                {
                    foundTransition = single->Sync;
                    tranDelta = (singleTime - timeCmp) / single->CurrentSpeed;
                    timeDelta -= tranDelta;

                    if (timeDelta < 0.0f)
                    {
                        timeDelta = 0.0f;
                    }
                }
            }
        }
        else if (!bl)
        {
            tranDelta = timeDelta;
            foundTransition = single->Sync;
            timeDelta = 0.0f;
        }
    }
    else if ((single->State->Flags & XANIMSTATE_UNK0x30MASK) == XANIMSTATE_UNK0x20)
    {
        float32 timeCmp = single->State->Default->T->SrcTime; // f26

        if (timeCmp == 0.0f || timeCmp > duration)
        {
            timeCmp = duration;
        }

        if (singleTime >= timeCmp && (!(single->State->Default->T->Flags & XANIMTRANSITION_UNK0x4) || !bl))
        {
            xAnimTransitionList* curr = single->State->Default; // r25

            while (curr && curr->T->Conditional && !curr->T->Conditional(curr->T, single, object))
            {
                curr = curr->Next;
            }

            if (!curr)
            {
                fprintf(stderr, "State \"%s\" no default conditionals true!\n", single->State->Name);
                curr = single->State->Default;
            }

            foundTransition = curr->T;

            if (single->LastTime < timeCmp)
            {
                tranDelta = (singleTime - timeCmp) / single->CurrentSpeed;
                timeDelta -= tranDelta;

                if (timeDelta < 0.0f)
                {
                    timeDelta = 0.0f;
                }
            }
            else
            {
                tranDelta = timeDelta;
                timeDelta = 0.0f;
            }
        }
    }

    if (single->BlendFactor != 0.0f)
    {
        float32 recip; // f3

        if (single->Tran)
        {
            recip = single->Tran->BlendRecip;
        }
        else
        {
            recip = single->State->FadeRecip;
        }

        if (recip * (single->BlendFactor + timeDelta) > 1.0f)
        {
            foundBlendstop = 1;
            blendDelta = single->BlendFactor + timeDelta - 1.0f / recip;
            timeDelta -= blendDelta;

            if (timeDelta < 0.0f)
            {
                timeDelta = 0.0f;
            }

            if (blendDelta < 0.0f)
            {
                blendDelta = 0.01f;
            }
        }
    }

    while (true)
    {
        if (!firstStep)
        {
            if (foundBlendstop)
            {
                single->BlendFactor = 0.0f;

                if (bl)
                {
                    EffectSingleStop(bl);

                    bl->State = NULL;
                    bl = NULL;

                    if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
                    {
                        xMemPoolFree(&sxAnimTempTranPool, single->Tran);
                    }

                    single->Tran = NULL;
                }
                else if (single->Tran)
                {
                    if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
                    {
                        xMemPoolFree(&sxAnimTempTranPool, single->Tran);
                    }

                    single->Tran = NULL;
                }
                else
                {
                    EffectSingleStop(single);
                    single->State = NULL;
                    return;
                }

                timeDelta = blendDelta;
                foundBlendstop = 0;
            }
            else
            {
                if (bl)
                {
                    EffectSingleStop(single);

                    bl->State = NULL;
                    bl = NULL;

                    single->BlendFactor = 0.0f;
                }

                if (foundTransition->BlendRecip == 0.0f || !single->Blend)
                {
                    EffectSingleStop(single);

                    if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
                    {
                        xMemPoolFree(&sxAnimTempTranPool, single->Tran);
                    }

                    single->Tran = NULL;
                }
                else
                {
                    bl = single->Blend;
                    bl->State = single->State;
                    bl->Time = single->Time;
                    bl->CurrentSpeed = single->CurrentSpeed;
                    bl->BilinearLerp[0] = single->BilinearLerp[0];
                    bl->BilinearLerp[1] = single->BilinearLerp[1];
                    bl->Effect = single->Effect;
                    bl->LastTime = single->LastTime;

                    memcpy(bl->ActiveList, single->ActiveList, single->ActiveCount * sizeof(xAnimActiveEffect));

                    single->ActiveList[0].Effect = NULL;

                    if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
                    {
                        xMemPoolFree(&sxAnimTempTranPool, single->Tran);
                    }

                    single->Tran = foundTransition;
                    single->BlendFactor = 0.0000001f;
                }

                TransitionTimeInit(single, foundTransition);

                single->State = foundTransition->Dest;
                single->CurrentSpeed = single->State->Speed;
                single->BilinearLerp[0] = 0.0f;
                single->BilinearLerp[1] = 0.0f;
                single->Sync = NULL;

                EffectSingleStart(single);

                if (foundTransition->Dest->BeforeEnter)
                {
                    foundTransition->Dest->BeforeEnter(single->Play, foundTransition->Dest);
                }

                if (foundTransition->Callback)
                {
                    foundTransition->Callback(foundTransition, single, single->Play->Object);
                }

                timeDelta = tranDelta;
                foundTransition = NULL;
            }
        }

        single->Time += timeDelta * single->CurrentSpeed;

        if (single->BlendFactor != 0.0f)
        {
            single->BlendFactor += timeDelta;
        }

        if ((single->State->Flags & XANIMSTATE_UNK0x30MASK) == XANIMSTATE_UNK0x10)
        {
            LoopUpdate(single);
        }
        else
        {
            StopUpdate(single);
        }

        EffectSingleRun(single);

        if (bl)
        {
            if ((bl->State->Flags & XANIMSTATE_UNK0x30MASK) == XANIMSTATE_UNK0x10)
            {
                LoopUpdate(bl);
            }
            else
            {
                StopUpdate(bl);
            }

            EffectSingleRun(bl);
        }

        firstStep = FALSE;

        if (!foundBlendstop && !foundTransition)
        {
            break;
        }
    }

    if (!single->Tran && single->BlendFactor == 0.0f && (single->State->Flags & XANIMSTATE_UNK0x30MASK) == XANIMSTATE_UNK0x30)
    {
        if (single->State->Flags & XANIMSTATE_UNK0x200)
        {
            if (single->Time >= duration)
            {
                single->BlendFactor = 0.0000001f;
            }
        }
        else
        {
            if (single->State->FadeRecip * (duration - single->Time) < 1.0f)
            {
                single->BlendFactor = 0.0000001f;
            }
        }
    }

    EffectSingleDuration(single);

    if (bl)
    {
        EffectSingleDuration(bl);
    }
}

static void SingleEval(xAnimSingle* single, xVec3* tran, xQuat* quat)
{
    if (single->Play->BoneCount > 1)
    {
        xAnimFileEval(single->State->Data, single->Time, single->BilinearLerp, XANIMFILEEVAL_UNK0x2, tran + 1, quat + 1, NULL);

        if (single->Blend && single->Blend->State)
        {
            xQuat* qbuf = (xQuat*)(giAnimScratch + 0xE40);
            xVec3* vbuf = (xVec3*)(qbuf + 65);

            xAnimFileEval(single->Blend->State->Data, single->Blend->Time, single->Blend->BilinearLerp, XANIMFILEEVAL_UNK0x2, vbuf, qbuf, NULL);
            iAnimBlend(single->BlendFactor, single->Tran->BlendRecip, single->Tran->BlendOffset, NULL, single->Play->BoneCount - 1, vbuf, qbuf, tran + 1, quat + 1, tran + 1, quat + 1);
        }
    }
}

void xAnimPlaySetup(xAnimPlay* play, void* object, xAnimTable* table, xModelInstance* modelInst)
{
    play->BoneCount = modelInst->BoneCount;
    play->Object = object;
    play->Table = table;
    play->ModelInst = modelInst;

    modelInst->Anim = play;
    modelInst->Flags |= XMODELINSTANCE_UNK0x4 | XMODELINSTANCE_UNK0x100;

    if (table->MorphIndex != 0)
    {
        modelInst->Flags |= XMODELINSTANCE_UNK0x80;
    }

    for (int32 i = 0; i < play->NumSingle; i++)
    {
        play->Single[i].SingleFlags = ((1 << i) & table->MorphIndex) ? XANIMSINGLE_UNK0x8000 : XANIMSINGLE_UNK0x1;
        play->Single[i].State = NULL;
        play->Single[i].Tran = NULL;

        if (play->Single[i].Blend)
        {
            play->Single[i].Blend->State = NULL;
        }
    }

    xAnimPlaySetState(play->Single, table->StateList, 0.0f);
}

void xAnimPlayChooseTransition(xAnimPlay* play)
{
    uint32 i;
    void* object = play->Object;
    xAnimTransition** found = (xAnimTransition**)giAnimScratch;

    memset(found, 0, play->NumSingle * sizeof(xAnimTransition*));

    for (i = 0; i < play->NumSingle; i++)
    {
        if (play->Single[i].State)
        {
            xAnimTransitionList* curr = play->Single[i].State->List;

            if (curr && curr->T->Conditional)
            {
                while (curr)
                {
                    if (curr->T->Conditional(curr->T, &play->Single[i], object) &&
                        (!found[curr->T->Dest->Flags & XANIMSTATE_UNK0xF] || curr->T->Priority > found[curr->T->Dest->Flags & XANIMSTATE_UNK0xF]->Priority))
                    {
                        found[curr->T->Dest->Flags & XANIMSTATE_UNK0xF] = curr->T;
                    }

                    curr = curr->Next;
                }
            }
        }
    }

    for (i = 0; i < play->NumSingle; i++)
    {
        if (found[i] &&
            (!play->Single[i].Sync || found[i]->Priority > play->Single[i].Sync->QueuePriority))
        {
            xAnimPlayStartTransition(play, found[i]);
        }
    }
}

void xAnimPlayStartTransition(xAnimPlay* play, xAnimTransition* transition) WIP
{
    xAnimSingle* single = &play->Single[transition->Dest->Flags & XANIMSTATE_UNK0xF];
    xAnimSingle* bl = single->Blend;

    if (transition->SrcTime != 0.0f || ((transition->Flags & XANIMTRANSITION_UNK0x4) && bl && bl->State))
    {
        single->Sync = transition;
        return;
    }

    if (bl && bl->State)
    {
        EffectSingleStop(bl);

        bl->State = NULL;
        single->BlendFactor = 0.0f;
    }

    if (transition->BlendRecip == 0.0f || !single->Blend)
    {
        EffectSingleStop(single);

        if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
        {
            xMemPoolFree(&sxAnimTempTranPool, single->Tran);
        }

        single->Tran = NULL;
    }
    else
    {
        if (single->State)
        {
            bl->State = single->State;
            bl->Time = single->Time;
            bl->CurrentSpeed = single->CurrentSpeed;
            bl->BilinearLerp[0] = single->BilinearLerp[0];
            bl->BilinearLerp[1] = single->BilinearLerp[1];
            bl->Effect = single->Effect;
            bl->LastTime = single->LastTime;

            memcpy(bl->ActiveList, single->ActiveList, single->ActiveCount * sizeof(xAnimActiveEffect));

            single->ActiveList[0].Effect = NULL;
        }

        if (single->Tran && (single->Tran->Flags & XANIMTRANSITION_UNK0x2))
        {
            xMemPoolFree(&sxAnimTempTranPool, single->Tran);
        }

        single->Tran = transition;
        single->BlendFactor = 0.0000001f;
    }

    TransitionTimeInit(single, transition);

    single->State = transition->Dest;
    single->CurrentSpeed = single->State->Speed;
    single->BilinearLerp[0] = 0.0f;
    single->BilinearLerp[1] = 0.0f;
    single->Sync = NULL;

    EffectSingleStart(single);

    if (transition->Dest->BeforeEnter)
    {
        transition->Dest->BeforeEnter(play, transition->Dest);
    }

    if (transition->Callback)
    {
        transition->Callback(transition, single, single->Play->Object);
    }
}

void xAnimPlayUpdate(xAnimPlay* play, float32 timeDelta)
{
    for (uint32 i = 0; i < play->NumSingle; i++)
    {
        xAnimSingle* single = &play->Single[i];

        SingleUpdate(single, timeDelta);

        if (single->State->StateCallback)
        {
            single->State->StateCallback(single->State, single, play->Object);
        }
    }
}

void xAnimPlayEval(xAnimPlay* play) WIP
{
    uint32 i;
    uint32 bone;
    xQuat* quatresult = (xQuat*)giAnimScratch;
    xVec3* tranresult = (xVec3*)(quatresult + 65);

    if (play->BoneCount > 1)
    {
        xQuat* quatblend = (xQuat*)(giAnimScratch + 0x720);
        xVec3* tranblend = (xVec3*)(quatblend + 65);

        SingleEval(play->Single, tranresult, quatresult);

        for (i = 1; i < play->NumSingle; i++)
        {
            xAnimSingle* si = &play->Single[i];

            if (si->State && !(si->SingleFlags & XANIMSINGLE_UNK0x8000))
            {
                float32 blendF = 1.0f;
                float32 blendR = 1.0f;
                uint16* blendO = NULL;

                SingleEval(si, tranblend, quatblend);

                if ((!si->Blend || !si->Blend->State) && si->BlendFactor != 0.0f)
                {
                    if (si->Tran)
                    {
                        blendF = si->BlendFactor;
                        blendR = si->Tran->BlendRecip;
                        blendO = si->Tran->BlendOffset;
                    }
                    else
                    {
                        blendF = -si->BlendFactor;
                        blendR = si->State->FadeRecip;
                        blendO = si->State->FadeOffset;
                    }
                }

                if ((si->SingleFlags & XANIMSINGLE_UNK0x3MASK) == XANIMSINGLE_UNK0x2)
                {
                    iAnimBlend(blendF, blendR, blendO, si->State->BoneBlend, play->BoneCount - 1, tranblend + 1, quatblend + 1, NULL, NULL, tranblend + 1, quatblend + 1);

                    for (bone = 1; bone < play->BoneCount; bone++)
                    {
                        tranresult[bone].x += tranblend[bone].x;
                        tranresult[bone].y += tranblend[bone].y;
                        tranresult[bone].z += tranblend[bone].z;

                        xQuatMul(&quatresult[bone], &quatresult[bone], &quatblend[bone]);
                    }
                }
                else
                {
                    iAnimBlend(blendF, blendR, blendO, si->State->BoneBlend, play->BoneCount - 1, tranresult + 1, quatresult + 1, tranblend + 1, quatblend + 1, tranresult + 1, quatresult + 1);
                }
            }
        }
    }

    memset(tranresult, 0, sizeof(xVec3));
    memset(quatresult, 0, sizeof(xQuat));

    if (play->Single->State->BeforeAnimMatrices)
    {
        play->Single->State->BeforeAnimMatrices(play, quatresult, tranresult, play->BoneCount);
    }

    if (play->BeforeAnimMatrices)
    {
        play->BeforeAnimMatrices(play, quatresult, tranresult, play->BoneCount);
    }

    iModelAnimMatrices(play->ModelInst->Data, quatresult, tranresult, play->ModelInst->Mat + 1);
}

void xAnimPoolCB(xMemPool* pool, void* data)
{
    int32 i;
    xAnimPlay* clone = (xAnimPlay*)data;
    xAnimPlay* play = (xAnimPlay*)pool->Buffer;
    xAnimSingle* clonesingle = (xAnimSingle*)(clone + 1);
    xAnimSingle* currsingle;
    xAnimActiveEffect* curract;

    clone->NumSingle = play->NumSingle;
    clone->Single = clonesingle;

    clonesingle += play->NumSingle;

    for (i = 0; i < play->NumSingle; i++)
    {
        clone->Single[i].Play = clone;

        if (play->Single[i].Blend)
        {
            clone->Single[i].Blend = clonesingle;

            clonesingle->Blend = NULL;
            clonesingle->Play = clone;

            clonesingle++;
        }
        else
        {
            clone->Single[i].Blend = NULL;
        }
    }

    curract = (xAnimActiveEffect*)clonesingle;

    for (i = 0; i < clone->NumSingle; i++)
    {
        clonesingle = &clone->Single[i];
        currsingle = &play->Single[i];

        while (clonesingle)
        {
            clonesingle->ActiveCount = currsingle->ActiveCount;

            if (currsingle->ActiveCount)
            {
                clonesingle->ActiveList = curract;

                curract += currsingle->ActiveCount;
            }
            else
            {
                clonesingle->ActiveList = NULL;
            }

            currsingle = currsingle->Blend;
            clonesingle = clonesingle->Blend;
        }
    }

    clone->Pool = pool;
}

#define thing1 ((blendFlags & 0xFFFF) & ((1 << singles) - 1))
#define thing2 ((blendFlags & 0xFFFF) & (((1 << singles) - 1) >> 4))
#define thing3 ((blendFlags & 0xFFFF) & (((1 << singles) - 1) >> 8))
#define thing4 ((blendFlags & 0xFFFF) & (((1 << singles) - 1) >> 12))

void xAnimPoolInit(xMemPool* pool, uint32 count, uint32 singles, uint32 blendFlags, uint32 effectMax) WIP
{
    uint32 size;
    uint32 i;
    void* buffer;
    xAnimPlay* play;
    xAnimSingle* currsingle;
    xAnimActiveEffect* curract;

    size = sizeof(xAnimPlay) + (effectMax * sizeof(xAnimActiveEffect) + sizeof(xAnimSingle)) *
               ((thing1 & 0x1) + ((thing1 & 0x2) >> 1) + ((thing1 & 0x4) >> 2) + ((thing1 & 0x8) >> 3) +
               (thing2 & 0x1) + ((thing2 & 0x2) >> 1) + ((thing2 & 0x4) >> 2) + ((thing2 & 0x8) >> 3) +
               (thing3 & 0x1) + ((thing3 & 0x2) >> 1) + ((thing3 & 0x4) >> 2) + ((thing3 & 0x8) >> 3) +
               (thing4 & 0x1) + ((thing4 & 0x2) >> 1) + ((thing4 & 0x4) >> 2) + ((thing4 & 0x8) >> 3) +
               singles);

    effectMax += effectMax & 1;
    buffer = xMEMALLOC(count * size);
    play = (xAnimPlay*)buffer;

    play->NumSingle = singles;
    play->Single = (xAnimSingle*)(play + 1);

    currsingle = play->Single + singles;

    for (i = 0; i < singles; i++)
    {
        if (blendFlags & (1 << i))
        {
            play->Single[i].Blend = currsingle;
            currsingle->Blend = NULL;

            currsingle++;
        }
        else
        {
            play->Single[i].Blend = NULL;
        }
    }

    curract = (xAnimActiveEffect*)currsingle;

    for (i = 0; i < play->NumSingle; i++)
    {
        currsingle = &play->Single[i];

        if (effectMax != 0)
        {
            while (currsingle)
            {
                currsingle->ActiveCount = effectMax;
                currsingle->ActiveList = curract;

                curract += effectMax;
                currsingle = currsingle->Blend;
            }
        }
        else
        {
            while (currsingle)
            {
                currsingle->ActiveCount = effectMax;
                currsingle->ActiveList = NULL;

                currsingle = currsingle->Blend;
            }
        }
    }

    play->Pool = pool;

    xMemPoolSetup(pool, play, 0, XMEMPOOL_UNK0x1, xAnimPoolCB, size, count, count / 2);
}

xAnimPlay* xAnimPoolAlloc(xMemPool* pool, void* object, xAnimTable* table, xModelInstance* modelInst)
{
    xAnimPlay* play = (xAnimPlay*)xMemPoolAlloc(pool);

    xAnimPlaySetup(play, object, table, modelInst);

    return play;
}

void xAnimPoolFree(xAnimPlay* play)
{
    for (uint32 i = 0; i < play->NumSingle; i++)
    {
        EffectSingleStop(&play->Single[i]);

        if (play->Single[i].Blend)
        {
            EffectSingleStop(play->Single[i].Blend);
        }
    }

    xMemPoolFree(play->Pool, play);
}