#pragma once

#include "zNPCGoalCommon.h"

class zNPCGoalKJIdle : public zNPCGoalCommon
{
private:
	float32 attack_delay;

public:
	zNPCGoalKJIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJBored : public zNPCGoalCommon
{
public:
	zNPCGoalKJBored(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJSpawnKids : public zNPCGoalCommon
{
private:
	float32 delay;
	int32 cycle;
	uint8 spawned;
	uint8 spewed;
	int32 child_count;
	int32 spawn_count;

public:
	zNPCGoalKJSpawnKids(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJTaunt : public zNPCGoalCommon
{
public:
	zNPCGoalKJTaunt(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJShockGround : public zNPCGoalCommon
{
private:
	float32 delay;
	int32 strikes;

public:
	zNPCGoalKJShockGround(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJDamage : public zNPCGoalCommon
{
public:
	zNPCGoalKJDamage(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

class zNPCGoalKJDeath : public zNPCGoalCommon
{
public:
	zNPCGoalKJDeath(int32 myType) WIP : zNPCGoalCommon(myType) {}
};