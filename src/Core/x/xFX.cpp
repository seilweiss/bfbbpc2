#include "xFX.h"

typedef struct _xFXAuraAngle
{
	float32 angle;
	float32 cc;
	float32 ss;
} xFXAuraAngle;

void xFXInit() STUB_VOID
static void DrawRingSetup() STUB_VOID
static void DrawRingSceneExit() STUB_VOID
static void DrawRing(xFXRing* m) STUB_VOID
xFXRing* xFXRingCreate(const xVec3* pos, const xFXRing* params) STUB
static void xFXRingUpdate(float32 dt) STUB_VOID
void xFXRingRender() STUB_VOID
void xFX_SceneEnter(RpWorld* world) STUB_VOID
void xFX_SceneExit(RpWorld*) STUB_VOID
void xFXUpdate(float32 dt) STUB_VOID
static void LightResetFrame(RpLight*) STUB_VOID
static RpMaterial* MaterialDisableMatFX(RpMaterial* material, void*) STUB
RpAtomic* AtomicDisableMatFX(RpAtomic* atomic) STUB
static RpAtomic* PreAllocMatFX_cb(RpAtomic* atomic, void*) STUB
void xFXPreAllocMatFX(RpClump* clump) STUB_VOID
RpMaterial* MaterialSetShininess(RpMaterial* material, void*) STUB
static RpAtomic* AtomicSetShininess(RpAtomic*, void*) STUB
static RpMaterial* MaterialSetEnvMap(RpMaterial* material, void* data) STUB
RpMaterial* MaterialSetEnvMap2(RpMaterial* material, void* data) STUB
RpAtomic* xFXBubbleRender(RpAtomic* atomic) STUB
RpAtomic* xFXShinyRender(RpAtomic* atomic) STUB
static RpAtomic* AtomicSetEnvMap(RpAtomic*, void*) STUB
RpAtomic* xFXAtomicEnvMapSetup(RpAtomic* atomic, uint32 envmapID, float32 shininess) STUB
static RpMaterial* MaterialSetBumpMap(RpMaterial*, void*) STUB
static RpMaterial* MaterialSetBumpEnvMap(RpMaterial*, RwTexture*, float32, RwTexture*, float32) STUB
void xFXanimUVSetTranslation(const xVec3* trans) STUB_VOID
void xFXanimUVSetScale(const xVec3* scale) STUB_VOID
void xFXanimUVSetAngle(float32 angle) STUB_VOID
void xFXanimUV2PSetTranslation(const xVec3* trans) STUB_VOID
void xFXanimUV2PSetScale(const xVec3* scale) STUB_VOID
void xFXanimUV2PSetAngle(float32 angle) STUB_VOID
void xFXanimUV2PSetTexture(RwTexture* texture) STUB_VOID
RpAtomic* xFXanimUVAtomicSetup(RpAtomic* atomic) STUB
bool32 xFXanimUVCreate() STUB

namespace {

	struct vert_data
	{
		xVec3 loc;
		xVec3 norm;
		RwRGBA color;
		RwTexCoords uv;
		float32 depth;
	};

	struct tri_data
	{
		vert_data vert[3];

		void init(const xVec3*, const xVec3*, const RwTexCoords*, const float32*, const uint16*) STUB_VOID;
	};

	void depth_sort(uint16* index, const tri_data* tri, ulong32 size) STUB_VOID;

	inline void set_vert(RwIm3DVertex& vert, const vert_data& vd) STUB_VOID;
	inline void push_triangle(RwIm3DVertex*&, const tri_data&) STUB_VOID;
	inline void lerp(float32&, float32, float32, float32) STUB_VOID;
	inline void lerp(xVec3&, float32, const xVec3&, const xVec3&) STUB_VOID;
	inline void lerp(uint8&, float32, uint8, uint8) STUB_VOID;
	inline void lerp(RwRGBA&, float32, RwRGBA, RwRGBA) STUB_VOID;
	inline void lerp(RwTexCoords&, float32, const RwTexCoords&, const RwTexCoords&) STUB_VOID;
	inline void lerp(vert_data& v, float32 frac, const vert_data& v0, const vert_data& v1) STUB_VOID;
	inline int32 clip_triangle(tri_data*, const tri_data&, float32) STUB;
	inline void refresh_vert_buffer(RwIm3DVertex*&, bool) STUB_VOID;
	inline int32 count_alpha_triangles(const RpTriangle*, const float32*, ulong32) STUB;

}

void xFXRenderProximityFade(const xModelInstance& model, float32 near_dist, float32 far_dist) STUB_VOID
void xFXFireworksInit(const char* fireworksTrailEmitter, const char* fireworksEmitter1, const char* fireworksEmitter2, const char* fireworksSound, const char* fireworksLaunchSound) STUB_VOID
void xFXFireworksLaunch(float32 countdownTime, const xVec3* pos, float32 fuelTime) STUB_VOID
void xFXFireworksUpdate(float32 dt) STUB_VOID
void xFXStreakInit() STUB_VOID
void xFXStreakUpdate(float32 dt) STUB_VOID
void xFXStreakRender() STUB_VOID
uint32 xFXStreakStart(float32 frequency, float32 alphaFadeRate, float32 alphaStart, uint32 textureID, const xColor* edge_a, const xColor* edge_b, bool32 taper) STUB
void xFXStreakStop(uint32 id) STUB_VOID
void xFXStreakUpdate(uint32 id, const xVec3* a, const xVec3* b) STUB_VOID
void xFXShineInit() STUB_VOID
void xFXShineUpdate(float32 dt) STUB_VOID
void xFXShineRender() STUB_VOID
uint32 xFXShineStart(const xVec3*, float32, float32, float32, float32, uint32, const xColor*, const xColor*, float32, int32) STUB

namespace {

	int32 compare_ribbons(const void* e1, const void* e2) STUB;
	void sort_ribbons() STUB_VOID;
	void activate_ribbon(xFXRibbon*) STUB_VOID;
	void deactivate_ribbon(xFXRibbon*) STUB_VOID;

}

void xFXRibbon::init(const char*, const char*) STUB_VOID
void xFXRibbon::set_default_config() STUB_VOID
void xFXRibbon::refresh_config() STUB_VOID
void xFXRibbon::set_curve(const curve_node* curve, ulong32 size) STUB_VOID
void xFXRibbon::insert(const xVec3& loc, const xVec3& norm, float32 scale, float32 alpha, uint32 flags) STUB_VOID
void xFXRibbon::insert(const xVec3& loc, float32 orient, float32 scale, float32 alpha, uint32 flags) STUB_VOID
void xFXRibbon::activate() STUB_VOID
void xFXRibbon::deactivate() STUB_VOID
void xFXRibbon::update(float32 dt) STUB_VOID
void xFXRibbon::start_render() STUB_VOID
void xFXRibbon::render() STUB_VOID
void xFXRibbon::set_raster(RwRaster*) STUB_VOID
void xFXRibbon::set_texture(RwTexture*) STUB_VOID
void xFXRibbon::set_texture(uint32 id) STUB_VOID
void xFXRibbon::set_texture(const char* name) STUB_VOID
void xFXRibbon::get_normal(xVec3& norm, const xVec3& dir, float32 orient) STUB_VOID
void xFXRibbon::eval_joint(const joint_data& joint, xColor& color, float32& width) STUB_VOID

namespace {

	inline void set_vert(RwIm3DVertex&, const xVec3&, float32, float32, xColor) STUB_VOID;

}

void xFXRibbon::render_strip(RwIm3DVertex* verts, tier_queue<joint_data>::iterator first, ulong32 size) STUB_VOID
int32 xFXRibbon::render_compare(const xFXRibbon& c) const STUB

void xFXRibbonSceneEnter() STUB_VOID
void xFXRibbonUpdate(float32) STUB_VOID
void xFXRibbonRender() STUB_VOID
void xFXAuraInit() STUB_VOID
void xFXAuraSetup() STUB_VOID
void xFXAuraAdd(void* parent, xVec3* pos, xColor* color, float32 size) STUB_VOID
void xFXAuraUpdate(float32 dt) STUB_VOID
static void RenderRotatedBillboard(xVec3* pos, xFXAuraAngle* rot, uint32 count, float32 width, float32 height, xColor tint, uint32 flipUV) STUB_VOID
void xFXAuraRender() STUB_VOID
void xFXStartup() STUB_VOID
void xFXShutdown() STUB_VOID
void xFXSceneInit() STUB_VOID
void xFXSceneSetup() STUB_VOID
void xFXSceneReset() STUB_VOID
void xFXScenePrepare() STUB_VOID
void xFXSceneFinish() STUB_VOID