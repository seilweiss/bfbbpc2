#pragma once

#include "xColor.h"
#include "xMath2.h"
#include "xString.h"

#include <rwcore.h>

struct xfont
{
	uint32 id;
	float32 width;
	float32 height;
	float32 space;
	xColor color;
	basic_rect<float32> clip;

	static xfont create(uint32, float32, float32, float32, xColor, const basic_rect<float32>&) STUB;
	static xfont create() STUB;
	static void init();
	static void set_render_state(RwRaster* raster);
	static void restore_render_state();

	basic_rect<float32> bounds(char) const;
	basic_rect<float32> bounds(const char* text) const;
	basic_rect<float32> bounds(const char* text, ulong32 text_size, float32 max_width, ulong32& size) const;
	void start_render() const;
	void stop_render() const;
	void irender(const char* text, float32 x, float32 y) const;
	void irender(const char* text, ulong32 text_size, float32 x, float32 y) const;
	void render(const char*, float32, float32) const;
};

struct xtextbox
{
	struct jot;

	struct callback
	{
		void(*render)(const jot& j, const xtextbox& tb, float32 x, float32 y);
		void(*layout_update)(const jot& j, xtextbox& tb, const xtextbox& ctb);
		void(*render_update)(const jot& j, xtextbox& tb, const xtextbox& ctb);
	};

	struct split_tag
	{
		substr tag;
		substr name;
		substr action;
		substr value;
	};

	struct tag_type
	{
		substr name;
		void(*parse_tag)(jot& a, const xtextbox& tb, const xtextbox& ctb, const split_tag& ti);
		void(*reset_tag)(jot& a, const xtextbox& tb, const xtextbox& ctb, const split_tag& ti);
		void* context;
	};

	struct tag_entry
	{
		substr name;
		char op;
		substr* args;
		ulong32 args_size;
	};

	struct tag_entry_list
	{
		tag_entry* entries;
		ulong32 size;
	};

	struct jot
	{
		substr s;
		struct
		{
			bool invisible : 1;
			bool ethereal : 1;
			bool merge : 1;
			bool word_break : 1;
			bool word_end : 1;
			bool line_break : 1;
			bool stop : 1;
			bool tab : 1;
			bool insert : 1;
			bool dynamic : 1;
			bool page_break : 1;
			bool stateful : 1;
			uint16 dummy : 4;
		} flag;
		uint16 context_size;
		void* context;
		basic_rect<float32> bounds;
		basic_rect<float32> render_bounds;
		callback* cb;
		tag_type* tag;

		void intersect_flags(const jot&) STUB_VOID;
		void reset_flags() STUB_VOID;
	};

	struct jot_line
	{
		basic_rect<float32> bounds;
		float32 baseline;
		ulong32 first;
		ulong32 last;
		bool page_break;
	};
	
	struct layout;

	xfont font;
	basic_rect<float32> bounds;
	uint32 flags;
	float32 line_space;
	float32 tab_stop;
	float32 left_indent;
	float32 right_indent;
	callback* cb;
	void* context;
	char** texts;
	ulong32* text_sizes;
	ulong32 texts_size;
	substr text;
	uint32 text_hash;

	static xtextbox create(const xfont& font, const basic_rect<float32>& bounds, uint32 flags, float32 line_space, float32 tab_stop, float32 left_indent, float32 right_indent) STUB;
	static xtextbox create() STUB;
	static tag_entry_list read_tag(const substr& s);
	static tag_entry* find_entry(const tag_entry_list& el, const substr& name);
	static ulong32 read_list(const tag_entry& e, float32* v, ulong32 vsize);
	static ulong32 read_list(const tag_entry& e, int32* v, ulong32 vsize);
	static void clear_layout_cache();
	static void register_tags(const tag_type* t, uint32 size);
	static tag_type* find_format_tag(const substr& s, int32& index);
	static tag_type* find_format_tag(const substr& s) WIP { int32 index; return find_format_tag(s, index); };

	void set_text(const char* text);
	void set_text(const char*, ulong32);
	void set_text(const char** texts, ulong32 size);
	void set_text(const char** texts, const ulong32* text_sizes, ulong32 size);
	layout& temp_layout(bool cache) const;
	float32 yextent(float32 max, int32& size, const layout& l, int32 begin_jot, int32 end_jot) const;
	float32 yextent(float32, int32&, bool) const STUB;
	float32 yextent(const layout&, int32, int32) const STUB;
	float32 yextent(bool) const STUB;

	void render(bool) const STUB_VOID;
};

struct xtextbox::layout
{
	xtextbox tb;
	jot _jots[512];
	ulong32 _jots_size;
	jot_line _lines[128];
	ulong32 _lines_size;
	uint8 context_buffer[1024];
	ulong32 context_buffer_size;
	uint16 dynamics[64];
	ulong32 dynamics_size;

	void refresh(const xtextbox& tb, bool force);
	void refresh_end(const xtextbox& tb);
	void clear();
	void trim_line(jot_line& line);
	void erase_jots(ulong32, ulong32);
	void merge_line(jot_line& line);
	void bound_line(jot_line& line);
	bool fit_line();
	void next_line();
	void calc(const xtextbox& ctb, ulong32 start_text);
	void render(const xtextbox& ctb, int32 begin_jot, int32 end_jot);
	float32 yextent(float32 max, int32& size, int32 begin_jot, int32 end_jot) const;
	bool changed(const xtextbox& ctb);
	ulong32 jots_size() const WIP { return _jots_size; }
};

void render_fill_rect(basic_rect<float32>& bounds, xColor color);

inline float32 NSCREENX(float32) STUB
inline float32 NSCREENY(float32) STUB