#pragma once

#include "zEnt.h"
#include "zNPCTypeCommon.h"

enum zControlOwner
{
	CONTROL_OWNER_GLOBAL = 0x1,
	CONTROL_OWNER_EVENT = 0x2,
	CONTROL_OWNER_OOB = 0x4,
	CONTROL_OWNER_BOSS = 0x8,
	CONTROL_OWNER_TALK_BOX = 0x10,
	CONTROL_OWNER_TAXI = 0x20,
	CONTROL_OWNER_BUS_STOP = 0x40,
	CONTROL_OWNER_TELEPORT_BOX = 0x80,
	CONTROL_OWNER_CRUISE_BUBBLE = 0x100,
	CONTROL_OWNER_FLY_CAM = 0x200,
	CONTROL_OWNER_FROZEN = 0x400,
	CONTROL_OWNER_TURRET = 0x800,
	CONTROL_OWNER_REWARDANIM = 0x1000,
	CONTROL_OWNER_BUNGEE = 0x2000,
	CONTROL_OWNER_SPRINGBOARD = 0x4000,
	CONTROL_OWNER_CUTSCENE = 0x8000
};

typedef enum _zPlayerType
{
	ePlayer_SB,
	ePlayer_Patrick,
	ePlayer_Sandy,
	ePlayer_MAXTYPES
} zPlayerType;

typedef enum _tagePlayerSnd
{
	ePlayerSnd_Invalid,
	ePlayerSnd_Land,
	ePlayerSnd_Jump,
	ePlayerSnd_DoubleJump,
	ePlayerSnd_BowlWindup,
	ePlayerSnd_BowlRelease,
	ePlayerSnd_BubbleBashStart,
	ePlayerSnd_BubbleBashHit1,
	ePlayerSnd_BubbleBashHitStart = ePlayerSnd_BubbleBashHit1,
	ePlayerSnd_BubbleBashHit2,
	ePlayerSnd_BubbleBashHitEnd = ePlayerSnd_BubbleBashHit2,
	ePlayerSnd_BubbleWand,
	ePlayerSnd_CruiseStart,
	ePlayerSnd_CruiseNavigate,
	ePlayerSnd_CruiseHit,
	ePlayerSnd_BounceStrike,
	ePlayerSnd_BoulderStart,
	ePlayerSnd_BoulderRoll,
	ePlayerSnd_BoulderEnd,
	ePlayerSnd_BellyMelee,
	ePlayerSnd_BellySmash,
	ePlayerSnd_Lift1,
	ePlayerSnd_Throw,
	ePlayerSnd_Chop,
	ePlayerSnd_Kick,
	ePlayerSnd_Heli,
	ePlayerSnd_LassoThrow,
	ePlayerSnd_LassoYank,
	ePlayerSnd_LassoStretch,
	ePlayerSnd_Ouch1,
	ePlayerSnd_OuchStart = ePlayerSnd_Ouch1,
	ePlayerSnd_Ouch2,
	ePlayerSnd_Ouch3,
	ePlayerSnd_Ouch4,
	ePlayerSnd_OuchEnd = ePlayerSnd_Ouch4,
	ePlayerSnd_Death,
	ePlayerSnd_FruitCrackle,
	ePlayerSnd_CheckPoint,
	ePlayerSnd_PickupSpatula,
	ePlayerSnd_PickupUnderwear,
	ePlayerSnd_Bus,
	ePlayerSnd_Taxi,
	ePlayerSnd_SlideLoop,
	ePlayerSnd_BeginBungee,
	ePlayerSnd_BungeeWind = ePlayerSnd_BeginBungee,
	ePlayerSnd_BungeeAttach,
	ePlayerSnd_BungeeRelease,
	ePlayerSnd_EndBungee = ePlayerSnd_BungeeRelease,
	ePlayerSnd_PickupSpatulaComment,
	ePlayerSnd_BungeeDive1,
	ePlayerSnd_BungeeDive2,
	ePlayerSnd_Sneak,
	ePlayerSnd_SlipLoop,
	ePlayerSnd_Total
} ePlayerSnd;

typedef enum _tagePlayerStreamSnd
{
	ePlayerStreamSnd_Invalid,
	ePlayerStreamSnd_PickupSock1,
	ePlayerStreamSnd_PickupSock2,
	ePlayerStreamSnd_PickupSock3,
	ePlayerStreamSnd_UnderwearComment1,
	ePlayerStreamSnd_UnderwearComment2,
	ePlayerStreamSnd_UnderwearComment3,
	ePlayerStreamSnd_EnterScene1,
	ePlayerStreamSnd_EnterScene2,
	ePlayerStreamSnd_EnterScene3,
	ePlayerStreamSnd_EnterScene4,
	ePlayerStreamSnd_EnterScene5,
	ePlayerStreamSnd_EnterScene6,
	ePlayerStreamSnd_EnterScene7,
	ePlayerStreamSnd_SpatulaComment1,
	ePlayerStreamSnd_ShinyComment1,
	ePlayerStreamSnd_ShinyComment2,
	ePlayerStreamSnd_ShinyComment3,
	ePlayerStreamSnd_ShinyComment4,
	ePlayerStreamSnd_ShinyComment5,
	ePlayerStreamSnd_SpongeBallComment1,
	ePlayerStreamSnd_SpongeBallComment2,
	ePlayerStreamSnd_SpongeBallComment3,
	ePlayerStreamSnd_CruiseComment1,
	ePlayerStreamSnd_CruiseComment2,
	ePlayerStreamSnd_CruiseComment3,
	ePlayerStreamSnd_BowlComment1,
	ePlayerStreamSnd_BowlComment2,
	ePlayerStreamSnd_BowlComment3,
	ePlayerStreamSnd_BowlComment4,
	ePlayerStreamSnd_BowlComment5,
	ePlayerStreamSnd_PushButton1,
	ePlayerStreamSnd_PushButton2,
	ePlayerStreamSnd_PushButton3,
	ePlayerStreamSnd_BellySmashComment1,
	ePlayerStreamSnd_BellySmashComment2,
	ePlayerStreamSnd_BellySmashComment3,
	ePlayerStreamSnd_ChopComment1,
	ePlayerStreamSnd_ChopComment2,
	ePlayerStreamSnd_ChopComment3,
	ePlayerStreamSnd_KickComment1,
	ePlayerStreamSnd_KickComment2,
	ePlayerStreamSnd_KickComment3,
	ePlayerStreamSnd_RopingComment1,
	ePlayerStreamSnd_RopingComment2,
	ePlayerStreamSnd_RopingComment3,
	ePlayerStreamSnd_HeliComment1,
	ePlayerStreamSnd_HeliComment2,
	ePlayerStreamSnd_HeliComment3,
	ePlayerStreamSnd_DestroyTiki1,
	ePlayerStreamSnd_DestroyTiki2,
	ePlayerStreamSnd_DestroyTiki3,
	ePlayerStreamSnd_DestroyRobot1,
	ePlayerStreamSnd_DestroyRobot2,
	ePlayerStreamSnd_DestroyRobot3,
	ePlayerStreamSnd_SeeWoodTiki,
	ePlayerStreamSnd_SeeLoveyTiki,
	ePlayerStreamSnd_SeeShhhTiki,
	ePlayerStreamSnd_SeeThunderTiki,
	ePlayerStreamSnd_SeeStoneTiki,
	ePlayerStreamSnd_SeeFodder,
	ePlayerStreamSnd_SeeHammer,
	ePlayerStreamSnd_SeeTarTar,
	ePlayerStreamSnd_SeeGLove,
	ePlayerStreamSnd_SeeMonsoon,
	ePlayerStreamSnd_SeeSleepyTime,
	ePlayerStreamSnd_SeeArf,
	ePlayerStreamSnd_SeeTubelets,
	ePlayerStreamSnd_SeeSlick,
	ePlayerStreamSnd_SeeKingJellyfish,
	ePlayerStreamSnd_SeePrawn,
	ePlayerStreamSnd_SeeDutchman,
	ePlayerStreamSnd_SeeSandyBoss,
	ePlayerStreamSnd_SeePatrickBoss1,
	ePlayerStreamSnd_SeePatrickBoss2,
	ePlayerStreamSnd_SeeSpongeBobBoss,
	ePlayerStreamSnd_SeeRobotPlankton,
	ePlayerStreamSnd_PickupSpecialGeneric1,
	ePlayerStreamSnd_PickupSpecialGeneric2,
	ePlayerStreamSnd_GoldenUnderwear4,
	ePlayerStreamSnd_GoldenUnderwear5,
	ePlayerStreamSnd_GoldenUnderwear6,
	ePlayerStreamSnd_Combo1,
	ePlayerStreamSnd_Combo2,
	ePlayerStreamSnd_Combo3,
	ePlayerStreamSnd_Combo4,
	ePlayerStreamSnd_Combo5,
	ePlayerStreamSnd_BigCombo1,
	ePlayerStreamSnd_BigCombo2,
	ePlayerStreamSnd_BigCombo3,
	ePlayerStreamSnd_BigCombo4,
	ePlayerStreamSnd_BigCombo5,
	ePlayerStreamSnd_Lift1,
	ePlayerStreamSnd_Exclaim1,
	ePlayerStreamSnd_Exclaim2,
	ePlayerStreamSnd_Exclaim3,
	ePlayerStreamSnd_Exclaim4,
	ePlayerStreamSnd_BeginBungee,
	ePlayerStreamSnd_BungeeAttachComment = ePlayerStreamSnd_BeginBungee,
	ePlayerStreamSnd_BungeeBeginDive,
	ePlayerStreamSnd_BungeeDive1 = ePlayerStreamSnd_BungeeBeginDive,
	ePlayerStreamSnd_BungeeDive2,
	ePlayerStreamSnd_BungeeEndDive = ePlayerStreamSnd_BungeeDive2,
	ePlayerStreamSnd_BungeeBeginDeath,
	ePlayerStreamSnd_BungeeDeath1 = ePlayerStreamSnd_BungeeBeginDeath,
	ePlayerStreamSnd_BungeeDeath2,
	ePlayerStreamSnd_BungeeDeath3,
	ePlayerStreamSnd_BungeeDeath4,
	ePlayerStreamSnd_BungeeDeath5,
	ePlayerStreamSnd_BungeeDeath6,
	ePlayerStreamSnd_BungeeDeath7,
	ePlayerStreamSnd_BungeeDeath8,
	ePlayerStreamSnd_BungeeDeath9,
	ePlayerStreamSnd_BungeeDeath10,
	ePlayerStreamSnd_BungeeDeath11,
	ePlayerStreamSnd_BungeeDeath12,
	ePlayerStreamSnd_BungeeDeath13,
	ePlayerStreamSnd_BungeeDeath14,
	ePlayerStreamSnd_BungeeDeath15,
	ePlayerStreamSnd_BungeeDeath16,
	ePlayerStreamSnd_BungeeDeath17,
	ePlayerStreamSnd_BungeeDeath18,
	ePlayerStreamSnd_BungeeEndDeath = ePlayerStreamSnd_BungeeDeath18,
	ePlayerStreamSnd_EndBungee = ePlayerStreamSnd_BungeeEndDeath,
	ePlayerStreamSnd_Total
} ePlayerStreamSnd;

struct zJumpParam
{
	float32 PeakHeight;
	float32 TimeGravChange;
	float32 TimeHold;
	float32 ImpulseVel;
};

struct zLedgeGrabParams
{
	float32 animGrab;
	float32 zdist;
	xVec3 tranTable[60];
	int32 tranCount;
	xEnt* optr;
	xMat4x3 omat;
	float32 y0det;
	float32 dydet;
	float32 r0det;
	float32 drdet;
	float32 thdet;
	float32 rtime;
	float32 ttime;
	float32 tmr;
	xVec3 spos;
	xVec3 epos;
	xVec3 tpos;
	int32 nrays;
	int32 rrand;
	float32 startrot;
	float32 endrot;
};

struct zPlayerSettings
{
	zPlayerType pcType;
	float32 MoveSpeed[6];
	float32 AnimSneak[3];
	float32 AnimWalk[3];
	float32 AnimRun[3];
	float32 JumpGravity;
	float32 GravSmooth;
	float32 FloatSpeed;
	float32 ButtsmashSpeed;
	zJumpParam Jump;
	zJumpParam Bounce;
	zJumpParam Spring;
	zJumpParam Wall;
	zJumpParam Double;
	zJumpParam SlideDouble;
	zJumpParam SlideJump;
	float32 WallJumpVelocity;
	zLedgeGrabParams ledge;
	float32 spin_damp_xz;
	float32 spin_damp_y;
	uint8 talk_anims;
	uint8 talk_filter_size;
	uint8 talk_filter[4];
};

void zEntPlayerControlOn(zControlOwner owner);
void zEntPlayerControlOff(zControlOwner owner);
void TellPlayerVillainIsNear(float32 visnear);
void SetPlayerKillsVillainTimer(float32 time);
bool32 zEntPlayer_InBossBattle();
void zEntPlayerSpeakStart(uint32 sndid, int32 anim);
void zEntPlayerSpeakStop();
void zEntPlayer_LassoNotify(en_LASSO_EVENT event);
bool32 zEntPlayer_IsSneaking();
void zEntPlayer_Init(xEnt* ent, xEntAsset* asset);
void zEntPlayer_RestoreSounds();
void zEntPlayer_Load(xEnt*, xSerial*);
void zEntPlayer_PredictPos(xVec3* pos, float32 timeIntoFuture, float32 leadFactor, int32 useTurn);
void zEntPlayer_Update(xEnt* ent, xScene* sc, float32 dt);
void zEntPlayer_CheckCritterContact(xEnt* player, float32 dt);
void zEntPlayer_PatrickLaunch(xEnt* patLauncher);
void zEntPlayer_ShadowModelEnable();
void zEntPlayer_ShadowModelDisable();
void zEntPlayerUpdateModel();
void zEntPlayer_Render(zEnt* ent);
void zEntPlayer_setBoulderMode(uint32 mode);
bool32 zEntPlayer_Damage(xBase* src, uint32 damage, const xVec3* knockback);
bool32 zEntPlayer_DamageNPCKnockBack(xBase* src, uint32 damage, xVec3* npcPos);
void zEntPlayer_DamageKnockIntoAir(float32 height);
bool32 zEntPlayer_Damage(xBase* src, uint32 damage);
uint32 zEntPlayer_MoveInfo();
void zEntPlayer_GiveHealth(int32 quantity);
void zEntPlayer_GiveSpatula(int32);
void zEntPlayer_GiveShinyObject(int32);
void zEntPlayer_GivePatsSocksCurrentLevel(int32 quantity);
void zEntPlayer_GiveLevelPickupCurrentLevel(int32);
void CalcJumpImpulse(zJumpParam* param, const zPlayerSettings* settings);
void zEntPlayerJumpStart(xEnt* ent, zJumpParam* jump);
void zEntPlayerExit(xEnt*);
bool32 zEntPlayer_ObjIDIsTrack(uint32);
void zEntPlayerPreReset();
void zEntPlayerReset(xEnt* ent);
void zEntPlayerCollide(xEnt* ent, xScene* sc, float32 dt);
void zEntPlayerCollTrigger(xEnt* ent, xScene* sc);
bool32 zEntPlayerEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
void zEntPlayer_StoreCheckPoint(xVec3* pos, float32 rot, uint32 initCamID);
void zEntPlayer_LoadCheckPoint();
void zEntPlayer_SNDPlay(ePlayerSnd player_snd, float32 delay);
void zEntPlayer_SNDPlayStream(ePlayerStreamSnd player_snd);
void zEntPlayer_SNDPlayStream(ePlayerStreamSnd, uint32);
void zEntPlayer_SNDPlayDelayed(float32 seconds);
void zEntPlayer_SNDPlayStream(uint32 lower, uint32 upper, ePlayerStreamSnd player_snd, uint32 flags);
void zEntPlayer_SNDPlayStreamRandom(uint32 lower, uint32 upper, ePlayerStreamSnd player_snd_start, ePlayerStreamSnd player_snd_end, float32 delay);
void zEntPlayer_SNDPlayStreamRandom(ePlayerStreamSnd player_snd_start, ePlayerStreamSnd player_snd_end, float32 delay);
void zEntPlayer_SNDPlayRandom(ePlayerSnd player_snd_start, ePlayerSnd player_snd_end, float32 delay);
void zEntPlayer_SNDSetVol(ePlayerSnd player_snd, float32 new_vol);
void zEntPlayer_SNDSetPitch(ePlayerSnd player_snd, float32 new_pitch);
void zEntPlayer_SNDStop(ePlayerSnd player_snd);
void zEntPlayer_SNDStopStream();
void zEntPlayer_SNDNotifyPlaying(uint32 id);
void zEntPlayer_LoadSounds();
void zEntPlayer_UnloadSounds();
bool zEntPlayer_MinimalUpdate(xEnt* ent, xScene* sc, float32 dt, xVec3& drive_motion);
void zEntPlayer_MinimalRender(zEnt* ent);
bool zEntPlayerDyingInGoo();