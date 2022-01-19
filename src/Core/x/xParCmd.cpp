#include "xParCmd.h"

void xParCmdInit() STUB_VOID
void xParCmdRegister(uint32 parType, uint32 size, xParCmdUpdateCallback func) STUB_VOID
uint32 xParCmdGetSize(uint32 parType) STUB
xParCmdUpdateCallback xParCmdGetUpdateFunc(uint32 parType) STUB
void xParCmdKillSlow_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdAge_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdFollow_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdOrbitPoint_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdOrbitLine_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdAccelerate_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdMove_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdMoveRandom_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdMoveRandomPar_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdScale3rdPolyReg_Update(xParCmd*, xParGroup*, float32) STUB_VOID
void xParCmdSmokeAlpha_Update(xParCmd*, xParGroup*, float32) STUB_VOID
void xParCmdScale_Update(xParCmd*, xParGroup*, float32) STUB_VOID
void xParCmdAlpha3rdPolyReg_Update(xParCmd*, xParGroup*, float32) STUB_VOID
void xParCmdRandomVelocityPar_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdApplyWind_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdRotPar_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdVelocityApply_Update(xParCmd*, xParGroup* ps, float32) STUB_VOID
void xParCmdRotateAround_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdTex_Update(xParCmd*, xParGroup*, float32) STUB_VOID
void xParCmdTexAnim_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmdCollideFall_Update(xParCmd* c, xParGroup* ps, float32) STUB_VOID
void xParCmdCollideFallSticky_Update(xParCmd* c, xParGroup* ps, float32) STUB_VOID
void xParCmd_DampenSpeed_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmd_SizeInOut_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID
void xParCmd_AlphaInOut_Update(xParCmd* c, xParGroup* ps, float32) STUB_VOID
void xParCmd_Shaper_Update(xParCmd* c, xParGroup* ps, float32 dt) STUB_VOID