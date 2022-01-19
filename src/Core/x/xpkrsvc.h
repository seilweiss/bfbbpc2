#pragma once

#include "xhipio.h"
#include "xordarray.h"

#include <time.h>

struct st_PACKER_READ_DATA;

typedef enum en_LAYER_TYPE
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
} LAYER_TYPE;

typedef enum en_PKR_LAYER_LOAD_DEST
{
	PKR_LDDEST_SKIP,
	PKR_LDDEST_KEEPSTATIC,
	PKR_LDDEST_KEEPMALLOC,
	PKR_LDDEST_RWHANDOFF,
	PKR_LDDEST_NOMORE,
	PKR_LDDEST_FORCE = FORCEENUMSIZEINT
} PKR_LAYER_LOAD_DEST;

typedef struct st_PACKER_ASSETTYPE
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
} PACKER_ASSETTYPE;

typedef struct st_PACKER_ATOC_NODE
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
	PACKER_ASSETTYPE* typeref;
	HIPLOADDATA* ownpkg;
	st_PACKER_READ_DATA* ownpr;
	char basename[32];

	char* Name() const { return "<unknown>"; }
} PACKER_ATOC_NODE;

typedef struct st_PACKER_LTOC_NODE
{
	LAYER_TYPE laytyp;
	XORDEREDARRAY assref;
	int32 flg_ldstat;
	int32 danglecnt;
	uint32 chksum;
	int32 laysize;
	char* laymem;
	char* laytru;
} PACKER_LTOC_NODE;

typedef struct st_PACKER_READ_DATA
{
	PACKER_ASSETTYPE* types;
	void* userdata;
	uint32 opts;
	uint32 pkgver;
	int32 cltver;
	int32 subver;
	int32 compatver;
	HIPLOADDATA* pkg;
	uint32 base_sector;
	int32 lockid;
	char packfile[128];
	int32 asscnt;
	int32 laycnt;
	XORDEREDARRAY asstoc;
	XORDEREDARRAY laytoc;
	PACKER_ATOC_NODE* pool_anode;
	int32 pool_nextaidx;
	XORDEREDARRAY typelist[129];
	time_t time_made;
	time_t time_mod;
} PACKER_READ_DATA;

typedef struct st_PKR_ASSET_TOCINFO
{
	uint32 aid;
	PACKER_ASSETTYPE* typeref;
	uint32 sector;
	uint32 plus_offset;
	uint32 size;
	void* mempos;
} PKR_ASSET_TOCINFO;

typedef struct st_PACKER_READ_FUNCS
{
	uint32 api_ver;
	PACKER_READ_DATA* (*Init)(void* userdata, char* pkgfile, uint32 opts, int32* cltver, PACKER_ASSETTYPE* typelist);
	void(*Done)(PACKER_READ_DATA* pr);
	bool32(*LoadLayer)(PACKER_READ_DATA*, LAYER_TYPE);
	uint32(*GetAssetSize)(PACKER_READ_DATA* pr, uint32 aid);
	void* (*LoadAsset)(PACKER_READ_DATA* pr, uint32 aid, char*, void*);
	void* (*AssetByType)(PACKER_READ_DATA* pr, uint32 type, int32 idx, uint32* size);
	int32(*AssetCount)(PACKER_READ_DATA* pr, uint32 type);
	bool32(*IsAssetReady)(PACKER_READ_DATA* pr, uint32 aid);
	bool32(*SetActive)(PACKER_READ_DATA* pr, LAYER_TYPE layer);
	char* (*AssetName)(PACKER_READ_DATA* pr, uint32 aid);
	uint32(*GetBaseSector)(PACKER_READ_DATA* pr);
	bool32(*GetAssetInfo)(PACKER_READ_DATA* pr, uint32 aid, PKR_ASSET_TOCINFO* tocinfo);
	bool32(*GetAssetInfoByType)(PACKER_READ_DATA* pr, uint32 type, int32 idx, PKR_ASSET_TOCINFO* tocinfo);
	bool32(*PkgHasAsset)(PACKER_READ_DATA* pr, uint32 aid);
	uint32(*PkgTimeStamp)(PACKER_READ_DATA* pr);
	void(*PkgDisconnect)(PACKER_READ_DATA* pr);
} PACKER_READ_FUNCS;

PACKER_READ_FUNCS* PKRGetReadFuncs(int32 apiver);
int32 PKRStartup();
int32 PKRShutdown();
bool32 PKRLoadStep();
void PKR_drv_guardLayer(PACKER_LTOC_NODE*);
READ_ASYNC_STATUS PKR_drv_guardVerify(PACKER_LTOC_NODE*);
uint32 PKRAssetIDFromInst(void* asset_inst);