#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct xJSPHeader;
struct xBBox;

struct iEnv
{
	RpWorld* world;
	RpWorld* collision;
	RpWorld* fx;
	RpWorld* camera;
	xJSPHeader* jsp;
	RpLight* light[2];
	RwFrame* light_frame[2];
	int32 memlvl;
};

inline void iEnvStartup() {}
inline xBBox* iEnvGetBBox(iEnv*) STUB