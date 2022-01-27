#pragma once

#include "xDynAsset.h"
#include "xFont.h"

struct xScene;

class ztextbox : public xBase
{
public:
	struct asset_type : xDynAsset
	{
		struct color_type
		{
			uint8 r;
			uint8 g;
			uint8 b;
			uint8 a;
		};

		uint32 text;
		basic_rect<float32> bounds;
		uint32 font;
		struct
		{
			float32 width;
			float32 height;
		} size;
		struct
		{
			float32 x;
			float32 y;
		} space;
		color_type color;
		struct
		{
			float32 left;
			float32 top;
			float32 right;
			float32 bottom;
		} inset;
		enum
		{
			XJ_LEFT,
			XJ_CENTER,
			XJ_RIGHT
		} xjustify;
		enum
		{
			EX_UP,
			EX_CENTER,
			EX_DOWN,
			MAX_EX
		} expand;
		float32 max_height;
		struct
		{
			uint32 type;
			color_type color;
			uint32 texture;
		} backdrop;
	};

private:
	struct
	{
		uint8 active : 1;
		uint8 dirty : 1;
		uint8 show_backdrop : 1;
		uint8 visible : 1;
		uint8 hack_invisible : 1;
	} flag;
	asset_type* asset;
	xtextbox tb;
	int8* segments[16];
	uint32 segments_size;
	ztextbox* next;
	ztextbox* prev;
	RwRaster* bgtex;

public:
	void load(const asset_type& a);
	void update(xScene&, float32);
	void reset();
	void render();
	void render_backdrop();
	void activate();
	void deactivate();
	void set_text(const char* s);
	void set_text(uint32 id);
	void add_text(const char* s);
	void add_text(uint32);
	void clear_text();
	void refresh();
	void get_text(char* buffer, ulong32 buffer_size) const;
	bool visible() STUB;

	static void init();
	static void load(xBase& data, xDynAsset& asset, ulong32);
	static void update_all(xScene&, float32);
	static void render_all();
};

inline ztextbox::asset_type::color_type convert(const ztextbox::asset_type::color_type&) STUB;