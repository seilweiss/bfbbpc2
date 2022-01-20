#pragma once

#include "xModelBucket.h"

struct xEnt;
struct xScene;

struct zLODTable
{
	xModelBucket** baseBucket;
	float32 noRenderDist;
	xModelBucket** lodBucket[3];
	float32 lodDist[3];
};

void zLOD_Setup();
void zLOD_Update(uint32 percent_update);
zLODTable* zLOD_Get(xEnt* ent);
void zLOD_UseCustomTable(xEnt* ent, zLODTable* lod);