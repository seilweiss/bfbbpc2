#pragma once

#include <types.h>

struct xBase;
class xSerial;

typedef bool32(*xBaseEventCallback)(xBase*, xBase*, uint32, const float32*, xBase*);

struct xBaseAsset
{
	uint32 id;
	uint8 baseType;
	uint8 linkCount;
	uint16 baseFlags;
};

struct xLinkAsset
{
	uint16 srcEvent;
	uint16 dstEvent;
	uint32 dstAssetID;
	float32 param[4];
	uint32 paramWidgetAssetID;
	uint32 chkAssetID;
};

struct xBase
{
	uint32 id;
	uint8 baseType;
	uint8 linkCount;
	uint16 baseFlags;
	xLinkAsset* link;
	xBaseEventCallback eventFunc;
};

#define XBASE_ENABLED 0x1
#define XBASE_PERSISTENT 0x2
#define XBASE_VALID 0x4
#define XBASE_CUTSCENEVIS 0x8
#define XBASE_RECSHADOW 0x10
#define XBASE_UNK0x20 0x20

void xBaseInit(xBase* xb, xBaseAsset* asset);
void xBaseSetup(xBase*);
void xBaseSave(xBase* ent, xSerial* s);
void xBaseLoad(xBase* ent, xSerial* s);
void xBaseReset(xBase* xb, xBaseAsset* asset);

inline void xBaseValidate(xBase* xb)
{
	xb->baseFlags |= XBASE_VALID;
}

inline uint32 xBaseIsValid(xBase*) STUB

inline void xBaseEnable(xBase* xb)
{
	xb->baseFlags |= XBASE_ENABLED;
}

inline void xBaseDisable(xBase* xb)
{
	xb->baseFlags &= ~XBASE_ENABLED;
}

inline bool xBaseIsEnabled(const xBase* xb)
{
	return xb->baseFlags & XBASE_ENABLED;
}