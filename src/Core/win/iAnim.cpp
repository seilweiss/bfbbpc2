#include "iAnim.h"

static uint8 scratchBuffer[9120];
uint8* giAnimScratch = scratchBuffer;

void iAnimInit() STUB_VOID
void iAnimEval(void* RawData, float32 time, uint32 flags, xVec3* tran, xQuat* quat) STUB_VOID
float32 iAnimDuration(void* RawData) STUB
uint32 iAnimBoneCount(void* RawData) STUB
void iAnimBlend(float32 BlendFactor, float32 BlendRecip, uint16* BlendTimeOffset, float32* BoneTable, uint32 BoneCount, xVec3* Tran1, xQuat* Quat1, xVec3* Tran2, xQuat* Quat2, xVec3* TranDest, xQuat* QuatDest) STUB_VOID