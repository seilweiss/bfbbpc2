#include "xScrFx.h"

void xScrFxInit() STUB_VOID
void xScrFxReset() STUB_VOID
void xScrFxUpdate(RwCamera* cam, float32 dt) STUB_VOID
void xScrFxRender(RwCamera*) STUB_VOID
void xScrFxDrawScreenSizeRectangle() STUB_VOID
void xScrFxFadeInit() STUB_VOID
static uint8 InterpCol(float32, uint8, uint8) STUB
void xScrFxFade(xColor* base, xColor* dest, float32 seconds, xScrFxFadeCallback callback, bool32 hold) STUB_VOID
void xScrFxStopFade() STUB_VOID
bool32 xScrFxIsFading() STUB
void xScrFxUpdateFade(RwCamera*, float32 seconds) STUB_VOID
void xScrFxLetterBoxInit() STUB_VOID
void xScrFxLetterboxReset() STUB_VOID
void xScrFxLetterBoxSetSize(float32 size) STUB_VOID
void xScrFxLetterBoxSetAlpha(uint8 alpha) STUB_VOID
void xScrFxLetterbox(bool32 enable) STUB_VOID
void xScrFxUpdateLetterBox(RwCamera*, float32 seconds) STUB_VOID
bool32 xScrFxIsLetterbox() STUB
void xScrFxDrawSafeArea() STUB_VOID
void xScrFxDistortionAdd(xVec3*, xVec3*, int32) {}
static void xScrFxDistortionUpdate(float32 dt) STUB_VOID
static void xScrFxDistortionRender(RwCamera*) {}
void xScrFXGlareInit() STUB_VOID
void xScrFXGlareReset() STUB_VOID
int32 xScrFXGlareAdd(xVec3* pos, float32 life, float32 intensity, float32 size, float32 r, float32 g, float32 b, float32 a, RwRaster* raster) STUB
void xScrFXGlareUpdate() STUB_VOID
void xScrFXFullScreenGlareRender() STUB_VOID
void xScrFXGlareRender(xCamera* cam) STUB_VOID
void xScrFxDrawBox(float32 x1, float32 y1, float32 x2, float32 y2, uint8 red, uint8 green, uint8 blue, uint8 alpha, float32 ushift, float32 vshift) STUB_VOID