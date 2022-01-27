#include "zEntPlayerOOBState.h"

#include "xModel.h"
#include "xColor.h"
#include "xScene.h"
#include "zTalkBox.h"

namespace oob_state {

	namespace {

		void set_camera(bool instant) STUB_VOID;
		void reset_camera() STUB_VOID;
		void render_model(xModelInstance&, const xVec3&, const xVec3&, const xVec3&) STUB_VOID;
		void move_up(xVec3&, float32) STUB_VOID;
		void move_right(xVec3& loc, float32 x) STUB_VOID;
		void update_max_out_time(const xSurface&) STUB_VOID;
		bool assume_player_is_stupid() STUB;
		void move_hand(float32 dt) STUB_VOID;
		inline void set_rect_vert(RwIm2DVertex& vert, float32 x, float32 y, float32 z, xColor c, float32 rcz) STUB_VOID;
		inline void set_rect_verts(RwIm2DVertex*, float32, float32, float32, float32, xColor, float32, float32) STUB_VOID;
		void render_fade() STUB_VOID;
		void render_ghost() STUB_VOID;
		void render_hand() STUB_VOID;

		enum state_enum
		{
			STATE_INVALID = -1,
			BEGIN_STATE = 0,
			STATE_IN = BEGIN_STATE,
			STATE_OUT,
			STATE_GRAB,
			STATE_DROP,
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
		};

		class in_state_type : public state_type
		{
		public:
			in_state_type() WIP : state_type(STATE_IN) {}

			virtual void start() STUB_VOID;
			virtual void stop() {}
			virtual state_enum update(xScene&, float32&) STUB;
		};

		class out_state_type : public state_type
		{
		public:
			out_state_type() WIP : state_type(STATE_OUT) {}

			virtual void start() STUB_VOID;
			virtual void stop() {}
			virtual state_enum update(xScene&, float32& dt) STUB;
		};

		class grab_state_type : public state_type
		{
		private:
			class tutorial_callback : public ztalkbox::callback
			{
			private:
				grab_state_type& owner;

			public:
				tutorial_callback(grab_state_type& owner) WIP : ztalkbox::callback(), owner(owner) {}

				virtual void on_stop() STUB_VOID;
			};

			enum substate_enum
			{
				SS_INVALID = -1,
				SS_REORIENT = 0,
				SS_BEGIN_WAIT,
				SS_MOVING_IN,
				SS_STOPPING,
				SS_STOPPED,
				SS_TUTORIAL,
				SS_STARTING,
				SS_MOVING_OUT,
				SS_START_FADE_OUT,
				SS_FADE_OUT,
				MAX_SS
			};

			typedef substate_enum(*substate_update)(grab_state_type&, xScene&, float32&);

			tutorial_callback cb;
			substate_enum move_substate;
			substate_enum fade_substate;
			xVec3 player_start;
			float32 reorient_time;
			float32 angle_delta;
			float32 delay;
			float32 fade_start_time;
			float32 fade_time;
			uint32 scene_reset;
			bool finished_tutorial;
			substate_update updatess[MAX_SS];

		public:
			grab_state_type() : state_type(STATE_GRAB), cb(*this) STUB_VOID;

			virtual void start() STUB_VOID;
			virtual void stop() {}
			virtual state_enum update(xScene& s, float32& dt) STUB;

			substate_enum update_reorient(xScene&, float32&) STUB;
			substate_enum update_begin_wait(xScene&, float32&) STUB;
			substate_enum update_moving_in(xScene&, float32&) STUB;
			substate_enum update_stopping(xScene&, float32&) STUB;
			substate_enum update_stopped(xScene&, float32&) STUB;
			substate_enum update_tutorial(xScene&, float32&) STUB;
			substate_enum update_starting(xScene&, float32&) STUB;
			substate_enum update_moving_out(xScene&, float32&) STUB;
			substate_enum update_start_fade_out(xScene&, float32&) STUB;
			substate_enum update_fade_out(xScene&, float32&) STUB;
			
			static substate_enum supdate_reorient(grab_state_type&, xScene&, float32&) STUB;
			static substate_enum supdate_begin_wait(grab_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_moving_in(grab_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_stopping(grab_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_stopped(grab_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_tutorial(grab_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_starting(grab_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_moving_out(grab_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_start_fade_out(grab_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_fade_out(grab_state_type& gst, xScene&, float32& dt) STUB;
		};

		class drop_state_type : public state_type
		{
		private:
			enum substate_enum
			{
				SS_INVALID = -1,
				SS_MOVING_IN = 0,
				SS_STOPPING,
				SS_STOPPED,
				SS_STARTING,
				SS_MOVING_OUT,
				SS_START_FADE_IN,
				SS_FADE_IN,
				MAX_SS
			};

			typedef substate_enum(*substate_update)(drop_state_type&, xScene&, float32&);

			substate_enum move_substate;
			substate_enum fade_substate;
			xVec3 player_start;
			float32 stop_time;
			float32 fade_start_time;
			float32 fade_time;
			substate_update updatess[MAX_SS];

		public:
			drop_state_type() : state_type(STATE_DROP) STUB_VOID;

			virtual void start() STUB_VOID;
			virtual void stop() STUB_VOID;
			virtual state_enum update(xScene& s, float32& dt) STUB;

			substate_enum update_moving_in(xScene&, float32&) STUB;
			substate_enum update_stopping(xScene&, float32&) STUB;
			substate_enum update_stopped(xScene&, float32&) STUB;
			substate_enum update_starting(xScene&, float32&) STUB;
			substate_enum update_moving_out(xScene&, float32&) STUB;
			substate_enum update_start_fade_in(xScene&, float32&) STUB;
			substate_enum update_fade_in(xScene&, float32&) STUB;

			static substate_enum supdate_moving_in(drop_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_stopping(drop_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_stopped(drop_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_starting(drop_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_moving_out(drop_state_type&, xScene&, float32& dt) STUB;
			static substate_enum supdate_start_fade_in(drop_state_type& gst, xScene&, float32& dt) STUB;
			static substate_enum supdate_fade_in(drop_state_type& gst, xScene&, float32& dt) STUB;
		};

	}

	void load_settings(xIniFile& ini) STUB_VOID;
	void init() STUB_VOID;
	bool update(xScene& s, float32 dt) STUB;
	bool IsPlayerInControl() STUB;
	float32 oob_timer() STUB;
	bool render() STUB;
	void fx_render() STUB_VOID;
	void force_start() STUB_VOID;
	void read_persistent(xSerial& s) STUB_VOID;
	void write_persistent(xSerial& s) STUB_VOID;

}