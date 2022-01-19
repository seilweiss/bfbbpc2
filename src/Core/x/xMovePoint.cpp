#include "xMovePoint.h"

void xMovePointInit(xMovePoint* m, xMovePointAsset* asset) STUB_VOID
void xMovePointSave(xMovePoint* ent, xSerial* s) STUB_VOID
void xMovePointLoad(xMovePoint* ent, xSerial* s) STUB_VOID
void xMovePointReset(xMovePoint* m) STUB_VOID
void xMovePointSetup(xMovePoint* m, xScene* sc) STUB_VOID
void xMovePointSplineSetup(xMovePoint* m) STUB_VOID
void xMovePointSplineDestroy(xMovePoint* m) STUB_VOID
float32 xMovePointGetNext(const xMovePoint* m, const xMovePoint* prev, xMovePoint** next, xVec3* hdng) STUB
xVec3* xMovePointGetPos(const xMovePoint* m) STUB