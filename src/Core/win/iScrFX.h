#pragma once

#include <types.h>
#include <rwcore.h>

void iScrFxInit();
void iScrFxBegin();
void iScrFxEnd();
void iScrFxDrawBox(float32 x1, float32 y1, float32 x2, float32 y2, uint8 red, uint8 green, uint8 blue, uint8 alpha);
void iCameraMotionBlurActivate(uint32 activate);
void iCameraSetBlurriness(float32 amount);
void iScrFxCameraCreated(RwCamera* pCamera);
void iScrFxCameraEndScene(RwCamera* pCamera);
void iScrFxPostCameraEnd(RwCamera*);
bool32 iScrFxMotionBlurOpen(RwCamera* camera);
bool32 iScrFxCameraDestroyed(RwCamera*);
void iScrFxMotionBlurRender(RwCamera*, uint32);