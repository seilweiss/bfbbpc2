#pragma once

#include <types.h>

struct xGroup;

typedef uint32(*xUpdateCullEntCallback)(void*, void*);
typedef void(*xUpdateCullMgrActivateCallback)(void*);
typedef void(*xUpdateCullMgrDeactivateCallback)(void*);

struct xUpdateCullEnt
{
	uint16 index;
	int16 groupIndex;
	xUpdateCullEntCallback cb;
	void* cbdata;
	xUpdateCullEnt* nextInGroup;
};

struct xUpdateCullGroup
{
	uint32 active;
	uint16 startIndex;
	uint16 endIndex;
	xGroup* groupObject;
};

struct xUpdateCullMgr
{
	uint32 entCount;
	uint32 entActive;
	void** ent;
	xUpdateCullEnt** mgr;
	uint32 mgrCount;
	uint32 mgrCurr;
	xUpdateCullEnt* mgrList;
	uint32 grpCount;
	xUpdateCullGroup* grpList;
	xUpdateCullMgrActivateCallback activateCB;
	xUpdateCullMgrDeactivateCallback deactivateCB;
};

uint32 xUpdateCull_AlwaysTrueCB(void*, void*);
uint32 xUpdateCull_DistanceSquaredCB(void* ent, void* cbdata);
xUpdateCullMgr* xUpdateCull_Init(void** ent, uint32 entCount, xGroup** group, uint32 groupCount);
void xUpdateCull_Update(xUpdateCullMgr* m, uint32 percent_update);
void xUpdateCull_SetCB(xUpdateCullMgr* m, void* entity, xUpdateCullEntCallback cb, void* cbdata);
void xUpdateCull_Reset(xUpdateCullMgr* m);