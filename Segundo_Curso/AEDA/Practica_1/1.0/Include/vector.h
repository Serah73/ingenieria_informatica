#pragma once
#include "common_types.h"
#include "stack.h"
#include <cstdio>
#include <cassert>


	class vector
	{
	private:

		TDATO* base_;
		size_t sz_;

		void build(void);
		void destroy(void);


	public:

		vector(size_t sz);
		vector(void);
		vector(const vector& v);
		~vector(void);

		TDATO& get_data(size_t i);
		void set_data(TDATO x, int n);
		const TDATO& get(size_t i) const;

		size_t size(void) const;
		void get_resize(size_t sz);

		void operator=(const stack& s);
		void operator=(const  vector& v);
		TDATO& operator[] (size_t i);
		const TDATO& operator[] (size_t i) const;
	};
