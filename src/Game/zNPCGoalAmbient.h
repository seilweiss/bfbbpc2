#pragma once

#include "zNPCGoalCommon.h"
#include "zNPCGoalStd.h"

struct zLightning;

class zNPCGoalJellyBumped : public zNPCGoalPushAnim
{
private:
	xVec3 pos_bumper;
	xVec3 pos_bumpin;
	xVec3 pos_grindin;
	uint32 streakID;

public:
	zNPCGoalJellyBumped(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void MoveSwoosh(float32);
	void PlayWithAnimSpd();
	void StreakPrep();
	void StreakDone();
	void StreakUpdate();
	void ExtractAimDir(xVec3* dir_aim);
	float32 CalcEndPoint(xVec3* pos_end, const xVec3* dir_aim);
};

class zNPCGoalJellyAttack : public zNPCGoalPushAnim
{
private:
	int32 flg_attack;
	zLightning* zap_lytnin[3];

public:
	zNPCGoalJellyAttack(int32 myType) WIP : zNPCGoalPushAnim(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void ZapperStart();
	void ZapperStop();
	void ZapperUpdate();
};

class zNPCGoalJellyBirth : public zNPCGoalCommon
{
private:
	xVec3 pos_spawn;
	float32 tmr_fall;

public:
	zNPCGoalJellyBirth(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x2);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantyp, float32 dt, void* ctxt, xScene* xscn);

	void BirthInfoSet(const xVec3* pos_birth, float32 tym_fall);
};

xFactoryInst* GOALCreate_Ambient(int32 who, RyzMemGrow* grow, void*);