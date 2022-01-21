#pragma once

#include "xString.h"

struct zVarEntry
{
	uint32 entry;
	uint32 varNameID;
	const char* varName;
	uint32(*varCB)(void*);
};

void var_init();
const char* var_text(const substr&);
void zVarInit(zVarEntry* table);
void zVarNewGame();
uint32 zVarEntryCB_SndMode(void*);
uint32 zVarEntryCB_SndMusicVol(void*);
uint32 zVarEntryCB_SndFXVol(void*);
uint32 zVarEntryCB_MCAvailable(void*);
uint32 zVarEntryCB_VibrationOn(void*);
uint32 zVarEntryCB_CurrentSceneLetter(void*);
uint32 zVarEntryCB_CurrentRoom(void*);
uint32 zVarEntryCB_CurrentLevelPickup(void*);
uint32 zVarEntryCB_CurrentLevelPSocks(void*);
uint32 zVarEntryCB_TotalPSocks(void*);
uint32 zVarEntryCB_Shinies(void*);
uint32 zVarEntryCB_Spatulas(void*);
uint32 zVarEntryCB_Date(void*);
uint32 zVarEntryCB_Hour(void*);
uint32 zVarEntryCB_Minute(void*);
uint32 zVarEntryCB_CounterValue(void* context);
uint32 zVarEntryCB_IsEnabled(void* context);
uint32 zVarEntryCB_IsVisible(void* context);