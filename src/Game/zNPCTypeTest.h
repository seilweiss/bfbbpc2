#pragma once

#include "zNPCTypeCommon.h"

class zNPCTest : public zNPCCommon
{
private:
	int32 numAnimations;
	int32 currentState;
	float32 transitionTimer;

public:
	zNPCTest(int32 myType);

	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32, en_NPC_GOAL_SPOT, xGoal*);
};

void ZNPC_Test_Startup();
void ZNPC_Test_Shutdown();
xFactoryInst* ZNPC_Create_Test(int32 who, RyzMemGrow* grow, void*);
void ZNPC_Destroy_Test(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_Test();