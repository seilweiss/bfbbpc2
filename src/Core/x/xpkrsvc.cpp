#include "xpkrsvc.h"

PACKER_READ_FUNCS* PKRGetReadFuncs(int32 apiver) STUB
int32 PKRStartup() STUB
int32 PKRShutdown() STUB
bool32 PKRLoadStep() STUB
static PACKER_READ_DATA* PKR_ReadInit(void* userdata, char* pkgfile, uint32 opts, int32* cltver, PACKER_ASSETTYPE* typelist) STUB
static void PKR_ReadDone(PACKER_READ_DATA* pr) STUB_VOID
static bool32 PKR_SetActive(PACKER_READ_DATA* pr, LAYER_TYPE layer) STUB
static bool32 PKR_parse_TOC(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 PKR_LoadStep_Async() STUB
static char* PKR_LayerMemReserve(PACKER_READ_DATA* pr, PACKER_LTOC_NODE* layer) STUB
static void PKR_LayerMemRelease(PACKER_LTOC_NODE* layer) STUB_VOID
void PKR_drv_guardLayer(PACKER_LTOC_NODE*) {}
READ_ASYNC_STATUS PKR_drv_guardVerify(PACKER_LTOC_NODE*) STUB
static PKR_LAYER_LOAD_DEST PKR_layerLoadDest(LAYER_TYPE) STUB
static bool32 PKR_layerTypeNeedsXForm(LAYER_TYPE) STUB
static bool32 PKR_findNextLayerToLoad(PACKER_READ_DATA** work_on_pkg, PACKER_LTOC_NODE** next_layer) STUB
static void PKR_updateLayerAssets(PACKER_LTOC_NODE* laynode) STUB_VOID
static void PKR_xformLayerAssets(PACKER_LTOC_NODE* laynode) STUB_VOID
static void PKR_xform_asset(PACKER_ATOC_NODE* assnode, bool32 dumpable_layer) STUB_VOID
static void* PKR_FindAsset(PACKER_READ_DATA* pr, uint32 aid) STUB
static bool32 PKR_LoadLayer(PACKER_READ_DATA*, LAYER_TYPE) STUB
static void* PKR_LoadAsset(PACKER_READ_DATA* pr, uint32 aid, const char*, void*) STUB
static uint32 PKR_GetAssetSize(PACKER_READ_DATA* pr, uint32 aid) STUB
static int32 PKR_AssetCount(PACKER_READ_DATA* pr, uint32 type) STUB
static void* PKR_AssetByType(PACKER_READ_DATA* pr, uint32 type, int32 idx, uint32* size) STUB
static bool32 PKR_IsAssetReady(PACKER_READ_DATA* pr, uint32 aid) STUB
static uint32 PKR_getPackTimestamp(PACKER_READ_DATA* pr) STUB
static void PKR_Disconnect(PACKER_READ_DATA* pr) STUB_VOID
uint32 PKRAssetIDFromInst(void* asset_inst) STUB
static char* PKR_AssetName(PACKER_READ_DATA* pr, uint32 aid) STUB
static uint32 PKR_GetBaseSector(PACKER_READ_DATA* pr) STUB
static bool32 PKR_GetAssetInfo(PACKER_READ_DATA* pr, uint32 aid, PKR_ASSET_TOCINFO* tocinfo) STUB
static bool32 PKR_GetAssetInfoByType(PACKER_READ_DATA* pr, uint32 type, int32 idx, PKR_ASSET_TOCINFO* tocinfo) STUB
static bool32 PKR_PkgHasAsset(PACKER_READ_DATA* pr, uint32 aid) STUB
static bool32 PKR_FRIEND_assetIsGameDup(uint32 aid, const PACKER_READ_DATA* skippr, int32 oursize, uint32 ourtype, uint32 chksum, char*) STUB
static bool32 PKR_makepool_anode(PACKER_READ_DATA*, int32) STUB
static void PKR_kiilpool_anode(PACKER_READ_DATA*) STUB_VOID
static PACKER_ATOC_NODE* PKR_newassnode(PACKER_READ_DATA*, uint32) STUB
static PACKER_LTOC_NODE* PKR_newlaynode(LAYER_TYPE, int32) STUB
static void PKR_oldlaynode(PACKER_LTOC_NODE*) STUB_VOID
static int32 OrdComp_R_Asset(void* vkey, void* vitem) STUB
static int32 OrdTest_R_AssetID(const void* vkey, void* vitem) STUB
static bool32 LOD_r_HIPA(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_PACK(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_PVER(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_PFLG(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_PCNT(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_PCRT(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_PMOD(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 ValidatePlatform(HIPLOADDATA*, PACKER_READ_DATA*, int32, char* plat, char* vid, char* lang, char* title) STUB
static bool32 LOD_r_PLAT(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_DICT(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_ATOC(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_AINF(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_AHDR(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_ADBG(HIPLOADDATA* pkg, PACKER_READ_DATA* pr, PACKER_ATOC_NODE* assnode) STUB
static bool32 LOD_r_LTOC(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_LINF(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_LHDR(HIPLOADDATA* pkg, PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_LDBG(HIPLOADDATA*, PACKER_READ_DATA*, PACKER_LTOC_NODE*) STUB
static bool32 LOD_r_STRM(HIPLOADDATA* pkg, PACKER_READ_DATA*) STUB
static bool32 LOD_r_DHDR(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static bool32 LOD_r_DPAK(HIPLOADDATA*, PACKER_READ_DATA*) STUB
static void PKR_spew_verhist() {}
static PACKER_ASSETTYPE* PKR_type2typeref(uint32 type, PACKER_ASSETTYPE* typelist) STUB
static void PKR_bld_typecnt(PACKER_READ_DATA* pr) STUB_VOID
static int32 PKR_typeHdlr_idx(PACKER_READ_DATA*, uint32) STUB
static void PKR_alloc_chkidx() {}
static void* PKR_getmem(uint32 id, int32 amount, uint32, int32 align) STUB
static void* PKR_getmem(uint32 id, int32 amount, uint32, int32 align, bool32 isTemp, char** memtru) STUB
static void PKR_relmem(uint32 id, int32 blksize, void* memptr, uint32, bool32 isTemp) STUB_VOID
static void PKR_push_memmark();
static void PKR_pop_memmark();