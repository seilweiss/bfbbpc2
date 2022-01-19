#include "xSFX.h"

void xSFXEnvironmentalStreamSceneExit() STUB_VOID
void xSFXUpdateEnvironmentalStreamSounds(xSFX* pSFXList, uint32 numSounds) STUB_VOID
static bool xSFXWillSendDone(xSFX*) STUB
void xSFXInit(void* t, void* asset) STUB_VOID
void xSFXInit(xSFX*, xSFXAsset*) STUB_VOID
void xSFXSave(xSFX* ent, xSerial* s) STUB_VOID
void xSFXLoad(xSFX* ent, xSerial* s) STUB_VOID
void xSFXReset(xSFX*) STUB_VOID
uint32 xSFXConvertFlags(uint32) STUB
static void xSFXUpdate(xSFX*) STUB_VOID
bool32 xSFXEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase*) STUB
static void xSFXPlay(xSFX* t);
static void xSFXStop(xSFX*);