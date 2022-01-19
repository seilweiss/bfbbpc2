#pragma once

#include <types.h>
#include <rwcore.h>

struct xClumpCollBSPVertInfo
{
	uint16 atomIndex;
	uint16 meshVertIndex;
};

struct xClumpCollBSPTriangle
{
	union
	{
		xClumpCollBSPVertInfo i;
		RwV3d* p;
	} v;
	uint8 flags;
	uint8 platData;
	uint16 matIndex;
};