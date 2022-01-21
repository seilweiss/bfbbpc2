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

inline void xModelBucket_RenderAlpha() STUB_VOID