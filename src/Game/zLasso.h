#pragma once

#include "xModel.h"

struct xEnt;
struct xAnimState;

struct zLasso
{
	uint32 flags;
	float32 secsTotal;
	float32 secsLeft;
	float32 stRadius;
	float32 tgRadius;
	float32 crRadius;
	xVec3 stCenter;
	xVec3 tgCenter;
	xVec3 crCenter;
	xVec3 stNormal;
	xVec3 tgNormal;
	xVec3 crNormal;
	xVec3 honda;
	float32 stSlack;
	float32 stSlackDist;
	float32 tgSlack;
	float32 tgSlackDist;
	float32 crSlack;
	float32 currDist;
	float32 lastDist;
	xVec3 lastRefs[5];
	uint8 reindex[5];
	xVec3 anchor;
	xModelTag tag;
	xModelInstance* model;
};

void zLasso_Init(zLasso* lasso, xModelInstance* model, float32 x, float32 y, float32 z);
void zLasso_AddGuide(xEnt* ent, xAnimState* lassoAnim, xModelInstance* lassoModel);
void zLasso_SetGuide(xEnt* ent, xAnimState* lassoAnim);
void zLasso_InterpToGuide(zLasso* lasso);
void zLasso_Render(zLasso* lasso);
void zLasso_Update(zLasso* lasso, xEnt* ent, float32 dt);
void zLasso_InitTimer(zLasso* lasso, float32 interpTime);
void zLasso_ResetTimer(zLasso* lasso, float32 interpTime);
void zLasso_scenePrepare();
