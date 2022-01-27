#pragma once

#include "zNPCGoalCommon.h"

#include <rwcore.h>
#include <rpworld.h>

class zNPCGoalBossSB1Idle : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Idle(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossSB1Taunt : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Taunt(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossSB1Stomp : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Stomp(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossSB1Smash : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSB1Smash(int32 myType) WIP : zNPCGoalCommon(myType) {}
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
};