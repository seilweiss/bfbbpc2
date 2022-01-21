#include "iAnimSKB.h"

void iAnimEvalSKB(iAnimSKBHeader* data, float32 time, uint32 flags, xVec3* tran, xQuat* quat) STUB_VOID
float32 iAnimDurationSKB(iAnimSKBHeader* data) STUB
void _iAnimSKBAdjustTranslate(iAnimSKBHeader* data, uint32 bone, float32* starttran, float32* endtran) STUB_VOID
int32 _iAnimSKBExtractTranslate(iAnimSKBHeader* data, uint32 bone, xVec3* tranArray, int32) STUB