#pragma once

#include "zNPCGoalCommon.h"
#include "zNPCGoalStd.h"

enum en_dupolive
{
	LIVESTAT_NORMAL,
	LIVESTAT_COUNTDOWN
};

class zNPCGoalDuploLive : public zNPCGoalCommon
{
private:
	float32 tmr_chkPlyrDist;
	int32 cnt_destruct;
	en_dupolive livestat;

public:
	zNPCGoalDuploLive(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0xC);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 NPCMessage(NPCMsg* mail);

	void CheckPlayer();
	void SDS_BigRedButton();
	bool32 SDS_Countdown(float32 dt);
	void SDS_StartExplode();
};

class zNPCGoalDuploDead : public zNPCGoalDead
{
public:
	zNPCGoalDuploDead(int32 myType) WIP : zNPCGoalDead(myType)
	{
		SetFlags(0x8);
	}
};

xFactoryInst* GOALCreate_Duplotron(int32 who, RyzMemGrow* grow, void*);