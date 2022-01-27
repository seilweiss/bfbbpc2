#pragma once

#include "zNPCGoalCommon.h"
#include "xMath3.h"

class zNPCGoalBossPatIdle : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatTaunt : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatTaunt(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatHit : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatHit(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatSpit : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 timeLeftToSpit;

public:
	zNPCGoalBossPatSpit(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatRun : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	uint32 runSndID;

public:
	zNPCGoalBossPatRun(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatSmack : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 globNum;

public:
	zNPCGoalBossPatSmack(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatFreeze : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 freezeSlope;

public:
	zNPCGoalBossPatFreeze(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatSpawn : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatSpawn(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatSpin : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 numGlobs;
	xVec3 vel;
	xVec3 pole[4];
	int32 currPole;
	uint32 spinSndID;
	uint32 globSndID;

public:
	zNPCGoalBossPatSpin(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalBossPatFudge : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 lerp;
	float32 globNum;
	uint32 vomitSndID;

public:
	zNPCGoalBossPatFudge(int32 myType) WIP : zNPCGoalCommon(myType) {}
};