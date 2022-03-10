#pragma once

#include "xBase.h"

struct xCounterAsset : xBaseAsset
{
	int16 count;
};

typedef struct _xCounter : xBase
{
	xCounterAsset* asset;
	int16 count;
	uint8 state;
	uint8 counterFlags;
} xCounter;

#define XCOUNTER_ACTIVE 0
#define XCOUNTER_EXPIRED 1

#define XCOUNTER_ISSPATULA 0x1

void xCounterInit();
void xCounterInit(void* b, void* asset);
void xCounterInit(xBase* b, xCounterAsset* asset);
void xCounterReset(xBase* b);
void xCounterSave(xCounter* ent, xSerial* s);
void xCounterLoad(xCounter* ent, xSerial* s);
bool32 xCounterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
