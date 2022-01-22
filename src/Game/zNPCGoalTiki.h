#pragma once

#include "zNPCGoalCommon.h"
#include "xMath3.h"

class zNPCGoalTikiIdle : public zNPCGoalCommon
{
private:
	float32 tmr_wait;

public:
	zNPCGoalTikiIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
};

class zNPCGoalTikiPatrol : public zNPCGoalCommon
{
private:
	xVec3 dest_pos;
	xVec3 vel;

public:
	zNPCGoalTikiPatrol(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
};

class zNPCGoalTikiHide : public zNPCGoalCommon
{
public:
	zNPCGoalTikiHide(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalTikiCount : public zNPCGoalCommon
{
private:
	float32 tmr_count;
	int32 beingCarried;

public:
	zNPCGoalTikiCount(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
};

class zNPCGoalTikiDying : public zNPCGoalCommon
{
private:
	float32 tmr_dying;

public:
	zNPCGoalTikiDying(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalTikiDead : public zNPCGoalCommon
{
private:
	float32 tmr_resurrect;

public:
	zNPCGoalTikiDead(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32, void*);
	virtual bool32 Exit(float32, void*);
};

xFactoryInst* GOALCreate_Tiki(int32 who, RyzMemGrow* grow, void*);