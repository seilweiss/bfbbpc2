#pragma once

#include "xBehaviour.h"

class xGoalGeneric : public xGoal
{
private:
	bool32(*fun_enter)(xGoal*, void*, float32, void*);
	bool32(*fun_exit)(xGoal*, void*, float32, void*);
	bool32(*fun_suspend)(xGoal*, void*, float32, void*);
	bool32(*fun_resume)(xGoal*, void*, float32, void*);
	bool32(*fun_sysevent)(xGoal*, void*, xBase*, xBase*, uint32, const float32*, xBase*, bool32*);
	void* usrData;

public:
	xGoalGeneric(int32 myType) WIP : xGoal(myType) {}

	virtual void Clear() {}
	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void* updCtxt);
	virtual bool32 Suspend(float32 dt, void* updCtxt);
	virtual bool32 Resume(float32 dt, void* updCtxt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual const char* Name() WIP { return "xGoalGeneric"; }
};

class xGoalEmpty : public xGoal
{
public:
	xGoalEmpty(int32 myType) WIP : xGoal(myType) {}

	virtual void Clear() {}
	virtual const char* Name() WIP { return "xGoalEmpty"; }
};

void xGoalSimple_RegisterTypes(xFactory* fac);