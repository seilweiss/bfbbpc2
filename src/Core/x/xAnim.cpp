#include "xAnim.h"

#include "xMath.h"
#include "xMemMgr.h"

static xMemPool sxAnimTempTranPool;
uint32 gxAnimUseGrowAlloc = 0;

static bool _xSingleCompare(char, char) STUB
static bool _xSingleCompare(char, const char*) STUB
static bool _xCharIn(char, const char*) STUB
static bool _xCheckAnimNameInner(const char* name, const char* pattern, int32 patternSize, char* extra, int32* nameOut, int32* extraOut) STUB
static bool _xCheckAnimName(const char*, const char*, char*) STUB
void xAnimInit() STUB_VOID
void xAnimTempTransitionInit(uint32 count) STUB_VOID
static float32 CalcRecipBlendMax(uint16*) STUB
static uint32 StateHasTransition(xAnimState*, xAnimTransition*) STUB
static uint32 DefaultHasTransition(xAnimState*, xAnimTransition*, uint32*) STUB
static uint32 DefaultOverride(xAnimState*, xAnimTransition*) STUB
static void TransitionTimeInit(xAnimSingle*, xAnimTransition*) STUB_VOID
xAnimFile* xAnimFileNewBilinear(void** rawData, const char* name, uint32 flags, xAnimFile** linkedList, uint32 numX, uint32 numY) STUB
xAnimFile* xAnimFileNew(void* rawData, const char* name, uint32 flags, xAnimFile** linkedList) STUB
void xAnimFileSetTime(xAnimFile* data, float32 duration, float32 timeOffset) STUB_VOID
void xAnimFileEval(xAnimFile* data, float32 time, float32* bilinear, uint32 flags, xVec3* tran, xQuat* quat, float32*) STUB_VOID
xAnimEffect* xAnimStateNewEffect(xAnimState* state, uint32 flags, float32 startTime, float32 endTime, xAnimEffectCallback callback, uint32 userDataSize) STUB
xAnimTable* xAnimTableNew(const char* name, xAnimTable** linkedList, uint32 userFlags) STUB
void xAnimDefaultBeforeEnter(xAnimPlay*, xAnimState* state) STUB_VOID
xAnimState* xAnimTableNewState(xAnimTable* table, const char* name, uint32 flags, uint32 userFlags, float32 speed, float32* boneBlend, float32* timeSnap, float32 fadeRecip, uint16* fadeOffset, void* callbackData, xAnimBeforeEnterCallback beforeEnter, xAnimStateCallback stateCallback, xAnimBeforeAnimMatricesCallback beforeAnimMatrices) STUB
static void _xAnimTableAddTransitionHelper(xAnimState*, xAnimTransition*, uint32&, uint32&, xAnimState**) STUB_VOID
static void _xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source, const char* dest) STUB_VOID
void xAnimTableAddTransition(xAnimTable* table, xAnimTransition* tran, const char* source) STUB_VOID
xAnimTransition* xAnimTableNewTransition(xAnimTable* table, const char* source, const char* dest, xAnimTransitionConditionalCallback conditional, xAnimTransitionCallback callback, uint32 flags, uint32 userFlags, float32 srcTime, float32 destTime, uint16 priority, uint16 queuePriority, float32 blendRecip, uint16* blendOffset) STUB
void xAnimTableAddFile(xAnimTable* table, xAnimFile* file, const char* states) STUB_VOID
xAnimState* xAnimTableAddFileID(xAnimTable* table, xAnimFile* file, uint32 stateID, uint32 subStateID, uint32 subStateCount) STUB
xAnimState* xAnimTableGetStateID(xAnimTable* table, uint32 ID) STUB
xAnimState* xAnimTableGetState(xAnimTable* table, const char* name) STUB
static void EffectActiveInsert(xAnimSingle*, xAnimActiveEffect*) STUB_VOID
static void EffectActiveRemove(xAnimActiveEffect*, uint32, uint32) STUB_VOID
static uint32 EffectPlaying(xAnimSingle*, xAnimEffect*) STUB
static void EffectSingleStart(xAnimSingle* single) STUB_VOID
static void EffectSingleDuration(xAnimSingle* single) STUB_VOID
static void EffectSingleRun(xAnimSingle* single) STUB_VOID
static void EffectSingleLoop(xAnimSingle* single) STUB_VOID
static void EffectSingleStop(xAnimSingle* single) STUB_VOID
static void StopUpdate(xAnimSingle*) STUB_VOID
static void LoopUpdate(xAnimSingle*) STUB_VOID
void xAnimPlaySetState(xAnimSingle* single, xAnimState* state, float32 startTime) STUB_VOID
static void SingleUpdate(xAnimSingle* single, float32 timeDelta) STUB_VOID
static void SingleEval(xAnimSingle*, xVec3*, xQuat*) STUB_VOID
void xAnimPlaySetup(xAnimPlay* play, void* object, xAnimTable* table, xModelInstance* modelInst) STUB_VOID
void xAnimPlayChooseTransition(xAnimPlay* play) STUB_VOID
void xAnimPlayStartTransition(xAnimPlay* play, xAnimTransition* transition) STUB_VOID
void xAnimPlayUpdate(xAnimPlay* play, float32 timeDelta) STUB_VOID
void xAnimPlayEval(xAnimPlay* play) STUB_VOID
void xAnimPoolCB(xMemPool* pool, void* data) STUB_VOID
void xAnimPoolInit(xMemPool* pool, uint32 count, uint32 singles, uint32 blendFlags, uint32 effectMax) STUB_VOID
xAnimPlay* xAnimPoolAlloc(xMemPool* pool, void* object, xAnimTable* table, xModelInstance* modelInst) STUB
void xAnimPoolFree(xAnimPlay* play) STUB_VOID