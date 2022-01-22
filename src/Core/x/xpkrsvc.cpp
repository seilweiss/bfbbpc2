#include "xpkrsvc.h"

st_PACKER_READ_FUNCS* PKRGetReadFuncs(int32 apiver) STUB
int32 PKRStartup() STUB
int32 PKRShutdown() STUB
bool32 PKRLoadStep() STUB
static st_PACKER_READ_DATA* PKR_ReadInit(void* userdata, char* pkgfile, uint32 opts, int32* cltver, st_PACKER_ASSETTYPE* typelist) STUB
static void PKR_ReadDone(st_PACKER_READ_DATA* pr) STUB_VOID
static bool32 PKR_SetActive(st_PACKER_READ_DATA* pr, en_LAYER_TYPE layer) STUB
static bool32 PKR_parse_TOC(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 PKR_LoadStep_Async() STUB
static char* PKR_LayerMemReserve(st_PACKER_READ_DATA* pr, st_PACKER_LTOC_NODE* layer) STUB
static void PKR_LayerMemRelease(st_PACKER_LTOC_NODE* layer) STUB_VOID
void PKR_drv_guardLayer(st_PACKER_LTOC_NODE*) {}
en_READ_ASYNC_STATUS PKR_drv_guardVerify(st_PACKER_LTOC_NODE*) STUB
static en_PKR_LAYER_LOAD_DEST PKR_layerLoadDest(en_LAYER_TYPE) STUB
static bool32 PKR_layerTypeNeedsXForm(en_LAYER_TYPE) STUB
static bool32 PKR_findNextLayerToLoad(st_PACKER_READ_DATA** work_on_pkg, st_PACKER_LTOC_NODE** next_layer) STUB
static void PKR_updateLayerAssets(st_PACKER_LTOC_NODE* laynode) STUB_VOID
static void PKR_xformLayerAssets(st_PACKER_LTOC_NODE* laynode) STUB_VOID
static void PKR_xform_asset(st_PACKER_ATOC_NODE* assnode, bool32 dumpable_layer) STUB_VOID
static void* PKR_FindAsset(st_PACKER_READ_DATA* pr, uint32 aid) STUB
static bool32 PKR_LoadLayer(st_PACKER_READ_DATA*, en_LAYER_TYPE) STUB
static void* PKR_LoadAsset(st_PACKER_READ_DATA* pr, uint32 aid, const char*, void*) STUB
static uint32 PKR_GetAssetSize(st_PACKER_READ_DATA* pr, uint32 aid) STUB
static int32 PKR_AssetCount(st_PACKER_READ_DATA* pr, uint32 type) STUB
static void* PKR_AssetByType(st_PACKER_READ_DATA* pr, uint32 type, int32 idx, uint32* size) STUB
static bool32 PKR_IsAssetReady(st_PACKER_READ_DATA* pr, uint32 aid) STUB
static uint32 PKR_getPackTimestamp(st_PACKER_READ_DATA* pr) STUB
static void PKR_Disconnect(st_PACKER_READ_DATA* pr) STUB_VOID
uint32 PKRAssetIDFromInst(void* asset_inst) STUB
static char* PKR_AssetName(st_PACKER_READ_DATA* pr, uint32 aid) STUB
static uint32 PKR_GetBaseSector(st_PACKER_READ_DATA* pr) STUB
static bool32 PKR_GetAssetInfo(st_PACKER_READ_DATA* pr, uint32 aid, st_PKR_ASSET_TOCINFO* tocinfo) STUB
static bool32 PKR_GetAssetInfoByType(st_PACKER_READ_DATA* pr, uint32 type, int32 idx, st_PKR_ASSET_TOCINFO* tocinfo) STUB
static bool32 PKR_PkgHasAsset(st_PACKER_READ_DATA* pr, uint32 aid) STUB
static bool32 PKR_FRIEND_assetIsGameDup(uint32 aid, const st_PACKER_READ_DATA* skippr, int32 oursize, uint32 ourtype, uint32 chksum, char*) STUB
static bool32 PKR_makepool_anode(st_PACKER_READ_DATA*, int32) STUB
static void PKR_kiilpool_anode(st_PACKER_READ_DATA*) STUB_VOID
static st_PACKER_ATOC_NODE* PKR_newassnode(st_PACKER_READ_DATA*, uint32) STUB
static st_PACKER_LTOC_NODE* PKR_newlaynode(en_LAYER_TYPE, int32) STUB
static void PKR_oldlaynode(st_PACKER_LTOC_NODE*) STUB_VOID
static int32 OrdComp_R_Asset(void* vkey, void* vitem) STUB
static int32 OrdTest_R_AssetID(const void* vkey, void* vitem) STUB
static bool32 LOD_r_HIPA(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_PACK(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_PVER(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_PFLG(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_PCNT(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_PCRT(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_PMOD(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 ValidatePlatform(st_HIPLOADDATA*, st_PACKER_READ_DATA*, int32, char* plat, char* vid, char* lang, char* title) STUB
static bool32 LOD_r_PLAT(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_DICT(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_ATOC(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_AINF(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_AHDR(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_ADBG(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr, st_PACKER_ATOC_NODE* assnode) STUB
static bool32 LOD_r_LTOC(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_LINF(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_LHDR(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA* pr) STUB
static bool32 LOD_r_LDBG(st_HIPLOADDATA*, st_PACKER_READ_DATA*, st_PACKER_LTOC_NODE*) STUB
static bool32 LOD_r_STRM(st_HIPLOADDATA* pkg, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_DHDR(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static bool32 LOD_r_DPAK(st_HIPLOADDATA*, st_PACKER_READ_DATA*) STUB
static void PKR_spew_verhist() {}
static st_PACKER_ASSETTYPE* PKR_type2typeref(uint32 type, st_PACKER_ASSETTYPE* typelist) STUB
static void PKR_bld_typecnt(st_PACKER_READ_DATA* pr) STUB_VOID
static int32 PKR_typeHdlr_idx(st_PACKER_READ_DATA*, uint32) STUB
static void PKR_alloc_chkidx() {}
static void* PKR_getmem(uint32 id, int32 amount, uint32, int32 align) STUB
static void* PKR_getmem(uint32 id, int32 amount, uint32, int32 align, bool32 isTemp, char** memtru) STUB
static void PKR_relmem(uint32 id, int32 blksize, void* memptr, uint32, bool32 isTemp) STUB_VOID
static void PKR_push_memmark();
static void PKR_pop_memmark();