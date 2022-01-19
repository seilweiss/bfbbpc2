#include "xHud.h"

#include "xModel.h"
#include "xMath2.h"

namespace xhud {

	void block_allocator::flush_all() STUB_VOID;
	block_allocator::block_allocator(uint32, uint32) STUB_VOID;
	void block_allocator::set_increment(uint32) STUB_VOID;
	void block_allocator::size_reserve(uint32) STUB_VOID;
	void* block_allocator::alloc() STUB;
	void block_allocator::free(void*) STUB_VOID;
	void block_allocator::flush() STUB_VOID;
	block_allocator* widget::motive_allocator() STUB;
	void init() STUB_VOID;
	void setup() STUB_VOID;
	void destroy() STUB_VOID;
	void update(float32 dt) STUB_VOID;
	void render() STUB_VOID;
	widget::widget(const asset& a) STUB_VOID;
	void widget::init_base(xBase& data, const xBaseAsset& asset, ulong32 chunk_size) STUB_VOID;
	void widget::destruct() STUB_VOID;
	void widget::presetup() STUB_VOID;
	void widget::updater(float32 dt) STUB_VOID;
	void widget::dispatcher(xBase*, uint32, const float32*, xBase*) STUB_VOID;
	uint32 widget::type() const STUB;
	bool widget::is(uint32 id) const STUB;
	void widget::show() STUB_VOID;
	void widget::hide() STUB_VOID;

	namespace {

		void fp_setup(widget& w) STUB_VOID;
		void fp_render(widget& w) STUB_VOID;

		class functor_disable
		{
		private:
			bool destroy_widgets;

		public:
			functor_disable(bool destroy_widgets) WIP : destroy_widgets(destroy_widgets) {}

			void operator()(widget&) STUB_VOID;
		};

		class functor_update
		{
		private:
			float32 dt;

		public:
			functor_update(float32 dt) WIP : dt(dt) {}

			void operator()(widget&) STUB_VOID;
		};

		template <class F> void for_each(uint8 type, uint32 size, F f) STUB_VOID;

	}

	void widget::disable_all(bool) STUB_VOID;
	void widget::setup_all() STUB_VOID;
	void widget::update_all(float32) STUB_VOID;
	void widget::render_all() STUB_VOID;
	void widget::add_motive(const motive& m) STUB_VOID;
	void widget::clear_motives() STUB_VOID;
	void widget::clear_motives(motive_fp_update fp_update, void* context) STUB_VOID;
	bool32 widget::cb_dispatch(xBase* from, xBase* to, uint32 event, const float32* argf, xBase* argw) STUB;
	xModelInstance* load_model(uint32 id) STUB;

	namespace {

		void render_one_model(xModelInstance&, float32, const basic_rect<float32>&, const xVec3&, const xVec3&, const xMat4x3&) STUB_VOID;

	}

	void render_model(xModelInstance& m, const render_context& rc) STUB_VOID;
	bool linear_motive_update(widget&, motive& m, float32 dt) STUB;
	bool accelerate_motive_update(widget&, motive& m, float32 dt) STUB;
	bool shake_motive_update(widget&, motive& m, float32) STUB;
	bool delay_motive_update(widget& w, motive& m, float32 dt) STUB;

}