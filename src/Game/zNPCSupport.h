#pragma once

#include "xEnt.h"

enum en_npctgt
{
	NPC_TGT_NONE,
	NPC_TGT_PLYR,
	NPC_TGT_ENT,
	NPC_TGT_BASE,
	NPC_TGT_POS,
	NPC_TGT_MVPT,
	NPC_TGT_NOMORE,
	NPC_TGT_FORCEINT = FORCEENUMSIZEINT
};

class NPCTarget
{
private:
	en_npctgt typ_target;
	union
	{
		xEnt* ent_target;
		xBase* bas_target;
		xVec3 pos_target;
		zMovePoint* nav_target;
	};
	zNPCCommon* npc_owner;

public:
	bool32 HaveTarget() STUB;
};

class NPCBlinker
{
private:
	float32 tmr_uvcell;
	int32 idx_uvcell;
};

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
	void Prepare() STUB_VOID;
	void RadiusSet(float32, float32) STUB_VOID;
	void UVScrollSet(float32, float32) STUB_VOID;
	void TextureSet(RwRaster*) STUB_VOID;
	RwRaster* TextureGet() STUB;
	void UVScrollUpdate(float32) STUB_VOID;
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
inline float32 RANGEWRAP(float32*, float32, float32) STUB