#pragma once

#include "xBase.h"

struct xCreditsData
{
	uint32 dummy;
};

void xCMupdate(float32 dt);
void xCMrender();
void xCMstart(xCreditsData* data, float32, xBase* parent);
void xCMstop();