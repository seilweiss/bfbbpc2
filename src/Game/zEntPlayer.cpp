#include "zEntPlayer.h"

#include "xPad.h"

static void zEntPlayer_SpawnWandBubbles(xVec3* center, uint32 count) STUB_VOID
static void zEntPlayerKillCarry() STUB_VOID
void zEntPlayerControlOn(zControlOwner owner) STUB_VOID
void zEntPlayerControlOff(zControlOwner owner) STUB_VOID
void TellPlayerVillainIsNear(float32 visnear) STUB_VOID
void SetPlayerKillsVillainTimer(float32 time) STUB_VOID
static void DampenControls(float32* angle, float32* mag, float32 x, float32 y) STUB_VOID
static void CalcAnimSpeed(xEnt*, float32, float32*) STUB_VOID
static void LeanUpdate(float32, float32) STUB_VOID
static void TurnToFace(xEnt* ent, const xVec3* target, float32 speedLimit, float32 dt) STUB_VOID
static void PlayerArrive(xEnt*, xBase*) STUB_VOID
static void PlayerAbsControl(xEnt* ent, float32 x, float32 z, float32 dt) STUB_VOID
static void InvReset() STUB_VOID
static void HealthReset() STUB_VOID
static uint32 RunAnyCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunStoicCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunScaredCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunVictoryCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunSlipCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 RunOutOfWorldCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WalkCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WalkStoicCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WalkVictoryCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WalkScaredCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleStoicCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleVictoryCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleScaredCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleSlipCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 AnyMoveCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 AnyStopCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 SlipRunCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 NoSlipCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 IdleCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 InactiveCheck(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 InactiveCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 InactiveFinishedCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandTrackCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandNoTrackCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandHighCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandRunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandWalkCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandFastCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandNoTrackWalkCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandSlipIdleCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandSlipRunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandNoTrackFastCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandNoTrackSlipRunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandNoTrackSlipIdleCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LandSlipRunCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 SandyLandCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BubbleSpinCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BubbleSpinCB(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BubbleBashCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BubbleBashCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBashStrikeCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBashStrikeCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBashToJumpCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BubbleBounceCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BubbleBounceCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBounceAttackCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBounceStrikeCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBounceStrikeCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBounceToJumpCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BBounceToJumpCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BbowlCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BbowlCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BbowlWindupEndCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlTossEndCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BbowlRecoverWalkCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlRecoverRunCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlRecoverRunScaredCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlRecoverRunVictoryCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlRecoverRunOutOfWorldCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BbowlRecoverRunSlipCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 GooCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 GooDeathCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit01Check(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit01CB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit02Check(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit02CB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit03Check(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit03CB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit04Check(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit04CB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit05Check(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Hit05CB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 Defeated01Check(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 Defeated02Check(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 Defeated03Check(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 Defeated04Check(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 Defeated05Check(xAnimTransition* tran, xAnimSingle*, void*) STUB
static uint32 DefeatedCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 SpatulaGrabCheck(xAnimTransition*, xAnimSingle*, void*) STUB
bool32 zEntPlayer_InBossBattle() STUB
static uint32 SpatulaGrabCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 SpatulaGrabStopCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LCopterCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LCopterCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 StopLCopterCB(xAnimTransition*, xAnimSingle*, void*) STUB
static void DoWallJumpCheck();
static uint32 WallJumpLaunchCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpLaunchCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpFlightLandCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpFlightLandCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpLandFlightCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 WallJumpLandFlightCallback(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 JumpCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 JumpCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 JumpApexCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BounceCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BounceCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BounceStopLCopterCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 DblJumpCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 DblJumpCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 TongueDblJumpCB(xAnimTransition* tran, xAnimSingle* anim, void* object) STUB
static uint32 TongueDblSpinCB(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 FallCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 BoulderRollMoveCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BoulderRollIdleCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BoulderRollCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BoulderRollWindupCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BoulderRollCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 BoulderRollDoneCheck() STUB
static uint32 BoulderRollDoneCB() STUB
static uint32 SlideTrackCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 SlideTrackCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 NoslideTrackCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 NoslideTrackCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 TrackFallCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 TrackFallCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 TrackPrefallJumpCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LedgeGrabCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LedgeGrabCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 LedgeFinishCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickGrabCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickGrabFailed(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickGrabKill(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickGrabThrow(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickAttackCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickStunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickMeleeCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 PatrickGrabCB(xAnimTransition*, xAnimSingle*, void*) STUB

namespace {

	uint32 TalkCheck(xAnimTransition* tran, xAnimSingle*, void*) STUB;
	uint32 TalkDoneCheck(xAnimTransition* tran, xAnimSingle*, void*) STUB;
	void speak_update(float32 dt) STUB_VOID;

}

void zEntPlayerSpeakStart(uint32 sndid, int32 anim) STUB_VOID
void zEntPlayerSpeakStop() STUB_VOID
static xEnt* GetPatrickTarget(xEnt* ent) STUB
static uint32 PatrickGrabThrowCB(xAnimTransition*, xAnimSingle*, void* object) STUB
void zEntPlayer_LassoNotify(en_LASSO_EVENT event) STUB_VOID
static uint32 MeleeCheck(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 LassoStartCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoLostTargetCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoStraightToDestroyCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoAboutToDestroyCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoDestroyCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoReyankCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailIdleSlipCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailIdleCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailWalkCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailRunCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailRunOutOfWorldCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoFailRunSlipCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 JumpMeleeCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 MeleeCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoStartCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 LassoThrowCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 LassoFlyCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 LassoDestroyCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoYankCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 MeleeStopCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 SpatulaMeleeStopCB(xAnimTransition* tran, xAnimSingle* anim, void* object) STUB
static uint32 LassoStopCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingGroundedBeginCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingBeginCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingReleaseCheck(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingBeginCB(xAnimTransition*, xAnimSingle*, void* object) STUB
static uint32 LassoSwingGroundedBeginCB(xAnimTransition* tran, xAnimSingle* anim, void* object) STUB
static uint32 LassoSwingTossCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingCB(xAnimTransition*, xAnimSingle* anim, void*) STUB
static uint32 LassoSwingGroundedCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 LassoSwingReleaseCB(xAnimTransition* tran, xAnimSingle* anim, void* object) STUB
static uint32 StunBubbleTrail(xAnimSingle* single) STUB
static uint32 BubbleBashContrails(xAnimSingle* single) STUB
static uint32 BubbleBounceContrails(xAnimSingle* single) STUB
static uint32 StunStartFallCB(xAnimTransition*, xAnimSingle*, void*) STUB
static uint32 StunRadiusCB(xAnimTransition*, xAnimSingle*, void*) STUB
static bool32 MeleeAttackBoundCollide(xEnt* ent, zScene* zsc, xBound* meleeB) STUB
static bool32 CheckObjectAgainstMeleeBound(xEnt* cbent, void* cbdata) STUB
bool32 zEntPlayer_IsSneaking() STUB
static int32 load_talk_filter(uint8* filter, xModelAssetParam* params, uint32 params_size, int32 max_size) STUB
static int32 count_talk_anims(xAnimTable*) STUB
static void load_player_ini(zPlayerSettings&, xModelInstance&, xModelAssetParam*, uint32) STUB_VOID
static void load_player_ini() STUB_VOID
void zEntPlayer_Init(xEnt* ent, xEntAsset* asset) STUB_VOID
void zEntPlayer_RestoreSounds() STUB_VOID
void zEntPlayer_Load(xEnt*, xSerial*) STUB_VOID
static void zEntPlayer_StreakFX(xEnt* ent, float32) STUB_VOID
static void zEntPlayer_SpringboardFX(xEnt* ent, float32 dt) STUB_VOID
static void getPadDefl(PadAnalog* stick, xVec2* v) STUB_VOID
static bool32 BoulderVEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
static void zEntPlayer_BoulderVehicleRender(zEnt*) STUB_VOID
static void zEntPlayer_BoulderVehicleMove(xEnt*, xScene*, float32, xEntFrame* frame) STUB_VOID
static void zEntPlayer_BoulderVehicleUpdate(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
static void zEntPlayer_PredictionUpdate(xEnt* ent, float32 dt) STUB_VOID
void zEntPlayer_PredictPos(xVec3* pos, float32 timeIntoFuture, float32 leadFactor, int32 useTurn) STUB_VOID
static bool32 zEntPlayerKnockToSafety(xEnt* ent) STUB
static xEnt* zEntPlayer_FindGrabEnt(xEnt* ent, zScene* zsc, int32* failed) STUB
void zEntPlayer_Update(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void zEntPlayer_CheckCritterContact(xEnt* player, float32 dt) STUB_VOID
void zEntPlayer_PatrickLaunch(xEnt* patLauncher) STUB_VOID
void zEntPlayer_ShadowModelEnable() STUB_VOID
void zEntPlayer_ShadowModelDisable() STUB_VOID
static void zEntPlayer_BubbleBowlLaneRender(zEnt* ent) STUB_VOID
inline void get_reticle_bound(xVec3&, float32) STUB_VOID
static void zEntPlayer_ReticleRender(zEnt*) STUB_VOID
static void zEntPlayerUpdateModelSB() STUB_VOID
void zEntPlayerUpdateModel() STUB_VOID
static void zEntPlayerEmitTongueBubbles() STUB_VOID
static void zEntPlayerEmitSlideBubbles() STUB_VOID
static void zEntPlayerCheckHelmetPop() STUB_VOID
static void zEntPlayerCheckShoePop() STUB_VOID
void zEntPlayer_Render(zEnt* ent) STUB_VOID
static void zEntPlayer_Move(xEnt* ent, xScene*, float32 dt, xEntFrame* frame) STUB_VOID
void zEntPlayer_setBoulderMode(uint32 mode) STUB_VOID
bool32 zEntPlayer_Damage(xBase* src, uint32 damage, const xVec3* knockback) STUB
bool32 zEntPlayer_DamageNPCKnockBack(xBase* src, uint32 damage, xVec3* npcPos) STUB
void zEntPlayer_DamageKnockIntoAir(float32 height) STUB_VOID
bool32 zEntPlayer_Damage(xBase* src, uint32 damage) STUB
uint32 zEntPlayer_MoveInfo() STUB
void zEntPlayer_GiveHealth(int32 quantity) STUB_VOID
void zEntPlayer_GiveSpatula(int32) STUB_VOID
void zEntPlayer_GiveShinyObject(int32) STUB_VOID
void zEntPlayer_GivePatsSocksCurrentLevel(int32 quantity) STUB_VOID
void zEntPlayer_GiveLevelPickupCurrentLevel(int32) STUB_VOID
static float32 CalcJumpImpulse_Smooth(float32 g, float32 j, float32 h, float32 Tgc, float32 Tgs) STUB
void CalcJumpImpulse(zJumpParam* param, const zPlayerSettings* settings) STUB_VOID
void zEntPlayerJumpStart(xEnt* ent, zJumpParam* jump) STUB_VOID
static void zEntPlayerJumpAddDriver(xEnt*) STUB_VOID
static void zEntPlayerJumpLand(xEnt* ent) STUB_VOID
static void zEntPlayerJumpUpdate(xEnt* ent, xScene*, float32 dt) STUB_VOID
static void zEntPlayerEGenUpdate(xEnt* p, xScene* sc, float32) STUB_VOID
static void zEntPlayerVelUpdate(xEnt* ent, xScene*, float32 dt) STUB_VOID
static RpCollisionTriangle* nearestTrackCB(RpIntersection*, RpCollisionTriangle* collTriangle, RwReal, void* data) STUB
static float32 det3x3top1(float32, float32, float32, float32, float32, float32) STUB
static void SlideTrackUpdate(xEnt* p) STUB_VOID
static void zEntPlayerTSlideUpdate(xEnt* p, xScene*, float32 dt) STUB_VOID
static void zEntPlayerFloorUpdate(xEnt* p, xScene*, float32 dt) STUB_VOID
static uint32 PlayerDepenQuery(xEnt*, xEnt*, xScene*, float32, xCollis* coll) STUB
static void PlayerBoundUpdate(xEnt* ent, xVec3* pos) STUB_VOID
static void zEntPlayerSurfDamageUpdate(xEnt* p, xScene*, float32) STUB_VOID
static void PlayerMountHackUpdate(float32) STUB_VOID
static void PlayerMountHackTakeAction(xEnt*, uint32) STUB_VOID
static void zEntPlayerDriveUpdate(xEnt* p, xScene*, float32 dt) STUB_VOID
void zEntPlayerExit(xEnt*) STUB_VOID
static void PlayerHitAnimInit(xModelInstance*, xAnimTransition*, uint32) STUB_VOID
bool32 zEntPlayer_ObjIDIsTrack(uint32) STUB
void zEntPlayerPreReset() STUB_VOID
void zEntPlayerReset(xEnt* ent) STUB_VOID
static void PlayerCollisBuildFromDepen(xCollis*) STUB_VOID
static xEnt* PlayerCollCheckOneEnt(xEnt* ent, xScene*, void* data) STUB
static uint32 CollidePyramidBoxTop(xCollis* coll, xBox* box, float32 height, xSphere* sph) STUB
static xEnt* PlayerCollCheckOneVillain(xEnt* ent, xScene*, void* data) STUB
static void PlayerCollisTranslate(xCollis* c, float32 x, float32 y, float32 z) STUB_VOID
static void PlayerCollsAllTranslate(xCollis*, float32, float32, float32) STUB_VOID
static void PlayerCollsWallsTranslate(xCollis*, float32, float32, float32) STUB_VOID
static void PlayerCollsWallsTranslate(xCollis*, const xVec3*) STUB_VOID
static void PlayerCollsSidesTranslate(xCollis*, float32, float32, float32) STUB_VOID
static void PlayerCollCheckEnv(xEnt*, xScene*) STUB_VOID
static float32 ComputeFudge(float32, float32) STUB
static void CalcCombinedDepen(float32& dx, float32& dz, float32 ax, float32 az, float32 bx, float32 bz, float32 fudge) STUB_VOID
static void PlayerCollsSelectDepen(xEnt* p, xScene*, float32) STUB_VOID
void zEntPlayerCollide(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
void zEntPlayerCollTrigger(xEnt* ent, xScene* sc) STUB_VOID
static xVec3& GetPosVec(xBase*) STUB_REF(xVec3)
bool32 zEntPlayerEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
static void PlayerSwingUpdate(xEnt* ent, float32 mag, float32 angle, float32 dt) STUB_VOID
static void PlayerTeeterCheck(xEnt*, xScene*, float32 dt) STUB_VOID
static void PlayerRotMatchUpdateEnt(xEnt* ent, xScene*, float32 dt, void* fdata) STUB_VOID
void zEntPlayer_StoreCheckPoint(xVec3* pos, float32 rot, uint32 initCamID) STUB_VOID
void zEntPlayer_LoadCheckPoint() STUB_VOID
static void SetupRumble(ePlayerSnd, RumbleType, float32) STUB_VOID
static void zEntPlayer_SNDInit() STUB_VOID
void zEntPlayer_SNDPlay(ePlayerSnd player_snd, float32 delay) STUB_VOID
void zEntPlayer_SNDPlayStream(ePlayerStreamSnd player_snd) STUB_VOID
void zEntPlayer_SNDPlayStream(ePlayerStreamSnd, uint32) STUB_VOID
void zEntPlayer_SNDPlayDelayed(float32 seconds) STUB_VOID
void zEntPlayer_SNDPlayStream(uint32 lower, uint32 upper, ePlayerStreamSnd player_snd, uint32 flags) STUB_VOID
void zEntPlayer_SNDPlayStreamRandom(uint32 lower, uint32 upper, ePlayerStreamSnd player_snd_start, ePlayerStreamSnd player_snd_end, float32 delay) STUB_VOID
void zEntPlayer_SNDPlayStreamRandom(ePlayerStreamSnd player_snd_start, ePlayerStreamSnd player_snd_end, float32 delay) STUB_VOID
void zEntPlayer_SNDPlayRandom(ePlayerSnd player_snd_start, ePlayerSnd player_snd_end, float32 delay) STUB_VOID
void zEntPlayer_SNDSetVol(ePlayerSnd player_snd, float32 new_vol) STUB_VOID
void zEntPlayer_SNDSetPitch(ePlayerSnd player_snd, float32 new_pitch) STUB_VOID
void zEntPlayer_SNDStop(ePlayerSnd player_snd) STUB_VOID
void zEntPlayer_SNDStopStream() STUB_VOID
void zEntPlayer_SNDNotifyPlaying(uint32 id) STUB_VOID
static void PlayerBeginCollideNoBupdate(xEnt* ent, xScene*, float32) STUB_VOID
static void PlayerCollsDetect(xEnt*, xScene*, float32) STUB_VOID
static void PlayerHackFixBbashMiss(xModelInstance* model) STUB_VOID
static void PlayerLedgeInit(zLedgeGrabParams* ledge, xModelInstance* model) STUB_VOID
static void PlayerLedgeUpdate(xEnt* ent, xScene* sc, float32 dt) STUB_VOID
static void zEntPlayer_UpdateVelocityBlur() STUB_VOID
static void dampen_velocity(xVec3&, const xVec3&, float32) STUB_VOID
static void player_sound_hop_load(uint32 hopid, int32 hip_or_hop) STUB_VOID
void zEntPlayer_LoadSounds() STUB_VOID
void zEntPlayer_UnloadSounds() STUB_VOID
static void dont_move(xEnt* ent, xScene*, float32 dt, xEntFrame*) STUB_VOID
bool zEntPlayer_MinimalUpdate(xEnt* ent, xScene* sc, float32 dt, xVec3& drive_motion) STUB
void zEntPlayer_MinimalRender(zEnt* ent) STUB_VOID
bool zEntPlayerDyingInGoo() STUB