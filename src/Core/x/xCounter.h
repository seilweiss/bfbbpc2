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

void xCounterInit();
void xCounterInit(void* b, void* asset);
void xCounterInit(xCounter* b, xCounterAsset* asset);
void xCounterReset(xBase* b);
void xCounterSave(xCounter* ent, xSerial* s);
void xCounterLoad(xCounter* ent, xSerial* s);
bool32 xCounterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
