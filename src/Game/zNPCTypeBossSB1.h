#pragma once

#include "zNPCTypeBoss.h"
#include "zNPCGoalCommon.h"

#include <rwcore.h>
#include <rpworld.h>

struct zEnt;
struct xFXRing;

class zNPCB_SB1 : public zNPCBoss
{
private:
	xModelInstance* m_subModels[6];
	xModelTag m_leftArmTags[4];
	xModelTag m_rightArmTags[4];
	xModelTag m_feetTags[4];
	float32 m_tauntTimer;
	zEnt* m_armColl[2];
	zEnt* m_bodyColl;
	zEnt* m_armTgt[2];
	xFXRing* m_stompRing[16];
	bool attacking;
	float32 attack_delay;

public:
	zNPCB_SB1(int32 myType) WIP : zNPCBoss(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void SelfSetup();
	virtual void Reset();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual float32 AttackTimeLeft();
	virtual void HoldUpDude();
	virtual void ThanksImDone();
};

class zNPCGoalBossSB1Idle : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Idle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSB1Taunt : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Taunt(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSB1Stomp : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Stomp(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSB1Smash : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Smash(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSB1Deflate : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	RwV3d morphVertBuf[600];
	RwV3d* targetVec;
	RwV3d* modelVec;
	RpGeometry* modelGeom;
	int32 morphVertCount;
	float32 morphInvTime;

public:
	zNPCGoalBossSB1Deflate(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_BossSB1();