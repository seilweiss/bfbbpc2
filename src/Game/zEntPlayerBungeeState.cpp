#include "zEntPlayerBungeeState.h"

#include "xDebug.h"

namespace bungee_state {

	namespace {

		enum sound_enum
		{
			SOUND_INVALID = -1,
			BEGIN_SOUND = 0,
			SOUND_ATTACH = BEGIN_SOUND,
			SOUND_ATTACH_COMMENT,
			SOUND_DETACH,
			SOUND_DIVE,
			SOUND_PEAK,
			SOUND_WIND_LOOP,
			SOUND_THUMP,
			SOUND_DAMAGE,
			SOUND_DEATH,
			END_SOUND,
			MAX_SOUND = END_SOUND
		};

		void play_sound(sound_enum which, float32 delay) STUB_VOID;
		void stop_sound(int32) STUB_VOID;
		void set_volume(int32, float32) STUB_VOID;
		void init_models() STUB_VOID;
		void show_models() STUB_VOID;
		void hide_models() STUB_VOID;
		void render_player(bool) STUB_VOID;
		void move_wedgie(const xVec3& stretch_loc) STUB_VOID;
		void update_hook_loc() STUB_VOID;
		bool find_drop_off() STUB;
		void trigger(uint32) STUB_VOID;

		enum state_enum
		{
			STATE_INVALID = -1,
			BEGIN_STATE = 0,
			STATE_ATTACHING = BEGIN_STATE,
			STATE_HANGING,
			END_STATE,
			MAX_STATE = END_STATE
		};

		class state_type
		{
		private:
			state_enum type;

		public:
			state_type(state_enum type) WIP : type(type) {}

			virtual void start() {}
			virtual void stop() {}
			virtual state_enum update(xScene& s, float32& dt) = 0;
			virtual void render() {}
		};

		class attaching_state_type : public state_type
		{
		private:
			xVec3* loc;
			xVec3* vel;
			xVec3 last_hook_loc;
			xVec3 hook_vel;
			float32 time_left;
			float32 time;
			float32 end_time;
			xVec3 player_loc;
			xVec3 player_vel;
			
		public:
			attaching_state_type() WIP : state_type(STATE_ATTACHING) {}

			virtual void start();
			virtual void stop();
			virtual state_enum update(xScene& s, float32& dt);
			virtual void render();
		};

		class hanging_state_type : public state_type
		{
		private:
			struct ent_info
			{
				xEnt* ent;
				int32 hits;
			};

			struct env_info
			{
				xEnv* env;
				uint8 collide;
				int32 hits;
			};

			class cb_cache_collisions
			{
			private:
				const xSphere& o;
				ent_info* ent_cache;
				int32& ent_cache_size;

			public:
				cb_cache_collisions(const xSphere& o, ent_info* ent_cache, int32& ent_cache_size) WIP : o(o), ent_cache(ent_cache), ent_cache_size(ent_cache_size) {}

				bool operator()(xEnt&, xGridBound&) STUB;
			};

			xVec3 loc;
			xVec3 vel;
			xVec3 last_loc;
			xVec3 last_hook_loc;
			xVec3 cam_loc;
			xVec3 cam_vel;
			xVec3 cam_dir;
			xVec3 cam_dir_vel;
			float32 dive_remaining;
			float32 rot;
			float32 rot_vel;
			xVec2 stick_loc;
			float32 stick_ang;
			float32 stick_mag;
			float32 stick_frac;
			xVec3 collide_accel;
			float32 roll_offset;
			uint8 detaching;
			xVec3 drop_off_vel;
			float32 max_yvel;
			uint8 dying;
			float32 control_lag_timer;
			float32 control_lag_max;
			uint8 has_dived;
			uint8 can_dive;
			uint32 last_health;
			struct
			{
				float32 time;
				float32 end_time;
				xVec3 start_loc;
				xVec3 end_loc;
				xQuat start_dir;
				xQuat end_dir;
			} detach;
			xModelInstance* root_model;
			xModelInstance* ass_model;
			xModelInstance* pants_model;
			hook_asset h;
			struct
			{
				struct
				{
					float32 rest_dist;
					float32 emax;
					float32 spring;
					float32 alpha;
					float32 omega;
				} vertical;
				struct
				{
					float32 vscale;
					float32 hscale;
					float32 roll_decay;
				} camera;
			} eh;
			ent_info ent_cache[256];
			int32 ent_cache_size;
			env_info env_cache;

		public:
			hanging_state_type() WIP : state_type(STATE_HANGING) {}

			virtual void start();
			virtual void stop();
			virtual state_enum update(xScene& s, float32& dt);
			virtual void render();

			xVec3 local_to_world(const xVec3& vl) const;
			xVec3 world_to_local(const xVec3& vw) const;
			void init_camera() STUB_VOID;
			void allow_dive(bool) STUB_VOID;
			void show_help() STUB_VOID;
			void hide_help() STUB_VOID;
			void update_sound(float32) STUB_VOID;
			void update_blur(float32) STUB_VOID;
			xSphere player_bound() const STUB;
			void multiply_dampening(float32) STUB_VOID;
			void short_drop_sudden_stop() STUB_VOID;
			void check_damage(bool thump) STUB_VOID;
			bool collide(xCollis&, const xSphere&, const xEnt&) const STUB;
			float32 trigger_collision(ent_info& ei, float32 mag, const xCollis&) STUB;
			bool ents_repath(const xScene&) STUB;
			void ouchie(bool) STUB_VOID;
			void trigger_collision(env_info& ei, float32 mag, const xCollis& coll) STUB_VOID;
			bool env_repath(const xScene&) STUB;
			int32 clip_nearest(float32&, float32&, float32, float32, float32) const STUB;
			bool hit_boundary(xVec3& norm, xVec3& depen, const xVec3& v) const STUB;
			bool boundary_repath(const xScene&) STUB;
			bool repath(const xScene& s) STUB;
			void collide_start(xScene& s) STUB_VOID;
			void update_collision(xScene&, float32) STUB_VOID;
			void rotate_camera() STUB_VOID;
			void update_camera_direction(float32) STUB_VOID;
			bool update_free_look(float32) WIP { return false; }
			void interpolate_camera_loc(const xVec3& dest, float32 dt) STUB_VOID;
			void update_camera(float32) STUB_VOID;
			void update_animation(float32 dt) STUB_VOID;
			void calc_movement(float32&, float32&, float32&, float32, float32, float32, float32, float32, float32) STUB_VOID;
			void update_vmovement(float32 dt) STUB_VOID;
			void update_hmovement(float32&, float32&, float32, float32, float32, float32) STUB_VOID;
			void update_hmovement(float32 dt) STUB_VOID;
			void update_heading(float32 dt) STUB_VOID;
			void update_movement(float32) STUB_VOID;
			void update_detach_camera(float32 dt) STUB_VOID;
			void detach_update(xScene&, float32&) STUB_VOID;
			void calc_drop_off_velocity(xVec3& v, const xVec3& from, const xVec3& to, float32 g, float32 t) STUB_VOID;
			void start_detaching() STUB_VOID;

			float32 find_spring_min(float32 min_dist, float32 max_dist, float32, float32 damp) const STUB;
			float32 spring_potential_energy(float32, float32) const STUB;
			float32 spring_potential_energy(float32, float32, float32, float32) const STUB;
			float32 kinetic_energy(float32) const STUB;
			float32 spring_energy(float32 x, float32 v, float32 k, float32 g, float32 xc) const STUB;
			float32 spring_velocity(float32 x, float32 v, float32 e, float32 k, float32 g, float32 xc) const STUB;

			void reset_props_vertical() STUB_VOID;
			void reset_props_horizontal() STUB_VOID;
			void reset_props_camera() STUB_VOID;
			void reset_props_collision() STUB_VOID;

			static void on_tweak_vertical(const tweak_info&) STUB_VOID;
			static void on_tweak_horizontal(const tweak_info&) STUB_VOID;
			static void on_tweak_camera(const tweak_info&) STUB_VOID;
			static void on_tweak_collision(const tweak_info&) STUB_VOID;
		};

		uint32 check_anim_start(xAnimTransition*, xAnimSingle*, void*) STUB;
		uint32 check_anim_hit_to_dive(xAnimTransition*, xAnimSingle*, void*) STUB;
		uint32 check_anim_hit_to_top(xAnimTransition*, xAnimSingle*, void*) STUB;
		uint32 check_anim_hit_to_bottom(xAnimTransition*, xAnimSingle*, void*) STUB;
		uint32 check_anim_hit_to_cycle(xAnimTransition*, xAnimSingle*, void*) STUB;
		uint32 check_anim_hit_to_death(xAnimTransition*, xAnimSingle*, void*) STUB;
		int32 find_nearest_hook(const xVec3& loc) STUB;
		void init_sounds() {}
		xModelInstance* get_hook_model() STUB;
		void fade_hook_reset() STUB_VOID;
		void fade_hook_out() STUB_VOID;
		void fade_hook_in() STUB_VOID;
		void fade_hook_update(float32 dt) STUB_VOID;
		void start() STUB_VOID;
		void cache_hook(hook_type&) STUB_VOID;
		void cache_drop(const drop_asset&, uint32) STUB_VOID;
		void init_cache() STUB_VOID;
		void common_update(xScene&, float32) STUB_VOID;

	}

	void load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID;
	void load_settings(xIniFile& ini) STUB_VOID;
	void init() STUB_VOID;
	void destroy() STUB_VOID;
	void reset() STUB_VOID;
	bool active() STUB;
	bool landed() STUB;
	bool update(xScene* sc, float32 dt) STUB;
	bool render() STUB;
	void stop() STUB_VOID;
	void insert_animations(xAnimTable& table) STUB_VOID;

	void attaching_state_type::start() STUB_VOID;
	void attaching_state_type::stop() STUB_VOID;
	state_enum attaching_state_type::update(xScene& s, float32& dt) STUB;
	void attaching_state_type::render() STUB_VOID;

	void hanging_state_type::start() STUB_VOID;
	void hanging_state_type::stop() STUB_VOID;
	state_enum hanging_state_type::update(xScene& s, float32& dt) STUB;
	void hanging_state_type::render() STUB_VOID;

}