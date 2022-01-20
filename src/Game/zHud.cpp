#include "zHud.h"

#include "xHudMeter.h"
#include "xHudModel.h"

namespace zhud {

	namespace {

		void hide_widget(xhud::widget& w, xhud::motive&) STUB_VOID;
		void ping_widget(xhud::widget&) STUB_VOID;
		void delay_hide_widget(xhud::widget&) STUB_VOID;
		xhud::meter_widget* get_meter_widget(int32) STUB;
		xhud::model_widget* get_model_widget(int32) STUB;
		void on_pause() STUB_VOID;
		void on_unpause() STUB_VOID;

	}

	void init() STUB_VOID;
	void setup() STUB_VOID;
	void destroy() STUB_VOID;
	void update(float32 dt) STUB_VOID;
	void render() STUB_VOID;
	void show() STUB_VOID;
	void hide() STUB_VOID;

}