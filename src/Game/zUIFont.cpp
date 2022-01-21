#include "zUIFont.h"

static void set_text(zUIFont&, uint32) STUB_VOID
static uint16 zUIFont_GetHackFlags(zUIFont*) STUB
void zUIFontInit() STUB_VOID
void zUIFont_Init(void* ent, void* asset) STUB_VOID
void zUIFont_Init(zUIFont* ent, xEntAsset* asset) STUB_VOID
void zUIFont_Save(zUIFont* ent, xSerial* s) STUB_VOID
void zUIFont_Load(zUIFont* ent, xSerial* s) STUB_VOID
void zUIFont_Reset(zUIFont*) STUB_VOID
void zUIFont_PreUpdate(zUIFont* ent, xScene* sc, float32 dt) STUB_VOID
void zUIFont_Update(zUIFont* ent, xScene*, float32) STUB_VOID
bool32 zUIFontEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void zUIFont_Render(xEnt* e) STUB_VOID