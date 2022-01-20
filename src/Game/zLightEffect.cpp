#include "zLightEffect.h"

static float32 leGetRandom() STUB
void zLightEffectInitStrobe(zLight*) STUB_VOID
void zLightEffectInitDim(zLight*) STUB_VOID
void zLightEffectInitHalfDim(zLight*) STUB_VOID
void zLightEffectInitRandomCol(zLight*) STUB_VOID
void zLightEffectInitFlicker(zLight* zlight) STUB_VOID
static void EffectFlicker(zLight* zlight, float32 seconds, float32 min, float32 rnd) STUB_VOID
void zLightEffectFlicker(zLight* zlight, float32 seconds) STUB_VOID
void zLightEffectFlickerSlow(zLight* zlight, float32 seconds) STUB_VOID
void zLightEffectFlickerErratic(zLight* zlight, float32 seconds) STUB_VOID
void zLightEffectStrobeSlow(zLight*, float32) STUB_VOID
void zLightEffectStrobe(zLight*, float32) STUB_VOID
void zLightEffectStrobeFast(zLight*, float32) STUB_VOID
void zLightEffectDimSlow(zLight*, float32) STUB_VOID
void zLightEffectDim(zLight*, float32) STUB_VOID
void zLightEffectDimFast(zLight*, float32) STUB_VOID
void zLightEffectHalfDimSlow(zLight*, float32) STUB_VOID
void zLightEffectHalfDim(zLight*, float32) STUB_VOID
void zLightEffectHalfDimFast(zLight*, float32) STUB_VOID
void zLightEffectRandomColSlow(zLight*, float32) STUB_VOID
void zLightEffectRandomCol(zLight*, float32) STUB_VOID
void zLightEffectRandomColFast(zLight*, float32) STUB_VOID
void zLightEffectInitCauldron(zLight* zlight) STUB_VOID
static float32 leBlendToCol(float32, float32, float32) STUB
void zLightEffectCauldron(zLight* zlight, float32 seconds) STUB_VOID