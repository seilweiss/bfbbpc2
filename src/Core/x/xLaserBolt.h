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
	bool visible() const STUB;
};