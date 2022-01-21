#pragma once

#include "xMath3.h"
#include "xColor.h"

#include <rwcore.h>
#include <rpworld.h>

struct iLight
{
	uint32 type;
	RpLight* hw;
	xSphere sph;
	float32 radius_sq;
	xFColor color;
	xVec3 dir;
	float32 coneangle;
};

void iLightInit(RpWorld* world);
iLight* iLightCreate(iLight* light, uint32 type);
void iLightModify(iLight* light, uint32 flags);
void iLightSetColor(iLight* light, xFColor* col);
void iLightSetPos(iLight* light, xVec3* pos);
void iLightDestroy(iLight* light);
void iLightEnv(iLight* light, int32 env);