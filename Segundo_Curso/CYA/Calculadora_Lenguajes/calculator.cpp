/*
 * calculator.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: Serah
 */

#include "calculator.h"

calculator_t::calculator_t()
{
	language_(request_language());
	language2_(request_language());
}

calculator_t::~calculator_t() {}

void calculator_t::inverse()
{
	    std::cout << "\n\tInversa\n\t\tlenguaje (1): {";
	    inverse_aux(language_);
	    
	    std::cout << "\n\tInversa\n\t\tlenguaje (2): {";
		inverse_aux(language2_);
}

void calculator_t::inverse_aux(language_t language)
{
	std::set<symbols_t>::reverse_iterator reverse = language.get_begin_rlanguage();
	std::set<symbols_t>::reverse_iterator end_while = language.get_end_rlanguage();
	std::set<symbols_t>::reverse_iterator aux = language.get_end_rlanguage();
	aux--;

    while (reverse != end_while)
    {
    	if(reverse == aux)
    		std::cout << (*reverse);

    	else
    		std::cout << (*reverse) << ", ";

    	reverse++;
    }
    std::cout << "}\n";
}

void calculator_t::concatenation()		////modificar
{
	std::set<symbols_t> final;
	std::set<symbols_t> laux = language_.get_language();
	std::set<symbols_t> l2aux = language2_.get_language();
	
    symbols_t aux;
    
    for (std::set<symbols_t>::iterator i = laux.begin(); i != laux.end(); i++) 
    {
        for (std::set<symbols_t>::iterator j = l2aux.begin(); j != l2aux.end(); j++) 
        {
            //aux.set_symbol(aux.add_symbol(*i, *j) );
            //aux = *i + *j;
            aux = prueba_concatenacion(*i, *j);
            final.insert(aux);
        }
    }
    std::cout << "\n\tConcatenacion\n\t\tlenguaje final: {";
    std::set<symbols_t>::iterator auxS = final.end();
    auxS--;
    
    for (std::set<symbols_t>::iterator k = final.begin(); k != final.end(); k++)
    {
        if (auxS == k) 
        	std::cout << *k;
        else 
        	std::cout << *k << ", ";
    }
    std::cout << "}\n";
}

symbols_t calculator_t::prueba_concatenacion(symbols_t a, symbols_t b)
{
	symbols_t aux;
	
	//aux.set_symbol( a.get_symbol() + b.get_symbol() );
	aux = a+b;
	
	
	return aux;
}


void calculator_t::unionl()
{
	//std::set<symbols_t> aux = language_.get_language();
	
	std::ostream_iterator<symbols_t> iter(std::cout, ", ");
	
    std::cout << "\n\tUnion de los lenguajes: {";
    
    std::set_union(language_.get_begin_language(), language_.get_end_language(),
    			   language2_.get_begin_language(), language2_.get_end_language(), iter);
    
    std::cout <<"}";
}

void calculator_t::intersection()
{
	//std::set<symbols_t> laux = language_.get_language();
	//std::set<symbols_t> l2aux = language_.get_language();
    std::ostream_iterator<symbols_t> iter( std::cout, ", " );
    std::cout << "\n\tIterseccion: {";
    std::set_intersection(language_.get_begin_language(), language_.get_end_language(),
    					  language2_.get_begin_language(), language2_.get_end_language(),
    					  iter);
    std::cout << "}";
}

void calculator_t::diference()
{
    std::ostream_iterator<symbols_t> iter( std::cout, ", " );
    std::cout << "\n\tDiferencia, lenguaje(1 - 2): {";
    std::set_difference(language_.get_begin_language(), language_.get_end_language(),
    					  language2_.get_begin_language(), language2_.get_end_language(),
    					  iter);
    std::cout << "}";
    
    std::cout << "\n\tDiferencia, lenguaje(2 - 1): {";
    std::set_difference(language2_.get_begin_language(), language2_.get_end_language(),
    					  language_.get_begin_language(), language_.get_end_language(),
    					  iter);
    std::cout << "}";
}

void calculator_t::sublanguage()
{
	bool its = true;

    std::set<symbols_t>::iterator it = language2_.get_begin_language();
     
    while ( (it != language2_.get_end_language() ) && (its) )
    {
    	its = language_.find(*it) != language_.get_end_language();
    	it++;
    }
    
    if (its)
        std::cout << "\t\tEl lenguaje (2) es un sublenguaje del lenguaje(1)\n";
    else
        std::cout << "\t\tEl lenguaje (2) no es un sublenguaje del lenguaje(1)\n";
}

void calculator_t::equality()
{
	bool its = true;
	
    std::set<symbols_t>::iterator it = language2_.get_begin_language();
    std::set<symbols_t>::iterator j = language_.get_begin_language();
     
    while ( (it != language2_.get_end_language()) && (its) )
    {
    	its = language_.find(*it) != language_.get_end_language();
    	it++;
    }
    
    while ( (j != language_.get_end_language()) && (its) )
    {
    	its = language2_.find(*j) != language2_.get_end_language();
    	j++;
    }
    
    if (its)
        std::cout << "\t\tLos lenguajes son iguales\n";
    else
        std::cout << "\t\tLos lenguajes no son iguales\n";
}

void calculator_t::potency()
{
    int n;
    
    symbols_t temp;
    std::set<symbols_t> final;
    std::set<symbols_t> aux = language_.get_language();
    
    std::cout << "\n\t¿Cuanto desea elevar el leguaje? ";
    std::cin >> n;
    
    if(n == 1)
    {
        std::cout << "\n\t\tResultado potencia: {";
        
        for ( std::set<symbols_t>::iterator it = language_.get_begin_language(); it != language_.get_end_language(); it++ )
            std::cout << *it << ", ";
        std::cout << "}\n";
    }else
    {
        for ( int it = 0; it < n - 1; it++ ) 
        {
            for ( std::set<symbols_t>::iterator i = language_.get_begin_language(); i != language_.get_end_language(); i++ ) 
            {
                for ( std::set<symbols_t>::iterator j = aux.begin(); j != aux.end(); j++ ) 
                {
                    temp = prueba_concatenacion(*i, *j);
                    final.insert(temp);
                }
            }
            aux = final;
            
            if (it != n - 2)
                final.clear();
        }
        std::cout << "\n\t \tResultado potencia: {";
        for ( std::set<symbols_t>::iterator k = final.begin(); k != final.end(); k++)
            std::cout << *k << " ";
            
        std::cout << "}\n";
    }
}

void calculator_t::kleene(std::set<symbols_t> language)
{
    symbols_t temp("&");
    std::set<symbols_t> final;
	/*
    std::set<symbols_t> acum = language;
    std::set<symbols_t> laux = language;
    std::ostream_iterator<symbols_t> iter( std::cout, " " );
    
    final.insert(temp);
    
    std::cout << "\tResultado del cierre (n = 5): ";
    std::cout << "\n\t{";
    std::set_union(final.begin(), final.end(), acum.begin(), acum.end(), iter);
    std::cout << "}";
    
    for (int it = 0; it < 2; it++) {
        
        for (std::set<symbols_t>::iterator i = language.begin(); i != language.end(); i++)
        {
            for (std::set<symbols_t>::iterator j = laux.begin(); j != laux.end(); j++)
            {
                
                temp = prueba_concatenacion(*i, *j);
                acum.insert(temp);
                
            }
            std::cout << "\n\t{";
            std::set_union(final.begin(), final.end(), acum.begin(), acum.end(), iter);
            std::cout << "}";
        }
        laux = acum;
    }
    
    std::cout << "\n" << "\t\t\t...\n";
    std::cout << "\t\t\t...\n";
    std::cout << "\t\t\t...\n";*/
    
}

void calculator_t::menu()
{
	int option;

	do{
		system("clear");
		std::cout << "\n\t\t ----MENU----\n\n";


		std::cout << "\t 1  -\tCambiar los dos lenguajes.\n";
		std::cout << "\t 2  -\tInversa.\n";
		std::cout << "\t 3  -\tConcatenacion.\n";
		std::cout << "\t 4  -\tUnion.\n";
		std::cout << "\t 5  -\tInterseccion.\n";
		std::cout << "\t 6  -\tDiferencia.\n";
		std::cout << "\t 7  -\tSublenguajes.\n";
		std::cout << "\t 8  -\tIgualdad de lenguajes.\n";
		std::cout << "\t 9  -\tPotencia.\n";
		std::cout << "\t10  -\tCierre de Kleene.\n";
		std::cout << "\t 0  -\tSalir.\n";

		std::cout << "\n\tElige la opcion: ";
		std::cin >> option;
		std::cout << "\n\n";
		
		switch(option)
		{
			case 0:
				std::cout << "\tSaliendo...\n";
				break;
	
			case 1:
				language_.clear();
				language2_.clear();
				language_(request_language());
				language2_(request_language());
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 2:
				//inversa
				std::cout << "antes\n";
				inverse();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 3:
				//concatenacion
				concatenation();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;
	
			case 4:
				//union
				unionl();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;
	
			case 5:
				//interseccion
				intersection();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;
		
			case 6:
				//diferencia
				diference();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 7:
				//sublenguajes
				sublanguage();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;
	
			case 8:
				//igualdad de lenguajes
				equality();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;
	
			case 9:
				//potencia
				potency();
				
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;	

			case 10:
				//kleene
				/*
				std::cout << "¿Que lenguaje quiere realizarle el cierre de kleene?(1- lenguaje(1), 2- lenguaje(2): ";
				int lenguaje;
				std::cin >> lenguaje;
				*/
				std::cout << "\tNo hecho correctamente. Mantenimiento...\n";
				/*
				if(lenguaje == 1)
					kleene(language_.get_language());
					
				else if(lenguaje == 2)
					kleene(language2_.get_language());
					
				else
					std::cout << "\tEso no te lo he dicho\n";
				*/
				std::cout << "\n\t---Pulse Enter para volver al menu...---";
				std::cin.ignore();
				std::cin.ignore();
				break;

			default:
				std::cout << "\t  *-¡Esa opcion no esta permitida!-*\n";
				break;
		}
	}while (option != 0);
}

std::string calculator_t::request_language()
{
	std::string input;
	std::cout << "Introduce un lenguaje: ";
	std::getline(std::cin, input);

	while((input[0] != '{') && (input[0] != '('))	//se imprime 2 veces porque si
	{
		
	////////////////////////////////////////////////////////////////////
	////////              D U D A                             //////////
	        std::cout << "*Introduzca el lenguaje correctamente *: ";
	        std::getline(std::cin, input);
	}
	return input;
}
