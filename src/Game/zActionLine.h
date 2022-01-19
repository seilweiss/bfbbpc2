#pragma once

#include "xMath3.h"

typedef struct _tagActionLine
{
	uint32 flags;
	xVec3 pos[4];
	float32 time_left;
} ActionLine;

void zActionLineInit();
void zActionLineUpdate(float32 seconds);
void zActionLineRender();