#include "xAnim.h"

#include "xMemMgr.h"
#include "xString.h"
#include "xModel.h"

#include <string.h>

static xMemPool sxAnimTempTranPool;
uint32 gxAnimUseGrowAlloc = 0;

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

static bool _xCheckAnimNameInner(const char* name, const char* pattern, int32 patternSize, char* extra, int32* nameOut, int32* extraOut) STUB

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
    xAnimFile* afile = (xAnimFile*)(gxAnimUseGrowAlloc ? xMEMGROWALLOC(numX * numY * sizeof(void*) + sizeof(xAnimFile)) :
                                                         xMEMALLOC(numX * numY * sizeof(void*) + sizeof(xAnimFile)));

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

void xAnimFileEval(xAnimFile* data, float32 time, float32* bilinear, uint32 flags, xVec3* tran, xQuat* quat, float32*) STUB_VOID

xAnimEffect* xAnimStateNewEffect(xAnimState* state, uint32 flags, float32 startTime, float32 endTime, xAnimEffectCallback callback, uint32 userDataSize)
{
    xAnimEffect* curr;
    xAnimEffect** prev;
    xAnimEffect* effect = (xAnimEffect*)(gxAnimUseGrowAlloc ? xMEMGROWALLOC(userDataSize + sizeof(xAnimEffect)) :
                                                              xMEMALLOC(userDataSize + sizeof(xAnimEffect)));

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
    xAnimState* state = (xAnimState*)(gxAnimUseGrowAlloc ? xMEMGROWALLOC(sizeof(xAnimState)) :
                                                           xMEMALLOC(sizeof(xAnimState)));

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

static void _xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source, const char* dest) STUB_VOID

void xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source)
{
    _xAnimTableAddTransition(table, tran, source, NULL);
}

xAnimTransition* xAnimTableNewTransition(xAnimTable* table, const char* source, const char* dest, xAnimTransitionConditionalCallback conditional, xAnimTransitionCallback callback, uint32 flags, uint32 userFlags, float32 srcTime, float32 destTime, uint16 priority, uint16 queuePriority, float32 blendRecip, uint16* blendOffset)
{
    xAnimTransition* tran = (xAnimTransition*)(gxAnimUseGrowAlloc ? xMEMGROWALLOC(sizeof(xAnimTransition)) :
                                                                    xMEMALLOC(sizeof(xAnimTransition)));

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
                state->MultiFile = (xAnimMultiFile*)(gxAnimUseGrowAlloc ? xMEMGROWALLOC(subStateCount * sizeof(xAnimMultiFileEntry) + sizeof(xAnimMultiFileBase)) :
                                                                          xMEMALLOC(subStateCount * sizeof(xAnimMultiFileEntry) + sizeof(xAnimMultiFileBase)));

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

static void SingleUpdate(xAnimSingle* single, float32 timeDelta) STUB_VOID

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

void xAnimPlayEval(xAnimPlay* play) STUB_VOID

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

void xAnimPoolInit(xMemPool* pool, uint32 count, uint32 singles, uint32 blendFlags, uint32 effectMax) STUB_VOID

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