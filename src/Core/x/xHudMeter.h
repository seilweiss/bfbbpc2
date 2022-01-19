#pragma once

#include "xHud.h"
#include "xSnd.h"

namespace xhud {

	struct meter_asset : asset
	{
		float32 start_value;
		float32 min_value;
		float32 max_value;
		float32 increment_time;
		float32 decrement_time;
		struct
		{
			uint32 start_increment;
			uint32 increment;
			uint32 start_decrement;
			uint32 decrement;
		} sound;

		static const char* type_name() WIP { return "hud:meter"; }
	};

	class meter_widget : public widget
	{
	private:
		const meter_asset& res;
		float32 value;
		float32 min_value;
		float32 max_value;
		float32 end_value;
		float32 value_vel;
		float32 value_accel;
		float32 ping_delay;
		float32 pitch;
		sound_queue<4> pings;

	public:
		meter_widget(const meter_asset& a);

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;
		virtual void update(float32 dt) WIP { updater(dt); }

		void set_value(float32 v);
		void set_value_immediate(float32 v);
		void destruct();
		void updater(float32 dt);
	};

}