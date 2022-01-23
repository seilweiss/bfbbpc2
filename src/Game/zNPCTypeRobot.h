#pragma once

#include "zNPCTypeCommon.h"
#include "zNPCGlyph.h"
#include "xEntDrive.h"
#include "zNPCSupport.h"
#include "zNPCHazard.h"
#include "xBehaveMgr.h"

class zNPCRobot;

class NPCArena
{
private:
	int32 flg_arena;
	xVec3 pos_arena;
	float32 rad_arena;
	zMovePoint* nav_arena;
	zMovePoint* nav_refer_dest;
	zMovePoint* nav_refer_curr;

public:
	xVec3* Pos() STUB;
	float32 Radius(float32) STUB;
	bool32 IncludesPlayer(float32, xVec3*) STUB;
	bool32 IncludesNPC(zNPCCommon*, float32, xVec3*) STUB;
	bool32 IsReady() STUB;
	void DBG_Draw(zNPCCommon*) {}
	bool32 IncludesPos(xVec3* pos, float32 rad_thresh, xVec3* vec);
	float32 PctFromHome(xVec3* pos);
	float32 DstSqFromHome(xVec3* pos, xVec3* delt);
	int32 NeedToCycle(zNPCCommon* npc);
	bool32 Cycle(zNPCCommon* npc, bool32 peek);
	zMovePoint* NextBestNav(zNPCCommon*, zMovePoint* nav_from);
	void SetHome(zNPCCommon* npc, zMovePoint* nav);
	void AdjustHome(zNPCCommon*, xVec3*, float32);
	void SyncHomeFromNav();
};

class NPCBattle
{
private:
	zNPCRobot* members[5];

public:
	void JoinBattle(zNPCRobot*) {}
	void LeaveBattle(zNPCRobot*) {}
};

class zNPCRobot : public zNPCCommon
{
private:
	int32 hitpoints;
	float32 tmr_safetime;
	NPCArena arena;
	NPCBattle* inf_battle;
	int32 idx_neckBone;
	float32 tmr_stunned;
	NPCGlyph* glyf_stun;
	int32 cnt_nextemit;
	xVec3 vel_bunnyhop;
	zNPCLassoInfo raw_lassoinfo;
	xEntDrive raw_drvdata;

public:
	zNPCRobot(int32 myType) WIP : zNPCCommon(myType), hitpoints(1) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void CollideReview();
	virtual uint8 ColChkFlags() const;
	virtual uint8 ColPenFlags() const;
	virtual uint8 ColChkByFlags() const WIP { return 0x3C; }
	virtual uint8 ColPenByFlags() const WIP { return 0x3C; }
	virtual uint8 PhysicsFlags() const;
	virtual bool32 NPCMessage(NPCMsg* mail);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual bool32 IsHealthy() STUB;
	virtual bool32 IsAlive() STUB;
	virtual void DuploOwner(zNPCCommon* duper);
	virtual void LassoNotify(en_LASSO_EVENT event);
	virtual bool32 SetCarryState(en_NPC_CARRY_STATE stat);
	virtual void Stun(float32 stuntime);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*);
	virtual float32 GenShadCacheRad();
	virtual xEntDrive* PRIV_GetDriverData() STUB;
	virtual zNPCLassoInfo* PRIV_GetLassoData() STUB;
	virtual bool32 LassoSetup();
	virtual bool32 RoboHandleMail(NPCMsg* mail);
	virtual int32 IsDying();
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;

	void DoAliveStuff(float32 dt);
	void CheckFalling(float32);
	void BunnyHopSet(xVec3*);
	void AddLassoing(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback);
	void AddMiscTypical(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback);
	void AddStunThrow(xPsyche* psy, xGoalProcessCallback eval_evilpat, xGoalProcessCallback eval_stunned, xGoalProcessCallback eval_patcarry, xGoalProcessCallback eval_patthrow);
	void AddDamage(xPsyche*, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback, xGoalProcessCallback);
	void AddSpawning(xPsyche*, xGoalProcessCallback, xGoalProcessCallback);
	int32 IsWounded();
	void SyncStunGlyph(float32 tmr_remain, float32 height);
	void InflictPain(int32 numHitPoints, bool32 giveCreditToPlayer);
	void TurnThemHeads();
	float32 FacePos(xVec3* pos, float32 dt, float32 spd_turn);
	void FacePlayer(float32, float32) STUB_VOID;
	float32 FaceAntiPlayer(float32 dt, float32 spd_turn);
	void CornerOfArena(xVec3* pos_corner, float32 dst);
	float32 MoveTowardsArena(float32 dt, float32 speed);
	void ShowerConfetti(xVec3* pos);
	void DoFX_Motorboat(float32);
	void VFXStarTrek(float32 dt, xVec3* pos, xVec3* vel);
	bool32 LaunchProjectile(en_npchaz haztyp, float32 spd_proj, float32 dst_minRange, en_mdlvert idx_mvtx, float32 tym_predictMax, float32 hyt_offset);
	bool32 IsDead() STUB;
};

class zNPCFodder : public zNPCRobot
{
public:
	zNPCFodder(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Stun(float32);
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCFodBomb : public zNPCRobot
{
private:
	NPCBlinker blinker;

public:
	zNPCFodBomb(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual void Stun(float32);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void RenderExtra() STUB_VOID;
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;

	void BlinkerReset();
	void BlinkerUpdate(float32 dt, float32 pct_timeRemain);
	void BlinkerRender();
};

class zNPCFodBzzt : public zNPCRobot
{
private:
	RwRGBA rgba_discoLight;
	float32 tmr_discoLight;
	xVec3 pos_discoLight;
	float32 uv_discoLight[2];

public:
	zNPCFodBzzt(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void Setup();
	virtual void Reset();
	virtual void SelfSetup();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void Stun(float32);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void RenderExtra();
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;

	void DiscoReset();
	void DiscoUpdate(float32 dt);
	void DiscoRender();
};

class zNPCChomper : public zNPCRobot
{
private:
	int32 cnt_spurt;
	int32 cnt_skipEmit;

public:
	zNPCChomper(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual void Stun(float32);
	virtual void Process(xScene* xscn, float32 dt);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;

	void BreathTrail();
};

class zNPCCritter : public zNPCRobot
{
public:
	zNPCCritter(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void SelfSetup();
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCHammer : public zNPCRobot
{
public:
	zNPCHammer(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCTarTar : public zNPCRobot
{
public:
	zNPCTarTar(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCGlove : public zNPCRobot
{
public:
	zNPCGlove(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCMonsoon : public zNPCRobot
{
public:
	zNPCMonsoon(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;

	bool32 FoulWeather(float32);
};

class zNPCSleepy : public zNPCRobot
{
private:
	int32 flg_sleepy;
	NPCHazard* haz_patriot;
	float32 tmr_nextPatriot;
	RwRGBA rgba_coneColor;
	float32 tmr_angry;
	float32 tmr_emitzeez;
	float32 cnt_grpzeez;

public:
	zNPCSleepy(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);

	void NightLightPos(xVec3*);
	void NightLightUVStep(float32 dt);
	void SnoreNZeez(float32 dt);
	bool32 RepelMissile(float32 dt);
	bool32 RepelBowlBall(float32);
	void ConeOfRange(float32, int32);

	virtual void RenderExtra();

	void RendConeOfDeath(bool32 tgt_isBowlingBall);
	void RendConeRange();

	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCArfDog;

class zNPCArfArf : public zNPCRobot
{
private:
	int32 flg_puppy[5];
	zNPCArfDog* pup_kennel[5];

public:
	zNPCArfArf(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void ParseLinks();

	void ParseChild(xBase* child);

	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void DuploNotice(en_SM_NOTICES note, void* data);
	
	zNPCArfDog* AdoptADoggie();
	zMovePoint* GetTelepoint(int32) STUB;

	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCArfDog : public zNPCRobot
{
private:
	NPCBlinker blinkHead;
	NPCBlinker blinkTail;

public:
	zNPCArfDog(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Stun(float32);
	virtual void Process(xScene* xscn, float32 dt);

	void BlinkReset();
	void BlinkUpdate(float32, float32);
	void BlinkRender();

	virtual void RenderExtra() STUB_VOID;
	virtual zNPCLassoInfo* PRIV_GetLassoData() WIP { return NULL; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

class zNPCChuck : public zNPCRobot
{
private:
	xVec3 dir_attack;

public:
	zNPCChuck(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold);
};

enum en_tubestat
{
	TUBE_STAT_UNKNOWN,
	TUBE_STAT_DUCKLING,
	TUBE_STAT_ATTACK,
	TUBE_STAT_LASSO,
	TUBE_STAT_DYING,
	TUBE_STAT_DEAD,
	TUBE_STAT_BORN,
	TUBE_STAT_NOMORE,
	TUBE_STAT_FORCE = FORCEENUMSIZEINT
};

class TubeNotice : public xPSYNote
{
private:
	zNPCCommon* npc;

public:
	TubeNotice() WIP : xPSYNote() {}

	virtual void Notice(en_psynote note, xGoal* goal, void*);
};

class zNPCTubeSlave;

class zNPCTubelet : public zNPCRobot
{
private:
	en_tubestat tubestat;
	zNPCTubeSlave* tub_paul;
	zNPCTubeSlave* tub_mary;
	float32 bonkSpinRate;
	float32 tmr_restoreHealth;
	int32 pete_attack_last;
	TubeNotice psynote;

public:
	zNPCTubelet(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void ParseLinks();

	void ParseChild(xBase* child);

	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 Respawn(const xVec3* pos, zMovePoint* mvptFirst, zMovePoint* mvptSpawnRef);

	void PrepTheBand();

	virtual bool32 RoboHandleMail(NPCMsg* mail);
	virtual void LassoNotify(en_LASSO_EVENT event);

	void Bonk();
	void Unbonk();
	bool32 Chk_IsBonked();
	void PainInTheBand();
	void Chk_NonAlertBonk(float32);

	virtual bool32 IsDying();
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold);
};

enum en_tubespot
{
	ROBO_TUBE_PETE,
	ROBO_TUBE_PAUL,
	ROBO_TUBE_MARY,
	ROBO_TUBE_NOMORE,
	ROBO_TUBE_FORCE = FORCEENUMSIZEINT
};

class zNPCTubeSlave : public zNPCRobot
{
private:
	en_tubespot tubespot;
	zNPCTubelet* tub_pete;

public:
	zNPCTubeSlave(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();

	void WeGotAGig();
	void PartyOn();

	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);

	void SetMaster(zNPCTubelet*, en_tubespot);

	virtual void Process(xScene* xscn, float32 dt);
	virtual void RenderExtra();
	virtual bool32 RoboHandleMail(NPCMsg* mail);
	virtual bool32 IsDying();

	void PosStacked(xVec3* pos_stacked);
	void DoLaserRendering();

	virtual uint8 ColChkFlags() WIP const { return 0; }
	virtual uint8 ColPenFlags() WIP const { return 0; }
	virtual uint8 ColChkByFlags() WIP const { return 0x10; }
	virtual uint8 ColPenByFlags() WIP const { return 0x10; }
	virtual uint8 PhysicsFlags() WIP const { return 0x3; }
	virtual bool32 CanRope() WIP { return FALSE; }
	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold);
};

class zNPCSlick : public zNPCRobot
{
private:
	float32 rad_shield;
	float32 tmr_repairShield;
	float32 tmr_invuln;
	float32 alf_shieldCurrent;
	float32 alf_shieldDesired;

public:
	zNPCSlick(int32 myType) WIP : zNPCRobot(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);

	void StuffToDoIfAlive(float32);

	virtual void Damage(en_NPC_DAMAGE_TYPE dmg_type, xBase* who, const xVec3* vec_hit);

	void ShieldUpdate(float32 dt);
	void ShieldCollide(float32);
	void ShieldFX(float32);
	void ShieldGeneratorDamaged();
	void RopePopsShield();

	virtual void BUpdate(xVec3* pos);

	bool32 IsShield() const;
	void ShieldHide();
	void ShieldShow();
	void YouOwnSlipFX();
	void SlipSlidenAway(float32);

	virtual void LassoModelIndex(int32* idxgrab, int32* idxhold) STUB_VOID;
};

void ZNPC_Robot_Startup();
void ZNPC_Robot_Shutdown();
void zNPCRobot_ScenePrepare();
void zNPCRobot_SceneFinish();
void zNPCRobot_SceneReset();
void zNPCRobot_ScenePostInit();
void zNPCRobot_Timestep(xScene*, float32 dt);
xFactoryInst* ZNPC_Create_Robot(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Robot(xFactoryInst* inst);
void ZNPC_AnimTable_RobotBase(xAnimTable* table);
xAnimTable* ZNPC_AnimTable_Fodder();
xAnimTable* ZNPC_AnimTable_Hammer();
xAnimTable* ZNPC_AnimTable_TarTar();
xAnimTable* ZNPC_AnimTable_TTSauce();
xAnimTable* ZNPC_AnimTable_GLove();
xAnimTable* ZNPC_AnimTable_Monsoon();
xAnimTable* ZNPC_AnimTable_ThunderCloud();
xAnimTable* ZNPC_AnimTable_NightLight();
xAnimTable* ZNPC_AnimTable_SleepyTime();
xAnimTable* ZNPC_AnimTable_ArfDog();
xAnimTable* ZNPC_AnimTable_ArfArf();
xAnimTable* ZNPC_AnimTable_Chuck();
xAnimTable* ZNPC_AnimTable_Tubelet();
xAnimTable* ZNPC_AnimTable_FloatDevice();
xAnimTable* ZNPC_AnimTable_SlickShield();
xAnimTable* ZNPC_AnimTable_Slick();
void zNPCRobot_TubeConfetti(const xVec3* pos_emit);
void zNPCFodBzzt_ResetDanceParty();
void zNPCFodBzzt_DoTheHokeyPokey(float32 dt);
void zNPCSleepy_Timestep(float32);
void ROBO_InitEffects();
void ROBO_KillEffects();