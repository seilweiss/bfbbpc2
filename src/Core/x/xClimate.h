#pragma once

#include "xMath3.h"

struct xEnvAsset;
struct zParEmitter;

typedef struct _tagRain
{
	int32 rain;
	float32 strength;
	zParEmitter* rain_emitter;
	zParEmitter* snow_emitter;
} Rain;

typedef struct _tagWind
{
	float32 strength;
	float32 angle;
	xVec3 dir;
} Wind;

typedef struct _tagClimate
{
	Rain rain;
	Wind wind;
} Climate;

void xClimateInit(Climate* climate);
void xClimateInitAsset(Climate* climate, xEnvAsset* easset);
void xClimateSetSnow(float32 stre);
void xClimateSetRain(float32 stre);
void xClimateUpdate(Climate* climate, float32 seconds);