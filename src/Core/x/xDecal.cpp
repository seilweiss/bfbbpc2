#include "xDecal.h"

namespace {

	inline float32 choose_greatest(float32, float32, float32) STUB;
	inline void lerp(float32&, float32, float32, float32) STUB_VOID;
	inline void lerp(uint8&, float32, uint8, uint8) STUB_VOID;
	inline void lerp(xColor&, float32, xColor, xColor) STUB_VOID;

}

void xDecalInit() STUB_VOID
void xDecalUpdate(float32 dt) STUB_VOID

void xDecalEmitter::init(int32 max_size, const char*) STUB_VOID
void xDecalEmitter::set_default_config() STUB_VOID
void xDecalEmitter::set_texture(const char* name) STUB_VOID
void xDecalEmitter::set_texture(uint32) STUB_VOID
void xDecalEmitter::set_texture(RwTexture*) STUB_VOID
void xDecalEmitter::refresh_config() STUB_VOID
void xDecalEmitter::set_curve(const curve_node* curve, ulong32 size) STUB_VOID
void xDecalEmitter::emit(const xMat4x3& mat, int32 texture_index) STUB_VOID
void xDecalEmitter::emit(const xMat4x3& mat, const xVec3& scale, int32 texture_index) STUB_VOID
void xDecalEmitter::update(float32 dt) STUB_VOID
void xDecalEmitter::update_frac(unit_data&) STUB_VOID
void xDecalEmitter::get_render_data(const unit_data& unit, float32 scale, xColor& color, xMat4x3& mat, xVec2& uv0, xVec2& uv1) STUB_VOID
int32 xDecalEmitter::select_texture_unit() STUB