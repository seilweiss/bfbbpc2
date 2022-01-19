#pragma once

#include "xEnt.h"

struct xAnimTable;

namespace cruise_bubble {

	void init();
	void reset();
	void launch();
	bool update(xScene* sc, float32 dt);
	bool render();
	void render_screen();
	void insert_player_animations(xAnimTable& table);
	xAnimTable* anim_table();
	bool active();
	float32 exploding();
	void get_explode_sphere(xVec3& center, float32& radius);
	xEnt** get_explode_hits(int32& size);
	void add_life(float32, float32);
	void set_life(float32);
	void reset_life();
	bool event_handler(xBase*, uint32 event, const float32* fparam, xBase*);

}