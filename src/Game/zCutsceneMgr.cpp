#include "zCutsceneMgr.h"

void zCutsceneMgrInit(void* b, void* tasset) STUB_VOID
void zCutsceneMgrInit(xBase*, xCutsceneMgrAsset*) STUB_VOID
void zCutsceneMgrReset(zCutsceneMgr*) STUB_VOID
void zCutsceneMgrSave(zCutsceneMgr*, xSerial* s) STUB_VOID
void zCutsceneMgrLoad(zCutsceneMgr*, xSerial* s) STUB_VOID
static RpAtomic* HackBoundCB(RpAtomic* atomic, void* data) STUB
static RpMaterial* HackAlphaSetMaterialAlphaCB(RpMaterial* material, void* data) STUB
static RpAtomic* HackAlphaCB(RpAtomic* atomic, void* data) STUB
void zCutSceneNamesTable_clearAll() STUB_VOID
static void zCutsceneMgrPlayStart(zCutsceneMgr* t) STUB_VOID
bool32 zCutsceneMgrEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB
void zCutsceneMgrFinishLoad(xBase* to) STUB_VOID
void zCutsceneMgrFinishExit(xBase* to) STUB_VOID
static void zCutsceneMgrKillFX(zCutsceneMgr*) STUB_VOID
static void zCutsceneMgrUpdateFX(zCutsceneMgr* t, float32) STUB_VOID
void zCutsceneMgrUpdate(xBase* to, xScene* sc, float32 dt) STUB_VOID
static void check_hide_entities() STUB_VOID