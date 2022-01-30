#pragma once

#include "xMath3.h"

#define IANIMEVAL_UNK0x2 0x2

extern uint8* giAnimScratch;

void iAnimInit();
void iAnimEval(void* RawData, float32 time, uint32 flags, xVec3* tran, xQuat* quat);
float32 iAnimDuration(void* RawData);
uint32 iAnimBoneCount(void* RawData);
void iAnimBlend(float32 BlendFactor, float32 BlendRecip, uint16* BlendTimeOffset, float32* BoneTable, uint32 BoneCount, xVec3* Tran1, xQuat* Quat1, xVec3* Tran2, xQuat* Quat2, xVec3* TranDest, xQuat* QuatDest);