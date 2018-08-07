#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include "dll_node_t.hpp"

using namespace std;

namespace AED {

    template <class T>
    class dll_t {
    private:
        dll_node_t<T>* head_;
        dll_node_t<T>* tail_;

        int sz_;

    public:
        dll_t(void);
	    dll_t(const dll_t& L);
        ~dll_t(void); 

	void insert_tail(dll_node_t<T>*);
        void insert_head(dll_node_t<T>*);

        dll_node_t<T>* extract_tail(void);
        dll_node_t<T>* extract_head(void);

        dll_node_t<T>* get_tail(void);
        dll_node_t<T>* get_head(void);

        bool empty(void) const ;

        void unlink(dll_node_t<T>*);

        int get_size(void) const;

        ostream& write(ostream& os) const;
    };


    template <class T>
    dll_t<T>::dll_t(void) :
    head_(NULL),
    tail_(NULL),
    sz_(0) {
    }

    template <class T>
    dll_t<T>::dll_t(const dll_t& L) :
    head_(NULL),
    tail_(NULL),
    sz_(0) {
	
       dll_node_t<T>* aux = L.head_;

        while (aux != NULL) {
            insert_tail(new dll_node_t<T>(aux->get_data()));
            aux = aux->get_next();
        }
    }

    template <class T>
    dll_t<T>::~dll_t(void) {

        dll_node_t<T>* aux = NULL;

        while (head_ != NULL) {
            aux = head_;
            head_ = head_->get_next();
            delete aux;
            aux = NULL;
        }
        sz_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }

    template <class T>
    bool dll_t<T>::empty(void) const{

	if (head_ == NULL){

	   assert(tail_ == NULL);
	   assert(sz_ == 0);

	   return true;
	} else 
	   return false;
    }

    template <class T>
    void dll_t<T>::insert_head(dll_node_t<T>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            head_->set_prev(nodo);
            nodo->set_next(head_);
            head_ = nodo;
        }

        sz_++;
    }

    template <class T>
    void dll_t<T>::insert_tail(dll_node_t<T>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            tail_->set_next(nodo);
            nodo->set_prev(tail_);
            tail_ = nodo;
        }

        sz_++;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_tail(void) {

        assert(!empty());

        dll_node_t<T>* aux = tail_;

        tail_ = tail_->get_prev();

        if (tail_ != NULL)
            tail_->set_next(NULL);
        else
            head_ = NULL;

        sz_--;

		aux->set_prev(NULL);

        return aux;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_head(void) {

        assert(!empty());

        dll_node_t<T>* aux = head_;

        head_ = head_->get_next();

        if (head_)
            head_->set_prev(NULL);
        else
            tail_ = NULL;

        sz_--;

		aux->set_next(NULL);

        return aux;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::get_head(void) {
	return head_;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::get_tail(void) {
	return tail_;
    }

    template <class T>
    ostream& dll_t<T>::write(ostream& os) const {
		
        dll_node_t<T>* aux = head_;

	os << "{";
        while (aux != NULL) {
            aux->write(os);
	    os <<  " <-> ";

            aux = aux->get_next();
        }

	os << "|| ";
	os << "}";
	return os;
    }

    template <class T>
    void dll_t<T>::unlink(dll_node_t<T>* nodo) {
			
        assert(nodo != NULL);

        if (nodo->get_prev() != NULL){
            nodo->get_prev()->set_next(nodo->get_next());
   	    nodo->set_prev(NULL);
	}
        else
            head_ = nodo->get_next();

        if (nodo->get_next() != NULL){
            nodo->get_next()->set_prev(nodo->get_prev());
	    nodo->set_next(NULL);
	}
        else
            tail_ = nodo->get_prev();

        sz_--;

    }

    template <class T>
    int dll_t<T>::get_size(void) const {
        return sz_;
    }	
}
