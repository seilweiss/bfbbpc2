#pragma once

#include "xMath2.h"
#include "xMath3.h"
#include "xColor.h"
#include "containers.h"

#include <rwcore.h>

class xDecalEmitter
{
public:
	enum texture_mode
	{
		TM_DEFAULT,
		TM_RANDOM,
		TM_CYCLE,
		MAX_TM,
		FORCE_INT_TM = 0xffffffff
	};

	struct config
	{
		uint32 flags;
		float32 life_time;
		uint32 blend_src;
		uint32 blend_dst;
		struct
		{
			xVec2 uv[2];
			uint8 rows;
			uint8 cols;
			texture_mode mode;
		} texture;
	};

	struct unit_data
	{
		uint8 flags;
		uint8 curve_index;
		uint8 u;
		uint8 v;
		float32 frac;
		float32 age;
		float32 cull_size;
		xMat4x3 mat;
	};

	struct curve_node
	{
		float32 time;
		xColor color;
		float32 scale;
	};

private:
	config cfg;
	struct
	{
		RwTexture* asset;
		uint32 units;
		xVec2 size;
		xVec2 isize;
		int32 prev;
	} texture;
	static_queue<unit_data> units;
	curve_node* curve;
	uint32 curve_size;
	uint32 curve_index;
	float32 ilife;

public:
	void init(int32 max_size, const char*);
	void set_default_config();
	void set_texture(const char* name);
	void set_texture(uint32);
	void set_texture(RwTexture*);
	void refresh_config();
	void set_curve(const curve_node* curve, ulong32 size);
	void emit(const xMat4x3& mat, int32 texture_index);
	void emit(const xMat4x3& mat, const xVec3& scale, int32 texture_index);
	void update(float32 dt);
	void update_frac(unit_data&);
	void get_render_data(const unit_data& unit, float32 scale, xColor& color, xMat4x3& mat, xVec2& uv0, xVec2& uv1);
	int32 select_texture_unit();
	bool need_update() const STUB;
	bool debug_need_update() const WIP { return false; }
	void debug_init(const char*) {}
	void debug_update_curve() {}
	void debug_update(float32) {}
	bool full() const STUB;
};

void xDecalInit();
void xDecalUpdate(float32 dt);

inline void xDecalDestroy() {}
inline void xDecalRender() {}