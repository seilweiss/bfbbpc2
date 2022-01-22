#pragma once

#include "zNPCTypeCommon.h"
#include "zNPCGlyph.h"
#include "xEntDrive.h"

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

	void FacePlayer(float32, float32) STUB_VOID;
};

class zNPCArfDog;

class zNPCArfArf : public zNPCRobot
{
private:
	int32 flg_puppy[5];
	zNPCArfDog* pup_kennel[5];

public:
	zMovePoint* GetTelepoint(int32) STUB;
};