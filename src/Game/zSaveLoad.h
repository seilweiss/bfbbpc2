#pragma once

#include "xsavegame.h"

struct zSaveLoadGame
{
	char label[64];
	char date[32];
	int32 progress;
	uint32 size;
	int8 thumbIconIndex;
};

struct zSaveLoadUI
{
	uint32 entry;
	uint32 nameID;
	const char* name;
};

void zUpdateThumbIcon();
void zSaveLoad_Tick();
int32 zSaveLoad_poll();
void zSendEventToThumbIcon(uint32);
void zChangeThumbIcon(const char*);
void zSaveLoadInit();
void zSaveLoadGameTableInit(zSaveLoadGame*);
void zSaveLoadUITableInit(zSaveLoadUI*);
void zSaveLoad_UIEvent(int32, uint32);
XSAVEGAME_DATA* zSaveLoadSGInit(SAVEGAME_MODE);
int32 zSaveLoadSGDone(XSAVEGAME_DATA*);
int32 zSaveLoad_getgame();
int32 zSaveLoad_getcard();
int32 zSaveLoad_getMCavailable();
int32 zSaveLoad_getMCneeded();
int32 zSaveLoad_getMCAccessType();
int32 zSaveLoadGetAutoSaveCard();
int32 format(int32 num, int32 mode);
int32 CardtoTgt(int32 card);
int32 zSaveLoad_CardCount();
int32 zSaveLoad_CardPrompt(int32 mode);
int32 zSaveLoad_CardPromptFormat(int32);
int32 zSaveLoad_CardPromptSpace(int32);
int32 zSaveLoad_CardPromptGames(int32);
int32 zSaveLoad_CardPromptGameSlotEmpty();
int32 zSaveLoad_CardPromptOverwrite();
int32 zSaveLoad_CardPromptOverwriteDamaged();
int32 zSaveLoad_ErrorPrompt(int32);
int32 zSaveLoad_DamagedSaveGameErrorPrompt(int32);
int32 zSaveLoad_CardWrongDeviceErrorPrompt(int32);
int32 zSaveLoad_CardDamagedErrorPrompt(int32);
int32 zSaveLoad_SaveDamagedErrorPrompt(int32);
int32 zSaveLoad_CardYankedErrorPrompt(int32);
int32 zSaveLoad_ErrorFormatPrompt(int32);
int32 zSaveLoad_ErrorFormatCardYankedPrompt(int32);
int32 zSaveLoad_CardCheckSingle(int32 num);
int32 zSaveLoad_CardCheckFormattedSingle(int32 num);
int32 zSaveLoad_CardCheckSpaceSingle_doCheck(XSAVEGAME_DATA* xsgdata, int32 num);
int32 zSaveLoad_CardCheckSpaceSingle(int32 num);
int32 zSaveLoad_CardCheckGamesSingle_doCheck(XSAVEGAME_DATA*, int32);
int32 zSaveLoad_CardCheckGamesSingle(int32 num);
int32 zSaveLoad_CardCheckSlotEmpty_hasGame_doCheck(XSAVEGAME_DATA* xsgdata, int32 num, int32 game);
int32 zSaveLoad_CardCheckSlotEmpty_hasGame(int32 num, int32 game);
int32 zSaveLoad_CardCheckSlotOverwrite_Free(int32, int32);
int32 zSaveLoad_CardCheck(int32 cardNumber, int32 mode);
int32 zSaveLoad_CardCheckFormatted(int32 cardNumber, int32 mode);
int32 zSaveLoad_CardCheckValid(int32 cardNumber, int32 mode);
int32 zSaveLoad_CardCheckSpace(int32 cardNumber, int32 mode);
int32 zSaveLoad_CardCheckGames(int32 cardNumber, int32 mode);
int32 zSaveLoad_CardCheckGameSlot(int32, int32, int32);
int32 zSaveLoad_CardCheckSlotEmpty(int32, int32);
int32 zSaveLoad_CardCheckSlotOverwrite(int32 cardNumber, int32 gameNumber);
int32 zSaveLoad_CardPick(int32 mode);
void zSaveLoad_BuildName(char* name_txt, int32 idx);
int32 zSaveLoad_GameSelect(int32 mode);
bool zSaveLoadGetPreAutoSave();
void zSaveLoadPreAutoSave(bool onOff);
void zSaveLoadAutoSaveUpdate();
int32 zSaveLoad_DoAutoSave();
int32 zSaveLoad_SaveGame();
int32 zSaveLoad_LoadGame();
uint32 zSaveLoad_LoadLoop();
uint32 zSaveLoad_SaveLoop();
void zSaveLoad_DispatchCB(uint32 dispatchEvent, const float32* toParam);
bool32 xSGT_SaveInfoCB(void*, XSAVEGAME_DATA*, int32* need, int32* most);
bool32 xSGT_SaveProcCB(void*, XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt);
bool32 xSGT_SaveInfoPrefsCB(void*, XSAVEGAME_DATA*, int32* need, int32* most);
bool32 xSGT_SaveProcPrefsCB(void*, XSAVEGAME_DATA* xsgdata, XSAVEGAME_WRITECONTEXT* wctxt);
bool32 xSGT_LoadLoadCB(void*, XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, uint32, int32);
bool32 xSGT_LoadPrefsCB(void*, XSAVEGAME_DATA* xsgdata, XSAVEGAME_READCONTEXT* rctxt, uint32, int32);
uint32 zSaveLoad_slotIsEmpty(uint32 i);