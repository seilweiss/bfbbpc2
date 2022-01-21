#pragma once

#include <types.h>
#include <rwcore.h>
#include <rpworld.h>

void iMorphOptimize(RpAtomic* model, int32 normals);
void iMorphRender(RpAtomic* model, RwMatrix* mat, int16** v_array, int16* weight, uint32 normals, float32 scale);
void FastS16unpack(float32* dest, int16* v, int32 count, float32 scale);
void FastS16weight2(float32* dest, int16** v_array, int16* weight, int32 count, float32 scale);
void FastS16weight4(float32* dest, int16** v_array, int16* weight, int32 count, float32 scale);