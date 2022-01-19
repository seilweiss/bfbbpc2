#include "xParGroup.h"

void xParGroupInit(xParGroup* ps) STUB_VOID
static void xParGroupRegisterInit() STUB_VOID
void xParGroupSetAging(xParGroup* ps, bool32 age) STUB_VOID
void xParGroupSetBack2Life(xParGroup* ps, bool32 b2l) STUB_VOID
void xParGroupSetVisibility(xParGroup* ps, bool32 vis) STUB_VOID
void xParGroupSetPriority(xParGroup* ps, uint8 val) STUB_VOID
void xParGroupRegister(xParGroup* ps) STUB_VOID
void xParGroupUnregister(xParGroup* ps) STUB_VOID
void xParGroupSetActive(xParGroup* ps, uint32 isActive) STUB_VOID
void xParGroupKillAllParticles(xParGroup* ps) STUB_VOID
void xParGroupAnimate(xParGroup* ps, float32 dt) STUB_VOID
void xParGroupAddParP(xParGroup*, xPar*) STUB_VOID
xPar* xParGroupAddPar(xParGroup* ps) STUB
void xParGroupKillPar(xParGroup* ps, xPar* p) STUB_VOID
void xParGroupAddParToDeadList(xParGroup*, xPar*) STUB_VOID