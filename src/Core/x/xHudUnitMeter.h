#pragma once

#include "xHudMeter.h"

namespace xhud {

	struct model_info
	{
		uint32 id;
		xVec3 loc;
		xVec3 size;
	};

	struct unit_meter_asset : meter_asset
	{
		model_info model[2];
		xVec3 offset;
		uint32 fill_forward;

		static const char* type_name() WIP { return "hud:meter:unit"; }
	};

	class unit_meter_widget : public meter_widget
	{
	private:
		unit_meter_asset res;
		xModelInstance* model[6][2];
		float32 anim_time;

	public:
		unit_meter_widget(const unit_meter_asset& a);

		virtual void destroy();
		void destruct();

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;
		virtual void setup();
		virtual void update(float32 dt);
		virtual void render();

		static void load(xBase& data, xDynAsset& asset, ulong32);
	};

}