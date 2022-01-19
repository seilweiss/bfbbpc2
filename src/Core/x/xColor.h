#pragma once

#include "iColor.h"

typedef iColor xColor;

inline xColor xColorFromRGBA(uint8 r, uint8 g, uint8 b, uint8 a) WIP
{
	xColor c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}