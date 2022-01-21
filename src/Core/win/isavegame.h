#pragma once

#include <types.h>

typedef enum en_CHGCODE
{
	ISG_CHG_NONE,
	ISG_CHG_TARGET,
	ISG_CHG_GAMELIST
} CHGCODE;

typedef enum en_NAMEGEN_TYPE
{
	ISG_NGTYP_GAMEDIR,
	ISG_NGTYP_GAMEFILE,
	ISG_NGTYP_CONFIG,
	ISG_NGTYP_ICONTHUM
} NAMEGEN_TYPE;

typedef enum en_ISG_IOMODE
{
	ISG_IOMODE_READ = 1,
	ISG_IOMODE_WRITE,
	ISG_IOMODE_APPEND
} ISG_IOMODE;

typedef enum en_ISGMC_ERRSTATUS
{
	ISGMC_ERR_NONE,
	ISGMC_ERR_NOMEMCARD,
	ISGMC_ERR_MKDIR,
	ISGMC_ERR_OPEN,
	ISGMC_ERR_CLOSE,
	ISGMC_ERR_READ,
	ISGMC_ERR_WRITE
} ISGMC_ERRSTATUS;

typedef enum en_ASYNC_OPCODE
{
	ISG_OPER_NOOP,
	ISG_OPER_INIT,
	ISG_OPER_SAVE,
	ISG_OPER_LOAD
} ASYNC_OPCODE;

typedef enum en_ASYNC_OPSTAT
{
	ISG_OPSTAT_FAILURE = -1,
	ISG_OPSTAT_INPROG = 0,
	ISG_OPSTAT_SUCCESS
} ASYNC_OPSTAT;

typedef enum en_ASYNC_OPERR
{
	ISG_OPERR_NONE,
	ISG_OPERR_NOOPER,
	ISG_OPERR_MULTIOPER,
	ISG_OPERR_INITFAIL,
	ISG_OPERR_GAMEDIR,
	ISG_OPERR_NOCARD,
	ISG_OPERR_NOROOM,
	ISG_OPERR_DAMAGE,
	ISG_OPERR_CORRUPT,
	ISG_OPERR_OTHER,
	ISG_OPERR_SVNOSPACE,
	ISG_OPERR_SVINIT,
	ISG_OPERR_SVWRITE,
	ISG_OPERR_SVOPEN,
	ISG_OPERR_LDINIT,
	ISG_OPERR_LDREAD,
	ISG_OPERR_LDOPEN,
	ISG_OPERR_TGTERR,
	ISG_OPERR_TGTREM,
	ISG_OPERR_TGTPREP,
	ISG_OPERR_UNKNOWN,
	ISG_OPERR_NOMORE
} ASYNC_OPERR;

typedef struct st_ISG_MEMCARD_DATA
{
	int32 mcport;
	int32 mcslot;
	int32 mcfp;
	ISG_IOMODE fmode;
	char gamepath[64];
	//sceMcTblGetDir finfo;
	int32 cur_mcop;
	ISGMC_ERRSTATUS mcerr;
	int32 allow_cache;
} ISG_MEMCARD_DATA;

typedef void(*iSGSessionChgFunction)(void*, en_CHGCODE);

typedef struct st_ISGSESSION
{
	ISG_MEMCARD_DATA* mcdata;
	char gameroot[64];
	char gamedir[64];
	ASYNC_OPCODE as_curop;
	ASYNC_OPSTAT as_opstat;
	ASYNC_OPERR as_operr;
	void* cltdata;
	CHGCODE chgcode;
	void(*chgfunc)(void*, CHGCODE);
} ISGSESSION;

int32 iSGStartup();
int32 iSGShutdown();
const char* iSGMakeName(NAMEGEN_TYPE type, const char* base, int32 idx);
ISGSESSION* iSGSessionBegin(void* cltdata, iSGSessionChgFunction chgfunc, int32 monitor);
void iSGSessionEnd(ISGSESSION* isgdata);
int32 iSGTgtCount(ISGSESSION*, int32* max);
int32 iSGTgtPhysSlotIdx(ISGSESSION*, int32);
int32 iSGTgtFormat(ISGSESSION* isgdata, int32 tgtidx, int32 async, int32*);
uint32 iSGTgtState(ISGSESSION* isgdata, int32 tgtidx, const char* dpath);
int32 iSGTgtSetActive(ISGSESSION* isgdata, int32 tgtidx);
int32 iSGTgtHaveRoom(ISGSESSION* isgdata, int32 tidx, int32 fsize, const char* dpath, const char* fname, int32* bytesNeeded, int32* availOnDisk, int32*);
int32 iSGTgtHaveRoomStartup(ISGSESSION* isgdata, int32 tidx, int32 fsize, const char* dpath, const char* fname, int32* bytesNeeded, int32* availOnDisk, int32*);
int32 iSGFileSize(ISGSESSION* isgdata, const char* fname);
const char* iSGFileModDate(ISGSESSION* isgdata, const char* fname);
const char* iSGFileModDate(ISGSESSION* isgdata, const char* fname, int32* sec, int32* min, int32* hr, int32* mon, int32* day, int32* yr);
void iSGMakeTimeStamp(char* str);
int32 iSGSelectGameDir(ISGSESSION* isgdata, const char* dname);
int32 iSGSetupGameDir(ISGSESSION* isgdata, const char* dname, int32 force_iconfix);
int32 iSGSaveFile(ISGSESSION* isgdata, const char* fname, char* data, int32 n, int32 async, char*);
int32 iSGLoadFile(ISGSESSION* isgdata, const char* fname, char* databuf, int32 async);
int32 iSGReadLeader(ISGSESSION* isgdata, const char* fname, char* databuf, int32 numbytes, int32 async);
ASYNC_OPSTAT iSGPollStatus(ISGSESSION* isgdata, ASYNC_OPCODE* curop, int32 block);
ASYNC_OPERR iSGOpError(ISGSESSION* isgdata, char* errmsg);
bool32 iSG_mcidx2slot(int32, int32*, int32*);
int32 iSGCheckForWrongDevice();
int32 iSGCheckForCorruptFiles(ISGSESSION*, char* [64]);
bool iSGCheckMemoryCard(ISGSESSION*, int32 index);
void iSGAutoSave_Startup();
ISGSESSION* iSGAutoSave_Connect(int32 idx_target, void* cltdata, iSGSessionChgFunction chg);
void iSGAutoSave_Disconnect(ISGSESSION* isg);
bool32 iSGAutoSave_Monitor(ISGSESSION* isg, int32 idx_target);