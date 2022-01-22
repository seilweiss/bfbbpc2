#pragma once

#include "xMath3.h"
#include "xColor.h"

inline void xDrawBegin() {}
inline void xDrawEnd() {}
inline void xDrawSetColor(xColor) {}
inline void xDrawSetColor(uint8, uint8, uint8, uint8) {}
inline void xDrawBox(const xBox*) {}
inline void xDrawOBB(const xBox*, const xMat4x3*) {}
inline void xDrawSphere(const xSphere*, uint32) {}
inline void xDrawSphere(const xVec3*, float32, uint32) {}
inline void xDrawSphere2(const xSphere*, uint32) {}
inline void xDrawSphere2(const xVec3*, float32, uint32) {}
inline void xDrawLine(const xVec3*, const xVec3*) {}
inline void xDrawCyl(const xVec3*, float32, float32, uint32) {}