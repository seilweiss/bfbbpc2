#pragma once

#include "xDynAsset.h"

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
	state_enum StatusGet() const STUB;
};