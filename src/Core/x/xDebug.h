#pragma once

#include "xString.h"

struct tweak_callback;

struct tweak_info
{
	substr name;
	void* value;
	tweak_callback* cb;
	void* context;
	uint8 type;
	uint8 value_size;
	uint16 flags;
	union
	{
		struct
		{
			int32 value_def;
			int32 value_min;
			int32 value_max;
		} int_context;
		struct
		{
			uint32 value_def;
			uint32 value_min;
			uint32 value_max;
		} uint_context;
		struct
		{
			float32 value_def;
			float32 value_min;
			float32 value_max;
		} float_context;
		struct
		{
			bool value_def;
		} bool_context;
		struct
		{
			uint32 value_def;
			uint32 labels_size;
			const char** labels;
			void* values;
		} select_context;
		struct
		{
			uint32 value_def;
			uint32 mask;
		} flag_context;
		struct
		{
			uint8 pad[16];
		} all_context;
	};
};

struct tweak_callback
{
	void(*on_change)(tweak_info&);
	void(*on_select)(tweak_info&);
	void(*on_unselect)(tweak_info&);
	void(*on_start_edit)(tweak_info&);
	void(*on_stop_edit)(tweak_info&);
	void(*on_expand)(tweak_info&);
	void(*on_collapse)(tweak_info&);
	void(*on_update)(tweak_info&);
	void(*convert_mem_to_tweak)(tweak_info&, void*);
	void(*convert_tweak_to_mem)(tweak_info&, void*);
};

typedef void(*xDebugModeCallback)();

void xprintf(const char*, ...);
int32 xDebugModeAdd(const char*, xDebugModeCallback);
void xDebugInit();
void xDebugUpdate();
void xDebugExit();
void xDebugTimestampScreen();

inline void xDebugAddTweak(const char*, float32*, float32, float32, const tweak_callback*, void*, uint32) {}
inline void xDebugRemoveTweak(const char*) {}