#pragma once

#include "zLight.h"

void zLightEffectInitStrobe(zLight*);
void zLightEffectInitDim(zLight*);
void zLightEffectInitHalfDim(zLight*);
void zLightEffectInitRandomCol(zLight*);
void zLightEffectInitFlicker(zLight* zlight);
void zLightEffectFlicker(zLight* zlight, float32 seconds);
void zLightEffectFlickerSlow(zLight* zlight, float32 seconds);
void zLightEffectFlickerErratic(zLight* zlight, float32 seconds);
void zLightEffectStrobeSlow(zLight*, float32);
void zLightEffectStrobe(zLight*, float32);
void zLightEffectInitCauldron(zLight* zlight);
void zLightEffectCauldron(zLight* zlight, float32 seconds);