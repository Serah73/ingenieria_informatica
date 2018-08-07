#pragma once
#include <cstdio>
#include <ostream>
#include "nodo_s.h"
#include <cassert>

	class lista_s
	{
	private:

		nodo* head_;
		int sz_;

	public:

		lista_s(void);
		~lista_s(void);

		nodo* find(const TDATO& dato);
		void write(std::ostream& os) const;

		void insert_head(TDATO& dato);
		void insert_tail(TDATO& dato);

		TDATO extract_head(void);
		TDATO extract_tail(void);

		nodo* get_head(void);
		int get_size(void) const;
		bool empty(void) const;

	};