#include "iScrFX.h"

inline RwRaster* FBMBlur_DebugIntervention(RwCamera*, RwRaster*) STUB

void iScrFxInit() {}
void iScrFxBegin() STUB_VOID
void iScrFxEnd() STUB_VOID
void iScrFxDrawBox(float32 x1, float32 y1, float32 x2, float32 y2, uint8 red, uint8 green, uint8 blue, uint8 alpha) STUB_VOID
void iCameraMotionBlurActivate(uint32 activate) STUB_VOID
void iCameraSetBlurriness(float32 amount) STUB_VOID
void iScrFxCameraCreated(RwCamera* pCamera) STUB_VOID
void iScrFxCameraEndScene(RwCamera* pCamera) STUB_VOID
void iScrFxPostCameraEnd(RwCamera*) STUB_VOID
static void iCameraOverlayRender(RwCamera*, RwRaster* ras, RwRGBA col) STUB_VOID
bool32 iScrFxMotionBlurOpen(RwCamera* camera) STUB
bool32 iScrFxCameraDestroyed(RwCamera*) STUB
void iScrFxMotionBlurRender(RwCamera*, uint32) STUB_VOID