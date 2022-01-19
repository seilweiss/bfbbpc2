#include "xsavegame.h"

#include "isavegame.h"

int32 xSGStartup() STUB
int32 xSGShutdown() STUB
XSAVEGAME_DATA* xSGInit(SAVEGAME_MODE mode) STUB
int32 xSGDone(XSAVEGAME_DATA* xsgdata) STUB
int32 xSGCheckForCorruptFiles(XSAVEGAME_DATA*, char* [64]) STUB
int32 xSGTgtCount(XSAVEGAME_DATA* xsgdata, int32* max) STUB
int32 xSGTgtPhysSlotIdx(XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
bool32 xSGTgtIsFormat(XSAVEGAME_DATA* xsgdata, int32 tidx, int32* badEncode) STUB
int32 xSGTgtFormatTgt(XSAVEGAME_DATA* xsgdata, int32 tidx, int32* canRecover) STUB
int32 xSGTgtSelect(XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
int32 xSGTgtHasGameDir(XSAVEGAME_DATA* xsgdata, int32 tidx) STUB
int32 xSGTgtHaveRoom(XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile) STUB
int32 xSGTgtHaveRoomStartup(XSAVEGAME_DATA* xsgdata, int32 tidx, int32 fsize, int32 slotidx, int32* bytesNeeded, int32* availOnDisk, int32* needFile) STUB
bool xSGCheckMemoryCard(XSAVEGAME_DATA* xsgdata, int32 index) STUB
void xSGGameSet(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB_VOID
int32 xSGGameIsEmpty(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameSize(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
char* xSGGameModDate(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
char* xSGGameLabel(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameThumbIndex(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGGameProgress(XSAVEGAME_DATA* xsgdata, int32 gidx) STUB
int32 xSGAddSaveClient(XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_INFOFUNC infofunc, XSAVEGAME_CLIENT_PROCFUNC procfunc) STUB
int32 xSGAddLoadClient(XSAVEGAME_DATA* xsgdata, uint32 clttag, void* cltdata, XSAVEGAME_CLIENT_LOADFUNC loadfunc) STUB
int32 xSGSetup(XSAVEGAME_DATA* xsgdata) STUB
int32 xSGSetup(XSAVEGAME_DATA* xsgdata, int32 gidx, char* label, int32 progress, iTime playtime, int32 thumbIconIdx) STUB
int32 xSGProcess(XSAVEGAME_DATA* xsgdata) STUB
int32 xSGWrapup(XSAVEGAME_DATA* xsgdata) STUB
XSGASYNC_STATUS xSGAsyncStatus(XSAVEGAME_DATA* xsgdata, int32 block, XSG_WHYFAIL* whyFail, char* errmsg) STUB
static int32 xSG_cb_leader_svinfo(void*, XSAVEGAME_DATA*, int32* cur_space, int32* max_fullgame) STUB
static int32 xSG_cb_leader_svproc(void* cltdata, XSAVEGAME_DATA* original_xsgdata, XSAVEGAME_WRITECONTEXT* wctxt) STUB
static int32 xSG_cb_leader_load(void*, XSAVEGAME_DATA* original_xsgdata, XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 elesiz, int32 n) STUB
int32 xSGWriteStrLen(const char* str) STUB
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, char* data, int32 n) STUB
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, int32* data, int32 n) STUB
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, uint32* data, int32 n) STUB
int32 xSGWriteData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt, float32* data, int32 n) STUB
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 elesiz, int32 n) STUB
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, char* buff, int32 n) STUB
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, int32* buff, int32 n) STUB
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, uint32* buff, int32 n) STUB
int32 xSGReadData(XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, float32* buff, int32 n) STUB
static int32 xSG_grab_leaders(st_XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_chdir_gamedir(XSAVEGAME_DATA*) STUB
char* xSG_cm_slotname(XSAVEGAME_DATA*, int32) STUB
static void xSG_areaComposeLabel(char*, int32, char*, int32) STUB_VOID
int32 xSG_sv_flipinfo(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_prepdest(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_flipproc(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_sv_bldchksum(XSAVEGAME_DATA*) STUB
int32 xSG_smem_blkopen(XSAVEGAME_DATA*) STUB
int32 xSG_smem_blkclose(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_smem_cltopen(XSAVEGAME_DATA*, XSAVEGAME_CLIENT*) STUB
int32 xSG_smem_cltclose(XSAVEGAME_DATA* xsgdata, XSAVEGAME_CLIENT* clt) STUB
int32 xSG_sv_commit(XSAVEGAME_DATA* xsgdata) STUB
void xSG_cb_ISGChange(void*, CHGCODE what) STUB_VOID
int32 xSG_ld_prepload(XSAVEGAME_DATA*) STUB
int32 xSG_ld_readgame(XSAVEGAME_DATA*) STUB
int32 xSG_ld_readhead(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_ld_validate(XSAVEGAME_DATA*) STUB
int32 xSG_ld_findcltblk(XSAVEGAME_DATA* xsgdata) STUB
int32 xSG_ld_flipload(XSAVEGAME_DATA* xsgdata) STUB
XSGAutoData* xSGAutoSave_GetCache() STUB
void xSGAutoSave_Startup() STUB_VOID
bool32 XSGAutoData::IsValid() STUB
void XSGAutoData::MarkInvalid() STUB_VOID
bool32 XSGAutoData::SetCache(int32 targ, int32 game, int32 physicalSlot) STUB
void XSGAutoData::Discard() STUB_VOID
st_ISGSESSION* XSGAutoData::HWConnect(int32) STUB
void XSGAutoData::HWDisconnect(st_ISGSESSION*) STUB_VOID
bool32 XSGAutoData::HWCheckConnect(int32) STUB
static void ASG_ISG_changed(void*, CHGCODE what) STUB_VOID