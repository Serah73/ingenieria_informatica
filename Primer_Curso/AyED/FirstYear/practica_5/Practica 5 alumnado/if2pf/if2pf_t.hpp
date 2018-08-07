#pragma once

#include <cstdio>
#include <cassert>
#include <iostream>

enum       OPERATOR_ID      { PLUS, MINUS, MULTIPLY, DIVIDE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS };
const int  precedence[]   = {    1,     1,        2,      2,                0                    };	//orden el la que voy a usar las operaciones
const char operator_sym[] = {  '+',   '-',      '*',     '/'                                     };

using namespace std;

namespace AED {

	template <class T>
	class if2pf_t{
	private:
		T stack_;

	public:
		if2pf_t() {}

		~if2pf_t() {}
	
		void compute(istream& is, ostream& os)
		{

			int operando;
			char operador;

			while(!is.eof()){

				is >> ws;	//para sacar los espacios en blanco.
				int c = is.peek();

				if (c != EOF) {

					if (isdigit(c)){
						is >> operando;
						os << operando << "  ";
					}
					else {
						is >> operador;
						operator_procedure(operator, os);
					}
				}
			}

			/* … */
		}

		private: 

			const int get_operator_id(char operador)
			{
				int current_operator_id = -1;

				/* … */				//switch para devolver la const asociada	''''caso +: current_operator_id;/break;

				return current_operator_id;
			}

			void operator_procedure(char operador, ostream& os){
				
				const int current_operator_id = get_operator_id(operador);

				if (current_operator_id == RIGHT_PARENTHESIS)	//este if es modificado
				{
					while(!stack_.empty() && stack_.top()!=LEFT_PARENTHESIS)//stack_.empty para controlar el parentesis
					{
						os<<operator_sym[stack_.top]<<" "; //espacio" "
						stack_.pop();
					}
					stack_.pop();//para luego separar no se que mierda.
				}
				else{					// else es modificado
					if(stack_.empty() || current_operator_id==LEFT_PARENTHESIS || precedence[stack_.top()]<=precedence[current_operator_id])
						stack_.push(current_operator_id);
				}

			}
			else
			{
				while(!stack_.empty() && precedence[stack_.top()]>=precedence[current_operator_id])
				{
					os << operator_sym[stack_.top()]<< " ";
					stack_pop();
				}
				stack_.push(current_operator_id);
			}

       };

}

/*
				solo queda el ultimo pto.
				sin la practica_4 estamos perdidos
*/