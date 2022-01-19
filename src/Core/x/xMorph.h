#pragma once

#include <types.h>
#include <rwcore.h>

struct xMorphSeqFile
{
	uint32 Magic;
	uint32 Flags;
	uint32 TimeCount;
	uint32 ModelCount;
};

typedef void* (*xMorphSeqFindAssetCB)(uint32, char*);

xMorphSeqFile* xMorphSeqSetup(void* data, xMorphSeqFindAssetCB FindAssetCB);
void xMorphRender(xMorphSeqFile* seq, RwMatrix* mat, float32 time);
float32 xMorphSeqDuration(xMorphSeqFile* seq);