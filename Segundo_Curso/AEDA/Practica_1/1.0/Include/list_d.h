#pragma once
#include <cstdio>
#include <ostream>
#include "nodo.h"
#include <cassert>

	class lista
	{
	private:
		
		nodo* head_;
		nodo* tail_;
		int sz_;

	public:

		lista(void);
		~lista(void);

		nodo* find(const TDATO& dato);
		void write(std::ostream& os) const;

		void insert_head(nodo* punto);
		void insert_tail(nodo* punto);

		TDATO extract_head(void);
		TDATO extract_tail(void);

		nodo* get_head(void);
		nodo* get_tail(void);
		int get_size(void) const;
		bool empty(void) const;

	};