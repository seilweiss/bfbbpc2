#pragma once

#include "xpkrsvc.h"

typedef int32(*xSTSwitchSceneProgressMonitor)(void*, float32);

int32 xSTStartup(PACKER_ASSETTYPE* handlers);
int32 xSTShutdown();
int32 xSTPreLoadScene(uint32 sid, void* userdata, int32 flg_hiphop);
int32 xSTQueueSceneAssets(uint32 sid, int32 flg_hiphop);
void xSTUnLoadScene(uint32 sid, int32 flg_hiphop);
float32 xSTLoadStep(uint32);
void xSTDisconnect(uint32 sid, int32 flg_hiphop);
int32 xSTSwitchScene(uint32 sid, void* userdata, xSTSwitchSceneProgressMonitor progmon);
char* xSTAssetName(uint32 aid);
char* xSTAssetName(void* raw_HIP_asset);
void* xSTFindAsset(uint32 aid, uint32* size);
int32 xSTAssetCountByType(uint32 type);
void* xSTFindAssetByType(uint32 type, int32 idx, uint32* size);
int32 xSTGetAssetInfo(uint32 aid, PKR_ASSET_TOCINFO* tocainfo);
int32 xSTGetAssetInfoByType(uint32 type, int32 idx, PKR_ASSET_TOCINFO* ainfo);
int32 xSTGetAssetInfoInHxP(uint32, PKR_ASSET_TOCINFO*, uint32);
char* xST_xAssetID_HIPFullPath(uint32 aid);
char* xST_xAssetID_HIPFullPath(uint32 aid, uint32* sceneID);
