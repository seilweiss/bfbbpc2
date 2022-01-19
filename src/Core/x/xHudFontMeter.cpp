#include "xHudFontMeter.h"

namespace xhud {

	void font_meter_widget::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID;
	font_meter_widget::font_meter_widget(const font_meter_asset& a) : meter_widget(a) STUB_VOID;
	void font_meter_widget::destruct() STUB_VOID;
	void font_meter_widget::destroy() STUB_VOID;
	uint32 font_meter_widget::type() const STUB;
	bool font_meter_widget::is(uint32 id) const STUB;
	void font_meter_widget::update(float32 dt) STUB_VOID;
	void font_meter_widget::render() STUB_VOID;

}