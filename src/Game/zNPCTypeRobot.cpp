#include "zNPCTypeRobot.h"

inline void PlayTheFiddle() {}

void ZNPC_Robot_Startup() STUB_VOID
void ZNPC_Robot_Shutdown() {}
void zNPCRobot_ScenePrepare() STUB_VOID
void zNPCRobot_SceneFinish() STUB_VOID
void zNPCRobot_SceneReset() STUB_VOID
void zNPCRobot_ScenePostInit() STUB_VOID
void zNPCRobot_Timestep(xScene*, float32 dt) STUB_VOID
xFactoryInst* ZNPC_Create_Robot(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Robot(xFactoryInst* inst) STUB_VOID
void ZNPC_AnimTable_RobotBase(xAnimTable* table) STUB_VOID
xAnimTable* ZNPC_AnimTable_Fodder() STUB
xAnimTable* ZNPC_AnimTable_Hammer() STUB
xAnimTable* ZNPC_AnimTable_TarTar() STUB
xAnimTable* ZNPC_AnimTable_TTSauce() STUB
xAnimTable* ZNPC_AnimTable_GLove() STUB
xAnimTable* ZNPC_AnimTable_Monsoon() STUB
xAnimTable* ZNPC_AnimTable_ThunderCloud() STUB
xAnimTable* ZNPC_AnimTable_NightLight() STUB
xAnimTable* ZNPC_AnimTable_SleepyTime() STUB
xAnimTable* ZNPC_AnimTable_ArfDog() STUB
xAnimTable* ZNPC_AnimTable_ArfArf() STUB
xAnimTable* ZNPC_AnimTable_Chuck() STUB
xAnimTable* ZNPC_AnimTable_Tubelet() STUB
xAnimTable* ZNPC_AnimTable_FloatDevice() STUB
xAnimTable* ZNPC_AnimTable_SlickShield() STUB
xAnimTable* ZNPC_AnimTable_Slick() STUB

uint8 zNPCRobot::ColChkFlags() const STUB
uint8 zNPCRobot::ColPenFlags() const STUB
uint8 zNPCRobot::PhysicsFlags() const STUB
void zNPCRobot::Init(xEntAsset* asset) STUB_VOID
void zNPCRobot::Reset() STUB_VOID
float32 zNPCRobot::GenShadCacheRad() STUB
void zNPCRobot::ParseINI() STUB_VOID
void zNPCRobot::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCRobot::NewTime(xScene* xscn, float32 dt) STUB_VOID
void zNPCRobot::SelfSetup() STUB_VOID
uint32 zNPCRobot::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*) STUB
bool32 zNPCRobot::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
bool32 zNPCRobot::NPCMessage(NPCMsg* mail) STUB
bool32 zNPCRobot::RoboHandleMail(NPCMsg* mail) STUB
void zNPCRobot::DuploOwner(zNPCCommon* duper) STUB_VOID
void zNPCRobot::DoAliveStuff(float32 dt) STUB_VOID
void zNPCRobot::CheckFalling(float32) STUB_VOID
void zNPCRobot::BunnyHopSet(xVec3*) STUB_VOID
void zNPCRobot::AddLassoing(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback) STUB_VOID
void zNPCRobot::AddMiscTypical(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback) STUB_VOID
void zNPCRobot::AddStunThrow(xPsyche* psy, xGoalProcessCallback eval_evilpat, xGoalProcessCallback eval_stunned, xGoalProcessCallback eval_patcarry, xGoalProcessCallback eval_patthrow) STUB_VOID
void zNPCRobot::AddDamage(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback) STUB_VOID
void zNPCRobot::AddSpawning(xPsyche*, xGoalProcessCallback, xGoalProcessCallback) STUB_VOID
bool32 zNPCRobot::LassoSetup() STUB
int32 zNPCRobot::IsDying() STUB
int32 zNPCRobot::IsWounded() STUB
bool32 zNPCRobot::SetCarryState(en_NPC_CARRY_STATE stat) STUB
void zNPCRobot::Stun(float32 stuntime) STUB_VOID
void zNPCRobot::SyncStunGlyph(float32 tmr_remain, float32 height) STUB_VOID
void zNPCRobot::LassoNotify(en_LASSO_EVENT event) STUB_VOID
void zNPCRobot::CollideReview() STUB_VOID
void zNPCRobot::InflictPain(int32 numHitPoints, bool32 giveCreditToPlayer) STUB_VOID
void zNPCRobot::TurnThemHeads() STUB_VOID
float32 zNPCRobot::FacePos(xVec3* pos, float32 dt, float32 spd_turn) STUB
float32 zNPCRobot::FaceAntiPlayer(float32 dt, float32 spd_turn) STUB
void zNPCRobot::CornerOfArena(xVec3* pos_corner, float32 dst) STUB_VOID
float32 zNPCRobot::MoveTowardsArena(float32 dt, float32 speed) STUB
void zNPCRobot::ShowerConfetti(xVec3* pos) STUB_VOID
void zNPCRobot_TubeConfetti(const xVec3* pos_emit) STUB_VOID

void zNPCFodder::Init(xEntAsset* asset) STUB_VOID
void zNPCFodder::ParseINI() STUB_VOID
void zNPCFodder::SelfSetup() STUB_VOID
uint32 zNPCFodder::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCFodder::Stun(float32) STUB_VOID

void zNPCFodBomb::Init(xEntAsset* asset) STUB_VOID
void zNPCFodBomb::Setup() STUB_VOID
void zNPCFodBomb::ParseINI() STUB_VOID
void zNPCFodBomb::SelfSetup() STUB_VOID
void zNPCFodBomb::Stun(float32) STUB_VOID
uint32 zNPCFodBomb::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCFodBomb::BlinkerReset() STUB_VOID
void zNPCFodBomb::BlinkerUpdate(float32 dt, float32 pct_timeRemain) STUB_VOID
void zNPCFodBomb::BlinkerRender() STUB_VOID

void zNPCFodBzzt::Init(xEntAsset* asset) STUB_VOID
void zNPCFodBzzt::ParseINI() STUB_VOID
void zNPCFodBzzt::Setup() STUB_VOID
void zNPCFodBzzt::Reset() STUB_VOID
void zNPCFodBzzt::SelfSetup() STUB_VOID
void zNPCFodBzzt::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCFodBzzt::Stun(float32) STUB_VOID
uint32 zNPCFodBzzt::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCFodBzzt::RenderExtra() STUB_VOID
void zNPCFodBzzt_ResetDanceParty() STUB_VOID
void zNPCFodBzzt_DoTheHokeyPokey(float32 dt) STUB_VOID
void zNPCFodBzzt::DiscoReset() STUB_VOID
void zNPCFodBzzt::DiscoUpdate(float32 dt) STUB_VOID
void zNPCFodBzzt::DiscoRender() STUB_VOID

void zNPCChomper::Init(xEntAsset* asset) STUB_VOID
void zNPCChomper::ParseINI() STUB_VOID
void zNPCChomper::SelfSetup() STUB_VOID
void zNPCChomper::Stun(float32) STUB_VOID
void zNPCChomper::Process(xScene* xscn, float32 dt) STUB_VOID
uint32 zNPCChomper::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCChomper::BreathTrail() STUB_VOID

void zNPCCritter::Init(xEntAsset* asset) STUB_VOID
void zNPCCritter::SelfSetup() STUB_VOID

void zNPCHammer::Init(xEntAsset* asset) STUB_VOID
void zNPCHammer::ParseINI() STUB_VOID
void zNPCHammer::SelfSetup() STUB_VOID
uint32 zNPCHammer::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB

void zNPCTarTar::Init(xEntAsset* asset) STUB_VOID
void zNPCTarTar::ParseINI() STUB_VOID
void zNPCTarTar::SelfSetup() STUB_VOID
uint32 zNPCTarTar::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB

void zNPCGlove::Init(xEntAsset* asset) STUB_VOID
void zNPCGlove::ParseINI() STUB_VOID
void zNPCGlove::SelfSetup() STUB_VOID
uint32 zNPCGlove::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB

void zNPCMonsoon::Init(xEntAsset* asset) STUB_VOID
void zNPCMonsoon::Reset() STUB_VOID
void zNPCMonsoon::ParseINI() STUB_VOID
void zNPCMonsoon::SelfSetup() STUB_VOID
uint32 zNPCMonsoon::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCMonsoon::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCMonsoon::NewTime(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCMonsoon::FoulWeather(float32) WIP { return FALSE; }

void zNPCSleepy_Timestep(float32) STUB_VOID
void zNPCSleepy::Init(xEntAsset* asset) STUB_VOID
void zNPCSleepy::Reset() STUB_VOID
void zNPCSleepy::ParseINI() STUB_VOID
void zNPCSleepy::SelfSetup() STUB_VOID
uint32 zNPCSleepy::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCSleepy::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCSleepy::NewTime(xScene* xscn, float32 dt) STUB_VOID
void zNPCSleepy::NightLightPos(xVec3*) STUB_VOID
void zNPCSleepy::NightLightUVStep(float32 dt) STUB_VOID
void zNPCSleepy::SnoreNZeez(float32 dt) STUB_VOID
bool32 zNPCSleepy::RepelMissile(float32 dt) STUB
bool32 zNPCSleepy::RepelBowlBall(float32) STUB
void zNPCSleepy::ConeOfRange(float32, int32) STUB_VOID
void zNPCSleepy::RenderExtra() STUB_VOID
void zNPCSleepy::RendConeOfDeath(bool32 tgt_isBowlingBall) STUB_VOID
void zNPCSleepy::RendConeRange() STUB_VOID

void zNPCArfArf::Init(xEntAsset* asset) STUB_VOID
void zNPCArfArf::Reset() STUB_VOID
void zNPCArfArf::ParseINI() STUB_VOID
void zNPCArfArf::ParseLinks() STUB_VOID
void zNPCArfArf::ParseChild(xBase* child) STUB_VOID
void zNPCArfArf::SelfSetup() STUB_VOID
uint32 zNPCArfArf::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCArfArf::DuploNotice(en_SM_NOTICES note, void* data) STUB_VOID
zNPCArfDog* zNPCArfArf::AdoptADoggie() STUB

void zNPCArfDog::Init(xEntAsset* asset) STUB_VOID
void zNPCArfDog::Setup() STUB_VOID
void zNPCArfDog::Reset() STUB_VOID
void zNPCArfDog::ParseINI() STUB_VOID
void zNPCArfDog::SelfSetup() STUB_VOID
uint32 zNPCArfDog::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCArfDog::Stun(float32) STUB_VOID
void zNPCArfDog::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCArfDog::BlinkReset() STUB_VOID
void zNPCArfDog::BlinkUpdate(float32, float32) STUB_VOID
void zNPCArfDog::BlinkRender() STUB_VOID

void zNPCChuck::Init(xEntAsset* asset) STUB_VOID
void zNPCChuck::Reset() STUB_VOID
void zNPCChuck::ParseINI() STUB_VOID
void zNPCChuck::SelfSetup() STUB_VOID
uint32 zNPCChuck::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB

void zNPCTubelet::Init(xEntAsset* asset) STUB_VOID
void zNPCTubelet::Reset() STUB_VOID
void zNPCTubelet::ParseINI() STUB_VOID
void zNPCTubelet::ParseLinks() STUB_VOID
void zNPCTubelet::ParseChild(xBase* child) STUB_VOID
void zNPCTubelet::SelfSetup() STUB_VOID
uint32 zNPCTubelet::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCTubelet::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCTubelet::Respawn(const xVec3* pos, zMovePoint* mvptFirst, zMovePoint* mvptSpawnRef) STUB
void zNPCTubelet::PrepTheBand() STUB_VOID
bool32 zNPCTubelet::RoboHandleMail(NPCMsg* mail) STUB
void zNPCTubelet::LassoNotify(en_LASSO_EVENT event) STUB_VOID
void zNPCTubelet::Bonk() STUB_VOID
void zNPCTubelet::Unbonk() STUB_VOID
bool32 zNPCTubelet::Chk_IsBonked() STUB
void zNPCTubelet::PainInTheBand() STUB_VOID
void zNPCTubelet::Chk_NonAlertBonk(float32) STUB_VOID
void TubeNotice::Notice(en_psynote note, xGoal* goal, void*) STUB_VOID
bool32 zNPCTubelet::IsDying() STUB

void zNPCTubeSlave::Init(xEntAsset* asset) STUB_VOID
void zNPCTubeSlave::Setup() STUB_VOID
void zNPCTubeSlave::Reset() STUB_VOID
void zNPCTubeSlave::WeGotAGig() STUB_VOID
void zNPCTubeSlave::PartyOn() STUB_VOID
void zNPCTubeSlave::ParseINI() STUB_VOID
void zNPCTubeSlave::SelfSetup() STUB_VOID
uint32 zNPCTubeSlave::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCTubeSlave::SetMaster(zNPCTubelet*, en_tubespot) STUB_VOID
void zNPCTubeSlave::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCTubeSlave::RenderExtra() STUB_VOID
bool32 zNPCTubeSlave::RoboHandleMail(NPCMsg* mail) STUB
bool32 zNPCTubeSlave::IsDying() STUB
void zNPCTubeSlave::PosStacked(xVec3* pos_stacked) STUB_VOID
void zNPCTubeSlave::DoLaserRendering() STUB_VOID

void zNPCSlick::Init(xEntAsset* asset) STUB_VOID
void zNPCSlick::Reset() STUB_VOID
void zNPCSlick::ParseINI() STUB_VOID
void zNPCSlick::SelfSetup() STUB_VOID
uint32 zNPCSlick::AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal) STUB
void zNPCSlick::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCSlick::StuffToDoIfAlive(float32) STUB_VOID
void zNPCSlick::Damage(en_NPC_DAMAGE_TYPE dmg_type, xBase* who, const xVec3* vec_hit) STUB_VOID
void zNPCSlick::ShieldUpdate(float32 dt) STUB_VOID
void zNPCSlick::ShieldCollide(float32) STUB_VOID
void zNPCSlick::ShieldFX(float32) STUB_VOID
static void WhereTheWildThingsAre(xModelInstance*) STUB_VOID
void zNPCSlick::ShieldGeneratorDamaged() STUB_VOID
void zNPCSlick::RopePopsShield() STUB_VOID
void zNPCSlick::BUpdate(xVec3* pos) STUB_VOID
bool32 zNPCSlick::IsShield() const STUB
void zNPCSlick::ShieldHide() STUB_VOID
void zNPCSlick::ShieldShow() STUB_VOID
void zNPCSlick::YouOwnSlipFX() STUB_VOID
void zNPCSlick::SlipSlidenAway(float32) STUB_VOID

static int32 DUMY_grul_returnToIdle(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 ROBO_grul_goAlertMelee(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 ROBO_grul_goAlertLobber(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 FODR_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 BOMB_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 BZZT_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 CHMP_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 HAMR_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 TART_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 GLOV_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 MOON_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 SLEP_grul_goAlert(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB
static int32 SLEP_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 ARFY_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 PUPY_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 CHUK_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 TUBE_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB
static int32 SLCK_grul_alert(xGoal*, void*, en_trantype* trantype, float32, void*) STUB

void ROBO_InitEffects() STUB_VOID
void ROBO_KillEffects() {}

void zNPCRobot::DoFX_Motorboat(float32) STUB_VOID
void zNPCRobot::VFXStarTrek(float32 dt, xVec3* pos, xVec3* vel) STUB_VOID
bool32 zNPCRobot::LaunchProjectile(en_npchaz haztyp, float32 spd_proj, float32 dst_minRange, en_mdlvert idx_mvtx, float32 tym_predictMax, float32 hyt_offset) STUB

bool32 NPCArena::IncludesPos(xVec3* pos, float32 rad_thresh, xVec3* vec) STUB
float32 NPCArena::PctFromHome(xVec3* pos) STUB
float32 NPCArena::DstSqFromHome(xVec3* pos, xVec3* delt) STUB
int32 NPCArena::NeedToCycle(zNPCCommon* npc) STUB
bool32 NPCArena::Cycle(zNPCCommon* npc, bool32 peek) STUB
zMovePoint* NPCArena::NextBestNav(zNPCCommon*, zMovePoint* nav_from) STUB
void NPCArena::SetHome(zNPCCommon* npc, zMovePoint* nav) STUB_VOID
void NPCArena::AdjustHome(zNPCCommon*, xVec3*, float32) STUB_VOID
void NPCArena::SyncHomeFromNav() STUB_VOID