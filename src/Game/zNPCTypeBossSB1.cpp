#include "zNPCTypeBossSB1.h"

xAnimTable* ZNPC_AnimTable_BossSB1() STUB
static void SB1Dummy_UpdateFunc(xEnt* ent, xScene*, float32) STUB_VOID
static void SB1Dummy_BoundFunc(xEnt* ent, xVec3*) STUB_VOID
static void SB1Dummy_RenderFunc(xEnt*) STUB_VOID
static bool32 SB1Dummy_TgtEventFunc(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
static void SB1_ResetGlobalStuff() STUB_VOID

void zNPCB_SB1::Init(xEntAsset* asset) STUB_VOID
void zNPCB_SB1::SelfSetup() STUB_VOID
void zNPCB_SB1::Reset() STUB_VOID
uint32 zNPCB_SB1::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCB_SB1::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCB_SB1::NewTime(xScene* xscn, float32 dt) STUB_VOID
float32 zNPCB_SB1::AttackTimeLeft() STUB
void zNPCB_SB1::HoldUpDude() STUB_VOID
void zNPCB_SB1::ThanksImDone() STUB_VOID

static bool32 SB1_CheckFeetStomp(zNPCB_SB1*, int32*, en_trantype*) STUB
static int32 idleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 tauntCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 stompCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 smashCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 deflateCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static bool32 SB1_FaceTarget(zNPCB_SB1* sb1, xVec3* target, float32 dt) STUB

bool32 zNPCGoalBossSB1Idle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB1Idle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSB1Taunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB1Taunt::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSB1Stomp::Enter(float32 dt, void* updCtxt) STUB
static void AddStompRing(zNPCB_SB1*, xVec3*) STUB_VOID
bool32 zNPCGoalBossSB1Stomp::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSB1Smash::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB1Smash::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB1Smash::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSB1Deflate::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB1Deflate::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB1Deflate::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB