#pragma once

#include "zNPCGoalCommon.h"

class zNPCGoalExist : public zNPCGoalCommon
{
public:
	zNPCGoalExist(int32 myType) WIP : zNPCGoalCommon(myType) {}
};

xFactoryInst* GOALCreate_Boss(int32 who, RyzMemGrow* grow, void*);