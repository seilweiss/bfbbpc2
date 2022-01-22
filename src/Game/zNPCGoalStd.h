#pragma once

#include "zNPCGoalCommon.h"
#include "xMath3.h"

struct xAnimState;

class zNPCGoalPushAnim : public zNPCGoalCommon
{
private:
	int32 flg_pushanim;
	float32 lastAnimTime;

public:
	zNPCGoalPushAnim(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0x6); }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalLoopAnim : public zNPCGoalCommon
{
private:
	int32 flg_loopanim;
	uint32 anid_stage[3];
	int32 cnt_loop;
	float32 lastAnimTime;
	uint32 origAnimFlags;
	uint32 animWeMolested;

public:
	zNPCGoalLoopAnim(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0x2); }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void MolestLoopAnim();
	void UnmolestAnim();
	void LoopCountSet(int32 num);
	void UseDefaultAnims();
	void ValidateStages();
	void TriggerExit() WIP { cnt_loop = 0; }
};

class zNPCGoalIdle : public zNPCGoalCommon
{
private:
	int32 flg_idle;

public:
	zNPCGoalIdle(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0xC); flg_npcgauto &= ~0x6; }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Suspend(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 NPCMessage(NPCMsg* msg);
};

class zNPCGoalPatrol : public zNPCGoalCommon
{
private:
	int32 flg_patrol;
	float32 tmr_wait;
	xVec3 pos_midpnt[4];
	int32 idx_midpnt;

public:
	zNPCGoalPatrol(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0x6); }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void DoOnArriveStuff();
	void PickTransition(int32*, trantype*);
	void MoveNormal(float32 dt);
	void MoveSpline(float32 dt);
	void Chk_AutoSmooth();
	void MoveAutoSmooth(float32 dt);
};

class zNPCGoalFidget : public zNPCGoalPushAnim
{
public:
	zNPCGoalFidget(int32 myType) WIP : zNPCGoalPushAnim(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
};

class zNPCGoalWander : public zNPCGoalCommon
{
private:
	int32 flg_wand;
	float32 tmr_remain;
	float32 rad_wand;
	xVec3 pos_home;
	float32 tmr_minwalk;
	float32 tmr_newdir;
	xVec3 dir_cur;

public:
	zNPCGoalWander(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0x6); flg_wand = 0xFFFF0000; }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);

	void VerticalWander(float32 spd_dt, const xVec3* vec_dest);
	void CalcNewDir();
};

class zNPCGoalWaiting : public zNPCGoalLoopAnim
{
private:
	int32 flg_waiting;
	float32 tmr_waiting;

public:
	zNPCGoalWaiting(int32 myType) WIP : zNPCGoalLoopAnim(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
};

class zNPCGoalDead : public zNPCGoalCommon
{
private:
	int32 flg_deadinfo;
	uint8 old_moreFlags;

public:
	zNPCGoalDead(int32 myType) WIP : zNPCGoalCommon(myType) { SetFlags(0x6); }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);

	void DieQuietly() WIP { flg_deadinfo |= 0x1; flg_deadinfo &= ~0x2; }
	void DieWithAWhimper() WIP { flg_deadinfo &= ~0x1; flg_deadinfo |= 0x2; }
	void DieWithABang() WIP { flg_deadinfo &= ~0x1; flg_deadinfo &= ~0x2; }
};

class zNPCGoalNoManLand : public zNPCGoalCommon
{
public:
	zNPCGoalNoManLand(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalLimbo : public zNPCGoalDead
{
public:
	zNPCGoalLimbo(int32 myType) WIP : zNPCGoalDead(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalDEVAnimCycle : public zNPCGoalCommon
{
public:
	zNPCGoalDEVAnimCycle(int32 myType) WIP : zNPCGoalCommon(myType) { flg_npcgauto &= ~0x6; }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	xAnimState* ASTGetNext(xAnimState*);
};

class zNPCGoalDEVAnimSpin : public zNPCGoalCommon
{
private:
	uint32 origAnimFlags;
	uint32 animWeMolested;

public:
	zNPCGoalDEVAnimSpin(int32 myType) WIP : zNPCGoalCommon(myType) { flg_npcgauto &= ~0x6; }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void ASTMolestAnim(xAnimState*);
	void ASTUnmolestAnim();
};

class zNPCGoalDEVHero : public zNPCGoalCommon
{
public:
	zNPCGoalDEVHero(int32 myType) WIP : zNPCGoalCommon(myType) { flg_npcgauto &= ~0x6; }

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

xFactoryInst* GOALCreate_Standard(int32 who, RyzMemGrow* grow, void*);
void GOALDestroy_Goal(xFactoryInst* inst);