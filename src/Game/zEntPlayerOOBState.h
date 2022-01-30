#pragma once

#include <types.h>

struct xIniFile;
struct xScene;
class xSerial;

namespace oob_state {

	void load_settings(xIniFile& ini);
	void init();
	bool update(xScene& s, float32 dt);
	bool IsPlayerInControl();
	float32 oob_timer();
	bool render();
	void fx_render();
	void force_start();
	void read_persistent(xSerial& s);
	void write_persistent(xSerial& s);

}