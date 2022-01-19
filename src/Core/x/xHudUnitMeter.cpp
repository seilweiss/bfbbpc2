#include "xHudUnitMeter.h"

namespace xhud {

	void unit_meter_widget::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID;
	unit_meter_widget::unit_meter_widget(const unit_meter_asset& a) : meter_widget(a) STUB_VOID;
	void unit_meter_widget::destruct() STUB_VOID;
	void unit_meter_widget::destroy() STUB_VOID;
	uint32 unit_meter_widget::type() const STUB;
	bool unit_meter_widget::is(uint32 id) const STUB;
	void unit_meter_widget::setup() STUB_VOID;
	void unit_meter_widget::update(float32 dt) STUB_VOID;
	void unit_meter_widget::render() STUB_VOID;

}