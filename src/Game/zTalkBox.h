#pragma once

#include "xDynAsset.h"

class ztextbox;
class zNPCCommon;
struct xIniFile;
struct xScene;

class ztalkbox : public xBase
{
public:
	struct asset_type : xDynAsset
	{
		uint32 dialog_box;
		uint32 prompt_box;
		uint32 quit_box;
		uint8 trap : 8;
		uint8 pause : 8;
		uint8 allow_quit : 8;
		uint8 trigger_pads : 8;
		uint8 page : 8;
		uint8 show : 8;
		uint8 hide : 8;
		uint8 audio_effect : 8;
		uint32 teleport;
		struct
		{
			struct
			{
				uint8 time : 8;
				uint8 prompt : 8;
				uint8 sound : 8;
				uint8 event : 8;
			} type;
			float32 delay;
			int32 which_event;
		} auto_wait;
		struct
		{
			uint32 skip;
			uint32 noskip;
			uint32 quit;
			uint32 noquit;
			uint32 yesno;
		} prompt;
	};

	enum answer_enum
	{
		ANSWER_CONTINUE,
		ANSWER_YES,
		ANSWER_NO
	};

	class callback
	{
	public:
		callback() WIP {}

		virtual void on_signal(uint32) {}
		virtual void on_start() {}
		virtual void on_stop() {}
		virtual void on_answer(answer_enum answer) {}
	};

private:
	struct
	{
		bool visible : 1;
	} flag;
	asset_type* asset;
	ztextbox* dialog_box;
	ztextbox* prompt_box;
	ztextbox* quit_box;
	struct
	{
		const char* skip;
		const char* noskip;
		const char* quit;
		const char* noquit;
		const char* yesno;
	} prompt;
	zNPCCommon* npc;

public:
	void load(const asset_type& a);
	void reset();
	void set_text(const char* s);
	void set_text(uint32 id);
	void add_text(const char*);
	void add_text(uint32);
	void clear_text();
	void start_talk(const char* s, callback* cb, zNPCCommon* npc);
	void start_talk(uint32 text_id, callback* cb, zNPCCommon* npc);
	void stop_talk();
	void stop_wait(uint32);
	void show();
	void hide();
	void MasterTellSlaves(bool32 isBeginning);
	void MasterLoveSlave(xBase* slave, bool32 starting);

	static void load_settings(xIniFile& ini);
	static void init();
	static void load(xBase& data, xDynAsset& asset, ulong32);
	static void update_all(xScene& s, float32 dt);
	static void render_all();
	static void reset_all();
	static ztalkbox* get_active();
	static void permit(uint32 add_flags, uint32 remove_flags);
};