#pragma once

#include "xHudMeter.h"
#include "xMath2.h"
#include "xFont.h"

namespace xhud {

	struct font_context
	{
		uint32 id;
		int32 justify;
		float32 w;
		float32 h;
		float32 space;
		float32 drop_x;
		float32 drop_y;
		color32u c;
		color32u drop_c;
	};

	struct font_meter_asset : meter_asset
	{
		font_context font;
		uint8 counter_mode;
		uint8 pad1;
		uint8 pad2;
		uint8 pad3;

		static const char* type_name() WIP { return "hud:meter:font"; }
	};

	class font_meter_widget : public meter_widget
	{
	private:
		font_context font;
		font_context start_font;
		int32 precision;
		xVec2 offset;
		char buffer[12];
		int32 last_value;
		xfont xf;

	public:
		font_meter_widget(const font_meter_asset&);

		virtual void destroy();
		void destruct();

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;
		virtual void update(float32 dt);
		virtual void render();

		static void load(xBase& data, xDynAsset& asset, ulong32);
	};

}