#pragma once

#include "iTime.h"

struct st_XSAVEGAME_DATA;
struct st_ISGSESSION;
struct st_XSAVEGAME_WRITECONTEXT;
struct st_XSAVEGAME_READCONTEXT;

typedef bool32(*XSAVEGAME_CLIENT_INFOFUNC)(void*, st_XSAVEGAME_DATA*, int32*, int32*);
typedef bool32(*XSAVEGAME_CLIENT_PROCFUNC)(void*, st_XSAVEGAME_DATA*, st_XSAVEGAME_WRITECONTEXT*);
typedef bool32(*XSAVEGAME_CLIENT_LOADFUNC)(void*, st_XSAVEGAME_DATA*, st_XSAVEGAME_READCONTEXT*, uint32, int32);

typedef enum en_SAVEGAME_MODE
{
	XSG_MODE_LOAD = 10,
	XSG_MODE_SAVE = 11
} SAVEGAME_MODE;

typedef enum en_XSGASYNC_STATUS
{
	XSG_ASTAT_NOOP,
	XSG_ASTAT_INPROG,
	XSG_ASTAT_SUCCESS,
	XSG_ASTAT_FAILED
} XSGASYNC_STATUS;

typedef enum en_XSG_WHYFAIL
{
	XSG_WHYERR_NONE,
	XSG_WHYERR_NOCARD,
	XSG_WHYERR_NOROOM,
	XSG_WHYERR_DAMAGE,
	XSG_WHYERR_CARDYANKED,
	XSG_WHYERR_OTHER,
	XSG_WHYERR_NOMORE
} XSG_WHYFAIL;

typedef struct st_XSAVEGAME_WRITECONTEXT
{
} XSAVEGAME_WRITECONTEXT;

typedef struct st_XSAVEGAME_READCONTEXT
{
} XSAVEGAME_READCONTEXT;

typedef struct st_XSAVEGAME_CLIENT
{
	uint32 idtag;
	XSAVEGAME_CLIENT_INFOFUNC cltinfo;
	XSAVEGAME_CLIENT_PROCFUNC cltproc;
	XSAVEGAME_CLIENT_LOADFUNC cltload;
	void* cltdata;
	int32 needamt;
	int32 maxamt;
	int32 realamt;
	char* buf_sizepos;
	char* buf_maxpos;
	int32 blokact;
	int32 blokmax;
	char* blokpos;
	char* readpos;
	int32 readamt;
	int32 readremain;
} XSAVEGAME_CLIENT;

typedef struct st_XSAVEGAME_DATA
{
	int32 gfile_idx;
	SAVEGAME_MODE mode;
	uint32 stage;
	int32 gslot;
	char label[64];
	int32 progress;
	int32 thumbIconIdx;
	iTime playtime;
	char* membuf;
	int32 memsize;
	char* buf_curpos;
	char* buf_sizespot;
	char* buf_cksmspot;
	int32 totamt;
	uint32 chksum;
	uint32 upd_tally;
	int32 cltneed;
	int32 cltmax;
	int32 chdrneed;
	int32 stkcnt;
	XSAVEGAME_CLIENT cltstk[128];
	XSAVEGAME_CLIENT dfltloadclt;
	uint32 file_chksum;
	uint32 read_chksum;
	int32 readsize;
	char* loadbuf;
	int32 loadsize;
	char* walkpos;
	int32 walkremain;
	st_ISGSESSION* isgsess;
} XSAVEGAME_DATA;

struct XSGAutoData
{
private:
	int32 flg_autodata;
	int32 lastTarg;
	int32 lastGame;
	int32 lastPhysicalSlot;
	st_ISGSESSION* isg_monitor;

public:
	bool32 IsValid();
	void MarkInvalid();
	bool32 SetCache(int32 targ, int32 game, int32 physicalSlot);
	void Discard();
	st_ISGSESSION* HWConnect(int32);
	void HWDisconnect(st_ISGSESSION*);
	bool32 HWCheckConnect(int32);
	int32 LastTarget() WIP { return lastTarg; }
	int32 LastGame() WIP { return lastGame; }
	int32 LastPhysicalSlot() WIP { return lastPhysicalSlot; }
};

int32 xSGStartup();
int32 xSGShutdown();
XSAVEGAME_DATA* xSGInit(SAVEGAME_MODE mode);
int32 xSGDone(XSAVEGAME_DATA* xsgdata);
int32 xSGCheckForCorruptFiles(XSAVEGAME_DATA*, char* [64]);
int32 xSGTgtCount(XSAVEGAME_DATA* xsgdata, int32* max);
int32 xSGTgtPhysSlotIdx(XSAVEGAME_DATA* xsgdata, int32 tidx);
int32 xSGTgtIsFormat(XSAVEGAME_DATA* xsgdata, int32 tidx, int32* badEncode);
int32 xSGTgtFormatTgt(XSAVEGAME_DATA* xsgdata, int32 tidx, int32* canRecover);
int32 xSGTgtSelect(XSAVEGAME_DATA* xsgdata, int32 tidx);
int32 xSGTgtHasGameDir(XSAVEGAME_DATA* xsgdata, int32 tidx);
int32 xSGTgtHaveRoom(XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile);
int32 xSGTgtHaveRoomStartup(XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile);
bool xSGCheckMemoryCard(XSAVEGAME_DATA* xsgdata, int32 index);
void xSGGameSet(XSAVEGAME_DATA* xsgdata, int32 gidx);
int32 xSGGameIsEmpty(XSAVEGAME_DATA* xsgdata, int32 gidx);
int32 xSGGameSize(XSAVEGAME_DATA* xsgdata, int32 gidx);
char* xSGGameModDate(XSAVEGAME_DATA* xsgdata, int32 gidx);
char* xSGGameLabel(XSAVEGAME_DATA* xsgdata, int32 gidx);
int32 xSGGameThumbIndex(XSAVEGAME_DATA* xsgdata, int32 gidx);
int32 xSGGameProgress(XSAVEGAME_DATA* xsgdata, int32 gidx);
int32 xSGAddSaveClient(XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_INFOFUNC infofunc, XSAVEGAME_CLIENT_PROCFUNC procfunc);
int32 xSGAddLoadClient(XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_LOADFUNC loadfunc);
int32 xSGSetup(XSAVEGAME_DATA* xsgdata);
int32 xSGSetup(XSAVEGAME_DATA* xsgdata, int32 gidx, char* label, int32 progress, iTime playtime, int32 thumbIconIdx);
int32 xSGProcess(XSAVEGAME_DATA* xsgdata);
int32 xSGWrapup(XSAVEGAME_DATA* xsgdata);
XSGASYNC_STATUS xSGAsyncStatus(XSAVEGAME_DATA* xsgdata, int32 block, XSG_WHYFAIL* whyFail, char* errmsg);
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 elesiz, int32 n);
int32 xSGWriteStrLen(const char* str);
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 n);
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, int32* data, int32 n);
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, uint32* data, int32 n);
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, float32* data, int32 n);
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 elesiz, int32 n);
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 n);
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, int32* buff, int32 n);
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, uint32* buff, int32 n);
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, float32* buff, int32 n);
int32 xSG_chdir_gamedir(XSAVEGAME_DATA*);
char* xSG_cm_slotname(XSAVEGAME_DATA*, int32);
int32 xSG_sv_flipinfo(XSAVEGAME_DATA* xsgdata);
int32 xSG_sv_prepdest(XSAVEGAME_DATA* xsgdata);
int32 xSG_sv_flipproc(XSAVEGAME_DATA* xsgdata);
int32 xSG_sv_bldchksum(XSAVEGAME_DATA*);
int32 xSG_smem_blkopen(XSAVEGAME_DATA*);
int32 xSG_smem_blkclose(XSAVEGAME_DATA* xsgdata);
int32 xSG_smem_cltopen(XSAVEGAME_DATA*, XSAVEGAME_CLIENT*);
int32 xSG_smem_cltclose(XSAVEGAME_DATA* xsgdata, XSAVEGAME_CLIENT* clt);
int32 xSG_sv_commit(XSAVEGAME_DATA* xsgdata);
int32 xSG_ld_prepload(XSAVEGAME_DATA*);
int32 xSG_ld_readgame(XSAVEGAME_DATA*);
int32 xSG_ld_readhead(XSAVEGAME_DATA* xsgdata);
int32 xSG_ld_validate(XSAVEGAME_DATA*);
int32 xSG_ld_findcltblk(XSAVEGAME_DATA* xsgdata);
int32 xSG_ld_flipload(XSAVEGAME_DATA* xsgdata);
XSGAutoData* xSGAutoSave_GetCache();
void xSGAutoSave_Startup();