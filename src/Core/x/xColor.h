#pragma once

#include "iColor.h"

typedef iColor xColor;

typedef struct _xFColor
{
	float32 r;
	float32 g;
	float32 b;
	float32 a;
} xFColor;

inline xColor xColorFromRGBA(uint8 r, uint8 g, uint8 b, uint8 a) WIP
{
	xColor c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}