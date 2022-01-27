#pragma once

#include "zNPCGoalCommon.h"

class zNPCGoalScript : public zNPCGoalCommon
{
private:
	int32 flg_script;

public:
	zNPCGoalScript(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x1C);
	}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 SysEvent(xBase*, xBase*, uint32, const float32*, xBase*, bool32*);
	virtual bool32 NPCMessage(NPCMsg* mail);
};

class zNPCGoalScriptAnim : public zNPCGoalCommon
{
public:
	zNPCGoalScriptAnim(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptAttack : public zNPCGoalCommon
{
public:
	zNPCGoalScriptAttack(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptMove : public zNPCGoalCommon
{
public:
	zNPCGoalScriptMove(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptTalk : public zNPCGoalCommon
{
public:
	zNPCGoalScriptTalk(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptFollow : public zNPCGoalCommon
{
public:
	zNPCGoalScriptFollow(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptLead : public zNPCGoalCommon
{
public:
	zNPCGoalScriptLead(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

class zNPCGoalScriptWait : public zNPCGoalCommon
{
public:
	zNPCGoalScriptWait(int32 myType) WIP : zNPCGoalCommon(myType)
	{
		SetFlags(0x6);
	}
};

xFactoryInst* GOALCreate_Script(int32 who, RyzMemGrow* grow, void*);