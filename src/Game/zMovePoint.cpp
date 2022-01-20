#include "zMovePoint.h"

zMovePoint* zMovePoint_GetMemPool(int32 cnt) STUB
void zMovePointInit(zMovePoint* m, xMovePointAsset* asset) STUB_VOID
zMovePoint* zMovePoint_GetInst(int32 n) STUB
void zMovePointSetup(zMovePoint* mvpt, zScene* scn) STUB_VOID
zMovePoint* zMovePoint_From_xAssetID(uint32 aid) STUB
void zMovePointSave(zMovePoint* ent, xSerial* s) STUB_VOID
void zMovePointLoad(zMovePoint* ent, xSerial* s) STUB_VOID
void zMovePointReset(zMovePoint*) STUB_VOID
bool32 zMovePointEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB
float32 zMovePointGetNext(const zMovePoint* current, const zMovePoint* prev, zMovePoint** next, xVec3* hdng) STUB
xVec3* zMovePointGetPos(const zMovePoint* m) STUB
float32 zMovePointGetDelay(const zMovePoint* m) STUB