#pragma once

#include "xNPCBasic.h"
#include "xDynAsset.h"
#include "xListItem.h"
#include "zNPCSpawner.h"
#include "zNPCGoalCommon.h"
#include "zBase.h"

struct zMovePoint;
struct xSpline3;
struct xEntDrive;
struct xPsyche;
struct zShrapnelAsset;
struct NPCMsg;
struct xSFX;

typedef enum en_LASSO_EVENT
{
	LASS_EVNT_BEGIN,
	LASS_EVNT_ENDED,
	LASS_EVNT_GRABSTART,
	LASS_EVNT_GRABEND,
	LASS_EVNT_YANK,
	LASS_EVNT_ABORT,
	LASS_EVNT_NOMORE,
	LASS_EVNT_FORCEINT = FORCEENUMSIZEINT
 } LASSO_EVENT;

typedef enum en_LASSO_STATUS
{
	LASS_STAT_DONE,
	LASS_STAT_PENDING,
	LASS_STAT_GRABBING,
	LASS_STAT_TOSSING,
	LASS_STAT_NOMORE,
	LASS_STAT_FORCEINT = FORCEENUMSIZEINT
} LASSO_STATUS;

typedef enum en_lassanim
{
	LASS_ANIM_UNKNOWN,
	LASS_ANIM_GRAB,
	LASS_ANIM_HOLD,
	LASS_ANIM_NOMORE,
	LASS_ANIM_FORCEINT = FORCEENUMSIZEINT
} lassanim;

struct xEntNPCAsset
{
	int32 npcFlags;
	int32 npcModel;
	int32 npcProps;
	uint32 movepoint;
	uint32 taskWidgetPrime;
	uint32 taskWidgetSecond;
};

struct zNPCSettings : xDynAsset
{
	npcbtyp basisType;
	int8 allowDetect;
	int8 allowPatrol;
	int8 allowWander;
	int8 reduceCollide;
	int8 useNavSplines;
	int8 pad[3];
	int8 allowChase;
	int8 allowAttack;
	int8 assumeLOS;
	int8 assumeFOV;
	dupowavmod duploWaveMode;
	float32 duploSpawnDelay;
	int32 duploSpawnLifeMax;
};

typedef enum en_NPC_SOUND
{
	NPC_STYP_BOGUS = -2,
	NPC_STYP_LISTEND = 0,
	NPC_STYP_ENCOUNTER,
	NPC_STYP_CLANKING,
	NPC_STYP_EXCLAIM,
	NPC_STYP_OUCH,
	NPC_STYP_CHEERING,
	NPC_STYP_RESPAWN,
	NPC_STYP_ALERT,
	NPC_STYP_DIZZY,
	NPC_STYP_DANCE,
	NPC_STYP_LAUGH,
	NPC_STYP_ATTACK,
	NPC_STYP_PUNCH,
	NPC_STYP_WEPLAUNCH,
	NPC_STYP_LIGHTNING,
	NPC_STYP_WARNBANG,
	NPC_STYP_DEATH,
	NPC_STYP_DEATHJELLY,
	NPC_STYP_BONKED,
	NPC_STYP_UNBONKED,
	NPC_STYP_TIKISTACK,
	NPC_STYP_TIKIEXPLODE,
	NPC_STYP_TIKITHUNDER,
	NPC_STYP_XSFXTALK,
	NPC_STYP_ONELINER,
	NPC_STYP_ONELINERTOO,
	NPC_STYP_NOMORE,
	NPC_STYP_FORCE = FORCEENUMSIZEINT
} NPC_SOUND;

typedef enum en_NPC_DAMAGE_TYPE
{
	DMGTYP_UNDECIDED,
	DMGTYP_ABOVE,
	DMGTYP_BELOW,
	DMGTYP_SIDE,
	DMGTYP_INSTAKILL,
	DMGTYP_KILLEVENT,
	DMGTYP_HITBYTOSS,
	DMGTYP_NPCATTACK,
	DMGTYP_ROPE,
	DMGTYP_CRUISEBUBBLE,
	DMGTYP_PROJECTILE,
	DMGTYP_BOULDER,
	DMGTYP_BUBBOWL,
	DMGTYP_THUNDER_TIKI_EXPLOSION,
	DMGTYP_DAMAGE_SURFACE,
	DMGTYP_BUNGEED,
	DMGTYP_SURFACE,
	DMGTYP_NOMORE,
	DMGTYP_FORCEINT = FORCEENUMSIZEINT
} NPC_DAMAGE_TYPE;

typedef enum en_NPC_CARRY_STATE
{
	zNPCCARRY_NONE,
	zNPCCARRY_PICKUP,
	zNPCCARRY_THROW,
	zNPCCARRY_ATTEMPTPICKUP,
	zNPCCARRY_FORCEINT = FORCEENUMSIZEINT
} NPC_CARRY_STATE;

typedef enum en_mdlvert
{
	NPC_MDLVERT_ATTACKBASE,
	NPC_MDLVERT_ATTACK,
	NPC_MDLVERT_ATTACK1,
	NPC_MDLVERT_ATTACK2,
	NPC_MDLVERT_ATTACK3,
	NPC_MDLVERT_ATTACK4,
	NPC_MDLVERT_LOSEYEBALL,
	NPC_MDLVERT_DMGSMOKE_A,
	NPC_MDLVERT_DMGSMOKE_B,
	NPC_MDLVERT_DMGSMOKE_C,
	NPC_MDLVERT_DMGFLAME_A,
	NPC_MDLVERT_DMGFLAME_B,
	NPC_MDLVERT_DMGFLAME_C,
	NPC_MDLVERT_PROPEL,
	NPC_MDLVERT_EXHAUST,
	NPC_MDLVERT_GEN01,
	NPC_MDLVERT_GEN02,
	NPC_MDLVERT_GEN03,
	NPC_MDLVERT_GEN04,
	NPC_MDLVERT_GEN05,
	NPC_MDLVERT_NOMORE,
	NPC_MDLVERT_FORCEINT = FORCEENUMSIZEINT
} mdlvert;

typedef enum en_npcvibe
{
	NPC_VIBE_SOFT,
	NPC_VIBE_NORM,
	NPC_VIBE_HARD,
	NPC_VIBE_BUILD_A,
	NPC_VIBE_BUILD_B,
	NPC_VIBE_BUILD_C,
	NPC_VIBE_NOMORE,
	NPC_VIBE_FORCE = FORCEENUMSIZEINT
} npcvibe;

struct NPCSndTrax
{
	NPC_SOUND typ_sound;
	char* nam_sound;
	uint32 aid_sound;
};

struct NPCSndQueue
{
	uint32 sndDirect;
	NPC_SOUND sndtype;
	int32 flg_snd;
	float32 tmr_delay;
	float32 radius;
};

struct NPCConfig : xListItem<NPCConfig>
{
	uint32 modelID;
	int32 flg_config;
	float32 spd_turnMax;
	float32 spd_moveMax;
	float32 fac_accelMax;
	float32 fac_driftMax;
	float32 fac_gravKnock;
	float32 fac_elastic;
	int32 pts_damage;
	int32 useBoxBound;
	xVec3 off_bound;
	xVec3 dim_bound;
	float32 npcMass;
	float32 npcMassInv;
	float32 rad_detect;
	float32 hyt_detect;
	float32 off_detect;
	float32 rad_attack;
	float32 fov_attack;
	xVec3 scl_model;
	float32 tym_attack;
	float32 tym_fidget;
	float32 tym_stun;
	float32 tym_alert;
	float32 dst_castShadow;
	float32 rad_shadowCache;
	float32 rad_shadowRaster;
	float32 rad_dmgSize;
	int32 flg_vert;
	xModelTag tag_vert[20];
	xVec3 animFrameRange[9];
	int32 cnt_esteem[5];
	float32 rad_sound;
	NPCSndTrax* snd_trax;
	NPCSndTrax* snd_traxShare;
	int32 test_count;
	uint8 talk_filter[4];
	uint8 talk_filter_size;
};

struct NPCSndProp
{
	NPC_SOUND sndtype;
	int32 flg_snd;
	float32 tym_delayNext;
};

struct zNPCLassoInfo
{
	LASSO_STATUS stage;
	xEnt* lassoee;
	xAnimState* holdGuideAnim;
	xModelInstance* holdGuideModel;
	xAnimState* grabGuideAnim;
	xModelInstance* grabGuideModel;
};

struct zAnimFxSound
{
	uint32 ID;
	float32 vol;
	float32 pitch;
	uint32 priority;
	uint32 flags;
	float32 radius;
};

class zNPCCommon : public xNPCBasic
{
private:
	xEntAsset* entass;
	xEntNPCAsset* npcass;
	zNPCSettings* npcsetass;
	int32 flg_vuln;
	int32 flg_move;
	int32 flg_misc;
	int32 flg_able;
	NPCConfig* cfg_npc;
	zNPCSettings npcset;
	zMovePoint* nav_past;
	zMovePoint* nav_curr;
	zMovePoint* nav_dest;
	zMovePoint* nav_lead;
	xSpline3* spl_mvptspline;
	float32 len_mvptspline;
	float32 dst_curspline;
	xEntDrive* drv_data;
	xPsyche* psy_instinct;
	zNPCCommon* npc_duplodude;
	float32 spd_throttle;
	int32 flg_xtrarend;
	float32 tmr_fidget;
	float32 tmr_invuln;
	zShrapnelAsset* explosion;
	xModelAssetParam* parmdata;
	uint32 pdatsize;
	zNPCLassoInfo* lassdata;
	NPCSndQueue snd_queue[4];

public:
	zNPCCommon(int32 myType) WIP : xNPCBasic(myType) {}

	virtual void Init(xEntAsset* entass);
	virtual void Setup();
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void BUpdate(xVec3* pos);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual void Move(xScene* xscn, float32 dt, xEntFrame*);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void CollideReview();
	virtual void Destroy();
	virtual bool32 NPCMessage(NPCMsg* mail);
	virtual void RenderExtra() WIP {}
	virtual void RenderExtraPostParticles() WIP {}
	virtual void ParseINI();
	virtual void ParseLinks();
	virtual void ParseProps();
	virtual void SelfSetup() WIP {}
	virtual void SelfDestroy();
	virtual bool32 IsHealthy() WIP { return TRUE; }
	virtual bool32 IsAlive() WIP { return TRUE; }
	virtual void Damage(NPC_DAMAGE_TYPE damtype, xBase* who, const xVec3* vec_hit);
	virtual bool32 Respawn(const xVec3* pos, zMovePoint* mvptFirst, zMovePoint* mvptSpawnRef);
	virtual void DuploOwner(zNPCCommon* duper) WIP { npc_duplodude = duper; }
	virtual void DuploNotice(SM_NOTICES, void*) WIP {}
	virtual bool32 CanRope() STUB;
	virtual void LassoNotify(LASSO_EVENT event);
	virtual bool32 SetCarryState(NPC_CARRY_STATE) WIP { return FALSE; }
	virtual void Stun(float32) WIP {}
	virtual void SpeakBegin() WIP {}
	virtual void SpeakEnd() WIP {}
	virtual void SpeakStart(uint32, uint32, int32) WIP {}
	virtual void SpeakStop() WIP {}
	virtual uint32 AnimPick(int32, NPC_GOAL_SPOT, xGoal*) WIP { return 0; }
	virtual void GetParm(npcparm pid, void* val);
	virtual bool32 GetParmDefault(npcparm pid, void* val);
	virtual float32 GenShadCacheRad() WIP { return 2.4f; }
	virtual xEntDrive* PRIV_GetDriverData() WIP { return NULL; }
	virtual zNPCLassoInfo* PRIV_GetLassoData() { return NULL; }
	virtual bool32 LassoSetup();

	float32 XZDstSqToPlayer(xVec3*, float32*) STUB;
	float32 XZDstSqToPos(const xVec3*, xVec3*, float32*) STUB;
	void XZVecToPos(xVec3*, const xVec3*, float32*) STUB_VOID;
	xVec3* Pos() STUB;
	float32 XYZDstSqToPos(xVec3*, xVec3*) STUB;
	void XYZVecToPos(xVec3*, xVec3*) STUB_VOID;
	void XZVecToPlayer(xVec3*, float32*) STUB_VOID;
	xMat4x3* BoneMat(int32) const STUB;
	xVec3* BonePos(int32) const STUB;
	float32 XYZDstSqToPlayer(xVec3*) STUB;
	xVec3* Center() STUB;
	void ModelScaleSet(float32 scale) WIP { ModelScaleSet(scale, scale, scale); }
	void InitBounds();
	float32 BoundAsRadius(bool32 useCfg) const;
	void ConvertHitEvent(xBase* from, xBase*, uint32, const float32* toParam, xBase*, bool32*);
	void VelStop();
	float32 ThrottleAdjust(float32 dt, float32 spd_want, float32 accel);
	float32 ThrottleAccel(float32 dt, bool32 speedup, float32 pct_max);
	float32 ThrottleApply(float32 dt, const xVec3* dir, bool32 force3D);
	float32 TurnToFace(float32 dt, const xVec3* dir_want, float32 useTurnRate);
	bool32 IsMountableType(ZBASETYPE);
	void TagVerts();
	bool32 GetVertPos(mdlvert vid, xVec3* pos);
	int32 IsAttackFrame(float32 tym_anim, int32 series);
	void GiveReward();
	void PlayerKiltMe();
	void ISeePlayer();
	void ConfigSceneDone();
	NPCConfig* ConfigCreate(uint32);
	NPCConfig* ConfigFind(uint32);
	void GetParm(npcparm pid, int32* val);
	void GetParm(npcparm, float32*);
	void GetParm(npcparm, xVec3*);
	void GetParm(en_npcparm pid, zMovePoint** val);
	bool32 CanDoSplines();
	zMovePoint* FirstAssigned();
	void MvptReset(zMovePoint* nav_goto);
	bool32 MvptCycle();
	bool32 HaveLOSToPos(xVec3* pos, float32 dist, xScene* xscn, xBase* tgt, xCollis* colCallers);
	xModelInstance* ModelAtomicHide(int32 index, xModelInstance* mdl);
	xModelInstance* ModelAtomicShow(int32 index, xModelInstance* mdl);
	xModelInstance* ModelAtomicFind(int32 index, int32 idx_prev, xModelInstance* mdl_prev);
	void ModelScaleSet(float32 x, float32 y, float32 z);
	bool32 AnimStart(uint32 animID, bool32 forceRestart);
	void AnimSetState(uint32 animID, float32 time);
	xAnimState* AnimFindState(uint32 animID);
	xAnimSingle* AnimCurSingle();
	xAnimState* AnimCurState();
	uint32 AnimCurStateID();
	float32 AnimDuration(xAnimState* ast);
	float32 AnimTimeRemain(xAnimState* ast);
	float32 AnimTimeCurrent();
	void Vibrate(float32 ds2_cur, float32 ds2_max);
	void Vibrate(npcvibe vibe, float32 duration);
	xVec3* MatPosSet(xVec3* pos);
	void WonderOfTalking(bool32 inprogress, xBase* owner);
	int32 SomethingWonderful();
	int32 SndPlayFromAFX(zAnimFxSound* afxsnd, uint32* sid_played);
	int32 SndPlayFromSFX(xSFX* sfx, uint32* sid_played);
	int32 SndPlayRandom(NPC_SOUND sndtype);
	uint32 SndStart(uint32 aid_toplay, NPCSndProp* sprop, float32 radius);
	bool32 SndIsAnyPlaying();
	bool32 SndChanIsBusy(int32 flg_chan);
	void SndKillSounds(int32 flg_chan, bool32 all);
	int32 SndQueUpdate(float32 dt);
	bool32 LassoInit();
	bool32 LassoUseGuides(int32 idx_grabmdl, int32 idx_holdmdl);
	bool32 LassoGetAnims(xModelInstance* modgrab, xModelInstance* modhold);
	void LassoSyncAnims(lassanim lassanim);
	zNPCLassoInfo* GimmeLassInfo();
	void AddBaseline(xPsyche* psy, xGoalProcessCallback eval_idle, xGoalProcessCallback eval_patrol, xGoalProcessCallback eval_wander, xGoalProcessCallback eval_waiting, xGoalProcessCallback eval_fidget);
	void AddScripting(xPsyche* psy, xGoalProcessCallback eval_script, xGoalProcessCallback eval_playanim, xGoalProcessCallback eval_attack, xGoalProcessCallback eval_move, xGoalProcessCallback eval_follow, xGoalProcessCallback eval_lead, xGoalProcessCallback eval_wait);
	void AddDEVGoals(xPsyche*);
	const char* DBG_Name() WIP { return NULL; }
	void DBG_AddTweakers() WIP {}
	void DBG_RptDataSize() WIP {}
	const char* DBG_InstName() WIP { return DBG_Name(); }
	void ModelScaleSet(const xVec3* scale) WIP { ModelScaleSet(scale->x, scale->y, scale->z); }
	xAnimTable* AnimGetTable() STUB;
};