#pragma once

#include "xBase.h"
#include "xMath3.h"

struct xSpline3;
struct xScene;

struct xMovePointAsset : xBaseAsset
{
	xVec3 pos;
	uint16 wt;
	uint8 on;
	uint8 bezIndex;
	uint8 flg_props;
	uint8 pad;
	uint16 numPoints;
	float32 delay;
	float32 zoneRadius;
	float32 arenaRadius;
};

struct xMovePoint : xBase
{
	xMovePointAsset* asset;
	xVec3* pos;
	xMovePoint** nodes;
	xMovePoint* prev;
	uint32 node_wt_sum;
	uint8 on;
	uint8 pad[2];
	float32 delay;
	xSpline3* spl;
};

void xMovePointInit(xMovePoint* m, xMovePointAsset* asset);
void xMovePointSave(xMovePoint* ent, xSerial* s);
void xMovePointLoad(xMovePoint* ent, xSerial* s);
void xMovePointReset(xMovePoint* m);
void xMovePointSetup(xMovePoint* m, xScene* sc);
void xMovePointSplineSetup(xMovePoint* m);
void xMovePointSplineDestroy(xMovePoint* m);
float32 xMovePointGetNext(const xMovePoint* m, const xMovePoint* prev, xMovePoint** next, xVec3* hdng);
xVec3* xMovePointGetPos(const xMovePoint* m);

inline uint16 xMovePointGetNumPoints(const xMovePoint*) STUB
inline xMovePoint* xMovePointGetPoint(const xMovePoint*, uint16) STUB
inline float32 xMovePointGetDelay(const xMovePoint*) STUB