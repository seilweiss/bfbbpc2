#pragma once

#include "xMath2.h"
#include "xMath3.h"
#include "containers.h"

#include <rwcore.h>

struct xEnt;
struct xParEmitter;
class xDecalEmitter;

class xLaserBoltEmitter
{
public:
	struct config
	{
		float32 radius;
		float32 length;
		float32 vel;
		float32 fade_dist;
		float32 kill_dist;
		float32 safe_dist;
		float32 hit_radius;
		float32 rand_ang;
		float32 scar_life;
		xVec2 bolt_uv[2];
		int32 hit_interval;
		float32 damage;
	};

	struct bolt
	{
		xVec3 origin;
		xVec3 dir;
		xVec3 loc;
		xVec3 hit_norm;
		float32 dist;
		float32 hit_dist;
		float32 prev_dist;
		float32 prev_check_dist;
		xEnt* hit_ent;
		float32 emitted;
		void* context;
	};

	enum fx_type_enum
	{
		FX_TYPE_PARTICLE,
		FX_TYPE_DECAL,
		FX_TYPE_DECAL_DIST,
		FX_TYPE_CALLBACK
	};

	enum fx_orient_enum
	{
		FX_ORIENT_DEFAULT,
		FX_ORIENT_PATH,
		FX_ORIENT_IPATH,
		FX_ORIENT_HIT_NORM,
		FX_ORIENT_HIT_REFLECT,
		MAX_FX_ORIENT,
		FORCE_INT_FX_ORIENT = 0xffffffff
	};

	enum fx_when_enum
	{
		FX_WHEN_LAUNCH,
		FX_WHEN_IMPACT,
		FX_WHEN_BIRTH,
		FX_WHEN_DEATH,
		FX_WHEN_HEAD,
		FX_WHEN_TAIL,
		FX_WHEN_KILL,
		MAX_FX_WHEN
	};

	struct effect_data
	{
		fx_type_enum type;
		fx_orient_enum orient;
		float32 rate;
		union
		{
			xParEmitter* par;
			xDecalEmitter* decal;
			struct
			{
				void(*fp)(bolt&, void*);
				void* context;
			} callback;
		} data;
		float32 irate;
	};

private:
	config cfg;
	static_queue<bolt> bolts;
	float32 ialpha;
	RwRaster* bolt_raster;
	int32 start_collide;
	effect_data* fx[7];
	uint32 fxsize[7];

public:
	void init(ulong32 max_bolts, const char*);
	void set_texture(const char* name);
	void set_texture(uint32);
	void set_texture(RwTexture*);
	void set_texture(RwRaster*);
	void reset();
	void refresh_config();
	void emit(const xVec3& loc, const xVec3& dir);
	void update(float32 dt);
	void render();
	void attach_effects(fx_when_enum when, effect_data* fx, ulong32 fxsize);
	void pre_collide(bolt&);
	void collide_update(bolt& b);
	RwIm3DVertex* render(bolt& b, RwIm3DVertex* vert);
	RwIm3DVertex* get_vert_buffer(int32&);
	void apply_damage(bolt&);
	void reset_fx(fx_when_enum);
	void update_fx(bolt& b, float32 prev_dist, float32 dt);
	void emit_particle(effect_data& effect, bolt& b, float32 from_dist, float32 to_dist, float32 dt);
	void emit_decal(effect_data& effect, bolt& b, float32, float32 to_dist, float32);
	void emit_decal_dist(effect_data& effect, bolt& b, float32 from_dist, float32 to_dist, float32);
	bool visible() const STUB;
	void debug_init(const char*) {}
	void emit_fx(effect_data&, bolt&, float32, float32, float32) STUB_VOID;
	void perturb_dir(xVec3&, float32) STUB_VOID;
	void update(bolt&, float32) STUB_VOID;
	void debug_update() {}
	void flush_verts(RwIm3DVertex*, int32) STUB_VOID;
	void debug_render() {}
	void debug_refresh_effects(fx_when_enum) {}
	void log_collide_statics(bool) {}
	void log_collide_dynamics(bool) {}
	void set_bolt_verts(RwIm3DVertex*, const xVec3&, const xVec3&, uint8, const xVec3&) STUB_VOID;
	void set_vert(RwIm3DVertex& vert, const xVec3& loc, float32 u, float32 v, uint8 alpha) STUB_VOID;
};