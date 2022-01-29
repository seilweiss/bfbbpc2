#include "xLaserBolt.h"

void xLaserBoltEmitter::init(ulong32 max_bolts, const char*) STUB_VOID
void xLaserBoltEmitter::set_texture(const char* name) STUB_VOID
void xLaserBoltEmitter::set_texture(uint32) STUB_VOID
void xLaserBoltEmitter::set_texture(RwTexture*) STUB_VOID
void xLaserBoltEmitter::set_texture(RwRaster*) STUB_VOID
void xLaserBoltEmitter::reset() STUB_VOID
void xLaserBoltEmitter::refresh_config() STUB_VOID
void xLaserBoltEmitter::emit(const xVec3& loc, const xVec3& dir) STUB_VOID
void xLaserBoltEmitter::update(float32 dt) STUB_VOID
void xLaserBoltEmitter::render() STUB_VOID
void xLaserBoltEmitter::attach_effects(fx_when_enum when, effect_data* fx, ulong32 fxsize) STUB_VOID
void xLaserBoltEmitter::pre_collide(bolt&) STUB_VOID
void xLaserBoltEmitter::collide_update(bolt& b) STUB_VOID
RwIm3DVertex* xLaserBoltEmitter::render(bolt& b, RwIm3DVertex* vert) STUB
RwIm3DVertex* xLaserBoltEmitter::get_vert_buffer(int32&) STUB
void xLaserBoltEmitter::apply_damage(bolt&) STUB_VOID
void xLaserBoltEmitter::reset_fx(fx_when_enum) STUB_VOID
void xLaserBoltEmitter::update_fx(bolt& b, float32 prev_dist, float32 dt) STUB_VOID
void xLaserBoltEmitter::emit_particle(effect_data& effect, bolt& b, float32 from_dist, float32 to_dist, float32 dt) STUB_VOID
void xLaserBoltEmitter::emit_decal(effect_data& effect, bolt& b, float32, float32 to_dist, float32) STUB_VOID
void xLaserBoltEmitter::emit_decal_dist(effect_data& effect, bolt& b, float32 from_dist, float32 to_dist, float32) STUB_VOID