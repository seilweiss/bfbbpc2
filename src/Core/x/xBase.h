#pragma once

#include <types.h>

struct xBase;
struct xSerial;

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

void xBaseInit(xBase* xb, xBaseAsset* asset);
void xBaseSetup(xBase*);
void xBaseSave(xBase* ent, xSerial* s);
void xBaseLoad(xBase* ent, xSerial* s);
void xBaseReset(xBase* xb, xBaseAsset* asset);

inline void xBaseValidate(xBase*) STUB_VOID
inline bool xBaseIsEnabled(const xBase*) STUB
inline void xBaseDisable(xBase*) STUB_VOID
inline void xBaseEnable(xBase*) STUB_VOID
inline uint32 xBaseIsValid(xBase*) STUB