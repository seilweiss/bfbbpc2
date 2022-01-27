#pragma once

#include "zNPCGoalCommon.h"

class zNPCGoalHere : public zNPCGoalCommon
{
public:
	zNPCGoalHere(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

xFactoryInst* GOALCreate_SubBoss(int32 who, RyzMemGrow* grow, void*);