#pragma once

#include "xScene.h"
#include "zPortal.h"
#include "zEnt.h"
#include "zEnv.h"

struct zScene : xScene
{
	zPortal* pendingPortal;
	union
	{
		uint32 num_ents;
		uint32 num_base;
	};
	union
	{
		xBase** base;
		zEnt** ents;
	};
	uint32 num_update_base;
	xBase** update_base;
	uint32 baseCount[72];
	xBase* baseList[72];
	zEnv* zen;
};