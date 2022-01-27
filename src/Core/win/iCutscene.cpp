#include "iCutscene.h"

#include "xFile.h"

void iCSSoundSetup(xCutscene*) STUB_VOID
void* iCSSoundGetData(xSndVoiceInfo*, uint32*) STUB
static void iCSAsyncReadCB(xFile*) STUB_VOID
uint32 iCSFileOpen(xCutscene* csn) STUB
void iCSFileAsyncRead(xCutscene* csn, void* dest, uint32 size) STUB_VOID
void iCSFileAsyncSkip(xCutscene*, uint32) STUB_VOID
void iCSFileClose(xCutscene* csn) STUB_VOID
bool32 iCSLoadStep(xCutscene* csn) STUB