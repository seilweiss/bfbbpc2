#pragma once

#include "xHud.h"

struct xAnimTable;

namespace xhud {

	struct model_asset : asset
	{
		uint32 model;

		static const char* type_name() WIP { return "hud:model"; }
	};

	class model_widget : public widget
	{
	private:
		uint32 mid;
		xModelInstance* model;

	public:
		model_widget(const model_asset& a);

		virtual void destroy();
		void destruct();

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;
		virtual void update(float32 dt);
		virtual void render();

		static void load(xBase& data, xDynAsset& asset, ulong32);
	};

}

xAnimTable* XHUD_AnimTable_Idle();