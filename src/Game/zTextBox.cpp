#include "zTextBox.h"

namespace {

	inline void set_vert(RwIm2DVertex&, float32, float32, float32, float32, xColor, float32, float32) STUB_VOID;

	void render_bk_fill(const ztextbox& e) STUB_VOID;
	void render_bk_tex_scale(const ztextbox& e) STUB_VOID;
	void render_bk_tex_wrap(const ztextbox&) {}
	void init_textbox(ztextbox& e) STUB_VOID;
	void parse_tag_blahblah(xtextbox::jot&, const xtextbox&, const xtextbox&, const xtextbox::split_tag&) {}
	bool32 cb_dispatch(xBase*, xBase* to, uint32 event, const float32* argf, xBase*) STUB;

}

void ztextbox::load(const asset_type& a) STUB_VOID
void ztextbox::update(xScene&, float32) STUB_VOID
void ztextbox::reset() STUB_VOID
void ztextbox::render() STUB_VOID
void ztextbox::render_backdrop() STUB_VOID
void ztextbox::activate() STUB_VOID
void ztextbox::deactivate() STUB_VOID
void ztextbox::set_text(const char* s) STUB_VOID
void ztextbox::set_text(uint32 id) STUB_VOID
void ztextbox::add_text(const char* s) STUB_VOID
void ztextbox::add_text(uint32) STUB_VOID
void ztextbox::clear_text() STUB_VOID
void ztextbox::refresh() STUB_VOID
void ztextbox::get_text(char* buffer, ulong32 buffer_size) const STUB_VOID
void ztextbox::init() STUB_VOID
void ztextbox::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void ztextbox::update_all(xScene&, float32) STUB_VOID
void ztextbox::render_all() STUB_VOID