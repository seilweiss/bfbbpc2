#include "xUpdateCull.h"

static void xUpdateCull_Swap(xUpdateCullMgr* m, uint32 a, uint32 b) STUB_VOID
static void xUpdateCull_MakeActive(xUpdateCullMgr*, xUpdateCullEnt*) STUB_VOID
static void xUpdateCull_MakeInactive(xUpdateCullMgr*, xUpdateCullEnt*) STUB_VOID
uint32 xUpdateCull_AlwaysTrueCB(void*, void*) WIP { return 1; }
uint32 xUpdateCull_DistanceSquaredCB(void* ent, void* cbdata) STUB
xUpdateCullMgr* xUpdateCull_Init(void** ent, uint32 entCount, xGroup** group, uint32 groupCount) STUB
void xUpdateCull_Update(xUpdateCullMgr* m, uint32 percent_update) STUB_VOID
void xUpdateCull_SetCB(xUpdateCullMgr* m, void* entity, xUpdateCullEntCallback cb, void* cbdata) STUB_VOID
void xUpdateCull_Reset(xUpdateCullMgr* m) STUB_VOID