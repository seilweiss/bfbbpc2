#pragma once

#include "xString.h"
#include "xMath3.h"

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

typedef void(*tweak_on_change_callback)(const tweak_info&);
typedef void(*tweak_on_select_callback)(const tweak_info&);
typedef void(*tweak_on_unselect_callback)(const tweak_info&);
typedef void(*tweak_on_start_edit_callback)(const tweak_info&);
typedef void(*tweak_on_stop_edit_callback)(const tweak_info&);
typedef void(*tweak_on_expand_callback)(const tweak_info&);
typedef void(*tweak_on_collapse_callback)(const tweak_info&);
typedef void(*tweak_on_update_callback)(const tweak_info&);
typedef void(*tweak_convert_mem_to_tweak_callback)(const tweak_info&, void*);
typedef void(*tweak_convert_tweak_to_mem_callback)(const tweak_info&, void*);

struct tweak_callback
{
	tweak_on_change_callback on_change;
	tweak_on_select_callback on_select;
	tweak_on_unselect_callback on_unselect;
	tweak_on_start_edit_callback on_start_edit;
	tweak_on_stop_edit_callback on_stop_edit;
	tweak_on_expand_callback on_expand;
	tweak_on_collapse_callback on_collapse;
	tweak_on_update_callback on_update;
	tweak_convert_mem_to_tweak_callback convert_mem_to_tweak;
	tweak_convert_tweak_to_mem_callback convert_tweak_to_mem;

	static tweak_callback create_change(tweak_on_change_callback) STUB;
};

typedef void(*xDebugModeCallback)();

void xprintf(const char*, ...);
int32 xDebugModeAdd(const char*, xDebugModeCallback);
void xDebugInit();
void xDebugUpdate();
void xDebugExit();
void xDebugTimestampScreen();

inline void xDebugAddTweak(const char*, const char*, const tweak_callback*, void*, uint32) {}
inline void xDebugAddTweak(const char*, uint8*, uint8, uint8, const tweak_callback*, void*, uint32) {}
inline void xDebugAddTweak(const char*, int16*, int16, int16, const tweak_callback*, void*, uint32) {}
inline void xDebugAddTweak(const char*, float32*, float32, float32, const tweak_callback*, void*, uint32) {}
inline void xDebugAddTweak(const char*, xVec3*, const tweak_callback*, void*, uint32) {}
inline void xDebugAddFlagTweak(const char*, uint32*, uint32, const tweak_callback*, void*, uint32) {}
inline void xDebugAddSelectTweak(const char*, uint32*, const char**, const uint32*, uint32, const tweak_callback*, void*, uint32) {}
inline void xDebugRemoveTweak(const char*) {}