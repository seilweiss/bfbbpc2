#include "zNPCTypeBoss.h"

void ZNPC_Boss_Startup() STUB_VOID
void ZNPC_Boss_Shutdown() {}
void zNPCBoss_ScenePrepare() STUB_VOID
void zNPCBoss_SceneFinish() STUB_VOID
xFactoryInst* ZNPC_Create_Boss(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Boss(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_BossSBobbyArm() STUB

void zNPCBoss::Setup() STUB_VOID

void BOSS_InitEffects() STUB_VOID