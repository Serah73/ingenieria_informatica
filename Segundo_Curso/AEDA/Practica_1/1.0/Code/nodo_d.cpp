#include "nodo_d.h"

	nodo::nodo(const TDATO& d):
	dato_(d)
	{
		next_ = NULL;
		prev_ = NULL;
	}

	nodo::~nodo(void)
	{
		delete next_;
		next_ = NULL;

		delete prev_;
		prev_ = NULL;
	}

	const TDATO& nodo::get_dato(void) const
	{
		return dato_;
	}

	void nodo::set_dato(const TDATO& dato)
	{
		dato_ = dato;
	}

	nodo* nodo::get_next(void)
	{
		return next_;
	}

	void nodo::set_next(nodo* next)
	{
		next_ = next;
	}

	nodo* nodo::get_prev(void)
	{
		return prev_;
	}

	void nodo::set_prev(nodo* prev)
	{
		prev_ = prev;
	}