#pragma once

#include "xhipio.h"
#include "xordarray.h"

#include <time.h>

struct st_PACKER_READ_DATA;

enum en_LAYER_TYPE
{
	PKR_LTYPE_ALL = -1,
	PKR_LTYPE_DEFAULT = 0,
	PKR_LTYPE_TEXTURE,
	PKR_LTYPE_BSP,
	PKR_LTYPE_MODEL,
	PKR_LTYPE_ANIMATION,
	PKR_LTYPE_VRAM,
	PKR_LTYPE_SRAM,
	PKR_LTYPE_SNDTOC,
	PKR_LTYPE_CUTSCENE,
	PKR_LTYPE_CUTSCENETOC,
	PKR_LTYPE_JSPINFO,
	PKR_LTYPE_NOMORE
};

enum en_PKR_LAYER_LOAD_DEST
{
	PKR_LDDEST_SKIP,
	PKR_LDDEST_KEEPSTATIC,
	PKR_LDDEST_KEEPMALLOC,
	PKR_LDDEST_RWHANDOFF,
	PKR_LDDEST_NOMORE,
	PKR_LDDEST_FORCE = FORCEENUMSIZEINT
};

struct st_PACKER_ASSETTYPE
{
	uint32 typetag;
	uint32 tflags;
	int32 typalign;
	void* (*readXForm)(void*, uint32, void*, uint32, uint32*);
	void* (*writeXForm)(void*, uint32, void*, void*, uint32, uint32*);
	int32(*assetLoaded)(void*, uint32, void*, int32);
	void* (*makeData)(void*, uint32, void*, int32*, int32*);
	void(*cleanup)(void*, uint32, void*);
	void(*assetUnloaded)(void*, uint32);
	void(*writePeek)(void*, uint32, void*, char*);
};

struct st_PACKER_ATOC_NODE
{
	uint32 aid;
	uint32 asstype;
	int32 d_off;
	int32 d_size;
	int32 d_pad;
	uint32 d_chksum;
	int32 assalign;
	int32 infoflag;
	int32 loadflag;
	char* memloc;
	int32 x_size;
	int32 readcnt;
	int32 readrem;
	st_PACKER_ASSETTYPE* typeref;
	st_HIPLOADDATA* ownpkg;
	st_PACKER_READ_DATA* ownpr;
	char basename[32];

	char* Name() const { return "<unknown>"; }
};

struct st_PACKER_LTOC_NODE
{
	en_LAYER_TYPE laytyp;
	st_XORDEREDARRAY assref;
	int32 flg_ldstat;
	int32 danglecnt;
	uint32 chksum;
	int32 laysize;
	char* laymem;
	char* laytru;
};

struct st_PACKER_READ_DATA
{
	st_PACKER_ASSETTYPE* types;
	void* userdata;
	uint32 opts;
	uint32 pkgver;
	int32 cltver;
	int32 subver;
	int32 compatver;
	st_HIPLOADDATA* pkg;
	uint32 base_sector;
	int32 lockid;
	char packfile[128];
	int32 asscnt;
	int32 laycnt;
	st_XORDEREDARRAY asstoc;
	st_XORDEREDARRAY laytoc;
	st_PACKER_ATOC_NODE* pool_anode;
	int32 pool_nextaidx;
	st_XORDEREDARRAY typelist[129];
	time_t time_made;
	time_t time_mod;
};

struct st_PKR_ASSET_TOCINFO
{
	uint32 aid;
	st_PACKER_ASSETTYPE* typeref;
	uint32 sector;
	uint32 plus_offset;
	uint32 size;
	void* mempos;
};

struct st_PACKER_READ_FUNCS
{
	uint32 api_ver;
	st_PACKER_READ_DATA* (*Init)(void* userdata, char* pkgfile, uint32 opts, int32* cltver, st_PACKER_ASSETTYPE* typelist);
	void(*Done)(st_PACKER_READ_DATA* pr);
	bool32(*LoadLayer)(st_PACKER_READ_DATA*, en_LAYER_TYPE);
	uint32(*GetAssetSize)(st_PACKER_READ_DATA* pr, uint32 aid);
	void* (*LoadAsset)(st_PACKER_READ_DATA* pr, uint32 aid, char*, void*);
	void* (*AssetByType)(st_PACKER_READ_DATA* pr, uint32 type, int32 idx, uint32* size);
	int32(*AssetCount)(st_PACKER_READ_DATA* pr, uint32 type);
	bool32(*IsAssetReady)(st_PACKER_READ_DATA* pr, uint32 aid);
	bool32(*SetActive)(st_PACKER_READ_DATA* pr, en_LAYER_TYPE layer);
	char* (*AssetName)(st_PACKER_READ_DATA* pr, uint32 aid);
	uint32(*GetBaseSector)(st_PACKER_READ_DATA* pr);
	bool32(*GetAssetInfo)(st_PACKER_READ_DATA* pr, uint32 aid, st_PKR_ASSET_TOCINFO* tocinfo);
	bool32(*GetAssetInfoByType)(st_PACKER_READ_DATA* pr, uint32 type, int32 idx, st_PKR_ASSET_TOCINFO* tocinfo);
	bool32(*PkgHasAsset)(st_PACKER_READ_DATA* pr, uint32 aid);
	uint32(*PkgTimeStamp)(st_PACKER_READ_DATA* pr);
	void(*PkgDisconnect)(st_PACKER_READ_DATA* pr);
};

st_PACKER_READ_FUNCS* PKRGetReadFuncs(int32 apiver);
int32 PKRStartup();
int32 PKRShutdown();
bool32 PKRLoadStep();
void PKR_drv_guardLayer(st_PACKER_LTOC_NODE*);
en_READ_ASYNC_STATUS PKR_drv_guardVerify(st_PACKER_LTOC_NODE*);
uint32 PKRAssetIDFromInst(void* asset_inst);