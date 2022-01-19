#pragma once

#include "xMemMgr.h"

class tier_queue_allocator
{
private:
	struct block_data
	{
		uint8 prev;
		uint8 next;
		uint16 flags;
		void* data;
	};

	block_data* blocks;
	ulong32 _unit_size;
	ulong32 _block_size;
	ulong32 _block_size_shift;
	ulong32 _max_blocks;
	ulong32 _max_blocks_shift;
	uint8 head;

public:
	ulong32 block_size() const WIP { return _block_size; }
	ulong32 block_size_shift() const WIP { return _block_size_shift; }
	ulong32 mod_block_size(ulong32 i) const WIP { return i & (_block_size - 1); }
	void* get_block(ulong32 i) const WIP { return blocks[i].data; }
	bool full() const WIP { return blocks[head].next == head; }

	void init(ulong32 r4, ulong32 r5, ulong32 r6) WIP
	{
		_unit_size = r4 % 4;
		_block_size_shift = log2_ceil(r5);
		_block_size = 1 << _block_size_shift;
		_max_blocks_shift = log2_ceil(r6);
		_max_blocks = 1 << _max_blocks_shift;
		blocks = (block_data*)xMEMALLOC(_max_blocks * sizeof(block_data));

		for (ulong32 i = 0; i < _max_blocks; i++)
		{
			blocks[i].data = NULL;
		}

		clear();
	}

	void clear() WIP
	{
		head = 0;

		for (ulong32 i = 0; i < _max_blocks; i++)
		{
			blocks[i].prev = (uint8)((i - 1) & (_max_blocks - 1));
			blocks[i].next = (uint8)((i + 1) & (_max_blocks - 1));
		}
	}

	uint8 alloc_block() WIP
	{
		uint8 old_head = head;
		block_data& block = blocks[head];

		head = block.next;

		blocks[block.prev].next = block.next;
		blocks[block.next].prev = block.prev;

		if (!block.data)
		{
			block.data = alloc_block_data();
		}

		return old_head;
	}

	void free_block(uint8 index) WIP
	{
		block_data& block = blocks[index];

		block.next = head;
		block.prev = blocks[head].prev;

		blocks[block.prev].next = index;
		blocks[block.next].prev = index;

		head = index;
	}

private:
	block_data* alloc_block_data() const WIP { return (block_data*)xMEMALLOC(_block_size * _unit_size); }

	ulong32 log2_ceil(ulong32 v) const WIP
	{
		ulong32 power = 0;

		while (v > 1)
		{
			power++;
			v >>= 1;
		}

		return power;
	}
};

template <class T> class tier_queue
{
private:
	ulong32 first;
	ulong32 _size;
	ulong32 wrap_mask;
	tier_queue_allocator* alloc;
	uint8 blocks[256];

public:
	class iterator
	{
	public:
		ulong32 global_index() const { return it; }
		iterator& operator+=(int32 i) WIP { it = owner->wrap_index(it + i); return *this; }
		iterator operator+(int32 i) const WIP { iterator c = *this; c += i; return c; }
		iterator& operator-=(int32 i) WIP { *this += -i; return *this; }
		iterator operator-(int32 i) const WIP { iterator c = *this; c -= i; return c; }
		iterator& operator--() WIP { *this -= 1; return *this; }
		bool operator==(const iterator& c) const WIP { return it == c.it; }
		bool operator!=(const iterator& c) const WIP { return it != c.it; }
		T& operator*() const WIP { return owner->get_at(it); }
		T* operator->() const WIP { return &*this; }

	private:
		ulong32 it;
		tier_queue* owner;
	};

	void init(tier_queue_allocator& a) WIP
	{
		first = 0;
		_size = 0;
		wrap_mask = (a.block_size() << 8) - 1;
		alloc = &a;
	}

	ulong32 size() const WIP { return _size; }
	bool empty() const WIP { return _size == 0; }
	iterator begin() const WIP { return create_iterator(first); }
	iterator end() const WIP { return create_iterator(wrap_index(first + _size)); }
	T& front() WIP { return *begin(); }
	T& back() WIP { return *(end() - 1); }
	
	void push_front() WIP
	{
		_size++;

		ulong32 i = first;

		first = wrap_index(first - 1);

		if (alloc->mod_block_size(i) == 0)
		{
			blocks[get_block(first)] = alloc->alloc_block();
		}
	}

	void pop_back() WIP
	{
		if (_size <= 1)
		{
			clear();
			return;
		}

		_size--;

		ulong32 i = wrap_index(first + _size);

		if (alloc->mod_block_size(i) == 0)
		{
			alloc->free_block(blocks[get_block(i)]);
		}
	}

	bool front_full() const WIP
	{
		if (alloc->full())
		{
			return alloc->mod_block_size(first) == 0;
		}

		return false;
	}
	
	void clear() WIP
	{
		ulong32 i = get_block(first);
		ulong32 end = wrap_block(i + get_block(_size + alloc->block_size() - 1));

		while (i != end)
		{
			alloc->free_block(blocks[i]);
			i = wrap_block(i + 1);
		}

		_size = 0;
		first = 0;
	}
	
	T& operator[](int32 i) WIP { return get_at(wrap_index(first + i)); }

private:
	iterator create_iterator(ulong32 i) const WIP { return { i, this }; }
	ulong32 get_block(ulong32 i) const WIP { return i >> alloc->block_size_shift(); }
	T& get_at(ulong32 i) const WIP { return ((T*)alloc->get_block(blocks[get_block(i)]))[alloc->mod_block_size(i)]; }
	ulong32 wrap_index(ulong32 i) const WIP { return i & wrap_mask; }
	ulong32 wrap_block(ulong32 i) const WIP { return i & 0xFF; }
};

template <class T, ulong32 N> struct fixed_queue
{
private:
	ulong32 _first;
	ulong32 _last;
	T _buffer[N];

public:
	class iterator
	{
	public:
		T& operator+=(int32) STUB_REF(T);
		T& operator++() STUB_REF(T);
		bool operator!=(const iterator& c) const STUB;
		T& operator*() const STUB_REF(T);
		T* operator->() const STUB;

	private:
		ulong32 _it;
		fixed_queue* _owner;
	};

	fixed_queue() STUB_VOID;

	ulong32 size() const STUB;
	ulong32 max_size() const WIP { return T; }
	iterator begin() const STUB;
	iterator end() const STUB;
	T& front() STUB_REF(T);

	void push_front(const T&) STUB_VOID;
	void pop_back() STUB_VOID;
	bool full() const STUB;
	void reset() STUB_VOID;

	T& operator[](int32) STUB_REF(T);

private:
	iterator create_iterator(ulong32) const STUB;
	void push_front() STUB_VOID;
	void clear() STUB_VOID;
	T& get_at(int32) const STUB_REF(T);
};