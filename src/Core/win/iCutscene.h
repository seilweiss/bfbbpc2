#pragma once

#include <types.h>

struct xCutscene;
struct xSndVoiceInfo;

void iCSSoundSetup(xCutscene*);
void* iCSSoundGetData(xSndVoiceInfo*, uint32*);
uint32 iCSFileOpen(xCutscene* csn);
void iCSFileAsyncRead(xCutscene* csn, void* dest, uint32 size);
void iCSFileAsyncSkip(xCutscene*, uint32);
void iCSFileClose(xCutscene* csn);
bool32 iCSLoadStep(xCutscene* csn);