#pragma once

#include "xBase.h"

typedef enum en_DISPATCH_COMMAND
{
	ZDSP_CMD_INITDFLT = -1,
	ZDSP_CMD_CTRL_CFGGET = 0,
	ZDSP_CMD_CTRL_CFGSET,
	ZDSP_CMD_CTRL_VIBEGET,
	ZDSP_CMD_CTRL_VIBESET,
	ZDSP_CMD_SNDMOD_GET,
	ZDSP_CMD_SNDMOD_SET,
	ZDSP_CMD_SNDVOL_GET,
	ZDSP_CMD_SNDVOL_SET,
	ZDSP_CMD_SNDVOL_INCR,
	ZDSP_CMD_SNDVOL_DECR,
	ZDSP_CMD_MUSVOL_GET,
	ZDSP_CMD_MUSVOL_SET,
	ZDSP_CMD_MUSVOL_INCR,
	ZDSP_CMD_MUSVOL_DECR,
	ZDSP_CMD_SFXVOL_GET,
	ZDSP_CMD_SFXVOL_SET,
	ZDSP_CMD_SFXVOL_INCR,
	ZDSP_CMD_SFXVOL_DECR,
	ZDSP_CMD_GSTATE_GET,
	ZDSP_CMD_GSTATE_SET,
	ZDSP_CMD_GMODE_GET,
	ZDSP_CMD_GMODE_SET,
	ZDSP_CHECKPNT_SET,
	ZDSP_CMD_NOMORE
} DISPATCH_COMMAND;

typedef struct st_ZDISPATCH_DATA : xBase
{
	xBaseAsset* rawass;
	int32 placeholder;
} ZDISPATCH_DATA;

void zDispatcher_Startup();
void zDispatcher_Shutdown();
void zDispatcher_scenePrepare();
void zDispatcher_sceneFinish();
ZDISPATCH_DATA* zDispatcher_memPool(int32 cnt);
ZDISPATCH_DATA* zDispatcher_getInst(ZDISPATCH_DATA* pool, int32 idx);
void zDispatcher_Init(ZDISPATCH_DATA* dspdata, xBaseAsset* bass);
void zDispatcher_InitDep(ZDISPATCH_DATA* dspdata);
void zDispatcher_Save(ZDISPATCH_DATA* dspdata, xSerial* s);
void zDispatcher_Load(ZDISPATCH_DATA* dspdata, xSerial* s);
bool32 ZDSP_injectCmd(ZDISPATCH_DATA*, DISPATCH_COMMAND);
bool32 ZDSP_injectCmd(ZDISPATCH_DATA*, DISPATCH_COMMAND, int32);
bool32 ZDSP_injectCmd(ZDISPATCH_DATA*, DISPATCH_COMMAND, void*, void*, void*);
void zDispatcherStoreOptions();
void zDispatcherRestoreOptions();