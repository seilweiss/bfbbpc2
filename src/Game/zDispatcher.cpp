#include "zDispatcher.h"

struct zScene;

struct st_ZDISPATCH_CONTEXT
{
	en_DISPATCH_COMMAND cmd;
	void* indata;
	void* inxtra;
	void* result;
};

void zDispatcher_Startup() STUB_VOID
void zDispatcher_Shutdown() STUB_VOID
void zDispatcher_scenePrepare() STUB_VOID
void zDispatcher_sceneFinish() STUB_VOID
st_ZDISPATCH_DATA* zDispatcher_memPool(int32 cnt) STUB
st_ZDISPATCH_DATA* zDispatcher_getInst(st_ZDISPATCH_DATA* pool, int32 idx) STUB
void zDispatcher_Init(st_ZDISPATCH_DATA* dspdata, xBaseAsset* bass) STUB_VOID
void zDispatcher_InitDep(st_ZDISPATCH_DATA* dspdata) STUB_VOID
void zDispatcher_Save(st_ZDISPATCH_DATA* dspdata, xSerial* s) STUB_VOID
void zDispatcher_Load(st_ZDISPATCH_DATA* dspdata, xSerial* s) STUB_VOID
static void ZDSP_instInit(st_ZDISPATCH_DATA*, xBaseAsset*) STUB_VOID
static void ZDSP_instInitDep(st_ZDISPATCH_DATA*, zScene*) STUB_VOID
static void ZDSP_instReset(st_ZDISPATCH_DATA*, zScene*) STUB_VOID
static void ZDSP_readAsset(st_ZDISPATCH_DATA*) STUB_VOID
bool32 ZDSP_injectCmd(st_ZDISPATCH_DATA*, en_DISPATCH_COMMAND) STUB
bool32 ZDSP_injectCmd(st_ZDISPATCH_DATA*, en_DISPATCH_COMMAND, int32) STUB
bool32 ZDSP_injectCmd(st_ZDISPATCH_DATA*, en_DISPATCH_COMMAND, void*, void*, void*) STUB
static bool32 ZDSP_doCommand(st_ZDISPATCH_DATA*, st_ZDISPATCH_CONTEXT* cmdCtxt) STUB
void zDispatcherStoreOptions() STUB_VOID
void zDispatcherRestoreOptions() STUB_VOID
static bool32 ZDSP_elcb_event(xBase*, xBase* xb, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
static void WRAP_xsnd_setMusicVolume(int32) STUB_VOID
static void WRAP_xsnd_setSFXVolume(int32) STUB_VOID