#pragma once

#include "xEnt.h"

struct xEntDrive
{
	struct tri_data : xCollis::tri_data
	{
		xVec3 loc;
		float32 yaw;
		xCollis* coll;
	};

	uint32 flags;
	float32 otm;
	float32 otmr;
	float32 os;
	float32 tm;
	float32 tmr;
	float32 s;
	xEnt* odriver;
	xEnt* driver;
	xEnt* driven;
	xVec3 op;
	xVec3 p;
	xVec3 q;
	float32 yaw;
	xVec3 dloc;
	tri_data tri;
};

void xEntDriveInit(xEntDrive* drv, xEnt* driven);
void xEntDriveMount(xEntDrive* drv, xEnt* driver, float32 mt, const xCollis* coll);
void xEntDriveDismount(xEntDrive* drv, float32 dmt);
void xEntDriveUpdate(xEntDrive* drv, xScene*, float32 dt, const xCollis*);
