#include "xsavegame.h"

#include "isavegame.h"

int32 xSGStartup() STUB
int32 xSGShutdown() STUB
st_XSAVEGAME_DATA* xSGInit(en_SAVEGAME_MODE mode) STUB
int32 xSGDone(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSGCheckForCorruptFiles(st_XSAVEGAME_DATA*, char* [64]) STUB
int32 xSGTgtCount(st_XSAVEGAME_DATA* xsgdata, int32* max) STUB
int32 xSGTgtPhysSlotIdx(st_XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
bool32 xSGTgtIsFormat(st_XSAVEGAME_DATA* xsgdata, int32 tidx, int32* badEncode) STUB
int32 xSGTgtFormatTgt(st_XSAVEGAME_DATA* xsgdata, int32 tidx, int32* canRecover) STUB
int32 xSGTgtSelect(st_XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
int32 xSGTgtHasGameDir(st_XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
int32 xSGTgtHaveRoom(st_XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile) STUB
int32 xSGTgtHaveRoomStartup(st_XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile) STUB
bool xSGCheckMemoryCard(st_XSAVEGAME_DATA* xsgdata, int32 index) STUB
void xSGGameSet(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB_VOID
int32 xSGGameIsEmpty(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameSize(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
char* xSGGameModDate(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
char* xSGGameLabel(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameThumbIndex(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameProgress(st_XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGAddSaveClient(st_XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_INFOFUNC infofunc, XSAVEGAME_CLIENT_PROCFUNC procfunc) STUB
int32 xSGAddLoadClient(st_XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_LOADFUNC loadfunc) STUB
int32 xSGSetup(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSGSetup(st_XSAVEGAME_DATA* xsgdata, int32 gidx, char* label, int32 progress, iTime playtime, int32 thumbIconIdx) STUB
int32 xSGProcess(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSGWrapup(st_XSAVEGAME_DATA* xsgdata) STUB
en_XSGASYNC_STATUS xSGAsyncStatus(st_XSAVEGAME_DATA* xsgdata, int32 block, en_XSG_WHYFAIL* whyFail, char* errmsg) STUB
static int32 xSG_cb_leader_svinfo(void*, st_XSAVEGAME_DATA*, int32* cur_space, int32* max_fullgame) STUB
static int32 xSG_cb_leader_svproc(void* cltdata, st_XSAVEGAME_DATA* original_xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt) STUB
static int32 xSG_cb_leader_load(void*, st_XSAVEGAME_DATA* original_xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB
int32 xSGWriteData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 elesiz, int32 n) STUB
int32 xSGWriteStrLen(const char* str) STUB
int32 xSGWriteData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 n) STUB
int32 xSGWriteData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt, int32* data, int32 n) STUB
int32 xSGWriteData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt, uint32* data, int32 n) STUB
int32 xSGWriteData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt, float32* data, int32 n) STUB
int32 xSGReadData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 elesiz, int32 n) STUB
int32 xSGReadData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 n) STUB
int32 xSGReadData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, int32* buff, int32 n) STUB
int32 xSGReadData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, uint32* buff, int32 n) STUB
int32 xSGReadData(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, float32* buff, int32 n) STUB
static int32 xSG_grab_leaders(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_chdir_gamedir(st_XSAVEGAME_DATA*) STUB
char* xSG_cm_slotname(st_XSAVEGAME_DATA*, int32) STUB
static void xSG_areaComposeLabel(char*, int32, char*, int32) STUB_VOID
int32 xSG_sv_flipinfo(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_prepdest(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_flipproc(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_bldchksum(st_XSAVEGAME_DATA*) STUB
int32 xSG_smem_blkopen(st_XSAVEGAME_DATA*) STUB
int32 xSG_smem_blkclose(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_smem_cltopen(st_XSAVEGAME_DATA*, st_XSAVEGAME_CLIENT*) STUB
int32 xSG_smem_cltclose(st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_CLIENT* clt) STUB
int32 xSG_sv_commit(st_XSAVEGAME_DATA* xsgdata) STUB
void xSG_cb_ISGChange(void*, en_CHGCODE what) STUB_VOID
int32 xSG_ld_prepload(st_XSAVEGAME_DATA*) STUB
int32 xSG_ld_readgame(st_XSAVEGAME_DATA*) STUB
int32 xSG_ld_readhead(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_ld_validate(st_XSAVEGAME_DATA*) STUB
int32 xSG_ld_findcltblk(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_ld_flipload(st_XSAVEGAME_DATA* xsgdata) STUB
XSGAutoData* xSGAutoSave_GetCache() STUB
void xSGAutoSave_Startup() STUB_VOID
bool32 XSGAutoData::IsValid() STUB
void XSGAutoData::MarkInvalid() STUB_VOID
bool32 XSGAutoData::SetCache(int32 targ, int32 game, int32 physicalSlot) STUB
void XSGAutoData::Discard() STUB_VOID
st_ISGSESSION* XSGAutoData::HWConnect(int32) STUB
void XSGAutoData::HWDisconnect(st_ISGSESSION*) STUB_VOID
bool32 XSGAutoData::HWCheckConnect(int32) STUB
static void ASG_ISG_changed(void*, en_CHGCODE what) STUB_VOID