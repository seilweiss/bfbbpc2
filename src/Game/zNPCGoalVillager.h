#pragma once

#include "zNPCGoalCommon.h"
#include "zNPCGoalStd.h"
#include "zNPCSupport.h"
#include "zNPCGlyph.h"

struct xSFX;

class zNPCGoalPlayerNear : public zNPCGoalCommon
{
private:
	int32 flg_plyrnear;
	NPCGlyph* talk_glyph;
	NPCWidget* talk_font;
	float32 tmr_actBored;

public:
	zNPCGoalPlayerNear(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Suspend(float32, void*);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void ChkCheatMedic();
	void DoCheatPanHandle();
	void ChkCheatDogTrix(int32* nextgoal, en_trantype* trantype);
};

class zNPCGoalTalk : public zNPCGoalCommon
{
private:
	float32 tmr_cycleAnim;
	float32 tmr_minTalk;
	int32 stopTalking;
	int32 killAndExit;
	xSFX* sfx_curTalk;
	uint32 aid_curSound;
	xVec3 pos_maintain;
	void* jawdata;
	float32 jawtime;

public:
	zNPCGoalTalk(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void StartSFX(xSFX*);
};

class zNPCGoalSpeak : public zNPCGoalCommon
{
private:
	float32 tmr_cycleAnim;
	xVec3 pos_maintain;
	void* jawdata;
	float32 jawtime;

public:
	zNPCGoalSpeak(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalCheer : public zNPCGoalLoopAnim
{
public:
	zNPCGoalCheer(int32 myType) WIP : zNPCGoalLoopAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalChatter : public zNPCGoalCommon
{
private:
	uint32 sid_played;
	uint32 playThisSound;

public:
	zNPCGoalChatter(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalHurt : public zNPCGoalPushAnim
{
public:
	zNPCGoalHurt(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void ChkRewardCheat();
};

class zNPCGoalBalloon : public zNPCGoalCommon
{
public:
	zNPCGoalBalloon(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
		AddFlags(0x20000);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalBoyRide : public zNPCGoalCommon
{
public:
	zNPCGoalBoyRide(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalBoyFall : public zNPCGoalCommon
{
private:
	int32 hitGround;

public:
	zNPCGoalBoyFall(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
		flg_npcgable |= 0x1;
	}

	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 CollReview(void*);
};

class zNPCGoalBoyWeep : public zNPCGoalCommon
{
private:
	float32 tmr_weep;
	float32 ang_spinrate;

public:
	zNPCGoalBoyWeep(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalBoySwim : public zNPCGoalCommon
{
public:
	zNPCGoalBoySwim(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}
};

xFactoryInst* GOALCreate_Villager(int32 who, RyzMemGrow* grow, void*);