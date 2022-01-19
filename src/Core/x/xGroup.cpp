#include "xGroup.h"

void xGroupInit(void* b, void* asset) STUB_VOID
void xGroupInit(xBase*, xGroupAsset*) STUB_VOID
void xGroupSetup(xGroup* g) STUB_VOID
void xGroupSave(xGroup* ent, xSerial* s) STUB_VOID
void xGroupLoad(xGroup* ent, xSerial* s) STUB_VOID
void xGroupReset(xGroup*) STUB_VOID
bool32 xGroupEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
uint32 xGroupGetCount(xGroup* g) STUB
xBase* xGroupGetItemPtr(xGroup* g, uint32 index) STUB
xBase* xGroupFindItemPtr(xGroup*, uint32) STUB
uint32 xGroupGetItem(xGroup* g, uint32 index) STUB
uint32 xGroup::get_any() STUB