#pragma once

#include "iEnv.h"

struct xLightKit;

struct xEnv
{
	iEnv* geom;
	iEnv ienv;
	xLightKit* lightKit;
};

void xEnvLoadBsp(xEnv* env, const void* data, uint32 datasize, int32 dataType);
void xEnvSetup(xEnv* env);
void xEnvFree(xEnv* env);
void xEnvRender(xEnv* env);

inline xBBox* xEnvGetBBox(xEnv*) STUB