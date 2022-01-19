#include "xCounter.h"

namespace { void add_tweaks(xCounter&) {} }
void xCounterInit() STUB_VOID
void xCounterInit(void* b, void* asset) STUB_VOID
void xCounterInit(xCounter* b, xCounterAsset* asset) STUB_VOID
void xCounterReset(xBase* b) STUB_VOID
void xCounterSave(xCounter* ent, xSerial* s) STUB_VOID
void xCounterLoad(xCounter* ent, xSerial* s) STUB_VOID
bool32 xCounterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB