#pragma once
#include "common_types.h"
#include <cstdio>
#include <cassert>

	class nodo
	{
	private:

		TDATO dato_;
		nodo* next_;

	public:

		nodo(const TDATO& d);
		~nodo(void);

		const TDATO& get_dato(void) const;
		void set_dato(const TDATO& dato);
		nodo* get_next(void);
		void set_next(nodo* next);
	};
