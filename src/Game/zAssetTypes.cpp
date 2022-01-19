#include "zAssetTypes.h"

#include "xJSP.h"
#include "xAnim.h"

void zAssetStartup() STUB_VOID
void zAssetShutdown() STUB_VOID
static void* Model_Read(void*, uint32 assetid, void* indata, uint32 insize, uint32* outsize) STUB
static void* Curve_Read(void*, uint32, void* indata, uint32 insize, uint32* outsize) STUB
static void Model_Unload(void* userdata, uint32) STUB_VOID
static void* BSP_Read(void*, uint32, void* indata, uint32 insize, uint32* outsize) STUB
static void BSP_Unload(void*, uint32) STUB_VOID
static RpAtomic* jsp_shadow_hack_atomic_cb(RpAtomic* atomic, void* data) STUB
bool jsp_shadow_hack_match(RpAtomic*) STUB
static void jsp_shadow_hack(xJSPHeader*) STUB_VOID
static void* JSP_Read(void*, uint32, void* indata, uint32 insize, uint32* outsize) STUB
static void JSP_Unload(void* userdata, uint32) STUB_VOID
static RwTexture* TexCB(RwTexture* texture, void* data) STUB
static void* RWTX_Read(void*, uint32, void* indata, uint32 insize, uint32* outsize) STUB
static void TextureRW3_Unload(void* userdata, uint32) STUB_VOID
static void ATBL_Init() STUB_VOID
void FootstepHackSceneEnter() STUB_VOID
static uint32 dummyEffectCB(uint32, xAnimActiveEffect*, xAnimSingle*, void*) STUB
static uint32 soundEffectCB(uint32 cbenum, xAnimActiveEffect* acteffect, xAnimSingle*, void* object) STUB
static void* FindAssetCB(uint32 ID, char*) STUB
static void* ATBL_Read(void*, uint32, void* indata, uint32, uint32* outsize) STUB
static void Anim_Unload(void*, uint32) STUB_VOID
static void LightKit_Unload(void* userdata, uint32) STUB_VOID
static xAnimTable* Anim_ATBL_getTable(xAnimTableConstructor) STUB
static void MovePoint_Unload(void* userdata, uint32) STUB_VOID
static void* SndInfoRead(void*, uint32, void*, uint32, uint32*) STUB