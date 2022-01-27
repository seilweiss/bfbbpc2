#pragma once

#include "xDynAsset.h"
#include "zTalkBox.h"

class zNPCCommon;

class ztaskbox : public xBase
{
public:
	struct asset_type : xDynAsset
	{
		bool persistent : 8;
		bool loop : 8;
		bool enable : 8;
		bool retry : 8;
		uint32 talk_box;
		uint32 next_task;
		uint32 stages[6];
	};

	enum state_enum
	{
		STATE_INVALID = -1,
		STATE_BEGIN = 0,
		STATE_DESCRIPTION,
		STATE_REMINDER,
		STATE_SUCCESS,
		STATE_FAILURE,
		STATE_END,
		MAX_STATE
	};

	class callback
	{
	public:
		callback() WIP {}

		virtual void on_talk_start() {}
		virtual void on_talk_stop() {}
	};

	class talk_callback;

private:
	struct
	{
		bool enabled : 8;
		uint32 dummy : 24;
	} flag;
	asset_type* asset;
	state_enum state;
	callback* cb;
	ztaskbox* current;

public:
	void load(const asset_type& a);
	void read(xSerial& s);
	void write(xSerial& s);
	void start_talk(zNPCCommon* npc);
	void stop_talk();
	void enable();
	void disable();
	void reset();
	void initiate();
	void succeed();
	void fail();
	void complete();
	void set_callback(callback* cb);
	bool exists(state_enum);
	void set_state(state_enum state);
	void on_talk_start();
	void on_talk_stop(ztalkbox::answer_enum);
	state_enum StatusGet() const STUB;

	static void init();
	static void load(xBase& data, xDynAsset& asset, ulong32);
	static const char* get_text(uint32);
	static bool32 cb_dispatch(xBase*, xBase* to, uint32 event, const float32*, xBase*);
};