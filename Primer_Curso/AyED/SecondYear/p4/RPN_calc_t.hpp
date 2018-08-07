#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

namespace AED {

	template <class T>
	class RPN_calc_t{
	private:
		T stack_;

	public:
		RPN_calc_t() {}

		~RPN_calc_t() {}
	
		const int compute(istream& is)
		{
			while(!is.eof()){

				is >> ws;

				if (!is.eof()) {
					
					int c = is.peek();
					
					if (isdigit(c)){			//si es un digito blabla.
						int operando;
						is >> operando;
						stack_.push(operando);		//lo metemos en la pila
					}
					else {
						
						char operador;
						is >> operador;
						operate(operador);
					}
				}
			}

            const int result = stack_.top();
            stack_.pop();
			assert(stack_.empty());
			return result;
		}
		
		
		bool pal(const char* cadena){
			const int sz = strlen(cadena);
			int i = 0, j = 0;
			while(j < sz/2)
			{
				if(i < sz/2)
				{
					stack_.push(cadena[i]);
					i++;		
				}else{
					if(stack_.top()==cadena[i])
					{
						i++;j++;
						stack_.pop();
					}else
						return false;
				}
			}
			return true;
		}
		
		bool equilibrada(const char* cadena){
    		
    		int i=0;
    		int N = 0;
    		int M = 0;
    
    		while((cadena[i] != '\0')){
    		
        		if(cadena[i] == '('){
            		stack_.push(0);
            		cout << "Entrada a la pila de (" << endl;
            		N++;
            		
        		}
        		else{
            	if(cadena[i] == ')'){
                	stack_.push(0);
                	//if(stack_.empty())
                    	//equi = false;
                    cout << "Entrada a la pila de )" << endl;
                    M++;
            	}
                else
                	stack_.pop();
        		}
        		i++;
    		}
    		if(N == M){
    			return true;
    		}
    		else{
    			return false;
    		}
    		
		}
		

		private: 

			void operate(char operador){
				
				
				const int r_op = stack_.top();		//cogemos el operano
				stack_.pop();						//subimos la pila
				
				const int l_op = stack_.top();
				stack_.pop();
				
				int result = 0;
				switch (operador){	
					case	'+': result = l_op + r_op;
							break;
					
					case	'-': result = l_op - r_op;	
							break;
					
					case	'*': result = l_op * r_op;
							break;
							
					case	'/': result = l_op / r_op;
							break;
							
					default	   : exit(0);
				}
				stack_.push(result);
			}

       };

}

// valgrind depurador en ejecucion