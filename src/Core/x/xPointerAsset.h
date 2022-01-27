#pragma once

#include "xDynAsset.h"
#include "xMath3.h"

struct pointer_asset : xDynAsset
{
	xVec3 loc;
	float32 yaw;
	float32 pitch;
	float32 roll;

	static const char* type_name() WIP { return "pointer"; }
};