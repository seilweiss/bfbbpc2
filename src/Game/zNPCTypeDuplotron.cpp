#include "zNPCTypeDuplotron.h"

void ZNPC_Duplotron_Startup() STUB_VOID
void ZNPC_Duplotron_Shutdown() {}
void zNPCDuplotron_ScenePrepare() {}
void zNPCDuplotron_SceneFinish() STUB_VOID
void zNPCDuplotron_ScenePostInit() STUB_VOID
xFactoryInst* ZNPC_Create_Duplotron(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Duplotron(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_Duplotron() STUB

void zNPCDuplotron::Init(xEntAsset* asset) STUB_VOID
void zNPCDuplotron::Setup() STUB_VOID
void zNPCDuplotron::ParseINI() STUB_VOID
void zNPCDuplotron::Reset() STUB_VOID
void zNPCDuplotron::ParseLinks() STUB_VOID
void zNPCDuplotron::BUpdate(xVec3* pos) STUB_VOID
void zNPCDuplotron::ParseChild(xBase* child) STUB_VOID
void zNPCDuplotron::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCDuplotron::SelfSetup() STUB_VOID
uint32 zNPCDuplotron::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*) STUB
void zNPCDuplotron::DuploNotice(en_SM_NOTICES note, void* data) STUB_VOID
bool32 zNPCDuplotron::IsAlive() STUB
bool32 zNPCDuplotron::NPCMessage(NPCMsg* mail) STUB
bool32 zNPCDuplotron::DupoHandleMail(NPCMsg* mail) STUB

void DUPO_InitEffects() STUB_VOID
void DUPO_KillEffects() {}

void zNPCDuplotron::VFXSmokeStack(float32 dt) STUB_VOID
void zNPCDuplotron::VFXOverheat(float32 dt, float32) STUB_VOID
void zNPCDuplotron::VFXCycleLights(float32 dt, int32 fastpace) STUB_VOID