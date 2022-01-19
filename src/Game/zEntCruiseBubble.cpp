#include "zEntCruiseBubble.h"

#include "zRumble.h"
#include "xColor.h"
#include "xAnim.h"
#include "xDebug.h"
#include "zNPCHazard.h"
#include "zShrapnel.h"

namespace cruise_bubble {

	namespace {

		inline xMat4x3& get_player_mat() STUB_REF(xMat4x3);
		inline xMat4x3& get_missle_mat() STUB_REF(xMat4x3);

		struct sound_config
		{
			const char* name;
			float32 volume;
			float32 radius_inner;
			float32 radius_outer;
			bool streamed;
			bool looping;
			SDRumbleType rumble;
			int32 first;
			int32 last;
			uint32 id;
			uint32 handle;
		};

		struct missle_record_data
		{
			xVec3 loc;
			float32 roll;

			missle_record_data(const xVec3&, float32) STUB_VOID;
		};

		enum thread_enum
		{
			THREAD_PLAYER,
			THREAD_MISSLE,
			THREAD_CAMERA,
			MAX_THREAD
		};

		enum state_enum
		{
			STATE_INVALID = -1,
			BEGIN_STATE_PLAYER = 0,
			BACKUP_STATE_PLAYER = BEGIN_STATE_PLAYER - 1,
			STATE_PLAYER_HALT,
			STATE_PLAYER_AIM,
			STATE_PLAYER_FIRE,
			STATE_PLAYER_WAIT,
			END_STATE_PLAYER,
			BEGIN_STATE_MISSLE = END_STATE_PLAYER,
			BACKUP_STATE_MISSLE = BEGIN_STATE_MISSLE - 1,
			STATE_MISSLE_APPEAR,
			STATE_MISSLE_FLY,
			STATE_MISSLE_EXPLODE,
			END_STATE_MISSLE,
			BEGIN_STATE_CAMERA = END_STATE_MISSLE,
			BACKUP_STATE_CAMERA = BEGIN_STATE_CAMERA - 1,
			STATE_CAMERA_AIM,
			STATE_CAMERA_SEIZE,
			STATE_CAMERA_ATTACH,
			STATE_CAMERA_SURVEY,
			STATE_CAMERA_RESTORE,
			END_STATE_CAMERA,
			MAX_STATE = END_STATE_CAMERA
		};

		class state_type
		{
		private:
			state_enum type;

		public:
			state_type(state_enum type) WIP : type(type) {}

			virtual void start() {}
			virtual void stop() {}
			virtual state_enum update(float32 dt) = 0;
			virtual void render() {}
			virtual void abort() {}
		};

		class state_player_halt : public state_type
		{
		private:
			bool first_update;
			float32 time;
			xVec3 last_motion;

		public:
			state_player_halt() WIP : state_type(STATE_PLAYER_HALT) {}

			void start();
			void stop();
			state_enum update(float32 dt);
		};

		class state_player_aim : public state_type
		{
		private:
			float32 yaw;
			float32 yaw_vel;
			float32 turn_delay;

		public:
			state_player_aim() WIP : state_type(STATE_PLAYER_AIM) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void face_camera(float32) STUB_VOID;
			void apply_yaw() STUB_VOID;
			void update_animation(float32) STUB_VOID;
		};

		class state_player_fire : public state_type
		{
		private:
			bool wand_shown;

		public:
			state_player_fire() WIP : state_type(STATE_PLAYER_FIRE) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void update_wand(float32) {}
		};

		class state_player_wait : public state_type
		{
		public:
			state_player_wait() WIP : state_type(STATE_PLAYER_WAIT) {}

			void start();
			state_enum update(float32);
		};

		class state_missle_appear : public state_type
		{
		public:
			state_missle_appear() WIP : state_type(STATE_MISSLE_APPEAR) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void move() STUB_VOID;
			void update_effects(float32) {}
		};

		class state_missle_fly : public state_type
		{
		private:
			float32 life;
			float32 vel;
			xVec3 rot;
			xVec3 rot_vel;
			float32 engine_pitch;
			xVec3 last_loc;
			float32 flash_time;

		public:
			state_missle_fly() WIP : state_type(STATE_MISSLE_FLY) {}

			void start();
			void stop();
			state_enum update(float32 dt);
			void abort();

		private:
			static bool hazard_check(NPCHazard& haz, void* context) STUB;

			void calculate_rotation(xVec2& d1, xVec2& v1, float32 dt, const xVec2& d0, const xVec2& v0, const xVec2& a0, const xVec2& a1) const STUB_VOID;
			void update_turn(float32) STUB_VOID;
			void update_move(float32) STUB_VOID;
			bool hit_test(xVec3& hit_loc, xVec3& hit_norm, xVec3& hit_depen, xEnt*& hit_ent) const STUB;
			bool collide() STUB;
			bool collide_hazards() STUB;
			void update_engine_sound(float32) STUB_VOID;
			void update_flash(float32) STUB_VOID;
		};

		class state_missle_explode : public state_type
		{
		private:
			float32 hit_time;

		public:
			state_missle_explode() WIP : state_type(STATE_MISSLE_EXPLODE) {}

			void start();
			void stop();
			state_enum update(float32 dt);

			float32 get_radius() const STUB;

		private:
			class cb_damage_ent
			{
			private:
				float32 radius;

			public:
				cb_damage_ent(float32 radius) WIP : radius(radius) {}

				bool operator()(xEnt&, xGridBound&) STUB;
			};

			static bool hazard_check(NPCHazard& haz, void* context) STUB;
			static void reset_quadrants(uint32 size, float32 ring) STUB_VOID;
			static void get_next_quadrant(float32&, float32&, float32&, float32&) STUB_VOID;
			static xVec3 perturb_direction(const xVec3&, float32, float32, float32, float32) STUB;
			static void cb_droplet(zFrag* frag, zFragAsset*);

			void apply_damage_hazards(float32) STUB_VOID;
			void apply_damage(float32) STUB_VOID;
			void start_effects() STUB_VOID;
		};

		class state_camera_aim : public state_type
		{
		private:
			float32 phi;
			float32 phi_vel;
			float32 height;
			float32 height_vel;
			float32 dist;
			float32 dist_vel;
			xQuat facing;
			xQuat target;
			float32 control_delay;
			float32 seize_delay;

		public:
			state_camera_aim() WIP : state_type(STATE_CAMERA_AIM) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void move(float32) STUB_VOID;
			void stop(float32) STUB_VOID;
			void apply_motion() const STUB_VOID;
			void collide_inward() STUB_VOID;
			void turn(float32) STUB_VOID;
			void apply_turn() const STUB_VOID;
		};

		class state_camera_seize : public state_type
		{
		private:
			float32 blend_time;
			xVec3 start_loc;
			xQuat start_dir;
			xQuat end_dir;
			xQuat cur_dir;
			float32 last_s;
			float32 fov;
			float32 wipe_bubbles;

		public:
			state_camera_seize() WIP : state_type(STATE_CAMERA_SEIZE) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void update_move(float32) STUB_VOID;
			void update_turn(float32) STUB_VOID;
			void refresh_missle_alpha(float32) STUB_VOID;
		};

		class state_camera_attach : public state_type
		{
		private:
			float32 reticle_delay;

		public:
			state_camera_attach() WIP : state_type(STATE_CAMERA_ATTACH) {}

			void start();
			void stop();
			state_enum update(float32);

		private:
			class cb_lock_targets
			{
			public:
				bool operator()(xEnt&, xGridBound&) STUB;
			};

			static bool hazard_check(NPCHazard& haz, void*) STUB;

			void get_view_bound(xBound& bound) const STUB_VOID;
			void lock_hazard_targets() STUB_VOID;
			void lock_targets() STUB_VOID;
		};

		class state_camera_survey : public state_type
		{
		private:
			float32 time;
			xVec2 start_sp;
			float32 path_distance[127];

		public:
			state_camera_survey() WIP : state_type(STATE_CAMERA_SURVEY) {}

			void start();
			void stop();
			state_enum update(float32 dt);

		private:
			void init_path() STUB_VOID;
			int32 find_nearest(float32) const STUB;
			void lerp(float32&, float32, float32, float32) const STUB_VOID;
			void lerp(xVec3&, float32, const xVec3&, const xVec3&) const STUB_VOID;
			void eval_missle_path(float32 dist, xVec3& loc, float32& roll) const STUB_VOID;
			void move() STUB_VOID;
			bool control_jerked() const STUB;
		};

		class state_camera_restore : public state_type
		{
		private:
			float32 control_delay;

		public:
			state_camera_restore() WIP : state_type(STATE_CAMERA_RESTORE) {}

			void start();
			void stop();
			state_enum update(float32 dt);
		};

		inline void distort_screen(float32) {}
		inline xVec3& get_player_loc() STUB_REF(xVec3);
		inline void lerp(uint8&, float32, uint8, uint8) STUB_VOID;
		inline void lerp(xColor&, float32, xColor, xColor) STUB_VOID;
		inline void init_debug() {}
		inline void render_debug() {}

		void init_sound() STUB_VOID;
		void stop_sound(int32 which, uint32 handle) STUB_VOID;
		uint32 play_sound(int32, float32) STUB;
		uint32 play_sound(int32, float32, const xVec3*) STUB;
		void set_pitch(int32, float32, uint32) STUB_VOID;
		void show_wand() STUB_VOID;
		void hide_wand() STUB_VOID;
		void show_missle() STUB_VOID;
		void hide_missle() STUB_VOID;
		void capture_camera() STUB_VOID;
		void release_camera() STUB_VOID;
		bool camera_taken() STUB;
		bool camera_leave() STUB;
		void start_damaging() STUB_VOID;
		void damage_entity(xEnt& ent, const xVec3& loc, const xVec3& dir, const xVec3& hit_norm, float32 radius, bool explosive) STUB_VOID;
		bool can_damage(xEnt* ent) STUB;
		bool was_damaged(xEnt*) STUB;
		void notify_triggers(xScene& s, const xSphere& o, const xVec3& dir) STUB_VOID;
		void exit_triggers(xScene& s) STUB_VOID;
		void signal_event(uint32) STUB_VOID;
		void refresh_trail(xMat4x3&, xQuat&) STUB_VOID;
		void start_trail() STUB_VOID;
		void stop_trail() STUB_VOID;
		void set_state(thread_enum, state_enum) STUB_VOID;
		bool check_launch() STUB;
		void kill(bool reset_camera, bool abortive) STUB_VOID;
		void update_player(xScene& s, float32 dt) STUB_VOID;
		void render_player() STUB_VOID;
		void refresh_controls() STUB_VOID;
		void update_state(xScene*, float32 dt) STUB_VOID;
		void render_state() STUB_VOID;
		RpAtomic* custom_bubble_render(RpAtomic* atomic) STUB;
		void init_states() STUB_VOID;
		void init_missle_model() STUB_VOID;
		void reset_wake_ribbons() STUB_VOID;
		void init_wake_ribbons() STUB_VOID;
		void reset_explode_decal() STUB_VOID;
		void init_explode_decal() STUB_VOID;
		void init_shrapnel() STUB_VOID;
		void add_trail_sample(const xVec3& loc0, const xVec3& dir0, const xVec3& loc1, const xVec3& dir1, float32 dt) STUB_VOID;
		void update_trail(float32 dt) STUB_VOID;
		void refresh_missle_model() {}
		void update_missle(xScene&, float32) STUB_VOID;
		void render_missle() STUB_VOID;
		xModelInstance* load_model(uint32) STUB;
		void render_model_2d(xModelInstance*, const basic_rect<float32>&, float32) STUB_VOID;
		void render_glow(xModelInstance* model, const basic_rect<float32>& r, float32 glow, float32 alpha) STUB_VOID;
		
		struct uv_animated_model
		{
			RpAtomic* model;
			RwTexCoords* uv;
			int32 uvsize;
			xVec2 offset;
			xVec2 offset_vel;

			bool init(RpAtomic*) STUB;
			bool clone_uv(RwTexCoords*&, int32&, RpAtomic*) const STUB;
			bool get_uv(RwTexCoords*&, int32&, RpAtomic*) const STUB;
			void refresh() STUB_VOID;
			void update(float32) STUB_VOID;
		};

		void init_hud() STUB_VOID;

		struct hud_gizmo
		{
			int32 flags;
			basic_rect<float32> bound;
			float32 alpha;
			float32 alpha_vel;
			float32 glow;
			float32 glow_vel;
			float32 opacity;
			xVec3* target;
			xModelInstance* model;
		};

		void show_gizmo(hud_gizmo&, const basic_rect<float32>&, xModelInstance*) STUB_VOID;
		void update_gizmo(hud_gizmo&, float32) STUB_VOID;
		void flash_hud() STUB_VOID;
		void render_timer(float32 alpha, float32 glow) STUB_VOID;
		void update_hud(float32 dt) STUB_VOID;
		void render_hud() STUB_VOID;
		void show_hud() STUB_VOID;
		void hide_hud() STUB_VOID;
		xVec3 world_to_screen(const xVec3& loc) STUB;
		int32 find_locked_target(const xVec3*) STUB;
		void lock_target(int32 index, const xVec3* target, float32 opacity) STUB_VOID;
		void check_lock_target(const xVec3* target) STUB_VOID;
		uint32 check_anim_aim(xAnimTransition*, xAnimSingle*, void*) STUB;
		void load_cheat_tweak() STUB_VOID;

		struct tweak_group
		{
			float32 aim_delay;
			struct
			{
				float32 halt_time;
				struct
				{
					float32 turn_speed;
					float32 anim_delta;
				} aim;
				struct
				{
					float32 delay_wand;
				} fire;
			} player;
			struct
			{
				float32 life;
				float32 hit_dist;
				float32 crash_angle;
				float32 collide_twist;
				int32 hit_tests;
				struct
				{
					float32 delay_show;
					float32 delay_fly;
					xVec3 offset;
				} appear;
				struct
				{
					float32 accel;
					float32 max_vel;
					float32 engine_pitch_max;
					float32 engine_pitch_sensitivity;
					float32 flash_interval;
					struct
					{
						float32 xdelta;
						float32 ydelta;
						float32 xdecay;
						float32 ydecay;
						float32 ybound;
						float32 roll_frac;
					} turn;
				} fly;
				struct
				{
					float32 hit_radius;
					float32 hit_duration;
				} explode;
			} missle;
			struct
			{
				struct
				{
					float32 dist;
					float32 height;
					float32 pitch;
					float32 accel;
					float32 max_vel;
					float32 stick_decel;
					float32 stick_accel;
					float32 stick_max_vel;
					float32 turn_speed;
				} aim;
				struct
				{
					float32 delay;
					float32 blend_time;
					float32 fade_dist;
					float32 hide_dist;
					float32 fov;
				} seize;
				struct
				{
					float32 duration;
					float32 min_duration;
					float32 min_dist;
					float32 cut_dist;
					float32 drift_dist;
					float32 drift_softness;
					float32 jerk_offset;
					float32 jerk_deflect;
				} survey;
				struct
				{
					float32 control_delay;
				} restore;
			} camera;
			struct
			{
				float32 env_alpha;
				float32 env_coeff;
				uint32 env_texture;
				float32 fresnel_alpha;
				float32 fresnel_coeff;
				uint32 fresnel_texture;
			} material;
			struct
			{
				float32 dist_min;
				float32 dist_max;
				float32 ang_show;
				float32 ang_hide;
				float32 delay_retarget;
			} reticle;
			struct
			{
				float32 sample_rate;
				float32 bubble_rate;
				float32 bubble_emit_radius;
				float32 wake_emit_radius;
			} trail;
			struct
			{
				uint32 emit;
				float32 radius;
				float32 vel;
				float32 rand_vel;
			} blast;
			struct
			{
				float32 dist_min;
				float32 dist_max;
				uint32 emit_min;
				uint32 emit_max;
				float32 vel_min;
				float32 vel_max;
				float32 vel_perturb;
				float32 vel_angle;
				float32 rot_vel_max;
			} droplet;
			struct
			{
				float32 glow_size;
				float32 time_fade;
				float32 time_glow;
				struct
				{
					float32 size;
					float32 du;
					float32 dv;
				} swirl;
				struct
				{
					float32 size;
					float32 du;
					float32 dv;
				} wind;
				struct
				{
					float32 size;
				} reticle;
				struct
				{
					float32 size;
				} target;
				struct
				{
					int32 font;
					float32 font_width;
					float32 font_height;
					float32 x;
					float32 y;
					float32 glow_size;
				} timer;
			} hud;
			struct
			{
				float32 freq;
				float32 decay;
				float32 min_freq;
			} dialog;
			void* context;
			tweak_callback cb_missle_model;

			void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID;
			void load(xModelAssetParam*, uint32) STUB_VOID;
		};

		void load_settings() STUB_VOID;

	}

	void init() STUB_VOID;
	void reset() STUB_VOID;
	void launch() STUB_VOID;
	bool update(xScene* sc, float32 dt) STUB;
	bool render() STUB;
	void render_screen() STUB_VOID;
	void insert_player_animations(xAnimTable& table) STUB_VOID;
	xAnimTable* anim_table() STUB;
	bool active() STUB;
	float32 exploding() STUB;
	void get_explode_sphere(xVec3& center, float32& radius) STUB_VOID;
	xEnt** get_explode_hits(int32& size) STUB;
	void add_life(float32, float32) STUB_VOID;
	void set_life(float32) STUB_VOID;
	void reset_life() STUB_VOID;
	bool event_handler(xBase*, uint32 event, const float32* fparam, xBase*) STUB;

	namespace {

		void state_player_halt::start() STUB_VOID;
		void state_player_halt::stop() STUB_VOID;
		state_enum state_player_halt::update(float32 dt) STUB;

		void state_player_aim::start() STUB_VOID;
		void state_player_aim::stop() STUB_VOID;
		state_enum state_player_aim::update(float32 dt) STUB;

		void state_player_fire::start() STUB_VOID;
		void state_player_fire::stop() STUB_VOID;
		state_enum state_player_fire::update(float32 dt) STUB;

		void state_player_wait::start() STUB_VOID;
		state_enum state_player_wait::update(float32) STUB;

		void state_missle_appear::start() STUB_VOID;
		void state_missle_appear::stop() STUB_VOID;
		state_enum state_missle_appear::update(float32 dt) STUB;

		void state_missle_fly::start() STUB_VOID;
		void state_missle_fly::stop() STUB_VOID;
		void state_missle_fly::abort() STUB_VOID;
		state_enum state_missle_fly::update(float32 dt) STUB;

		void state_missle_explode::start() STUB_VOID;
		void state_missle_explode::stop() STUB_VOID;
		state_enum state_missle_explode::update(float32 dt) STUB;

		void state_camera_aim::start() STUB_VOID;
		void state_camera_aim::stop() STUB_VOID;
		state_enum state_camera_aim::update(float32 dt) STUB;

		void state_camera_seize::start() STUB_VOID;
		void state_camera_seize::stop() STUB_VOID;
		state_enum state_camera_seize::update(float32 dt) STUB;

		void state_camera_attach::start() STUB_VOID;
		void state_camera_attach::stop() STUB_VOID;
		state_enum state_camera_attach::update(float32) STUB;

		void state_camera_survey::start() STUB_VOID;
		void state_camera_survey::stop() STUB_VOID;
		state_enum state_camera_survey::update(float32 dt) STUB;

		void state_camera_restore::start() STUB_VOID;
		void state_camera_restore::stop() STUB_VOID;
		state_enum state_camera_restore::update(float32 dt) STUB;

	}

}