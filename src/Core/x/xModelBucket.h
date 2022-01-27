#pragma once

#include "xModel.h"

struct xModelBucket
{
	RpAtomic* Data;
	RpAtomic* OriginalData;
	xModelInstance* List;
	int32 ClipFlags;
	uint32 PipeFlags;
};

void xModelBucket_PreCountReset();
void xModelBucket_PreCountBucket(RpAtomic* data, uint32 pipeFlags, uint32 subObjects);
void xModelBucket_PreCountAlloc(int32 maxAlphaModels);
void FullAtomicDupe(RpAtomic* atomic, int32 count, RpAtomic** output);
void xModelBucket_InsertBucket(RpAtomic* data, uint32 pipeFlags, uint32 subObjects);
void xModelBucket_Init();
xModelBucket** xModelBucket_GetBuckets(RpAtomic* data);
void xModelBucket_Begin();
void xModelBucket_Add(xModelInstance* minst);
void xModelBucket_RenderOpaque();
void xModelBucket_RenderAlphaBegin();
void xModelBucket_RenderAlphaLayer(int32 maxLayer);
void xModelBucket_RenderAlphaEnd();
void xModelBucket_Deinit();

inline void xModelBucket_RenderAlpha() STUB_VOID