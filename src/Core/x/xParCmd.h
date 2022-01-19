#pragma once

#include <types.h>

struct xParGroup;

struct xParCmdAsset
{
	uint32 type;
	uint8 enabled;
	uint8 mode;
	uint8 pad[2];
};

struct xParCmd
{
	uint32 flag;
	xParCmdAsset* tasset;
};

typedef void(*xParCmdUpdateCallback)(xParCmd* c, xParGroup* ps, float32 dt);

void xParCmdInit();
void xParCmdRegister(uint32 parType, uint32 size, xParCmdUpdateCallback func);
uint32 xParCmdGetSize(uint32 parType);
xParCmdUpdateCallback xParCmdGetUpdateFunc(uint32 parType);
void xParCmdKillSlow_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdAge_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdFollow_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdOrbitPoint_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdOrbitLine_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdAccelerate_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdMove_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdMoveRandom_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdMoveRandomPar_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdScale3rdPolyReg_Update(xParCmd*, xParGroup*, float32);
void xParCmdSmokeAlpha_Update(xParCmd*, xParGroup*, float32);
void xParCmdScale_Update(xParCmd*, xParGroup*, float32);
void xParCmdAlpha3rdPolyReg_Update(xParCmd*, xParGroup*, float32);
void xParCmdRandomVelocityPar_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdApplyWind_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdRotPar_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdVelocityApply_Update(xParCmd*, xParGroup* ps, float32);
void xParCmdRotateAround_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdTex_Update(xParCmd*, xParGroup*, float32);
void xParCmdTexAnim_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmdCollideFall_Update(xParCmd* c, xParGroup* ps, float32);
void xParCmdCollideFallSticky_Update(xParCmd* c, xParGroup* ps, float32);
void xParCmd_DampenSpeed_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmd_SizeInOut_Update(xParCmd* c, xParGroup* ps, float32 dt);
void xParCmd_AlphaInOut_Update(xParCmd* c, xParGroup* ps, float32);
void xParCmd_Shaper_Update(xParCmd* c, xParGroup* ps, float32 dt);