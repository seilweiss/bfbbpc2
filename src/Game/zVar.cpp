#include "zVar.h"

#include "xFont.h"

namespace {

	const char* var_text_ActivePad() STUB;
	const char* var_text_BadCard() STUB;
	const char* var_text_BadCardAvailable() STUB;
	const char* var_text_BadCardNeeded() STUB;
	const char* var_text_CorruptFileName() STUB;
	const char* var_text_CurrentArea() STUB;
	const char* var_text_CurrentDate() STUB;
	const char* var_text_CurrentLevelCollectable() STUB;
	const char* var_text_CurrentLevelPatsSocks() STUB;
	const char* var_text_CurrentScene() STUB;
	const char* var_text_CurrentTime() STUB;
	const char* zVarGameSlotInfo(int32 i, char* buffer, ulong32) STUB;
	const char* var_text_GameSlot0() STUB;
	const char* var_text_GameSlot1() STUB;
	const char* var_text_GameSlot2() STUB;
	const char* var_text_GameSlot3() STUB;
	const char* var_text_GameSlot4() STUB;
	const char* var_text_GameSlot5() STUB;
	const char* var_text_GameSlot6() STUB;
	const char* var_text_GameSlot7() STUB;
	const char* var_text_MCAccessType() STUB;
	const char* var_text_MCAutoSaveCard() STUB;
	const char* var_text_MCPS2MaxSpace() STUB;
	const char* var_text_MCPS2MinSpace() STUB;
	const char* var_text_MCSelectedCard() STUB;
	const char* var_text_MCSelectedGame() STUB;
	const char* var_text_PlayerHeShe() STUB;
	const char* var_text_PlayerName() STUB;
	const char* var_text_PlayerPosition() STUB;
	const char* var_text_SelectedArea() STUB;
	const char* var_text_ShinyCount() STUB;
	const char* var_text_ShinyCountText() STUB;
	const char* var_text_SoundFXVolume() STUB;
	const char* var_text_SoundMusicVolume() STUB;
	const char* var_text_SpaceAvailable() STUB;
	const char* var_text_SpaceAvailableString() STUB;
	const char* var_text_SpaceNeeded() STUB;
	const char* var_text_TotalPatsSocks() STUB;
	const char* var_text_MCName() STUB;

	struct var_type
	{
		substr name;
		const char* (*get_text)();
	};

	var_type* find_var(const substr& s) STUB;
	void parse_tag_var(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;

}

void var_init() STUB_VOID
const char* var_text(const substr&) STUB
void zVarInit(zVarEntry* table) STUB_VOID
void zVarNewGame() {}
uint32 zVarEntryCB_SndMode(void*) STUB
uint32 zVarEntryCB_SndMusicVol(void*) STUB
uint32 zVarEntryCB_SndFXVol(void*) STUB
uint32 zVarEntryCB_MCAvailable(void*) STUB
uint32 zVarEntryCB_VibrationOn(void*) STUB
uint32 zVarEntryCB_CurrentSceneLetter(void*) STUB
uint32 zVarEntryCB_CurrentRoom(void*) STUB
uint32 zVarEntryCB_CurrentLevelPickup(void*) STUB
uint32 zVarEntryCB_CurrentLevelPSocks(void*) STUB
uint32 zVarEntryCB_TotalPSocks(void*) STUB
uint32 zVarEntryCB_Shinies(void*) STUB
uint32 zVarEntryCB_Spatulas(void*) STUB
uint32 zVarEntryCB_Date(void*) STUB
uint32 zVarEntryCB_Hour(void*) STUB
uint32 zVarEntryCB_Minute(void*) STUB
uint32 zVarEntryCB_CounterValue(void* context) STUB
uint32 zVarEntryCB_IsEnabled(void* context) STUB
uint32 zVarEntryCB_IsVisible(void* context) STUB