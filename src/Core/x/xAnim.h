#pragma once

#include "iAnim.h"
#include "xMorph.h"

struct xAnimFile;
struct xAnimMultiFileEntry;
struct xAnimMultiFileBase;
struct xAnimMultiFile;
struct xAnimEffect;
struct xAnimActiveEffect;
struct xAnimState;
struct xAnimTransition;
struct xAnimTransitionList;
struct xAnimSingle;
struct xAnimTable;
struct xAnimPlay;

typedef xAnimTable*(*xAnimTableConstructor)();
typedef uint32(*xAnimEffectCallback)(uint32, xAnimActiveEffect*, xAnimSingle*, void*);
typedef void(*xAnimBeforeEnterCallback)(xAnimPlay*, xAnimState*);
typedef void(*xAnimStateCallback)(xAnimState*, xAnimSingle*, void*);
typedef void(*xAnimBeforeAnimMatricesCallback)(xAnimPlay*, xQuat*, xVec3*, int32);
typedef uint32(*xAnimTransitionConditionalCallback)(xAnimTransition*, xAnimSingle*, void*);
typedef uint32(*xAnimTransitionCallback)(xAnimTransition*, xAnimSingle*, void*);

struct xMemPool;
struct xModelInstance;

struct xAnimFile
{
	xAnimFile* Next;
	const char* Name;
	uint32 ID;
	uint32 FileFlags;
	float32 Duration;
	float32 TimeOffset;
	uint16 BoneCount;
	uint8 NumAnims[2];
	void** RawData;
};

#define XANIMFILE_UNK0x1000 0x1000
#define XANIMFILE_UNK0x2000 0x2000
#define XANIMFILE_UNK0x4000 0x4000
#define XANIMFILE_USEMORPHSEQ 0x8000

struct xAnimMultiFileEntry
{
	uint32 ID;
	xAnimFile* File;
};

struct xAnimMultiFileBase
{
	uint32 Count;
};

struct xAnimMultiFile : xAnimMultiFileBase
{
	xAnimMultiFileEntry Files[1];
};

struct xAnimEffect
{
	xAnimEffect* Next;
	uint32 Flags;
	float32 StartTime;
	float32 EndTime;
	xAnimEffectCallback Callback;
};

#define XANIMEFFECT_UNK0x1 0x1
#define XANIMEFFECT_UNK0x2 0x2
#define XANIMEFFECT_UNK0x4 0x4
#define XANIMEFFECT_UNK0x8 0x8
#define XANIMEFFECT_UNK0x10 0x10
#define XANIMEFFECT_UNK0x20 0x20

struct xAnimActiveEffect
{
	xAnimEffect* Effect;
	uint32 Handle;
};

struct xAnimState
{
	xAnimState* Next;
	const char* Name;
	uint32 ID;
	uint32 Flags;
	uint32 UserFlags;
	float32 Speed;
	xAnimFile* Data;
	xAnimEffect* Effects;
	xAnimTransitionList* Default;
	xAnimTransitionList* List;
	float32* BoneBlend;
	float32* TimeSnap;
	float32 FadeRecip;
	uint16* FadeOffset;
	void* CallbackData;
	xAnimMultiFile* MultiFile;
	xAnimBeforeEnterCallback BeforeEnter;
	xAnimStateCallback StateCallback;
	xAnimBeforeAnimMatricesCallback BeforeAnimMatrices;
};

#define XANIMSTATE_UNK0xF 0xF
#define XANIMSTATE_UNK0x100 0x100

struct xAnimTransition
{
	xAnimTransition* Next;
	xAnimState* Dest;
	xAnimTransitionConditionalCallback Conditional;
	xAnimTransitionCallback Callback;
	uint32 Flags;
	uint32 UserFlags;
	float32 SrcTime;
	float32 DestTime;
	uint16 Priority;
	uint16 QueuePriority;
	float32 BlendRecip;
	uint16* BlendOffset;
};

#define XANIMTRANSITION_UNK0x2 0x2
#define XANIMTRANSITION_UNK0x4 0x4
#define XANIMTRANSITION_UNK0x10 0x10
#define XANIMTRANSITION_UNK0x20 0x20

struct xAnimTransitionList
{
	xAnimTransitionList* Next;
	xAnimTransition* T;
};

struct xAnimSingle
{
	uint32 SingleFlags;
	xAnimState* State;
	float32 Time;
	float32 CurrentSpeed;
	float32 BilinearLerp[2];
	xAnimEffect* Effect;
	uint32 ActiveCount;
	float32 LastTime;
	xAnimActiveEffect* ActiveList;
	xAnimPlay* Play;
	xAnimTransition* Sync;
	xAnimTransition* Tran;
	xAnimSingle* Blend;
	float32 BlendFactor;
	uint32 pad;
};

#define XANIMSINGLE_UNK0x1 0x1
#define XANIMSINGLE_UNK0x8000 0x8000

struct xAnimTable
{
	xAnimTable* Next;
	const char* Name;
	xAnimTransition* TransitionList;
	xAnimState* StateList;
	uint32 AnimIndex;
	uint32 MorphIndex;
	uint32 UserFlags;
};

struct xAnimPlay
{
	xAnimPlay* Next;
	uint16 NumSingle;
	uint16 BoneCount;
	xAnimSingle* Single;
	void* Object;
	xAnimTable* Table;
	xMemPool* Pool;
	xModelInstance* ModelInst;
	xAnimBeforeAnimMatricesCallback BeforeAnimMatrices;
};

extern uint32 gxAnimUseGrowAlloc;

#define XANIMFILEEVAL_UNK0x2 0x2

#define xAnimFileGetDuration(file) (((file)->FileFlags & XANIMFILE_USEMORPHSEQ) ? xMorphSeqDuration((xMorphSeqFile*)(file)->RawData[0]) : iAnimDuration((file)->RawData[0]))

void xAnimInit();
void xAnimTempTransitionInit(uint32 count);
xAnimFile* xAnimFileNewBilinear(void** rawData, const char* name, uint32 flags, xAnimFile** linkedList, uint32 numX, uint32 numY);
xAnimFile* xAnimFileNew(void* rawData, const char* name, uint32 flags, xAnimFile** linkedList);
void xAnimFileSetTime(xAnimFile* data, float32 duration, float32 timeOffset);
void xAnimFileEval(xAnimFile* data, float32 time, float32* bilinear, uint32 flags, xVec3* tran, xQuat* quat, float32*);
xAnimEffect* xAnimStateNewEffect(xAnimState* state, uint32 flags, float32 startTime, float32 endTime, xAnimEffectCallback callback, uint32 userDataSize);
xAnimTable* xAnimTableNew(const char* name, xAnimTable** linkedList, uint32 userFlags);
void xAnimDefaultBeforeEnter(xAnimPlay*, xAnimState* state);
xAnimState* xAnimTableNewState(xAnimTable* table, const char* name, uint32 flags, uint32 userFlags, float32 speed, float32* boneBlend, float32* timeSnap, float32 fadeRecip, uint16* fadeOffset, void* callbackData, xAnimBeforeEnterCallback beforeEnter, xAnimStateCallback stateCallback, xAnimBeforeAnimMatricesCallback beforeAnimMatrices);
void xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source);
xAnimTransition* xAnimTableNewTransition(xAnimTable* table, const char* source, const char* dest, xAnimTransitionConditionalCallback conditional, xAnimTransitionCallback callback, uint32 flags, uint32 userFlags, float32 srcTime, float32 destTime, uint16 priority, uint16 queuePriority, float32 blendRecip, uint16* blendOffset);
void xAnimTableAddFile(xAnimTable* table, xAnimFile* file, const char* states);
xAnimState* xAnimTableAddFileID(xAnimTable* table, xAnimFile* file, uint32 stateID, uint32 subStateID, uint32 subStateCount);
xAnimState* xAnimTableGetStateID(xAnimTable* table, uint32 ID);
xAnimState* xAnimTableGetState(xAnimTable* table, const char* name);
void xAnimPlaySetState(xAnimSingle* single, xAnimState* state, float32 startTime);
void xAnimPlaySetup(xAnimPlay* play, void* object, xAnimTable* table, xModelInstance* modelInst);
void xAnimPlayChooseTransition(xAnimPlay* play);
void xAnimPlayStartTransition(xAnimPlay* play, xAnimTransition* transition);
void xAnimPlayUpdate(xAnimPlay* play, float32 timeDelta);
void xAnimPlayEval(xAnimPlay* play);
void xAnimPoolCB(xMemPool* pool, void* data);
void xAnimPoolInit(xMemPool* pool, uint32 count, uint32 singles, uint32 blendFlags, uint32 effectMax);
xAnimPlay* xAnimPoolAlloc(xMemPool* pool, void* object, xAnimTable* table, xModelInstance* modelInst);
void xAnimPoolFree(xAnimPlay* play);

inline float32 xAnimFileRawTime(xAnimFile* file, float32 time)
{
	if ((file->FileFlags & XANIMFILE_UNK0x1000) ||
		((file->FileFlags & XANIMFILE_UNK0x2000) && time > 0.5f * file->Duration))
	{
		return file->TimeOffset + file->Duration - time;
	}

	return file->TimeOffset + time;
}