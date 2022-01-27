#include "zNPCTypeBossSandy.h"

#include "xDebug.h"

static void on_change_newsfish(const tweak_info&) STUB_VOID
static void on_change_shockwave(const tweak_info&) STUB_VOID
xAnimTable* ZNPC_AnimTable_BossSandy() STUB
static uint32 HeadIsCarried(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 HeadNotCarried(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 HeadIsShocked(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 HeadNotShocked(xAnimTransition*, xAnimSingle*, void*) STUB
xAnimTable* ZNPC_AnimTable_BossSandyHead() STUB
xAnimTable* ZNPC_AnimTable_BossSandyScoreboard() STUB

void zNPCBSandy::Init(xEntAsset* asset) STUB_VOID
void zNPCBSandy::Setup() STUB_VOID
void zNPCBSandy::SelfSetup() STUB_VOID
void zNPCBSandy::Reset() STUB_VOID
void zNPCBSandy::ParseINI() STUB_VOID
uint32 zNPCBSandy::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal* rawgoal) STUB

struct SandyLimbSpring
{
	float32 node1;
	float32 vel1;
	float32 node2;
	float32 vel2;
	xBound* bound;
};

static void SpringRender(SandyLimbSpring* spring) STUB_VOID
static void zNPCBSandy_BossDamageEffect_Init() STUB_VOID
static void zNPCBSandy_BossDamageEffect(xModelInstance* minst, uint32 turnOff) STUB_VOID
static void zNPCBSandy_BossDamageEffect_Update(float32 dt) STUB_VOID

void zNPCBSandy::Render() STUB_VOID
void zNPCBSandy::CalcMagnetizeInfo() STUB_VOID
void zNPCBSandy::InitFX() STUB_VOID
void zNPCBSandy::UpdateFX(float32 dt) STUB_VOID

static void UpdateSandyBossCam(zNPCBSandy* sandy, float32 dt) STUB_VOID
static void GetBonePos(xVec3* result, xMat4x3* matArray, int32 index, xVec3* offset) STUB_VOID
static void MakeOBBFor(int32 index1, int32 index2, xEnt* ent, xMat4x3* matArray) STUB_VOID
static bool32 BoundEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB

void zNPCBSandy::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCBSandy::hiddenByCutscene() STUB_VOID
void zNPCBSandy::Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*) STUB_VOID

void zNPCBSandy_AddBoundEntsToGrid(zScene*) STUB_VOID
void zNPCBSandy_GameIsPaused(zScene*) STUB_VOID

void zNPCBSandy::NewTime(xScene* xscn, float32 dt) STUB_VOID

static int32 idleCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 tauntCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 chaseCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 meleeCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 noHeadCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 elbowDropCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 leapCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 sitCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 getUpCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB
static int32 runToRopeCB(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 clotheslineCB(xGoal* rawgoal, void*, en_trantype* trantype, float32 dt, void*) STUB

bool32 zNPCGoalBossSandyIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyIdle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandyIdle::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandyTaunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyTaunt::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSandyChase::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyChase::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandyChase::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandyMelee::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyMelee::Exit(float32, void*) STUB
bool32 zNPCGoalBossSandyMelee::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSandyNoHead::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyNoHead::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSandyElbowDrop::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyElbowDrop::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandyElbowDrop::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandyLeap::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyLeap::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandyLeap::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandySit::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandySit::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandySit::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandyGetUp::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyGetUp::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalBossSandyRunToRope::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyRunToRope::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalBossSandyRunToRope::Exit(float32, void*) STUB

bool32 zNPCGoalBossSandyClothesline::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSandyClothesline::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB