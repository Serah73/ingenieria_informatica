#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;
namespace AED {

	template <class T>
	class stack_v_t{
	private:

		vector_t<T> v_;
		int         top_;

	public:	
		stack_v_t(int max_sz):
		v_(max_sz),
		top_(-1) {}

		~stack_v_t(void) {}

		bool empty(void){
			return (top_ < 0);
		}

		T top(void){

			assert(!empty());
			return v_[top_];
		}

		void pop(void){

			assert(!empty());			
			top_--;
		}

		void push(T dato){

			assert(top_ < v_.get_sz() - 1);

			top_ ++;
			v_[top_] = dato;
		}

		ostream& write(ostream& os){

			for(int i = top_; i >= 0; i--)
				cout << " │ " << setw(2)<< v_.get_v(i) << "  │" << endl;
			cout << " └─────┘" << endl; 
		}

	};
}

