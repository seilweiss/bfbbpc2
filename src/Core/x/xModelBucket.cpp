#include "xModelBucket.h"

static int32 CmpAlphaBucket(const void* _a, const void* _b) STUB

void xModelBucket_PreCountReset() STUB_VOID
void xModelBucket_PreCountBucket(RpAtomic* data, uint32 pipeFlags, uint32 subObjects) STUB_VOID
void xModelBucket_PreCountAlloc(int32 maxAlphaModels) STUB_VOID
void FullAtomicDupe(RpAtomic* atomic, int32 count, RpAtomic** output) STUB_VOID
void xModelBucket_InsertBucket(RpAtomic* data, uint32 pipeFlags, uint32 subObjects) STUB_VOID
void xModelBucket_Init() STUB_VOID
xModelBucket** xModelBucket_GetBuckets(RpAtomic* data) STUB
void xModelBucket_Begin() STUB_VOID
void xModelBucket_Add(xModelInstance* minst) STUB_VOID
void xModelBucket_RenderOpaque() STUB_VOID
void xModelBucket_RenderAlphaBegin() STUB_VOID
void xModelBucket_RenderAlphaLayer(int32 maxLayer) STUB_VOID
void xModelBucket_RenderAlphaEnd() STUB_VOID
void xModelBucket_Deinit() STUB_VOID