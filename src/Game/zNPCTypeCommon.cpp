#include "zNPCTypeCommon.h"

xFactoryInst* ZNPC_Create_Common(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Common(xFactoryInst* inst) STUB_VOID
void ZNPC_Common_Startup() STUB_VOID
void ZNPC_Common_Shutdown() STUB_VOID
void zNPCCommon_ScenePrepare() STUB_VOID
void zNPCCommon_SceneFinish() STUB_VOID
void zNPCCommon_SceneReset() STUB_VOID
void zNPCCommon_ScenePostInit() STUB_VOID
void zNPCCommon_Timestep(xScene*, float32 dt) STUB_VOID
void zNPCCommon::Init(xEntAsset* entass) STUB_VOID
void zNPCCommon::InitBounds() STUB_VOID
void zNPCCommon::Setup() STUB_VOID
void zNPCCommon::Reset() STUB_VOID
void zNPCCommon::Destroy() STUB_VOID
void zNPCCommon::Damage(en_NPC_DAMAGE_TYPE damtype, xBase* who, const xVec3* vec_hit) STUB_VOID
bool32 zNPCCommon::Respawn(const xVec3* pos, zMovePoint* mvptFirst, zMovePoint* mvptSpawnRef) STUB
bool32 zNPCCommon::NPCMessage(NPCMsg* mail) STUB
void zNPCCommon::Move(xScene* xscn, float32 dt, xEntFrame*) STUB_VOID
void zNPCCommon::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCCommon::BUpdate(xVec3* pos) STUB_VOID
float32 zNPCCommon::BoundAsRadius(int32 useCfg) const STUB
void zNPCCommon::NewTime(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCCommon::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCCommon::ConvertHitEvent(xBase* from, xBase*, uint32, const float32* toParam, xBase*, bool32*) STUB_VOID
void zNPCCommon::VelStop() STUB_VOID
float32 zNPCCommon::ThrottleAdjust(float32 dt, float32 spd_want, float32 accel) STUB
float32 zNPCCommon::ThrottleAccel(float32 dt, int32 speedup, float32 pct_max) STUB
float32 zNPCCommon::ThrottleApply(float32 dt, const xVec3* dir, int32 force3D) STUB
float32 zNPCCommon::TurnToFace(float32 dt, const xVec3* dir_want, float32 useTurnRate) STUB
void zNPCCommon::ParseLinks() STUB_VOID
void zNPCCommon::ParseINI() STUB_VOID
void zNPCCommon::ParseProps() STUB_VOID
void zNPCCommon::CollideReview() STUB_VOID
bool32 zNPCCommon::IsMountableType(en_ZBASETYPE) STUB
void zNPCCommon::SelfDestroy() STUB_VOID
void zNPCCommon::TagVerts() STUB_VOID
bool32 zNPCCommon::GetVertPos(en_mdlvert vid, xVec3* pos) STUB
int32 zNPCCommon::IsAttackFrame(float32 tym_anim, int32 series) STUB
void zNPCCommon::GiveReward() STUB_VOID
static void zNPCPlyrSnd_Reset() STUB_VOID
static void zNPCPlyrSnd_Update(float32) STUB_VOID
void zNPCCommon::PlayerKiltMe() STUB_VOID
void zNPCCommon::ISeePlayer() STUB_VOID
void zNPCCommon::ConfigSceneDone() STUB_VOID
NPCConfig* zNPCCommon::ConfigCreate(uint32) STUB
NPCConfig* zNPCCommon::ConfigFind(uint32) STUB
void zNPCCommon::GetParm(en_npcparm pid, int32* val) STUB_VOID
void zNPCCommon::GetParm(en_npcparm, float32*) STUB_VOID
void zNPCCommon::GetParm(en_npcparm, xVec3*) STUB_VOID
void zNPCCommon::GetParm(en_npcparm pid, zMovePoint** val) STUB_VOID
void zNPCCommon::GetParm(en_npcparm pid, void* val) STUB_VOID
bool32 zNPCCommon::GetParmDefault(en_npcparm pid, void* val) STUB
bool32 zNPCCommon::CanDoSplines() STUB
zMovePoint* zNPCCommon::FirstAssigned() STUB
void zNPCCommon::MvptReset(zMovePoint* nav_goto) STUB_VOID
bool32 zNPCCommon::MvptCycle() STUB
bool32 zNPCCommon::HaveLOSToPos(xVec3 * pos, float32 dist, xScene * xscn, xBase * tgt, xCollis * colCallers) STUB
xModelInstance* zNPCCommon::ModelAtomicHide(int32 index, xModelInstance* mdl) STUB
xModelInstance* zNPCCommon::ModelAtomicShow(int32 index, xModelInstance* mdl) STUB
xModelInstance* zNPCCommon::ModelAtomicFind(int32 index, int32 idx_prev, xModelInstance* mdl_prev) STUB
void zNPCCommon::ModelScaleSet(float32 x, float32 y, float32 z) STUB_VOID
bool32 zNPCCommon::AnimStart(uint32 animID, bool32 forceRestart) STUB
void zNPCCommon::AnimSetState(uint32 animID, float32 time) STUB_VOID
xAnimState* zNPCCommon::AnimFindState(uint32 animID) STUB
xAnimSingle* zNPCCommon::AnimCurSingle() STUB
xAnimState* zNPCCommon::AnimCurState() STUB
uint32 zNPCCommon::AnimCurStateID() STUB
float32 zNPCCommon::AnimDuration(xAnimState* ast) STUB
float32 zNPCCommon::AnimTimeRemain(xAnimState* ast) STUB
float32 zNPCCommon::AnimTimeCurrent() STUB
void zNPCSettings_MakeDummy() STUB_VOID
zNPCSettings* zNPCSettings_Find(uint32) STUB
void zNPCCommon::Vibrate(float32 ds2_cur, float32 ds2_max) STUB_VOID
void zNPCCommon::Vibrate(en_npcvibe vibe, float32 duration) STUB_VOID
xVec3* zNPCCommon::MatPosSet(xVec3* pos) STUB
bool32 NPCC_NPCIsConversing() STUB
void zNPCCommon_WonderReset() STUB_VOID
void zNPCCommon::WonderOfTalking(bool32 inprogress, xBase* owner) STUB_VOID
int32 zNPCCommon::SomethingWonderful() STUB
int32 zNPCCommon::SndPlayFromAFX(zAnimFxSound* afxsnd, uint32* sid_played) STUB
int32 zNPCCommon::SndPlayFromSFX(xSFX* sfx, uint32* sid_played) STUB
int32 zNPCCommon::SndPlayRandom(en_NPC_SOUND sndtype) STUB
uint32 zNPCCommon::SndStart(uint32 aid_toplay, NPCSndProp* sprop, float32 radius) STUB
bool32 zNPCCommon::SndIsAnyPlaying() STUB
bool32 zNPCCommon::SndChanIsBusy(int32 flg_chan) STUB
void zNPCCommon::SndKillSounds(int32 flg_chan, bool32 all) STUB_VOID
int32 zNPCCommon::SndQueUpdate(float32 dt) STUB
bool32 zNPCCommon::LassoInit() STUB
bool32 zNPCCommon::LassoSetup() STUB
bool32 zNPCCommon::LassoUseGuides(int32 idx_grabmdl, int32 idx_holdmdl) STUB
bool32 zNPCCommon::LassoGetAnims(xModelInstance* modgrab, xModelInstance* modhold) STUB
void zNPCCommon::LassoSyncAnims(en_lassanim lassanim) STUB_VOID
zNPCLassoInfo* zNPCCommon::GimmeLassInfo() STUB
void zNPCCommon::LassoNotify(en_LASSO_EVENT event) STUB_VOID
void zNPCCommon::AddBaseline(xPsyche* psy, xGoalProcessCallback eval_idle, xGoalProcessCallback eval_patrol, xGoalProcessCallback eval_wander, xGoalProcessCallback eval_waiting, xGoalProcessCallback eval_fidget) STUB_VOID
void zNPCCommon::AddScripting(xPsyche* psy, xGoalProcessCallback eval_script, xGoalProcessCallback eval_playanim, xGoalProcessCallback eval_attack, xGoalProcessCallback eval_move, xGoalProcessCallback eval_follow, xGoalProcessCallback eval_lead, xGoalProcessCallback eval_wait) STUB_VOID
void zNPCCommon::AddDEVGoals(xPsyche*) {}
xAnimTable* ZNPC_AnimTable_Common() STUB
xAnimTable* ZNPC_AnimTable_LassoGuide() STUB
void NPCC_BuildStandardAnimTran(xAnimTable* table, char** namelist, int32* ourAnims, int32 idx_dflt, float32 blend) STUB_VOID
void zNPCCommon_EjectPhlemOnPawz() STUB_VOID