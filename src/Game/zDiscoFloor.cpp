#include "zDiscoFloor.h"

#include "zEntSimpleObj.h"
#include "xSurface.h"
#include "xColor.h"

namespace {

	void create_glow_light() STUB_VOID;
	void destroy_glow_light() STUB_VOID;
	void object_prefix(const char* name, ulong32& size, ulong32& first) STUB_VOID;
	zEntSimpleObj* find_object(const char*) STUB;
	ulong32 find_tiles(const char* name, z_disco_floor::tile_data* tiles, ulong32 size) STUB;
	uint32 get_tile(const uint8*, ulong32) STUB;
	void set_tile(uint8*, ulong32, uint32) STUB_VOID;
	void translate_mask(uint8*, const uint8*, ulong32) STUB_VOID;
	void refresh_state(z_disco_floor& df) STUB_VOID;
	void set_object_state(const z_disco_floor&, ulong32, int32) STUB_VOID;
	void play_sound(z_disco_floor& df) STUB_VOID;
	float32 update_transition(z_disco_floor&, float32) STUB;
	ulong32 state_byte_size(ulong32) STUB;
	void update_state(z_disco_floor& df, float32 dt) STUB_VOID;
	xSurface& get_damage_surface() STUB_REF(xSurface);
	void render_model(xModelInstance*, const xSphere&) STUB_VOID;
	void render_model(xModelInstance*, xSphere&, float32) STUB_VOID;

	struct render_context
	{
		xMat4x3 mat;
		xColor color;
	};

	struct bucket_data
	{
		RpAtomic* atomic;
		RpAtomic* atomic_clone;
		render_context* rc;
		uint16 size;
		uint16 used;
	};

	struct clone_pipe_data
	{
		bucket_data* buckets;
		uint32 buckets_size;
		RwFrame** frames;
		RwRGBAReal* colors;

		void init() {}
		void post_setup() {}
		void destroy() {}
	};

	inline void add_global_tweaks() {}
	inline void add_tweaks(z_disco_floor&) {}

}

void z_disco_floor::init() STUB_VOID
void z_disco_floor::post_setup() STUB_VOID
void z_disco_floor::destroy() STUB_VOID
void z_disco_floor::render_all() STUB_VOID
void z_disco_floor::effects_render_all() STUB_VOID
void z_disco_floor::init(void* ent, void* asset) STUB_VOID
void z_disco_floor::load(z_disco_floor_asset& asset) STUB_VOID
void z_disco_floor::setup() STUB_VOID
void z_disco_floor::reset() STUB_VOID
void z_disco_floor::update(xScene&, float32 dt) STUB_VOID
void z_disco_floor::set_state(ulong32 state, bool immediate) STUB_VOID
void z_disco_floor::enable() STUB_VOID
void z_disco_floor::disable() STUB_VOID
void z_disco_floor::set_state_range(int32 min, int32 max, bool immediate) STUB_VOID
void z_disco_floor::set_transition_delay(float32 s) STUB_VOID
void z_disco_floor::set_state_delay(float32 s) STUB_VOID
void z_disco_floor::refresh_spheres() STUB_VOID
void z_disco_floor::update_pulse(float32) STUB_VOID
void z_disco_floor::refresh_bound() STUB_VOID
void z_disco_floor::refresh_cull_dist() STUB_VOID
void z_disco_floor::distance_cull() STUB_VOID
void z_disco_floor::render(int32) STUB_VOID
void z_disco_floor::effects_render(int32) STUB_VOID
bool32 z_disco_floor::event_handler(xBase*, xBase* to, uint32 event, const float32* argf, xBase*) STUB