#include "zEGenerator.h"

void zEGenerator_Init(void* egen, void* asset) STUB_VOID
void zEGenerator_Init(zEGenerator* egen, xEntAsset* asset) STUB_VOID
void zEGenerator_Save(zEGenerator* ent, xSerial* s) STUB_VOID
void zEGenerator_Load(zEGenerator* ent, xSerial* s) STUB_VOID
void zEGenerator_Reset(zEGenerator* egen, xScene*) STUB_VOID
void zEGenerator_Move(zEGenerator*, xScene*, float32) STUB_VOID
void zEGenerator_Update(zEGenerator* egen, xScene* sc, float32 dt) STUB_VOID
void zEGenerator_Render(zEGenerator* egen) STUB_VOID
void zEGenerator_TurnOn(zEGenerator* egen) STUB_VOID
void zEGenerator_TurnOff(zEGenerator*) STUB_VOID
bool32 zEGeneratorEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase* toParamWidget) STUB