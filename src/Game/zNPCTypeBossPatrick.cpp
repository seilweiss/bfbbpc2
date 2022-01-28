#include "zNPCTypeBossPatrick.h"

#include "xDebug.h"

xAnimTable* ZNPC_AnimTable_BossPatrick() STUB
static void UpdatePatrickBossCam(zNPCBPatrick* pat, float32 dt) STUB_VOID
static void GetBonePos(xVec3* result, xMat4x3* matArray, int32 index, xVec3* offset) STUB_VOID
static bool32 BoundEventCB(xBase*, xBase*, uint32, const float32*, xBase*) { return TRUE; }
static void Pat_ResetGlobalStuff() {}

void zNPCBPatrick::Init(xEntAsset* asset) STUB_VOID

static void on_change_newsfish(const tweak_info&) STUB_VOID
static void on_change_recenter(const tweak_info&) STUB_VOID

void zNPCBPatrick::Setup() STUB_VOID
void zNPCBPatrick::SelfSetup() STUB_VOID
void zNPCBPatrick::Reset() STUB_VOID
void zNPCBPatrick::Destroy() STUB_VOID
uint32 zNPCBPatrick::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal* rawgoal) STUB
void zNPCBPatrick::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCBPatrick::DuploNotice(en_SM_NOTICES note, void* data) STUB_VOID
void zNPCBPatrick::Damage(en_NPC_DAMAGE_TYPE dmg_type, xBase*, const xVec3* vec_hit) STUB_VOID

void zNPCBPatrick_AddBoundEntsToGrid(zScene*) STUB_VOID
void zNPCBPatrick_GameIsPaused(zScene*) STUB_VOID

void zNPCBPatrick::RenderGlobs() STUB_VOID
void zNPCBPatrick::RenderFrozenPlayer() STUB_VOID
void zNPCBPatrick::RenderExtra() STUB_VOID
void zNPCBPatrick::NewTime(xScene* xscn, float32 dt) STUB_VOID
int32 zNPCBPatrick::nextGoal() STUB
zNPCBPatrick::bossPatGlob* zNPCBPatrick::getNextFreeGlob() STUB
void zNPCBPatrick::playSplat(xVec3* pos) STUB_VOID
uint32 zNPCBPatrick::canSpawnChucks() STUB
void zNPCBPatrick::gotoRound(int32 num) STUB_VOID
void zNPCBPatrick::hiddenByCutscene() STUB_VOID
float32 zNPCBPatrick::ConveyorTimeLeft(zPlatform*, xVec3*) STUB
void zNPCBPatrick::ParabolaHitsConveyors(xParabola* path, xCollis* colls) STUB_VOID
void zNPCBPatrick::bossPatBoxCheckCollide(bossPatBox*) STUB_VOID
void zNPCBPatrick::bossPatBoxUpdate(bossPatBox* bx, float32 dt) STUB_VOID

static int32 idleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 tauntCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 hitCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 spitCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 runCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 smackCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 freezeCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 spawnCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 spinCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 fudgeCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 Pat_FaceTarget(zNPCBPatrick* pat, const xVec3* target, float32 turn_rate, float32 dt) STUB

bool32 zNPCGoalBossPatIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatIdle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossPatTaunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatTaunt::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossPatHit::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatHit::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossPatHit::Exit(float32, void*) STUB

bool32 zNPCGoalBossPatSpit::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatSpit::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossPatRun::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatRun::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossPatRun::Exit(float32, void*) STUB

bool32 zNPCGoalBossPatSmack::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatSmack::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

static void StartFreezeBreath() STUB_VOID
static void EmitFreezeBreath(xVec3* pos, xVec3* vel, float32 dt, float32 elapsed, float32 total) STUB_VOID
static void StopFreezeBreath() STUB_VOID

bool32 zNPCGoalBossPatFreeze::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatFreeze::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossPatSpawn::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatSpawn::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossPatSpin::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatSpin::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossPatSpin::Exit(float32, void*) STUB

bool32 zNPCGoalBossPatFudge::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossPatFudge::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB