#pragma once

#include "xBase.h"

struct xGroupAsset : xBaseAsset
{
	uint16 itemCount;
	uint16 groupFlags;
};

struct xGroup : xBase
{
	xGroupAsset* asset;
	xBase** item;
	uint32 last_index;
	int32 flg_group;

	uint32 get_any();
};

void xGroupInit(void* b, void* asset);
void xGroupInit(xBase*, xGroupAsset*);
void xGroupSetup(xGroup* g);
void xGroupSave(xGroup* ent, xSerial* s);
void xGroupLoad(xGroup* ent, xSerial* s);
void xGroupReset(xGroup*);
bool32 xGroupEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget);
uint32 xGroupGetCount(xGroup* g);
xBase* xGroupGetItemPtr(xGroup* g, uint32 index);
xBase* xGroupFindItemPtr(xGroup*, uint32);
uint32 xGroupGetItem(xGroup* g, uint32 index);