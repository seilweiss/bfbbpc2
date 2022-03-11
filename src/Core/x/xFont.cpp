#include "xFont.h"

#include "xModel.h"

namespace {

	struct font_asset
	{
		uint32 tex_id;
		uint16 u;
		uint16 v;
		uint8 du;
		uint8 dv;
		uint8 line_size;
		uint8 baseline;
		struct
		{
			int16 x;
			int16 y;
		} space;
		uint32 flags;
		uint8 char_set[128];
		struct
		{
			uint8 offset;
			uint8 size;
		} char_pos[127];
	};

	struct font_data
	{
		font_asset* asset;
		uint32 index_max;
		uint8 char_index[256];
		float32 iwidth;
		float32 iheight;
		basic_rect<float32> tex_bounds[127];
		basic_rect<float32> bounds[127];
		xVec2 dstfrac[127];
		RwTexture* texture;
		RwRaster* raster;
	};

	basic_rect<int32> find_bounds(const xColor* bits, const basic_rect<int32>& r, int32 pitch) STUB;
	bool reset_font_spacing(font_asset& a) STUB;
	basic_rect<float32> get_tex_bounds(const font_data&, uint8) STUB;
	basic_rect<float32> get_bounds(const font_data&, uint8) STUB;
	bool init_font_data(font_data& fd) STUB;
	void start_tex_render(uint32) STUB_VOID;
	void tex_flush() STUB_VOID;
	void stop_tex_render() STUB_VOID;
	void tex_render(const basic_rect<float32>& src, const basic_rect<float32>& dst, const basic_rect<float32>& clip, xColor color) STUB_VOID;
	void set_vert(RwIm2DVertex&, float32, float32, float32, float32, xColor) STUB_VOID;
	void init_model_cache() STUB_VOID;
	xModelInstance* load_model(uint32 id) STUB;

}

void xfont::init() STUB_VOID
void xfont::set_render_state(RwRaster* raster) STUB_VOID
void xfont::restore_render_state() STUB_VOID
basic_rect<float32> xfont::bounds(char) const STUB
basic_rect<float32> xfont::bounds(const char* text) const STUB
basic_rect<float32> xfont::bounds(const char* text, ulong32 text_size, float32 max_width, ulong32& size) const STUB
void xfont::start_render() const STUB_VOID
void xfont::stop_render() const STUB_VOID

namespace {

	void char_render(uint8, uint32, const basic_rect<float32>&, const basic_rect<float32>&, xColor) STUB_VOID;
	RwRaster* set_tex_raster(RwRaster*) STUB;

}

void xfont::irender(const char* text, float32 x, float32 y) const STUB_VOID
void xfont::irender(const char* text, ulong32 text_size, float32 x, float32 y) const STUB_VOID

namespace {

	uint32 parse_split_tag(xtextbox::split_tag& ti) STUB;
	const char* parse_next_tag_jot(xtextbox::jot& a, const xtextbox& tb, const xtextbox& ctb, const char* text, ulong32 text_size) STUB;
	const char* parse_next_text_jot(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const char* text, ulong32) STUB;
	const char* parse_next_jot(xtextbox::jot&, const xtextbox&, const xtextbox&, const char*, ulong32) STUB;
	
	struct tex_args
	{
		RwRaster* raster;
		float32 rot;
		basic_rect<float32> src;
		basic_rect<float32> dst;
		xVec2 off;
		enum
		{
			SCALE_FONT,
			SCALE_SCREEN,
			SCALE_SIZE,
			SCALE_FONT_WIDTH,
			SCALE_FONT_HEIGHT,
			SCALE_SCREEN_WIDTH,
			SCALE_SCREEN_HEIGHT
		} scale;
	};
	
	void reset_tex_args(tex_args&) STUB_VOID;
	void load_tex_args(tex_args& ta, const substr& s) STUB_VOID;

	struct model_args
	{
		xModelInstance* model;
		xVec3 rot;
		basic_rect<float32> dst;
		xVec2 off;
		enum
		{
			SCALE_FONT,
			SCALE_SCREEN,
			SCALE_SIZE
		} scale;
	};

	void reset_model_args(model_args&) STUB_VOID;
	void load_model_args(model_args& ma, const substr& s) STUB_VOID;
	void start_layout(const xtextbox&) STUB_VOID;
	void stop_layout(const xtextbox&) {}
	void start_render(const xtextbox&) STUB_VOID;
	void stop_render(const xtextbox&) STUB_VOID;
	void text_render(const xtextbox::jot& j, const xtextbox& tb, float32 x, float32 y) STUB_VOID;

}

void xtextbox::text_render(const jot& j, const xtextbox& tb, float32 x, float32 y) STUB_VOID

xtextbox::callback xtextbox::text_cb = { xtextbox::text_render, NULL, NULL };

void xtextbox::set_text(const char* text) STUB_VOID
void xtextbox::set_text(const char*, ulong32) STUB_VOID
void xtextbox::set_text(const char** texts, ulong32 size) STUB_VOID
void xtextbox::set_text(const char** texts, const ulong32* text_sizes, ulong32 size) STUB_VOID

namespace tweaker {

	namespace {

		void log_cache(bool) {}

	}

}

xtextbox::layout& xtextbox::temp_layout(bool cache) const STUB_REF(xtextbox::layout)
void xtextbox::render(layout& l, int32 begin_jot, int32 end_jot) const STUB_VOID
float32 xtextbox::yextent(float32 max, int32& size, const layout& l, int32 begin_jot, int32 end_jot) const STUB
xtextbox::tag_entry_list xtextbox::read_tag(const substr& s) STUB
xtextbox::tag_entry* xtextbox::find_entry(const tag_entry_list& el, const substr& name) STUB
ulong32 xtextbox::read_list(const tag_entry& e, float32* v, ulong32 vsize) STUB
ulong32 xtextbox::read_list(const tag_entry& e, int32* v, ulong32 vsize) STUB
void xtextbox::clear_layout_cache() STUB_VOID
void xtextbox::layout::refresh(const xtextbox& tb, bool force) STUB_VOID
void xtextbox::layout::refresh_end(const xtextbox& tb) STUB_VOID
void xtextbox::layout::clear() STUB_VOID
void xtextbox::layout::trim_line(jot_line& line) STUB_VOID
void xtextbox::layout::erase_jots(ulong32, ulong32) STUB_VOID
void xtextbox::layout::merge_line(jot_line& line) STUB_VOID
void xtextbox::layout::bound_line(jot_line& line) STUB_VOID
bool xtextbox::layout::fit_line() STUB
void xtextbox::layout::next_line() STUB_VOID
void xtextbox::layout::calc(const xtextbox& ctb, ulong32 start_text) STUB_VOID
void xtextbox::layout::render(const xtextbox& ctb, int32 begin_jot, int32 end_jot) STUB_VOID
float32 xtextbox::layout::yextent(float32 max, int32& size, int32 begin_jot, int32 end_jot) const STUB
bool xtextbox::layout::changed(const xtextbox& ctb) STUB

namespace {

	void update_tag_alpha(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_alpha(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_alpha(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_alpha(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_red(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_red(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_red(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_red(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_green(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_green(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_green(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_green(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_blue(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_blue(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_blue(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_blue(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_width(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_width(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_width(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_width(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_height(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_height(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_height(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_height(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_left_indent(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_left_indent(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_left_indent(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_left_indent(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_right_indent(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_right_indent(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_right_indent(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_right_indent(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_tab_stop(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_tab_stop(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_tab_stop(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_tab_stop(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_xspace(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_xspace(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_xspace(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_xspace(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_yspace(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_yspace(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_yspace(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_yspace(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_reset_all(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void reset_tag_all(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_color(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_color(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_color(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_color(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_font(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_font(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_font(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_font(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_wrap(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_wrap(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_wrap(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_wrap(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_xjustify(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_xjustify(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_xjustify(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_xjustify(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void update_tag_yjustify(const xtextbox::jot& j, xtextbox& tb, const xtextbox&) STUB_VOID;
	void update_tag_reset_yjustify(const xtextbox::jot&, xtextbox& tb, const xtextbox& ctb) STUB_VOID;
	void parse_tag_yjustify(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_yjustify(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void parse_tag_open_curly(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void parse_tag_newline(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void parse_tag_tab(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void parse_tag_word_break(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void parse_tag_page_break(xtextbox::jot& a, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void render_tag_model(const xtextbox::jot& j, const xtextbox& tb, float32 x, float32 y) STUB_VOID;
	void parse_tag_model(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void reset_tag_model(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void render_tag_tex(const xtextbox::jot& j, const xtextbox& tb, float32 x, float32 y) STUB_VOID;
	void parse_tag_tex(xtextbox::jot& a, const xtextbox& tb, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	xVec2 get_texture_size(RwRaster&) STUB;
	void reset_tag_tex(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) STUB_VOID;
	void parse_tag_insert(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void parse_tag_insert_hash(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void parse_tag_pop(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;
	void parse_tag_timer(xtextbox::jot& j, const xtextbox&, const xtextbox&, const xtextbox::split_tag& ti) STUB_VOID;

}

void xtextbox::register_tags(const tag_type* t, uint32 size) STUB_VOID
xtextbox::tag_type* xtextbox::find_format_tag(const substr& s, int32& index) STUB
void render_fill_rect(basic_rect<float32>& bounds, xColor color) STUB_VOID

namespace {

	void set_rect_verts(RwIm2DVertex*, float32, float32, float32, float32, xColor, float32, float32) STUB_VOID;
	void set_rect_vert(RwIm2DVertex& vert, float32 x, float32 y, float32 z, xColor c, float32 rcz) STUB_VOID;

}