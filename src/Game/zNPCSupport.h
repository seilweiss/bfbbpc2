#pragma once

#include "xEnt.h"

class NPCLaser
{
private:
	RwRaster* rast_laser;
	float32 radius[2];
	float32 uv_scroll[2];
	RwRGBA rgba[2];
	float32 uv_base[2];

public:
	void ColorSet(const RwRGBA*, const RwRGBA*) STUB_VOID;
};

inline xVec3* NPCC_rightDir(xEnt* ent) STUB
inline xVec3* NPCC_upDir(xEnt* ent) STUB
inline xVec3* NPCC_faceDir(xEnt* ent) STUB
inline float32 NPCC_DstSq(const xVec3*, const xVec3*, xVec3*) STUB
inline void NPCC_DrawPlayerPredict(int32, float32, float32) {}
inline uint8 LERP(float32, uint8, uint8) STUB
inline float32 LERP(float32, float32, float32) STUB
inline float32 EASE(float32) STUB
inline float32 SMOOTH(float32, float32, float32) STUB