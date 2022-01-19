#include "xHudMeter.h"

namespace xhud {

	namespace {

		void add_global_tweaks() STUB_VOID;

	}

	void meter_widget::set_value(float32 v) STUB_VOID;
	void meter_widget::set_value_immediate(float32 v) STUB_VOID;
	meter_widget::meter_widget(const meter_asset& a) : widget(a), res(a) STUB_VOID;
	void meter_widget::destruct() STUB_VOID;
	uint32 meter_widget::type() const STUB;
	bool meter_widget::is(uint32 id) const STUB;
	void meter_widget::updater(float32 dt) STUB_VOID;

}