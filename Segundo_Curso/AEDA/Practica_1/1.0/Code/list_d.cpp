#include "lista.h"

	lista::lista(void):
	head_(NULL),
	tail_(NULL),
	sz_(0)
	{}

	lista::~lista(void)
	{
		while (head_ != NULL)
		{
			nodo* aux = head_->get_next();
			delete head_;
			head_ = aux;
		}
		sz_ = 0;
		head_ = NULL;
		tail_ = NULL;
	}

	nodo* lista::find(const TDATO& dato)
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

	void lista::write(std::ostream& os) const
	{
		nodo* aux = head_;

		while (aux != NULL)
		{
			os << aux->get_dato() << " ---> ";
			aux = aux->get_next();
		}
		os << "NULL" << std::endl;
	}

	void lista::insert_head(nodo* punto)
	{
		assert(punto != NULL);

		if (empty()) {
			head_ = punto;
			tail_ = head_;
		}
		else {
			head_->set_prev(punto);
			punto->set_next(head_);
			head_ = punto;
		}

		sz_++;
	}

	void lista::insert_tail(nodo* punto) {

		assert(punto != NULL);

		if (empty()) {
			head_ = punto;
			tail_ = head_;
		}
		else {
			tail_->set_next(punto);
			punto->set_prev(tail_);
			tail_ = punto;
		}

		sz_++;
	}


	TDATO lista::extract_head(void)
	{

		assert(!empty());

		nodo* aux = head_;

		head_ = head_->get_next();

		if (head_)
			head_->set_prev(NULL);
		else
			tail_ = NULL;

		sz_--;

		aux->set_next(NULL);
		TDATO dato = aux->get_dato();
		
		return dato;
	}

	TDATO lista::extract_tail(void)
	{

		assert(!empty());

		nodo* aux = tail_;

		tail_ = tail_->get_prev();

		if (tail_ != NULL)
			tail_->set_next(NULL);
		else
			head_ = NULL;

		sz_--;

		aux->set_prev(NULL);
		TDATO dato = aux->get_dato();

		return dato;
	}

	nodo* lista::get_head(void)
	{
		return head_;
	}


	nodo* lista::get_tail(void)
	{
		return tail_;
	}

	int lista::get_size(void) const
	{
		return sz_;
	}

	bool lista::empty(void) const
	{
		if (head_ == NULL) {
			assert(tail_ == NULL);
			assert(sz_ == 0);
			return true;
		}
		else
			return false;
	}