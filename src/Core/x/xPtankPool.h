#pragma once

#include "xMath3.h"
#include "xMath2.h"
#include "xColor.h"

#include <rwcore.h>
#include <rpworld.h>

enum ptank_group_type
{
	PGT_COLOR_MAT_UV2,
	PGT_POS_COLOR_SIZE_UV2,
	MAX_PGT
};

class ptank_pool
{
private:
	struct render_state
	{
		RwTexture* texture;
		uint32 src_blend;
		uint32 dst_blend;
		uint32 flags;
	};

	render_state rs;
	uint32 used;
	RpAtomic* ptank;
	struct
	{
		uint8* data;
		int32 stride;
		uint32 size;
	} hide;

public:
	bool valid() const STUB;
	bool at_block_end() const STUB;
	void unlock_block() STUB_VOID;
	void reset() STUB_VOID;
	void grab_block(ptank_group_type type);
	void flush();
};

class ptank_pool__pos_color_size_uv2 : public ptank_pool
{
private:
	xVec3* pos;
	xColor* color;
	xVec2* size;
	xVec2* uv;
	int32 stride;

public:
	void flush() STUB_VOID;
	void next() STUB_VOID;
	void lock_block() STUB_VOID;
};

class ptank_pool__color_mat_uv2 : public ptank_pool
{
private:
	xColor* color;
	xMat4x3* mat;
	xVec2* uv;
	int32 stride;

public:
	void flush() STUB_VOID;
	void next() STUB_VOID;
	void lock_block() STUB_VOID;
};