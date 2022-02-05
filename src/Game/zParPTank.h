#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct zParPTank;
struct xParEmitter;

typedef void(*zParPTankUpdateCallback)(zParPTank*, float32);

struct zParPTank
{
	uint32 flags;
	zParPTankUpdateCallback update;
	RpAtomic* ptank;
	uint32 num_particles;
	uint32 max_particles;
};

extern uint32 gPTankDisable;

void zParPTankSpawnSparkles(xVec3* pos, uint32 count);
void zParPTankSpawnBubbles(xVec3* pos, xVec3* vel, uint32 count, float32 scale);
int32 zParPTankBubblesAvailable();
void zParPTankSpawnMenuBubbles(xVec3* pos, xVec3* vel, uint32 count);
void zParPTankSpawnSnow(xVec3* pos, xVec3* vel, uint32 count);
zParPTank* zParPTankAdd();
void zParPTankInit();
void zParPTankSceneEnter();
void zParPTankSceneExit();
void zParPTankExit();
void zParPTankUpdate(float32 dt);
void zParPTankRender();
int32 zParPTankConvertEmitRate(xParEmitter* pe, float32 dt);