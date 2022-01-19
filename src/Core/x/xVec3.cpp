#include "xVec3.h"

const xVec3 xVec3::m_Null = { 0.0f, 0.0f, 0.0f };
const xVec3 xVec3::m_UnitAxisX = { 1.0f, 0.0f, 0.0f };
const xVec3 xVec3::m_UnitAxisY = { 0.0f, 1.0f, 0.0f };

float32 xVec3Normalize(xVec3* o, const xVec3* v) STUB
float32 xVec3NormalizeFast(xVec3* o, const xVec3* v) STUB