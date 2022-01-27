#pragma once

#include "zNPCGoalCommon.h"

class zNPCGoalPrawnIdle : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalPrawnBeam : public zNPCGoalCommon
{
private:
	enum substate_enum
	{
		SS_AIM,
		SS_FIRE,
		SS_HOLD,
		SS_SWEEP,
		SS_STOP,
		MAX_SS
	};

	substate_enum substate;
	int32 sweeps;
	float32 sweep_dir;
	float32 delay;

public:
	zNPCGoalPrawnBeam(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalPrawnBowl : public zNPCGoalCommon
{
private:
	bool aiming;

public:
	zNPCGoalPrawnBowl(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalPrawnDamage : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnDamage(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalPrawnDeath : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnDeath(int32 myType) WIP : zNPCGoalCommon(myType) {}
};