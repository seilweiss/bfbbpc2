#pragma once

#include <types.h>
#include <rwcore.h>

void zGameInit(uint32 theSceneID);
void zGameExit();
void zGameSetup();
void zGameLoop();
bool32 zGameIsPaused();
void zGamePause();
void zGameStall();
void zGameTakeSnapShot(RwCamera*);
void zGameUpdateTransitionBubbles();
void zGameScreenTransitionBegin();
void zGameScreenTransitionUpdate(float32 percentComplete, char* msg);
void zGameScreenTransitionUpdate(float32 percentComplete, char* msg, uint8* rgba);
void zGameScreenTransitionEnd();
void zGameSetupPlayer();
void zGameStats_Init();