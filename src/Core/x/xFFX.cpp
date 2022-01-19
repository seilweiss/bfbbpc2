#include "xFFX.h"

void xFFXPoolInit(uint32 num_ffx) STUB_VOID
xFFX* xFFXAlloc() STUB
void xFFXFree(xFFX*) STUB_VOID
void xFFXTurnOn(xFFX* f) STUB_VOID
void xFFXTurnOff(xFFX* f) STUB_VOID
int16 xFFXAddEffect(xEnt* ent, xFFX* f) STUB
int16 xFFXAddEffect(xEnt* ent, xFFXDoEffectCallback dof, void* fd) STUB
bool32 xFFXRemoveEffectByFData(xEnt*, void*) STUB
static void xFFXApplyOne(xFFX* ffx, xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xFFXApply(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void xFFXShakeUpdateEnt(xEnt* ent, xScene*, float32 dt, void* fdata) STUB_VOID
void xFFXShakePoolInit(uint32 num) STUB_VOID
xFFXShakeState* xFFXShakeAlloc() STUB
void xFFXShakeFree(xFFXShakeState* s) STUB_VOID
void xFFXRotMatchPoolInit(uint32 num) STUB_VOID
xFFXRotMatchState* xFFXRotMatchAlloc() STUB