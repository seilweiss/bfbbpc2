#pragma once

#include <types.h>
#include <rwcore.h>

void xRenderStateSetTexture(RwTexture* texture);
void xRenderStateSetSrcBlendMode(int32 xmode);
void xRenderStateSetDstBlendMode(int32 xmode);