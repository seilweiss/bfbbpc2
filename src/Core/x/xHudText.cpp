#include "xHudText.h"

namespace xhud {

	void text_widget::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID;
	text_widget::text_widget(const text_asset& a) : widget(a) STUB_VOID;
	void text_widget::destruct() STUB_VOID;
	void text_widget::setup() STUB_VOID;
	void text_widget::destroy() STUB_VOID;
	uint32 text_widget::type() const STUB;
	bool text_widget::is(uint32 id) const STUB;
	void text_widget::update(float32 dt) STUB_VOID;
	void text_widget::render() STUB_VOID;

}