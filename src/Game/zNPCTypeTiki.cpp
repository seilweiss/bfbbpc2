#include "zNPCTypeTiki.h"

void ZNPC_Tiki_Startup() STUB_VOID
void ZNPC_Tiki_Shutdown() {}
void zNPCTiki_InitStacking(zScene* zsc) STUB_VOID
void zNPCTiki_InitFX(zScene*) STUB_VOID
void zNPCTiki_ExplodeFX(zNPCTiki* tiki) STUB_VOID
static void zNPCTiki_PickTikisToAnimate() STUB_VOID
void zNPCTiki_Timestep(xScene*, float32 dt) STUB_VOID
void zNPCTiki_ReparentOrphans() STUB_VOID
xFactoryInst* ZNPC_Create_Tiki(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Tiki(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_Tiki() STUB

void zNPCTiki::Reset() STUB_VOID
void zNPCTiki::Setup() STUB_VOID
void zNPCTiki::Init(xEntAsset* entass) STUB_VOID
void zNPCTiki::Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*) STUB_VOID
bool32 zNPCTiki::SetCarryState(en_NPC_CARRY_STATE cs) STUB
void zNPCTiki::SelfSetup() STUB_VOID
void zNPCTiki::ParseINI() STUB_VOID
void zNPCTiki::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCTiki::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCTiki::AddChild(zNPCTiki*) STUB_VOID
void zNPCTiki::RemoveChild(zNPCTiki*) STUB_VOID
void zNPCTiki::RemoveParent(zNPCTiki*) STUB_VOID
void zNPCTiki::FindParents(zScene* zsc) STUB_VOID
void zNPCTiki::ParentUpdated(zNPCTiki*) STUB_VOID
void zNPCTiki::RemoveFromFamily() STUB_VOID

static void loveyFloat(zNPCTiki*, float32) STUB_VOID
static bool32 loveyIdleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 loveyPatrolCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 quietIdleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 quietHideCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 thunderIdleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 thunderCountCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 tikiDyingCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 tikiDeadCB(xGoal* rawgoal, void*, en_trantype*, float32, void*) STUB
static void genericTikiRender(xEnt* ent) STUB_VOID
static void loveyTikiRender(xEnt* ent) STUB_VOID