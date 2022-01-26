#include "xParEmitter.h"

static void add_tweaks(xParEmitter&) {}
int32 xParInterpConvertInterpMode(xParInterp* p) STUB
void xParEmitterInit(void* b, void* tasset) STUB_VOID
void xParEmitterInit(xBase* b, xParEmitterAsset* pea) STUB_VOID
void xParEmitterSetup(xParEmitter* t) STUB_VOID
void xParEmitterReset(xParEmitter*) STUB_VOID
bool32 xParEmitterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
xPar* xParEmitterEmitCustom(xParEmitter* p, float32 dt, xParEmitterCustomSettings* info) STUB
static bool32 xParEmitterCull(xParEmitter*, xPar*) STUB
float32 xParInterpCompute(int32 interp_mode, xParInterp* r, float32 time, int32 time_has_elapsed, float32 lastVal) STUB
xPar* xParEmitterEmitSetTexIdxs(xPar* p, const xParSys* ps) STUB
xPar* xParEmitterEmit(xParEmitter* pe, float32 emit_dt, float32 par_dt) STUB
void xParEmitterUpdate(xBase* to, xScene*, float32 dt) STUB_VOID
void xParEmitterDestroy() STUB_VOID