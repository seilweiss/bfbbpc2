#include "zTalkBox.h"

#include "xFont.h"
#include "xMath3.h"
#include "xScene.h"
#include "xSnd.h"
#include "containers.h"

namespace {

	enum query_enum
	{
		Q_SKIP,
		Q_YESNO
	};

	struct wait_context
	{
		struct
		{
			uint8 time : 1;
			uint8 prompt : 1;
			uint8 sound : 1;
			uint8 event : 1;
			uint16 pad : 12;
		} type;
		uint8 need;
		float32 delay;
		uint32 event_mask;
		query_enum query;

		void reset_type() STUB_VOID;
	};

	struct sound_context
	{
		uint32 id;
		struct
		{
			enum
			{
				ACTION_SET,
				ACTION_PUSH,
				ACTION_POP
			} action : 8;
			enum
			{
				TYPE_INVALID,
				TYPE_VOLUME,
				TYPE_TARGET,
				TYPE_ORIGIN
			} type : 8;
			enum
			{
				SOURCE_MEMORY,
				SOURCE_STREAM
			} source : 8;
		};
		uint8 anim;
		union
		{
			struct
			{
				float32 left;
				float32 right;
			} volume;
			uint32 target;
			xVec3 origin;
		};
		uint32 speaker;
	};

	void speak_stop() STUB_VOID;
	void trigger(uint32 event) STUB_VOID;
	void trigger_pads(uint32 pressed) STUB_VOID;
	void flush_triggered() STUB_VOID;
	bool read_bool(const substr& s, bool def) STUB;
	void reset_auto_wait() STUB_VOID;
	void load_wait_context(wait_context& c, const xtextbox::tag_entry_list& el) STUB_VOID;
	void parse_tag_auto_wait(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_auto_wait(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag&) STUB_VOID;
	bool trigger_auto_wait(const xtextbox::jot& j) STUB;
	void parse_tag_signal(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag& ti) STUB_VOID;
	bool trigger_signal(const xtextbox::jot& j) STUB;
	bool load_sound_type(sound_context&, const xtextbox::tag_entry_list&) STUB;
	void parse_tag_sound(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_sound(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag&) STUB_VOID;
	bool trigger_sound(const xtextbox::jot& j) STUB;
	void parse_tag_pause(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) {}
	void reset_tag_pause(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) {}
	bool trigger_pause(const xtextbox::jot&) WIP { return true; }
	void parse_tag_allow_quit(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_allow_quit(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag&) STUB_VOID;
	bool trigger_allow_quit(const xtextbox::jot& j) STUB;
	void parse_tag_teleport(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void move_player(const xVec3&) STUB_VOID;
	void turn_player(float32) STUB_VOID;
	bool trigger_teleport(const xtextbox::jot& j) STUB;
	void parse_tag_trap(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_trap(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag&) STUB_VOID;
	bool trigger_trap(const xtextbox::jot& j) STUB;
	void parse_tag_wait(xtextbox::jot& j, const xtextbox&, const xtextbox& ctb, const xtextbox::split_tag& ti) STUB_VOID;
	bool trigger_wait(const xtextbox::jot& j) STUB;
	void start_audio_effect(ztalkbox&) STUB_VOID;
	void stop_audio_effect() STUB_VOID;
	void deactivate() STUB_VOID;
	void activate(ztalkbox&) STUB_VOID;
	bool is_wait_jot(const xtextbox::jot&) STUB;
	bool layout_contains_streams() STUB;
	void lock_stream() STUB_VOID;
	void unlock_stream() STUB_VOID;
	void refresh_prompts() STUB_VOID;
	void update_prompt_status(float32) STUB_VOID;
	void update_quit_status(float32) STUB_VOID;
	void hide_prompts() STUB_VOID;
	void stop_wait(ztalkbox& e, const float32* args, ulong32 args_size) STUB_VOID;
	bool32 cb_dispatch(xBase*, xBase* to, uint32 event, const float32* argf, xBase*) STUB;
	const char* load_text(uint32) STUB;
	inline void stop() STUB_VOID;
	inline uint32* pad_pressed() STUB;
	inline bool trigger_jot(const xtextbox::jot&) STUB;
	inline bool trigger_jot(int32) STUB;

	enum state_enum
	{
		STATE_INVALID = -1,
		BEGIN_STATE = 0,
		STATE_START,
		STATE_NEXT,
		STATE_WAIT,
		STATE_STOP,
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
		virtual state_enum update(xScene&, float32 dt) = 0;
	};

	class start_state_type : public state_type
	{
	public:
		start_state_type() WIP : state_type(STATE_START) {}

		virtual void start();
		virtual void stop();
		virtual state_enum update(xScene&, float32 dt);
	};

	class next_state_type : public state_type
	{
	private:
		int32 prev_wait_jot;

	public:
		next_state_type() WIP : state_type(STATE_NEXT) {}

		virtual void start();
		virtual void stop();
		virtual state_enum update(xScene&, float32 dt);
	};

	class wait_state_type : public state_type
	{
	private:
		bool answer_yes;

	public:
		wait_state_type() WIP : state_type(STATE_WAIT) {}

		virtual void start();
		virtual void stop();
		virtual state_enum update(xScene&, float32 dt);
	};

	class stop_state_type : public state_type
	{
	public:
		stop_state_type() WIP : state_type(STATE_STOP) {}

		virtual void start();
		virtual void stop();
		virtual state_enum update(xScene&, float32 dt);
	};

	struct trigger_pair
	{
		ztalkbox* origin;
		uint32 event;
	};

	struct shared_type
	{
		int32 flags;
		uint32 permit;
		ztalkbox* active;
		state_type* state;
		state_type* states[MAX_STATE];
		xtextbox::layout lt;
		int32 begin_jot;
		int32 end_jot;
		int32 page_end_jot;
		wait_context wait;
		wait_context auto_wait;
		uint32 wait_event_mask;
		float32 prompt_delay;
		float32 quit_delay;
		uint8 prompt_ready;
		uint8 quit_ready;
		uint8 stream_locked[2];
		int32 next_stream;
		sound_queue<4> sounds;
		uint8 allow_quit;
		uint8 quitting;
		uint8 delay_events;
		ztalkbox::callback* cb;
		fixed_queue<trigger_pair, 32> triggered;
		float32 volume;
		zNPCCommon* speak_npc;
		uint32 speak_player;

		shared_type() STUB_VOID;
	};

}

void ztalkbox::load(const asset_type& a) STUB_VOID
void ztalkbox::reset() STUB_VOID
void ztalkbox::set_text(const char* s) STUB_VOID
void ztalkbox::set_text(uint32 id) STUB_VOID
void ztalkbox::add_text(const char*) STUB_VOID
void ztalkbox::add_text(uint32) STUB_VOID
void ztalkbox::clear_text() STUB_VOID
void ztalkbox::start_talk(const char* s, callback* cb, zNPCCommon* npc) STUB_VOID
void ztalkbox::start_talk(uint32 text_id, callback* cb, zNPCCommon* npc) STUB_VOID
void ztalkbox::stop_talk() STUB_VOID
void ztalkbox::stop_wait(uint32) STUB_VOID
void ztalkbox::show() STUB_VOID
void ztalkbox::hide() STUB_VOID
void ztalkbox::MasterTellSlaves(bool32 isBeginning) STUB_VOID
void ztalkbox::MasterLoveSlave(xBase* slave, bool32 starting) STUB_VOID
void ztalkbox::load_settings(xIniFile& ini) STUB_VOID
void ztalkbox::init() STUB_VOID
void ztalkbox::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void ztalkbox::update_all(xScene& s, float32 dt) STUB_VOID
void ztalkbox::render_all() STUB_VOID
void ztalkbox::reset_all() STUB_VOID
ztalkbox* ztalkbox::get_active() STUB
void ztalkbox::permit(uint32 add_flags, uint32 remove_flags) STUB_VOID

void start_state_type::start() STUB_VOID
void start_state_type::stop() {}
state_enum start_state_type::update(xScene&, float32) WIP { return STATE_NEXT; }

void next_state_type::start() STUB_VOID
void next_state_type::stop() {}
state_enum next_state_type::update(xScene&, float32) STUB;

void wait_state_type::start() STUB_VOID
void wait_state_type::stop() STUB_VOID
state_enum wait_state_type::update(xScene&, float32) STUB;

void stop_state_type::start() {}
void stop_state_type::stop() {}
state_enum stop_state_type::update(xScene&, float32) WIP { return STATE_INVALID; }