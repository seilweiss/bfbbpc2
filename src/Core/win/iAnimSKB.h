#pragma once

#include "xMath3.h"

struct iAnimSKBHeader
{
	uint32 Magic;
	uint32 Flags;
	uint16 BoneCount;
	uint16 TimeCount;
	uint32 KeyCount;
	float32 Scale[3];
};

void iAnimEvalSKB(iAnimSKBHeader* data, float32 time, uint32 flags, xVec3* tran, xQuat* quat);
float32 iAnimDurationSKB(iAnimSKBHeader* data);
void _iAnimSKBAdjustTranslate(iAnimSKBHeader* data, uint32 bone, float32* starttran, float32* endtran);
int32 _iAnimSKBExtractTranslate(iAnimSKBHeader* data, uint32 bone, xVec3* tranArray, int32);