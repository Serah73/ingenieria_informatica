#include "nodo_s.h"

	nodo::nodo(const TDATO& d) :
		dato_(d)
	{
		next_ = NULL;
	}

	nodo::~nodo(void) 
	{
		delete next_;
		next_ = NULL;
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
