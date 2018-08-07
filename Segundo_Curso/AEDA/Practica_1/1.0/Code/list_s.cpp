#include "list_s.h"


	lista_s::lista_s(void) :
		head_(NULL),
		sz_(0)
	{}

	lista_s::~lista_s(void)
	{
		while (head_ != NULL)
		{
			nodo* aux = head_->get_next();
			delete head_;
			head_ = aux;
		}
		sz_ = 0;
		head_ = NULL;
	}

	nodo* lista_s::find(const TDATO& dato)
	{
		nodo* aux1 = NULL;
		nodo* aux2 = head_;
		bool finded = false;

		while ((aux1 == NULL) && (aux2 == NULL) && (finded))
		{
			if (aux2->get_dato() == dato)
			{
				aux2 = aux1;
				finded = true;
			}

			aux2 = aux2->get_next();
		}

		return aux1;
	}

	void lista_s::write(std::ostream& os) const
	{
		nodo* aux = head_;

		while (aux != NULL)
		{
			os << aux->get_dato() << " ---> ";
			aux = aux->get_next();
		}
		os << "NULL" << std::endl;
	}

	void lista_s::insert_head(TDATO& dato)
	{
		if (empty())
		{
		    nodo* aux = new nodo(dato);
			head_ = aux;
		}else 
		{
			nodo* aux = new nodo(dato);
			aux->set_next(head_);
			head_ = aux;
		}

		sz_++;
	}

	void lista_s::insert_tail(TDATO& dato) 
	{
		if (empty())
			head_ = new nodo(dato);
		else {
			nodo* aux = head_;
			nodo* aux_data = new nodo(dato);

			while (aux->get_next() != NULL)
				aux = aux->get_next();
			aux->set_next(aux_data);
		}

		sz_++;
	}


	TDATO lista_s::extract_head(void)
	{

		assert(!empty());

		nodo* aux = head_;

		head_ = head_->get_next();

		sz_--;

		aux->set_next(NULL);
        TDATO dato = aux->get_dato();
        
		return dato;
	}

	TDATO lista_s::extract_tail(void)
	{

		assert(!empty());

		nodo* borrador = head_;
		nodo* aux = head_;

		while (borrador->get_next() != NULL)
			borrador = borrador->get_next();

		while (aux->get_next() != borrador)
			aux = aux->get_next();

		aux->set_next(NULL);

		sz_--;
        TDATO dato = borrador->get_dato();
        
        delete borrador;
        
		return dato;
	}

	nodo* lista_s::get_head(void)
	{
		return head_;
	}

	int lista_s::get_size(void) const
	{
		return sz_;
	}

	bool lista_s::empty(void) const
	{
		if (head_ == NULL)
		{
			assert(sz_ == 0);
			return true;
		}
		else
			return false;
	}