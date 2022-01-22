#include "zSaveLoad.h"

void zUpdateThumbIcon() STUB_VOID
void zSaveLoad_Tick() STUB_VOID
int32 zSaveLoad_poll() STUB
void zSendEventToThumbIcon(uint32) STUB_VOID
void zChangeThumbIcon(const char*) STUB_VOID
void zSaveLoadInit() STUB_VOID
void zSaveLoadGameTableInit(zSaveLoadGame*) STUB_VOID
void zSaveLoadUITableInit(zSaveLoadUI*) STUB_VOID
void zSaveLoad_UIEvent(int32, uint32) STUB_VOID
st_XSAVEGAME_DATA* zSaveLoadSGInit(en_SAVEGAME_MODE) STUB
int32 zSaveLoadSGDone(st_XSAVEGAME_DATA*) STUB
int32 zSaveLoad_getgame() STUB
int32 zSaveLoad_getcard() STUB
int32 zSaveLoad_getMCavailable() STUB
int32 zSaveLoad_getMCneeded() STUB
int32 zSaveLoad_getMCAccessType() STUB
int32 zSaveLoadGetAutoSaveCard() STUB
int32 format(int32 num, int32 mode) STUB
int32 CardtoTgt(int32 card) STUB
int32 zSaveLoad_CardCount() STUB
int32 zSaveLoad_CardPrompt(int32 mode) STUB
int32 zSaveLoad_CardPromptFormat(int32) STUB
int32 zSaveLoad_CardPromptSpace(int32) STUB
int32 zSaveLoad_CardPromptGames(int32) STUB
int32 zSaveLoad_CardPromptGameSlotEmpty() STUB
int32 zSaveLoad_CardPromptOverwrite() STUB
int32 zSaveLoad_CardPromptOverwriteDamaged() STUB
int32 zSaveLoad_ErrorPrompt(int32) STUB
int32 zSaveLoad_DamagedSaveGameErrorPrompt(int32) STUB
int32 zSaveLoad_CardWrongDeviceErrorPrompt(int32) STUB
int32 zSaveLoad_CardDamagedErrorPrompt(int32) STUB
int32 zSaveLoad_SaveDamagedErrorPrompt(int32) STUB
int32 zSaveLoad_CardYankedErrorPrompt(int32) STUB
int32 zSaveLoad_ErrorFormatPrompt(int32) STUB
int32 zSaveLoad_CardCheckSingle(int32 num) STUB
int32 zSaveLoad_CardCheckFormattedSingle(int32 num) STUB
int32 zSaveLoad_CardCheckSpaceSingle_doCheck(st_XSAVEGAME_DATA* xsgdata, int32 num) STUB
int32 zSaveLoad_CardCheckSpaceSingle(int32 num) STUB
int32 zSaveLoad_CardCheckGamesSingle_doCheck(st_XSAVEGAME_DATA*, int32) STUB
int32 zSaveLoad_CardCheckGamesSingle(int32 num) STUB
int32 zSaveLoad_CardCheckSlotEmpty_hasGame_doCheck(st_XSAVEGAME_DATA* xsgdata, int32 num, int32 game) STUB
int32 zSaveLoad_CardCheckSlotEmpty_hasGame(int32 num, int32 game) STUB
int32 zSaveLoad_CardCheckSlotOverwrite_Free(int32, int32) STUB
int32 zSaveLoad_CardCheck(int32 cardNumber, int32 mode) STUB
int32 zSaveLoad_CardCheckFormatted(int32 cardNumber, int32 mode) STUB
int32 zSaveLoad_CardCheckValid(int32 cardNumber, int32 mode) STUB
int32 zSaveLoad_CardCheckSpace(int32 cardNumber, int32 mode) STUB
int32 zSaveLoad_CardCheckGames(int32 cardNumber, int32 mode) STUB
int32 zSaveLoad_CardCheckGameSlot(int32, int32, int32) STUB
int32 zSaveLoad_CardCheckSlotEmpty(int32, int32) STUB
int32 zSaveLoad_CardCheckSlotOverwrite(int32 cardNumber, int32 gameNumber) STUB
int32 zSaveLoad_CardPick(int32 mode) STUB
static bool IsValidName(char*) STUB
static void BuildIt(char* build_txt, int32 i) STUB_VOID
void zSaveLoad_BuildName(char* name_txt, int32 idx) STUB_VOID
int32 zSaveLoad_GameSelect(int32 mode) STUB
bool zSaveLoadGetPreAutoSave() STUB
void zSaveLoadPreAutoSave(bool onOff) STUB_VOID
void zSaveLoadAutoSaveUpdate() STUB_VOID
int32 zSaveLoad_DoAutoSave() STUB
int32 zSaveLoad_SaveGame() STUB
int32 zSaveLoad_LoadGame() STUB
uint32 zSaveLoad_LoadLoop() STUB
uint32 zSaveLoad_SaveLoop() STUB
void zSaveLoad_DispatchCB(uint32 dispatchEvent, const float32* toParam) STUB_VOID
bool32 xSGT_SaveInfoCB(void*, st_XSAVEGAME_DATA*, int32* need, int32* most) STUB
bool32 xSGT_SaveProcCB(void*, st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt) STUB
bool32 xSGT_SaveInfoPrefsCB(void*, st_XSAVEGAME_DATA*, int32* need, int32* most) STUB
bool32 xSGT_SaveProcPrefsCB(void*, st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_WRITECONTEXT* wctxt) STUB
bool32 xSGT_LoadLoadCB(void*, st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB
bool32 xSGT_LoadPrefsCB(void*, st_XSAVEGAME_DATA* xsgdata, st_XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB
uint32 zSaveLoad_slotIsEmpty(uint32 i) STUB