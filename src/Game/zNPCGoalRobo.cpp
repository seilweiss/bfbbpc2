#include "zNPCGoalRobo.h"

xFactoryInst* GOALCreate_Robotic(int32 who, RyzMemGrow* grow, void*) STUB

bool32 zNPCGoalNotice::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalTaunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTaunt::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalEvade::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalEvade::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB

bool32 zNPCGoalGoHome::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB

bool32 zNPCGoalAlert::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlert::Exit(float32, void*) STUB
bool32 zNPCGoalAlert::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalAlertFodder::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertFodder::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertFodder::CheckSpot(float32) STUB
void zNPCGoalAlertFodder::FlankPlayer(float32 dt) STUB_VOID
void zNPCGoalAlertFodder::GetInArena(float32 dt) STUB_VOID
void zNPCGoalAlertFodder::MoveEvade(float32 dt) STUB_VOID

bool32 zNPCGoalAlertFodBomb::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertFodBomb::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertFodBomb::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertFodBomb::Detonate() STUB_VOID
void zNPCGoalAlertFodBomb::SonarHoming(float32 dt) STUB_VOID

bool32 zNPCGoalAlertFodBzzt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertFodBzzt::Exit(float32, void*) STUB
bool32 zNPCGoalAlertFodBzzt::Suspend(float32, void*) STUB
bool32 zNPCGoalAlertFodBzzt::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertFodBzzt::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertFodBzzt::ToggleOrbit() STUB_VOID
void zNPCGoalAlertFodBzzt::OrbitPlayer(float32 dt) STUB_VOID
void zNPCGoalAlertFodBzzt::GetInArena(float32) STUB_VOID
void zNPCGoalAlertFodBzzt::DeathRayUpdate(float32 dt) STUB_VOID
void zNPCGoalAlertFodBzzt::DeathRayRender() STUB_VOID

bool32 zNPCGoalAlertChomper::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertChomper::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertChomper::CirclePlayer(float32 dt) STUB_VOID
void zNPCGoalAlertChomper::GetInArena(float32 dt) STUB_VOID
bool32 zNPCGoalAlertChomper::CalcEvadePos(xVec3* pos) STUB
bool32 zNPCGoalAlertChomper::MoveEvadePos(const xVec3* pos, float32 dt) STUB
bool32 zNPCGoalAlertChomper::CheckSpot(float32) STUB

bool32 zNPCGoalAlertHammer::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertHammer::Exit(float32, void*) STUB
bool32 zNPCGoalAlertHammer::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertHammer::PlayerInSpot(float32) STUB
void zNPCGoalAlertHammer::MoveChase(float32 dt) STUB_VOID
void zNPCGoalAlertHammer::MoveEvade(float32 dt) STUB_VOID

bool32 zNPCGoalAlertTarTar::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertTarTar::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertTarTar::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertTarTar::NPCMessage(NPCMsg* mail) STUB
int32 zNPCGoalAlertTarTar::HoppyUpdate(trantype * trantype, float32 dt) STUB
void zNPCGoalAlertTarTar::GetInArena(float32 dt) STUB_VOID

bool32 zNPCGoalAlertGlove::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertGlove::Exit(float32, void*) STUB
bool32 zNPCGoalAlertGlove::Suspend(float32, void*) STUB
bool32 zNPCGoalAlertGlove::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertGlove::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertGlove::FXTurbulence() STUB_VOID
void zNPCGoalAlertGlove::FXWhirlwind() STUB_VOID
void zNPCGoalAlertGlove::CalcAttackVector() STUB_VOID
bool32 zNPCGoalAlertGlove::CheckHandBones() STUB
bool32 zNPCGoalAlertGlove::CollReview(void*) STUB

bool32 zNPCGoalAlertMonsoon::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertMonsoon::Exit(float32, void*) STUB
bool32 zNPCGoalAlertMonsoon::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertMonsoon::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertMonsoon::MoveCorner(float32 dt) STUB_VOID

bool32 zNPCGoalAlertSleepy::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertSleepy::Exit(float32, void*) STUB
bool32 zNPCGoalAlertSleepy::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertSleepy::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalAlertArf::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertArf::Exit(float32, void*) STUB
bool32 zNPCGoalAlertArf::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertArf::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertArf::NPCMessage(NPCMsg* mail) STUB
en_arfdoes zNPCGoalAlertArf::DecideAttack() STUB

bool32 zNPCGoalAlertPuppy::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertPuppy::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertPuppy::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalAlertChuck::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertChuck::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertChuck::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertChuck::GetInArena(float32 dt) STUB_VOID
bool32 zNPCGoalAlertChuck::ZoomMove(float32 dt) STUB

bool32 zNPCGoalAlertTubelet::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertTubelet::Exit(float32, void*) STUB
bool32 zNPCGoalAlertTubelet::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertTubelet::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalAlertTubelet::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID
bool32 zNPCGoalAlertTubelet::MoveToHome(float32 dt) STUB
void zNPCGoalAlertTubelet::PeteAttackBegin() STUB_VOID
void zNPCGoalAlertTubelet::PeteAttackParSys(float32, int32) STUB_VOID
void zNPCGoalAlertTubelet::EmitSteam(float32) STUB_VOID

bool32 zNPCGoalAlertSlick::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertSlick::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAlertSlick::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
bool32 zNPCGoalAlertSlick::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalAlertSlick::GetInArena(float32 dt) STUB_VOID
void zNPCGoalAlertSlick::MoveCorner(float32 dt) STUB_VOID

bool32 zNPCGoalChase::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB

bool32 zNPCGoalAttackCQC::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackCQC::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB

bool32 zNPCGoalAttackFodder::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackFodder::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackFodder::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalAttackFodder::CattleNotify::Notify(haznote note, NPCHazard*) STUB
bool32 zNPCGoalAttackFodder::SyncCattleProd() STUB

bool32 zNPCGoalAttackChomper::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackChomper::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackChomper::BreathAttack() STUB_VOID

bool32 zNPCGoalAttackHammer::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackHammer::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackHammer::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackHammer::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID
bool32 zNPCGoalAttackHammer::PlayerTests(xVec3* pos_vert, float32) STUB
bool32 zNPCGoalAttackHammer::ShockwaveTests(xVec3* pos_vert, float32) STUB
void zNPCGoalAttackHammer::TellBunnies() STUB_VOID
void zNPCGoalAttackHammer::ModifyAnimSpeed() STUB_VOID
void zNPCGoalAttackHammer::FXStreakPrep() STUB_VOID
void zNPCGoalAttackHammer::FXStreakDone() STUB_VOID
void zNPCGoalAttackHammer::FXStreakUpdate(xVec3* pos_streak) STUB_VOID

bool32 zNPCGoalAttackTarTar::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackTarTar::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalAttackTarTar::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalAttackTarTar::CacheAimPoint() STUB_VOID
bool32 zNPCGoalAttackTarTar::ShootBlob(float32, int32 zapidx) STUB

bool32 zNPCGoalAttackMonsoon::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackMonsoon::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalAttackMonsoon::SpitCloud() STUB

bool32 zNPCGoalAttackArfMelee::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackArfMelee::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackArfMelee::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackArfMelee::PlayerTests() STUB_VOID
void zNPCGoalAttackArfMelee::FXStreakPrep() STUB_VOID
void zNPCGoalAttackArfMelee::FXStreakDone() STUB_VOID
void zNPCGoalAttackArfMelee::FXStreakUpdate() STUB_VOID

bool32 zNPCGoalAttackArf::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackArf::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackArf::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackArf::SetAttackMode(int32, int32) STUB_VOID
void zNPCGoalAttackArf::LaunchBone(float32, int32) STUB_VOID
bool32 zNPCGoalAttackArf::LaunchDoggie(float32) STUB

bool32 zNPCGoalAttackChuck::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackChuck::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackChuck::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackChuck::BombzAway(float32) STUB_VOID

bool32 zNPCGoalAttackSlick::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAttackSlick::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalAttackSlick::FireOne(int32) STUB_VOID

bool32 zNPCGoalDogLaunch::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDogLaunch::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalDogLaunch::ViciousAttack(xVec3*, xVec3*, zMovePoint*, int32) STUB_VOID
void zNPCGoalDogLaunch::PreCollide() STUB_VOID
bool32 zNPCGoalDogLaunch::BallisticUpdate(float32 dt) STUB
void zNPCGoalDogLaunch::BubTrailCone(const xVec3* pos, int32 num, const xVec3* pos_rand, const xVec3* vel_rand, const xMat3x3* mat) STUB_VOID
void zNPCGoalDogLaunch::FurryFlurry() STUB_VOID

bool32 zNPCGoalDogBark::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDogBark::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalDogDash::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDogDash::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalDogDash::HoundPlayer(float32) STUB_VOID

bool32 zNPCGoalDogPounce::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDogPounce::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDogPounce::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalDogPounce::Detonate() STUB_VOID

bool32 zNPCGoalTeleport::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTeleport::Exit(float32, void*) STUB
bool32 zNPCGoalTeleport::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalTeleport::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalHokeyPokey::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalHokeyPokey::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalEvilPat::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalEvilPat::Exit(float32, void*) STUB
bool32 zNPCGoalEvilPat::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalEvilPat::NPCMessage(NPCMsg* msg) STUB
int32 zNPCGoalEvilPat::InputStun(NPCStunInfo* info) STUB
void zNPCGoalEvilPat::GlyphStart() STUB_VOID
void zNPCGoalEvilPat::GlyphStop() STUB_VOID

bool32 zNPCGoalStunned::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalStunned::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
int32 zNPCGoalStunned::InputInfo(NPCStunInfo*) STUB

bool32 zNPCGoalPatCarry::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPatCarry::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalPatThrow::Enter(float32 dt, void* updCtxt) STUB

bool32 zNPCGoalLassoBase::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalLassoBase::Exit(float32, void*) STUB
bool32 zNPCGoalLassoBase::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalLassoGrab::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalLassoGrab::DoTurnAway(float32 dt) STUB_VOID

bool32 zNPCGoalLassoThrow::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalLassoThrow::Exit(float32, void*) STUB
bool32 zNPCGoalLassoThrow::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalLassoThrow::CollReview(void*) STUB
void zNPCGoalLassoThrow::ApplyYank(int32 left) STUB_VOID

bool32 zNPCGoalDamage::Process(trantype* trantype, float32, void*, xScene*) STUB
bool32 zNPCGoalDamage::NPCMessage(NPCMsg* mail) STUB
int32 zNPCGoalDamage::InputInfo(NPCDamageInfo* info) STUB

bool32 zNPCGoalBashed::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBashed::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalWound::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalWound::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
bool32 zNPCGoalWound::CollReview(void*) STUB
bool32 zNPCGoalWound::NPCMessage(NPCMsg* mail) STUB

bool32 zNPCGoalKnock::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKnock::Exit(float32, void*) STUB
bool32 zNPCGoalKnock::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
int32 zNPCGoalKnock::InputInfo(NPCDamageInfo* info) STUB
bool32 zNPCGoalKnock::CollReview(void*) STUB
void zNPCGoalKnock::StreakPrep() STUB_VOID
void zNPCGoalKnock::StreakDone() STUB_VOID
void zNPCGoalKnock::StreakUpdate() STUB_VOID

bool32 zNPCGoalAfterlife::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalAfterlife::NPCMessage(NPCMsg* mail) STUB
void zNPCGoalAfterlife::DieTheGoodDeath() STUB_VOID

bool32 zNPCGoalRespawn::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalRespawn::Exit(float32, void*) STUB
bool32 zNPCGoalRespawn::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
float32 zNPCGoalRespawn::LaunchRoboBits() STUB
void zNPCGoalRespawn::DoAppearFX(float32 dt) STUB_VOID
void zNPCGoalRespawn::KickFromTheNest() STUB_VOID
int32 zNPCGoalRespawn::InputInfo(NPCSpawnInfo*) STUB

bool32 zNPCGoalTubePal::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubePal::EvalRules(trantype* trantype, float32 dt, void* updCtxt) STUB
void zNPCGoalTubePal::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID

bool32 zNPCGoalTubeDuckling::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeDuckling::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeDuckling::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalTubeDuckling::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID
void zNPCGoalTubeDuckling::MoveFrolic(float32 dt) STUB_VOID
void zNPCGoalTubeDuckling::DuckStackInterpInit() STUB_VOID
int32 zNPCGoalTubeDuckling::DuckStackInterp(float32 dt) STUB

bool32 zNPCGoalTubeAttack::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeAttack::Resume(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeAttack::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalTubeAttack::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID
void zNPCGoalTubeAttack::LaserRender() STUB_VOID
void zNPCGoalTubeAttack::MaryAttack(float32 dt, xScene*) STUB_VOID
void zNPCGoalTubeAttack::MarySpinUp() STUB_VOID
void zNPCGoalTubeAttack::MarySpinDown() STUB_VOID
void zNPCGoalTubeAttack::MaryzFury() STUB_VOID
void zNPCGoalTubeAttack::MaryzBlessing() STUB_VOID
void zNPCGoalTubeAttack::AttackDataReset() STUB_VOID

bool32 zNPCGoalTubeLasso::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeLasso::Exit(float32, void*) STUB
bool32 zNPCGoalTubeLasso::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalTubeLasso::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID
void zNPCGoalTubeLasso::MoveTryToEscape(float32 dt) STUB_VOID

bool32 zNPCGoalTubeBirth::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeBirth::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalTubeBirth::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID

bool32 zNPCGoalTubeBonked::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeBonked::Exit(float32, void*) STUB
bool32 zNPCGoalTubeBonked::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalTubeBonked::CheckForTran(trantype* trantype, int32* nextgoal) STUB_VOID

bool32 zNPCGoalTubeDead::Process(trantype* trantype, float32 dt, void* updCtxt, xScene*) STUB
void zNPCGoalTubeDead::ChkPrelimTran(trantype* trantype, int32* nextgoal) STUB_VOID

bool32 zNPCGoalTubeDying::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalTubeDying::Exit(float32, void*) STUB
bool32 zNPCGoalTubeDying::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalTubeDying::DeathByLasso(const xVec3*) STUB_VOID

bool32 zNPCGoalDeflate::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDeflate::Exit(float32, void*) STUB
bool32 zNPCGoalDeflate::Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

void ROBO_PrepRoboCop() STUB_VOID
static int32 RoboToCntrIdx(int32) STUB
static void CollectBountyOnRobot(int32) STUB_VOID