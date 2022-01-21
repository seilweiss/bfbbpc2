#include "iMorph.h"

static void MorphCommon(RpAtomic* model, RwMatrix* mat, int16** v_array, int16* weight, uint32 normals, float32 scale, int32 dorender) STUB_VOID
void iMorphOptimize(RpAtomic* model, int32 normals) STUB_VOID
void iMorphRender(RpAtomic* model, RwMatrix* mat, int16** v_array, int16* weight, uint32 normals, float32 scale) STUB_VOID
void FastS16unpack(float32* dest, int16* v, int32 count, float32 scale) STUB_VOID
void FastS16weight2(float32* dest, int16** v_array, int16* weight, int32 count, float32 scale) STUB_VOID
void FastS16weight4(float32* dest, int16** v_array, int16* weight, int32 count, float32 scale) STUB_VOID