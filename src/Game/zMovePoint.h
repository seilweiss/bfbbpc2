#pragma once

#include "xMovePoint.h"

struct zScene;

struct zMovePoint : xMovePoint
{
};

zMovePoint* zMovePoint_GetMemPool(int32 cnt);
void zMovePointInit(zMovePoint* m, xMovePointAsset* asset);
zMovePoint* zMovePoint_GetInst(int32 n);
void zMovePointSetup(zMovePoint* mvpt, zScene* scn);
zMovePoint* zMovePoint_From_xAssetID(uint32 aid);
void zMovePointSave(zMovePoint* ent, xSerial* s);
void zMovePointLoad(zMovePoint* ent, xSerial* s);
void zMovePointReset(zMovePoint*);
bool32 zMovePointEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*);
float32 zMovePointGetNext(const zMovePoint* current, const zMovePoint* prev, zMovePoint** next, xVec3* hdng);
xVec3* zMovePointGetPos(const zMovePoint* m);
float32 zMovePointGetDelay(const zMovePoint* m);