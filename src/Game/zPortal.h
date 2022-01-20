#pragma once

#include "xBase.h"

struct xPortalAsset : xBaseAsset
{
	uint32 assetCameraID;
	uint32 assetMarkerID;
	float32 ang;
	uint32 sceneID;
};

typedef struct _zPortal : xBase
{
	xPortalAsset* passet;
} zPortal;

void zPortalInit(void* portal, void* passet);
void zPortalInit(zPortal*, xPortalAsset*);
void zPortalReset(zPortal*);
void zPortalSave(zPortal* ent, xSerial* s);
void zPortalLoad(zPortal* ent, xSerial* s);
bool32 zPortalEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);