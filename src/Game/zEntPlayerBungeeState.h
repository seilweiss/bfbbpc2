#pragma once

#include "xEnt.h"
#include "xDynAsset.h"
#include "xIni.h"
#include "xAnim.h"

namespace bungee_state {

	struct hook_asset : xDynAsset
	{
		uint32 entity;
		xVec3 center;
		struct
		{
			float32 dist;
			float32 travel_time;
		} attach;
		struct
		{
			float32 dist;
			float32 free_fall_time;
			float32 accel;
		} detach;
		struct
		{
			float32 unused1;
			float32 unused2;
		} turn;
		struct
		{
			float32 frequency;
			float32 gravity;
			float32 dive;
			float32 min_dist;
			float32 max_dist;
			float32 damp;
		} vertical;
		struct
		{
			float32 max_dist;
		} horizontal;
		struct
		{
			float32 rest_dist;
			float32 view_angle;
			float32 offset;
			float32 offset_dir;
			float32 turn_speed;
			float32 vel_scale;
			float32 roll_speed;
			xVec3 unused1;
		} camera;
		struct
		{
			float32 hit_loss;
			float32 damage_velocity;
			float32 hit_velocity;
		} collision;
	};

	struct hook_type : xBase
	{
		hook_asset* asset;
		xEnt* ent;
	};

	struct drop_asset : xDynAsset
	{
		uint32 marker;
		uint32 set_view_angle;
		float32 view_angle;

		static const char* type_name() WIP { return "game_object:bungee_drop"; }
	};

	void load(xBase& data, xDynAsset& asset, ulong32);
	void load_settings(xIniFile& ini);
	void init();
	void destroy();
	void reset();
	bool active();
	bool landed();
	bool update(xScene* sc, float32 dt);
	bool render();
	void stop();
	void insert_animations(xAnimTable& table);

}