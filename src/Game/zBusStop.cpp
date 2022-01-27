#include "zBusStop.h"

void zBusStop_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void zBusStop_Init(zBusStop* bstop, busstop_asset* asset) STUB_VOID
void zBusStop_Setup(zBusStop* bstop) STUB_VOID
void zBusStop_Update(xBase* to, xScene*, float32 dt) STUB_VOID
bool32 zBusStopEventCB(xBase*, xBase*, uint32, const float32*, xBase*) { return TRUE; }