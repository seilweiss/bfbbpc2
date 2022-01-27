#include "xPtankPool.h"

namespace {

	struct ptank_context
	{
		ptank_context* next;
		RpAtomic* ptank;
		uint32 flags;
		uint32 src_blend;
		uint32 dst_blend;
	};

	struct group_data
	{
		uint32 max_size;
		uint32 create_flags;
		ptank_context* ptanks;
		ptank_context** buckets;
		uint32 size;
		uint32 used;
		uint32 buckets_used;
	};

	void sort_buckets(group_data& group) STUB_VOID;
	void init_groups() STUB_VOID;
	RpAtomic* create_ptank(uint32 flags) STUB;
	void destroy_ptank(RpAtomic*) STUB_VOID;
	void render_ptank(const ptank_context&) STUB_VOID;
	int32 compare_ptanks(const void* e1, const void* e2) STUB;
	inline uint32 create_ptanks(group_data&, ulong32) STUB;

}

void xPTankPoolSceneEnter() STUB_VOID
void xPTankPoolSceneExit() STUB_VOID
void xPTankPoolRender() STUB_VOID

void ptank_pool::grab_block(ptank_group_type type) STUB_VOID
void ptank_pool::flush() STUB_VOID