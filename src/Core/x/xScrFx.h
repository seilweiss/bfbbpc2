#pragma once

#include "xColor.h"
#include "xMath3.h"

#include <rwcore.h>

struct xCamera;

typedef void(*xScrFxFadeCallback)();

void xScrFxInit();
void xScrFxReset();
void xScrFxUpdate(RwCamera* cam, float32 dt);
void xScrFxRender(RwCamera*);
void xScrFxDrawScreenSizeRectangle();
void xScrFxFadeInit();
void xScrFxFade(xColor* base, xColor* dest, float32 seconds, xScrFxFadeCallback callback, bool32 hold);
void xScrFxStopFade();
bool32 xScrFxIsFading();
void xScrFxUpdateFade(RwCamera*, float32 seconds);
void xScrFxLetterBoxInit();
void xScrFxLetterboxReset();
void xScrFxLetterBoxSetSize(float32 size);
void xScrFxLetterBoxSetAlpha(uint8 alpha);
void xScrFxLetterbox(bool32 enable);
void xScrFxUpdateLetterBox(RwCamera*, float32 seconds);
bool32 xScrFxIsLetterbox();
void xScrFxDrawSafeArea();
void xScrFxDistortionAdd(xVec3*, xVec3*, int32);
void xScrFXGlareInit();
void xScrFXGlareReset();
int32 xScrFXGlareAdd(xVec3* pos, float32 life, float32 intensity, float32 size, float32 r, float32 g, float32 b, float32 a, RwRaster* raster);
void xScrFXGlareUpdate();
void xScrFXFullScreenGlareRender();
void xScrFXGlareRender(xCamera* cam);
void xScrFxDrawBox(float32 x1, float32 y1, float32 x2, float32 y2, uint8 red, uint8 green, uint8 blue, uint8 alpha, float32 ushift, float32 vshift);
