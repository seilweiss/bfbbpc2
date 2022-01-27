#pragma once

#include "xBase.h"
#include "xMath3.h"

struct zEntSimpleObj;
struct xScene;

struct z_disco_floor_asset : xBaseAsset
{
	uint32 flags;
	struct
	{
		float32 transition;
		float32 state;
	} interval;
	struct
	{
		uint32 off;
		uint32 transition;
		uint32 on;
	} prefix_offset;
	ulong32 state_mask_size;
	ulong32 states_offset;
	ulong32 states_size;
};

struct z_disco_floor : xBase
{
	struct tile_data
	{
		bool culled;
		zEntSimpleObj* ent;
		xSphere sphere;
	};

	struct
	{
		bool enabled;
		bool forward;
		bool culled;
		bool glow_culled;
	} flag;
	z_disco_floor_asset* asset;
	uint8** state_masks;
	uint8* active_state_mask;
	uint8* next_state_mask;
	char* prefix[3];
	tile_data* tiles[3];
	ulong32 tiles_size;
	ulong32 min_state;
	ulong32 max_state;
	ulong32 state;
	ulong32 next_state;
	ulong32 state_counter;
	float32 transition_delay;
	float32 state_delay;
	float32 transition_time;
	float32 state_time;
	xSphere bound;
	float32 pulse_time;
	float32 pulse_glow[3];
	float32 cull_dist_glow;
	float32 cull_dist_update;
	float32 glow_fade;
	float32 sound_delay;
	int32 curr_note;

	static void init();
	static void post_setup();
	static void destroy();
	static void render_all();
	static void effects_render_all();
	static void init(void* ent, void* asset);

	void load(z_disco_floor_asset& asset);
	void setup();
	void reset();
	void update(xScene&, float32 dt);
	void set_state(ulong32 state, bool immediate);
	void enable();
	void disable();
	void set_state_range(int32 min, int32 max, bool immediate);
	void set_transition_delay(float32 s);
	void set_state_delay(float32 s);
	void refresh_spheres();
	void update_pulse(float32);
	void refresh_bound();
	void refresh_cull_dist();
	void distance_cull();
	void render(int32);
	void effects_render(int32);

	static bool32 event_handler(xBase*, xBase* to, uint32 event, const float32* argf, xBase*);
};