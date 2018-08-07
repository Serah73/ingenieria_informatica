#include "vector.h"


	void vector::build(void)
	{
		base_ = new TDATO[sz_];
	}

	void vector::destroy(void)
	{
		if (base_ != NULL)
			delete base_;

		base_ = NULL;
	}

	vector::vector(void) :
		base_(NULL),
		sz_(0) {}

	vector::vector(size_t sz) :
		base_(NULL),
		sz_(sz)
	{
		build();
	}

	vector::~vector(void)
	{
		destroy();
	}

	vector::vector(const vector& v) :
	base_(NULL),
	sz_(v.sz_)
	{
		build();

		for (size_t i = 0; i < sz_; i++)
			base_[i] = v.base_[i];
	}

	TDATO& vector::get_data(size_t i)
	{
		assert(i < sz_);
		return base_[i];
	}
	
	void vector::set_data(TDATO x, int n)
	{
		base_[n] = x;
	}

	const TDATO& vector::get(size_t i) const
	{
		assert(i < sz_);
		return base_[i];
	}

	size_t vector::get_size(void) const
	{
		return sz_;
	}

	void vector::resize(size_t sz)
	{
		destroy();
		sz_ = sz;
	}

	void vector::operator=(const stack& s)
	{/*
		destroy();
		sz_ = s.size();
		build();
		
		base_[1] = s.get_head();
	*/}

	void vector::operator=(const vector& v)
	{
		destroy();
		sz_ = v.sz_;
		build();

		for (size_t i = 0; i < sz_; i++)
			base_[i] = v.get(i);
	}

	TDATO& vector::operator[](size_t i)
	{
		return get(i);
	}

	const TDATO& vector::operator[](size_t i) const
	{
		return get(i);
	}