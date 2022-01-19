#pragma once

#include "xMath3.h"
#include "xColor.h"
#include "containers.h"

#include <rwcore.h>
#include <rpworld.h>

struct xModelInstance;

struct xFXRing
{
	uint32 texture;
	float32 lifetime;
	xVec3 pos;
	float32 time;
	float32 ring_radius;
	float32 ring_radius_delta;
	float32 ring_tilt;
	float32 ring_tilt_delta;
	float32 ring_height;
	float32 ring_height_delta;
	xColor ring_color;
	uint16 ring_segs;
	uint8 u_repeat;
	uint8 v_repeat;
	xFXRing** parent;
};

struct xFXRibbon
{
	struct config
	{
		float32 life_time;
		uint32 blend_src;
		uint32 blend_dst;
		float32 pivot;
	};

	struct joint_data
	{
		uint32 flags;
		uint32 born;
		xVec3 loc;
		xVec3 norm;
		float32 orient;
		float32 scale;
		float32 alpha;
	};

	struct curve_node
	{
		float32 time;
		xColor color;
		float32 scale;
	};

	config cfg;
	bool activated;
	RwRaster* raster;
	tier_queue<joint_data> joints;
	curve_node* curve;
	uint32 curve_size;
	uint32 curve_index;
	float32 ilife;
	uint32 mtime;
	uint32 mlife;

	void init(const char*, const char*);
	void set_default_config();
	void refresh_config();
	void set_curve(const curve_node* curve, ulong32 size);
	void insert(const xVec3& loc, const xVec3& norm, float32 scale, float32 alpha, uint32 flags);
	void insert(const xVec3& loc, float32 orient, float32 scale, float32 alpha, uint32 flags);
	void activate();
	void deactivate();
	void update(float32 dt);
	void start_render();
	void render();
	void set_raster(RwRaster*);
	void set_texture(RwTexture*);
	void set_texture(uint32 id);
	void set_texture(const char* name);
	void get_normal(xVec3& norm, const xVec3& dir, float32 orient);
	void refresh_joint(joint_data& joint, const tier_queue<joint_data>::iterator& it);
	void eval_joint(const joint_data& joint, xColor& color, float32& width);
	void render_strip(RwIm3DVertex* verts, tier_queue<joint_data>::iterator first, ulong32 size);
	int32 render_compare(const xFXRibbon& c) const;
	void debug_init(const char*, const char*) WIP {}
	void update_curve_tweaks() WIP {}
	void debug_update_curve() WIP {}
	bool need_update() const STUB;
	bool debug_need_update() const WIP { return false; }
	bool visible() const STUB;
	void debug_update() WIP {}
	float32 get_age(const joint_data&) const STUB;
};

void xFXInit();
xFXRing* xFXRingCreate(const xVec3* pos, const xFXRing* params);
void xFXRingRender();
void xFX_SceneEnter(RpWorld* world);
void xFX_SceneExit(RpWorld*);
void xFXUpdate(float32 dt);
RpAtomic* AtomicDisableMatFX(RpAtomic* atomic);
void xFXPreAllocMatFX(RpClump* clump);
RpMaterial* MaterialSetShininess(RpMaterial* material, void*);
RpMaterial* MaterialSetEnvMap2(RpMaterial* material, void* data);
RpAtomic* xFXBubbleRender(RpAtomic* atomic);
RpAtomic* xFXShinyRender(RpAtomic* atomic);
RpAtomic* xFXAtomicEnvMapSetup(RpAtomic* atomic, uint32 envmapID, float32 shininess);
void xFXanimUVSetTranslation(const xVec3* trans);
void xFXanimUVSetScale(const xVec3* scale);
void xFXanimUVSetAngle(float32 angle);
void xFXanimUV2PSetTranslation(const xVec3* trans);
void xFXanimUV2PSetScale(const xVec3* scale);
void xFXanimUV2PSetAngle(float32 angle);
void xFXanimUV2PSetTexture(RwTexture* texture);
RpAtomic* xFXanimUVAtomicSetup(RpAtomic* atomic);
bool32 xFXanimUVCreate();
void xFXRenderProximityFade(const xModelInstance& model, float32 near_dist, float32 far_dist);
void xFXFireworksInit(const char* fireworksTrailEmitter, const char* fireworksEmitter1, const char* fireworksEmitter2, const char* fireworksSound, const char* fireworksLaunchSound);
void xFXFireworksLaunch(float32 countdownTime, const xVec3* pos, float32 fuelTime);
void xFXFireworksUpdate(float32 dt);
void xFXStreakInit();
void xFXStreakUpdate(float32 dt);
void xFXStreakRender();
uint32 xFXStreakStart(float32 frequency, float32 alphaFadeRate, float32 alphaStart, uint32 textureID, const xColor* edge_a, const xColor* edge_b, bool32 taper);
void xFXStreakStop(uint32 id);
void xFXStreakUpdate(uint32 id, const xVec3* a, const xVec3* b);
void xFXShineInit();
void xFXShineUpdate(float32 dt);
void xFXShineRender();
uint32 xFXShineStart(const xVec3*, float32, float32, float32, float32, uint32, const xColor*, const xColor*, float32, int32);
void xFXRibbonSceneEnter();
void xFXRibbonUpdate(float32);
void xFXRibbonRender();
void xFXAuraInit();
void xFXAuraSetup();
void xFXAuraAdd(void* parent, xVec3* pos, xColor* color, float32 size);
void xFXAuraUpdate(float32 dt);
void xFXAuraRender();
void xFXStartup();
void xFXShutdown();
void xFXSceneInit();
void xFXSceneSetup();
void xFXSceneReset();
void xFXScenePrepare();
void xFXSceneFinish();