#pragma once

#include "xHud.h"
#include "xFont.h"

namespace xhud {

	struct text_asset : asset
	{
		uint32 text_box;
		uint32 text;

		static const char* type_name() WIP { return "hud:text"; }
	};

	class text_widget : public widget
	{
	private:
		char text[128];
		xtextbox tb;

	public:
		text_widget(const text_asset&);

		static void load(xBase& data, xDynAsset& asset, ulong32);

		virtual void destroy();
		void destruct();

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;

		virtual void setup();
		virtual void update(float32 dt);
		virtual void render();
	};

}