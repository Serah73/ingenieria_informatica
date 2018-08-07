#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>


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

			//string token;
			int operando;
			char operador;

			while(!is.eof()){//mientras no final de fich

				is >> ws;
				int c = is.peek();	//peek es solo verlo no sacarlo

				if (!is.eof()) {

					if (isdigit(c)){		//
						is >> operando;		//lo saco del string y lo meto en el operando
						/* ... */			//push sobre stack.push un numero, si no es un digito sigue
					}
					else {
						is >> operador;
						/* ... */			//sino es un digito es un operador que es lo que haria aqui
					}
				}
			}

                        /* ... */		//top pop return(resumen)
			return result;
		}

		private: 

			void operate(char operador){
				
				/* ... */		//operador que salga en el prueba.txt, un switch que tenga las operaciones aritmeticas, 
			}

       };

}

