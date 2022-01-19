#include "xTimer.h"

static float32 GetRandomizedTime(xTimerAsset*) STUB
void xTimerInit(void* b, void* tasset) STUB_VOID
static bool32 xTimer_ObjIDIsPauseTimer(uint32 id) STUB
void xTimerInit(xBase*, xTimerAsset*) STUB_VOID
void xTimerReset(xTimer*) STUB_VOID
void xTimerSave(xTimer* ent, xSerial* s) STUB_VOID
void xTimerLoad(xTimer* ent, xSerial* s) STUB_VOID
bool32 xTimerEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB
void xTimerUpdate(xBase* to, xScene*, float32 dt) STUB_VOID