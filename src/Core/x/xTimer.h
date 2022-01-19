#pragma once

#include "xBase.h"

struct xScene;

struct xTimerAsset : xBaseAsset
{
	float32 seconds;
	float32 randomRange;
};

struct xTimer : xBase
{
	xTimerAsset* tasset;
	uint8 state;
	bool runsInPause;
	uint16 flags;
	float32 secondsLeft;
};

void xTimerInit(void* b, void* tasset);
void xTimerInit(xBase*, xTimerAsset*);
void xTimerReset(xTimer*);
void xTimerSave(xTimer* ent, xSerial* s);
void xTimerLoad(xTimer* ent, xSerial* s);
bool32 xTimerEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*);
void xTimerUpdate(xBase* to, xScene*, float32 dt);
