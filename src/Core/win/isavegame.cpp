#include "isavegame.h"

int32 iSGStartup() STUB
int32 iSGShutdown() STUB
const char* iSGMakeName(NAMEGEN_TYPE type, const char* base, int32 idx) STUB
ISGSESSION* iSGSessionBegin(void* cltdata, iSGSessionChgFunction chgfunc, int32 monitor) STUB
void iSGSessionEnd(ISGSESSION* isgdata) STUB_VOID
int32 iSGTgtCount(ISGSESSION*, int32* max) STUB
int32 iSGTgtPhysSlotIdx(ISGSESSION*, int32) STUB
int32 iSGTgtFormat(ISGSESSION* isgdata, int32 tgtidx, int32 async, int32*) STUB
uint32 iSGTgtState(ISGSESSION* isgdata, int32 tgtidx, const char* dpath) STUB
int32 iSGTgtSetActive(ISGSESSION* isgdata, int32 tgtidx) STUB
int32 iSGTgtHaveRoom(ISGSESSION* isgdata, int32 tidx, int32 fsize, const char* dpath, const char* fname, int32* bytesNeeded, int32* availOnDisk, int32*) STUB
int32 iSGTgtHaveRoomStartup(ISGSESSION* isgdata, int32 tidx, int32 fsize, const char* dpath, const char* fname, int32* bytesNeeded, int32* availOnDisk, int32*) STUB
int32 iSGFileSize(ISGSESSION* isgdata, const char* fname) STUB
const char* iSGFileModDate(ISGSESSION* isgdata, const char* fname) STUB
const char* iSGFileModDate(ISGSESSION* isgdata, const char* fname, int32* sec, int32* min, int32* hr, int32* mon, int32* day, int32* yr) STUB
void iSGMakeTimeStamp(char* str) STUB_VOID
int32 iSGSelectGameDir(ISGSESSION* isgdata, const char* dname) STUB
int32 iSGSetupGameDir(ISGSESSION* isgdata, const char* dname, int32 force_iconfix) STUB
int32 iSGSaveFile(ISGSESSION* isgdata, const char* fname, char* data, int32 n, int32 async, char*) STUB
int32 iSGLoadFile(ISGSESSION* isgdata, const char* fname, char* databuf, int32 async) STUB
int32 iSGReadLeader(ISGSESSION* isgdata, const char* fname, char* databuf, int32 numbytes, int32 async) STUB
ASYNC_OPSTAT iSGPollStatus(ISGSESSION* isgdata, ASYNC_OPCODE* curop, int32 block) STUB
ASYNC_OPERR iSGOpError(ISGSESSION* isgdata, char* errmsg) STUB
static int32 iSG_start_your_engines() STUB
bool32 iSG_mcidx2slot(int32, int32*, int32*) STUB
static bool32 iSG_mc_exists(int32) STUB
static bool32 iSG_mc_tryRepair(ISG_MEMCARD_DATA*) STUB
static bool32 iSG_mc_isformatted(ISG_MEMCARD_DATA*) STUB
static bool32 iSG_isSpaceForFile(ISG_MEMCARD_DATA*, int32, const char*, int32*, int32*, int32*) STUB
static bool32 iSG_mc_settgt(ISG_MEMCARD_DATA*, int32) STUB
static bool32 iSG_get_finfo(ISG_MEMCARD_DATA*, const char*) STUB
static int32 iSG_get_fsize(ISG_MEMCARD_DATA*, const char*) STUB
static bool32 iSG_get_fmoddate(ISG_MEMCARD_DATA* mcdata, const char* fname, int32* sec, int32* min, int32* hr, int32* mon, int32* day, int32* yr) STUB
static int32 iSG_cubeicon_size(int32, int32) STUB
static bool32 iSG_chk_icondata() STUB
static bool32 iSG_load_icondata() STUB
static void iSG_discard_icondata() STUB_VOID
static bool32 iSG_mc_mount(int32) STUB
static bool32 iSG_mc_unmount(int32) STUB
static int32 iSG_mc_format(ISG_MEMCARD_DATA*, int32, int32*) STUB
static bool32 iSG_mc_fopen(ISG_MEMCARD_DATA*, const char*, int32, ISG_IOMODE, ASYNC_OPERR*) STUB
static bool32 iSG_mc_fclose(ISG_MEMCARD_DATA*) STUB
static bool32 iSG_mc_fdel(ISG_MEMCARD_DATA*, const char*) STUB
static bool32 iSG_mc_fread(ISG_MEMCARD_DATA*, char*, int32, int32) STUB
static bool32 iSG_mc_fwrite(ISG_MEMCARD_DATA*, char*, int32) STUB
int32 iSGCheckForWrongDevice() STUB
int32 iSGCheckForCorruptFiles(ISGSESSION*, char* [64]) STUB
bool iSGCheckMemoryCard(ISGSESSION*, int32 index) STUB
void iSGAutoSave_Startup() {}
ISGSESSION* iSGAutoSave_Connect(int32 idx_target, void* cltdata, iSGSessionChgFunction chg) STUB
void iSGAutoSave_Disconnect(ISGSESSION* isg) STUB_VOID
bool32 iSGAutoSave_Monitor(ISGSESSION* isg, int32 idx_target) STUB