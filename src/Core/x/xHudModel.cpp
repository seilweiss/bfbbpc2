#include "xHudModel.h"

xAnimTable* XHUD_AnimTable_Idle() STUB

namespace xhud {

	void model_widget::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID;
	model_widget::model_widget(const model_asset& a) : widget(a) STUB_VOID;
	void model_widget::destruct() STUB_VOID;
	void model_widget::destroy() STUB_VOID;
	uint32 model_widget::type() const STUB;
	bool model_widget::is(uint32 id) const STUB;
	void model_widget::update(float32 dt) STUB_VOID;
	void model_widget::render() STUB_VOID;

}