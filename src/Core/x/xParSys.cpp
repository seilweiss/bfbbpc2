#include "xParSys.h"

inline bool using_ptank_render(const xParSysAsset&) STUB

static void par_sprite_begin() STUB_VOID
static void par_sprite_update(xParSys& sys, xParGroup& group) STUB_VOID
static void render_par_sprite(void* data, xParGroup* ps) STUB_VOID
void xParCmdTexInit(xParCmdTex*) STUB_VOID
void xParSysInit(void* b, void* tasset) STUB_VOID
void xParSysInit(xBase* b, xParSysAsset* tasset) STUB_VOID
void xParSysSetup(xParSys* t) STUB_VOID
void xParSysReset(xParSys*) STUB_VOID
void xParSysExit(xParSys* t) STUB_VOID
bool32 xParSysEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
void xParSysUpdate(xBase* to, xScene*, float32 dt) STUB_VOID
static void xParGroupUpdateR(xParSys* s, xParGroup* g, float32 dt) STUB_VOID
static void xParGroupUpdate(xParSys*, xParGroup*, float32) STUB_VOID
void xParSysRender(xBase* b) STUB_VOID