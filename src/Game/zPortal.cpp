#include "zPortal.h"

void zPortalInit(void* portal, void* passet) STUB_VOID
void zPortalInit(zPortal*, xPortalAsset*) STUB_VOID
void zPortalReset(zPortal*) STUB_VOID
void zPortalSave(zPortal* ent, xSerial* s) STUB_VOID
void zPortalLoad(zPortal* ent, xSerial* s) STUB_VOID
bool32 zPortalEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB