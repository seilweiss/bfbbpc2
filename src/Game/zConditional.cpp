#include "zConditional.h"

void zConditionalInit(void* b, void* asset) STUB_VOID
void zConditionalInit(xBase*, zCondAsset*) STUB_VOID
void zConditionalReset(zConditional*) STUB_VOID
void zConditionalSave(zConditional* ent, xSerial* s) STUB_VOID
void zConditionalLoad(zConditional* ent, xSerial* s) STUB_VOID
uint32 zConditional_Evaluate(zConditional* c) STUB
bool32 zConditionalEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB