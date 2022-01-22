#include "xstransvc.h"

struct st_STRAN_SCENE
{
	uint32 scnid;
	int32 lockid;
	st_PACKER_READ_DATA* spkg;
	bool32 isHOP;
	void* userdata;
	char fnam[256];
};

int32 xSTStartup(st_PACKER_ASSETTYPE* handlers) STUB
int32 xSTShutdown() STUB
int32 xSTPreLoadScene(uint32 sid, void* userdata, int32 flg_hiphop) STUB
int32 xSTQueueSceneAssets(uint32 sid, int32 flg_hiphop) STUB
void xSTUnLoadScene(uint32 sid, int32 flg_hiphop) STUB_VOID
float32 xSTLoadStep(uint32) STUB
void xSTDisconnect(uint32 sid, int32 flg_hiphop) STUB_VOID
int32 xSTSwitchScene(uint32 sid, void* userdata, xSTSwitchSceneProgressMonitor progmon) STUB
char* xSTAssetName(uint32 aid) STUB
char* xSTAssetName(void* raw_HIP_asset) STUB
void* xSTFindAsset(uint32 aid, uint32* size) STUB
int32 xSTAssetCountByType(uint32 type) STUB
void* xSTFindAssetByType(uint32 type, int32 idx, uint32* size) STUB
int32 xSTGetAssetInfo(uint32 aid, st_PKR_ASSET_TOCINFO* tocainfo) STUB
int32 xSTGetAssetInfoByType(uint32 type, int32 idx, st_PKR_ASSET_TOCINFO* ainfo) STUB
int32 xSTGetAssetInfoInHxP(uint32, st_PKR_ASSET_TOCINFO*, uint32) STUB
char* xST_xAssetID_HIPFullPath(uint32 aid) STUB
char* xST_xAssetID_HIPFullPath(uint32 aid, uint32* sceneID) STUB
static int32 XST_PreLoadScene(st_STRAN_SCENE*, const char*) STUB
static char* XST_translate_sid(uint32, char*) STUB
static char* XST_translate_sid_path(uint32, char*) STUB
static void XST_reset_raw() STUB_VOID
static st_STRAN_SCENE* XST_lock_next() STUB
static void XST_unlock(st_STRAN_SCENE*) STUB_VOID
static void XST_unlock_all() STUB_VOID
static st_STRAN_SCENE* XST_get_rawinst(int32) STUB
static int32 XST_cnt_locked() STUB
static st_STRAN_SCENE* XST_nth_locked(int32) STUB
static st_STRAN_SCENE* XST_find_bySID(uint32 sid, bool32 findTheHOP) STUB