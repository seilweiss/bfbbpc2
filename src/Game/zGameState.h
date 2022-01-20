#pragma once

#include <types.h>

typedef enum _GameOstrich
{
	eGameOstrich_Loading,
	eGameOstrich_PlayingMovie,
	eGameOstrich_InScene,
	eGameOstrich_Total
} GameOstrich;

enum eGameMode
{
	eGameMode_Boot,
	eGameMode_Intro,
	eGameMode_Title,
	eGameMode_Start,
	eGameMode_Load,
	eGameMode_Options,
	eGameMode_Save,
	eGameMode_Pause,
	eGameMode_Stall,
	eGameMode_WorldMap,
	eGameMode_MonsterGallery,
	eGameMode_ConceptArtGallery,
	eGameMode_Game,
	eGameMode_Count
};

int32 zGameStateGet();
int32 zGameModeGet();
GameOstrich zGameGetOstrich();
void zGameSetOstrich(GameOstrich o);
bool32 zGameStateFindEvent(uint32*, int32, int32, int32, int32*, int32*);
void zGameStateSwitchEvent(int32 event);
void zGameStateSwitch(int32 theNewState);
void zGameModeSwitch(eGameMode modeNew);