#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED {

	template <class T>
	class stack_l_t{
	private:

		dll_t<T>    l_;

	public:	
		stack_l_t(void):
		l_() {}

		~stack_l_t(void) {}

		bool empty(void){
			return l_.empty();
		}

		T top(void){

			assert(!empty());
			
			dll_node_t<T>* node = l_.get_head();
			T data = node->get_data();
			return (data);
		}

		void pop(void){
			assert(!empty());			

			dll_node_t<T>* node = l_.extract_head();
			delete node;
		}

		void push(T dato){

			dll_node_t<T>* node = new dll_node_t<T>(dato);
			l_.insert_head(node);
		}

		ostream& write(ostream& os){
			
			dll_node_t<T>* aux = l_.get_head();

			while(aux != NULL){
				cout << " │ " << setw(2)<< aux->get_data() << "  │" << endl;
				aux = aux->get_next();
			}

			cout << " └─────┘" << endl; 
		}

	};
}
