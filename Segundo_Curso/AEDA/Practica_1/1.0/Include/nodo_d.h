#pragma once
#include "common_types.h"
#include <cstdio>
#include <cassert>

	class nodo
	{
	private:

		TDATO dato_;
		nodo* next_;
		nodo* prev_;

	public:

		nodo(const TDATO& d);
		~nodo(void);
		
		const TDATO& get_dato(void) const;
		void set_dato(const TDATO& dato);
		nodo* get_next(void);
		void set_next(nodo* next);
		nodo* get_prev(void);
		void set_prev(nodo* prev);
	};