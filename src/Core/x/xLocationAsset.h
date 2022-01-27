#pragma once

#include "xDynAsset.h"
#include "xMath3.h"

struct location_asset : xDynAsset
{
	xVec3 loc;

	static const char* type_name() WIP { return "location"; }
};