//Created by Jose Ramon Rodriguez Hernandez
//User: Serah
//Year: 2018

#include <iostream>
#include <algorithm>

#include "dfa.h"


int main(void)
{
	dfa_t d;
	dfa_t min;
	int option = 0;
	char fn[20];
	bool inserted, minimo = false;

	do
	{
		system("clear");
		std::cout << "\t\t- - - M E N U - - -\n";
		std::cout << "\t1 - Leer DFA\n";
		std::cout << "\t2 - Mostrar DFA\n";
		std::cout << "\t3 - Identificar estados de muerte\n";
		std::cout << "\t4 - Analizar cadena\n";
		std::cout << "\t5 - Minimizacion del DFA\n";
		if ( minimo ) 
			std::cout << "\t6 - Exportar DFA(minimo)\n";
		
		std::cout << "\t0 - Salir\n";
		std::cout << "\t\t>>> Introduzca una opcion: ";

	    std::cin >> option;

        system("clear");

	    switch (option)
	    {
	    	case 1:
			{
				int count = 0;
				minimo = false;

	    		std::cout << "\t- - - Lector de DFA - - -\n";

				do{
	            	if ( count != 0 )
						std::cout << "\n\tPor favor, Introduzca un archivo correcto: ";
	            	else
						std::cout << "\n\tIntroduzca un archivo: ";
	            	
					std::cin >> fn;
	            
					d.destroy();
					d.build(fn);

					count++;
				
				}while( d.get_error() );

	            std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

	            break;
			}

	        case 2:

	        	std::cout << "\t- - - Mostrar DFA - - -\n\n";

				std::cout << d;

	            std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

	            break;

	        case 3:

	        	std::cout << "\t- - - Identificar estados de muerte - - - \n";

	            d.dead_state();

	            break;

	        case 4:
	        {
	            std::cout << "\t- - - Analizar cadena - - - \n\n";

	            std::string c;

	            std::cout << "\n\tIntroduzca una cadena: ";
	            std::cin >> c;

	            d.check_user(c);

	            break;
	        }

			case 5:

				std::cout << "\t- - - Minimizacion del automata - - - \n";

				d.minimize( min );
				
				minimo = true;

				std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

				break;

			case 6:

				if( minimo )
				{
					std::cout << "\t- - - Exportacion del automata minimo - - - \n";

					min.build_file();

					std::cout << "\n\tPulse enter para ir al menu...";
	            	std::cin.ignore();
	            	std::cin.ignore();

					break;
				}
	    }

	} while (option != 0);
	return 0;
}
