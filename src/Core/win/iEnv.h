#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct xJSPHeader;
struct xBBox;
struct xEnvAsset;

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

void iEnvLoad(iEnv* env, const void* data, uint32, int32 dataType);
void iEnvFree(iEnv* env);
void iEnvDefaultLighting(iEnv*);
void iEnvLightingBasics(iEnv*, xEnvAsset*);
void iEnvRender(iEnv* env);
void iEnvEndRenderFX(iEnv*);

inline void iEnvStartup() {}
inline xBBox* iEnvGetBBox(iEnv*) STUB