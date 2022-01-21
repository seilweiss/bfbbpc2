#include "zUI.h"

#include "zUIFont.h"

namespace {

	void refresh_model(zUI&) STUB_VOID;
	void init_tweaks() {}
	void debug_update(zScene&, float32) {}
	void debug_render() {}

}

void zUIMgr::PreUpdate(zScene* s, float32 dt) STUB_VOID
void zUIMgr::Update(zScene* s, float32 dt) STUB_VOID
void zUIMgr::Setup(zScene* s) STUB_VOID
void zUIMgr::Touch(zUI* ui) STUB_VOID
void zUIMgr::Remove(zUI* ui) STUB_VOID
void zUIMgr::Remove_PreUpdate(zUI*) STUB_VOID
void zUIMgr::Remove_Update(zUI*) STUB_VOID
void zUIMgr::Add(zUI*) STUB_VOID
void zUIMgr::Add_PreUpdate(zUI*) STUB_VOID
void zUIMgr::Add_Update(zUI*) STUB_VOID
void zUI_Init() STUB_VOID
void zUI_Init(void* ent, void* asset) STUB_VOID

namespace {

	xModelInstance* load_model(uint32) STUB;
	void load_anim_list(zUI& ui) STUB_VOID;

}

void zUI_Init(zUI* ent, xEntAsset* asset) STUB_VOID
void zUI_Save(zUI* ent, xSerial* s) STUB_VOID
void zUI_Load(zUI* ent, xSerial* s) STUB_VOID
void zUI_Reset(zUI* ent) STUB_VOID
void zUI_PreUpdate(zUI* ent, xScene*, float32) STUB_VOID
void zUI_Update(zUI* ent, xScene*, float32 dt) STUB_VOID
static xBase* zUIRenderIteratorInsert(xBase* b, zScene*, void*) STUB
int32 iRenderQSort_Face(const void* arg1, const void* arg2) STUB
void zUIRenderAll() STUB_VOID
void zUI_Render(xEnt* ent) STUB_VOID
bool32 zUIEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB
void zUI_ParseINI(xIniFile* ini) STUB_VOID
static zUI* findUI(zScene*, uint32) STUB
static zUIFont* findUIFont(zScene*, uint32) STUB
bool32 zUIPortalEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void zUI_ScenePortalSetToCurrentLevel(zScene* zsc) STUB_VOID
static void init_patsocks(zScene*) STUB_VOID
void zUI_ScenePortalInit(zScene* zsc) STUB_VOID
static void hideWorld() STUB_VOID
static void showWorld(uint32) STUB_VOID
static void disable_ui(zUI*) STUB_VOID
static void enable_ui(zUI*) STUB_VOID
static void refresh_patsocks(uint32 world) STUB_VOID
void zUI_PortalToKrabs(uint32 taskNum) STUB_VOID
void zUI_ScenePortalUpdate() STUB_VOID
void zUI_ScenePortalSave(xSerial* s) STUB_VOID
void zUI_ScenePortalLoad(xSerial* s) STUB_VOID