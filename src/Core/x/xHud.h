#pragma once

#include "xMath3.h"
#include "xDynAsset.h"

struct xModelInstance;

namespace xhud {

	struct color32u
	{
		uint8 r;
		uint8 g;
		uint8 b;
		uint8 a;
	};

	class block_allocator
	{
	private:
		struct holder
		{
			struct header
			{
				holder* next;
			};

			header h;
			uint8 data[1];
		};

		uint32 _block_size;
		uint32 _alloc_size;
		holder* _top;
		block_allocator* _next_alloc;

	public:
		block_allocator(uint32, uint32);

		void flush_all();
		void set_increment(uint32);
		void size_reserve(uint32);
		void* alloc();
		void free(void*);
		void flush();
	};

	class motive;
	class widget;

	typedef bool(*motive_fp_update)(widget&, motive&, float32);

	class motive
	{
	private:
		float32* value;
		float32 delta;
		float32 start_delta;
		float32 max_offset;
		float32 offset;
		float32 accel;
		motive_fp_update fp_update;
		void* context;
		bool inverse;

	public:
		motive(const motive&) STUB_VOID;
		motive(float32*, float32, float32, float32, motive_fp_update, void*) STUB_VOID;

		void update(widget& w, float32 dt) WIP { fp_update(w, *this, dt); }
		void finish() STUB_VOID;
	};

	struct motive_node
	{
		motive m;
		motive_node* next;
	};

	struct render_context
	{
		xVec3 loc;
		xVec3 size;
		xVec3 rot;
		float32 r;
		float32 g;
		float32 b;
		float32 a;
	};

	struct asset : xDynAsset
	{
		xVec3 loc;
		xVec3 size;

		static const char* type_name() { return "hud"; }
	};

	class widget
	{
	private:
		struct
		{
			bool visible;
			bool enabled;
		} flag;
		render_context rc;
		render_context start_rc;
		asset* a;
		enum
		{
			ACT_NONE,
			ACT_SHOW,
			ACT_HIDE,
			MAX_ACT
		} activity;

	public:
		widget(const asset& a);
		
		virtual void destroy() {}
		void destruct();

		virtual uint32 type() const;
		virtual bool is(uint32 id) const;

		virtual void init() {}

		void presetup();
		virtual void setup() WIP { presetup(); }
		
		virtual void update(float32 dt) WIP { updater(dt); }
		void updater(float32 dt);

		virtual void render() {}
		
		virtual void dispatch(xBase* from, uint32 event, const float32* argf, xBase* argw) WIP { dispatcher(from, event, argf, argw); }
		void dispatcher(xBase* from, uint32 event, const float32* argf, xBase* argw);

		bool enabled() const WIP { return flag.enabled; }
		void enable() WIP { flag.enabled = true; }
		void disable() WIP { flag.enabled = false; }

		bool visible() const WIP { return flag.visible && enabled(); }
		void show();
		void hide();

		void add_motive(const motive& m);
		void clear_motives();
		void clear_motives(motive_fp_update fp_update, void* context);
		
		static void init_base(xBase& data, const xBaseAsset& asset, ulong32 chunk_size);
		static void disable_all(bool);
		static void setup_all();
		static void update_all(float32);
		static void render_all();
		static bool32 cb_dispatch(xBase* from, xBase* to, uint32 event, const float32* argf, xBase* argw);

	private:
		motive_node* _motive_top;
		motive_node* _motive_temp;
		motive_node** _motive_temp_tail;

		void add_tweaks() {}

		static block_allocator* motive_allocator();
		static void debug_render() {}
	};

	void init();
	void setup();
	void destroy();
	void update(float32 dt);
	void render();
	xModelInstance* load_model(uint32 id);
	void render_model(xModelInstance& m, const render_context& rc);
	bool linear_motive_update(widget&, motive& m, float32 dt);
	bool accelerate_motive_update(widget&, motive& m, float32 dt);
	bool shake_motive_update(widget&, motive& m, float32);
	bool delay_motive_update(widget& w, motive& m, float32 dt);

}