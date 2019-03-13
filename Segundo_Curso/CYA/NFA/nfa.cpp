#include "nfa.h"

Nfa_t::Nfa_t()
{
    destroy();
}

Nfa_t::Nfa_t(char file[])
{
    destroy();

	build(file);
}

Nfa_t::Nfa_t(const Nfa_t &nfa)
{
    destroy();

    set_error( nfa.get_error(), nfa.get_type_error() );
    set_nstates( nfa.get_nstates() );
    set_qstart( nfa.get_qstart() );
    set_error_state( nfa.get_error_state() );
    set_dfa( nfa.get_dfa() );
    set_alphabet( nfa.get_alphabet() );
}

Nfa_t::~Nfa_t(){}

void Nfa_t::important_state()
{
    std::vector<int> imp_ids;
    std::vector<int> non_imp_ids;
    std::set<state_t> aux_dfa = get_dfa();
    for (std::set<state_t>::iterator i = aux_dfa.begin(); i != aux_dfa.end(); i++)
    {
        state_t aux_st = *i;
        
        if(aux_st.check_imp())
            imp_ids.push_back( aux_st.get_id() );
        
        else  
            non_imp_ids.push_back( aux_st.get_id() );
    }
    
    if( !imp_ids.empty() )
    {  
        //Important's
        int size_imp = imp_ids.size();

        if (size_imp == 1)
            std::cout << "\tEstado importante: ";
        else
            std::cout << "\tEstados importantes: \n\t\t";
        
        for (int i = 0; i < size_imp; i++) 
        { 
            if ( i == size_imp - 1 )
                std::cout << "q" << imp_ids[i];
            else
                std::cout << "q" << imp_ids[i] << ", ";
        }

        std::cout << "\n";
        
        //Not important's
        int size_noimp = non_imp_ids.size();

        if (size_noimp == 1)
            std::cout << "\tEstado no importante: ";
        else
            std::cout << "\tEstados no importantes: \n\t\t";

        for (int i = 0; i < size_noimp; i++) 
        {  
            if ( i == size_noimp - 1) 
                std::cout << "q" << non_imp_ids[i];
            else
                std::cout << "q" << non_imp_ids[i] << ", ";
        }
        
        std::cout << "\n\n\tPulse Enter para volver al menu...";
        std::cin.ignore();
        std::cin.ignore();
    }
    else 
    {   
        std::cout << "\tNo existen estados importantes.\n";
        
        std::cout << "\n\tPulse Enter para volver al menu...";
        std::cin.ignore();
        std::cin.ignore();
    }
}

bool Nfa_t::its_dfa()
{ 
    std::set<state_t> dfa_aux = get_dfa();
    std::set<state_t>::iterator it = dfa_aux.begin();
 
    while (it != dfa_aux.end() )
    {        
    	state_t comp = *it;

    	if ( comp.get_transition().size() != get_alphabet().size() )
    	    return false;
    	
        else if(comp.get_transition().size() > 1)
        
            for (int i = 1; i < comp.get_transition().size(); i++) 
                //when the symbol in the interaction is the same that "i", the next positions, then it isn't a DFA.
                if (comp.get_transition()[0].get_symbol() == comp.get_transition()[i].get_symbol())
                    return false;
    	
    	
    	it++;
    }
    return true;
}
        
//estado, buffer, cadena, lugar cadena, siguiente, aceptado el camino, Ncamino tomado
void Nfa_t::ways(state_t state, const std::stringbuf &buffer, std::string str, int pos, int next, bool &a, int &n)
{
   
    state = get_state(next);
    int j = 0;
    
    if( str[pos+1] != '\0' )
    {
        //First way's with epsilon transitions
        std::set<int>transiciones = state.get_clausura();  //Probamos a obtener las transiciones de epsilon clausura
        
        if( transiciones.size() != 0 ) //Si se han conseguido las imprimimos
            for( std::set<int>::iterator x = transiciones.begin(); x != transiciones.end(); x++ )
            {                
                std::stringbuf b2;
                std::ostream os2(&b2);
                
                os2 << std::left << buffer.str() << "\t" << std::left << std::setw(17) << std::setfill(' ') << state.get_id() << std::setw(11) << std::setfill(' ') << "~" << (*x) << "\n";
                ways(state, b2, str, pos, (*x), a, n);
            }
        
        if( !transiciones.empty() )
		    transiciones.erase(transiciones.begin(), transiciones.end());
        
        //Probamos a obtener el conjunto de transiciones
        transiciones = state.get_transition( str[pos+1] );
        
        if( transiciones.size() == 0 )
        {
            n++;
            std::cout << "\n\tCamino " << n << ":\n";
            std::cout << "\tEstado actual    Entrada    Siguiente estado\n";
            std::cout << std::left << buffer.str();
            std::cout << std::left << std::setw(17) << std::setfill(' ') << state.get_id() << std::setw(11) << std::setfill(' ') << str[ pos + 1 ] << get_dfa().size() << "\n";
            
            for( int i = pos+2; str[i] != '\0'; i++ )    
                std::cout << std::left << std::setw(17) << std::setfill(' ') << get_dfa().size() << std::setw(11) << std::setfill(' ') << str[j] << get_dfa().size()<< "\n";
            
            std::cout<<"\tCadena de entrada ";
            std::cout<<"\tNO ACEPTADA.\n";
            
        }
        else

            for( std::set<int>::iterator x = transiciones.begin(); x != transiciones.end(); x++)
            {                
                std::stringbuf b2;
                std::ostream os2(&b2);
                
                os2 << std::left << buffer.str() << "\t" << std::left <<std::setw(17) << std::setfill(' ') << state.get_id() << std::setw(11) << std::setfill(' ') << str[pos+1] << (*x) << "\n";
                ways(state, b2, str, pos+1, (*x), a, n);
            }
        
    }else
    {    
        std::set<int> ep_transiciones = state.get_clausura();
        
        if( ep_transiciones.size() != 0 ) 
            for( std::set<int>::iterator x = ep_transiciones.begin(); x != ep_transiciones.end(); x++)
            {
                std::stringbuf b2;
                std::ostream os2(&b2);
                os2 << std::left << buffer.str() << "\t" << std::left << std::setw(17) << std::setfill(' ') << state.get_id() << std::setw(11) << std::setfill(' ') << "~" << (*x) << "\n";
                ways(state, b2, str, pos+1, (*x), a, n);
            }
        
        n++;
        std::cout << "\tCamino "<< n <<":\n";
        std::cout << "\tEstado actual    Entrada    Siguiente estado\n";
        std::cout << std::left << buffer.str() << "\n";
        
        if( state.get_state() == 1 )
        {            
            std::cout << "\tCadena ACEPTADA\n";
            
            if(!a)  a = true;
        } 
        else
            std::cout << "\tCadena NO ACEPTADA\n";
    }
}
void Nfa_t::check_user(std::string str)
{
    bool aceptada = false;
    int n_way = 0;
    state_t q;
    std::stringbuf buffer;
    std::ostream os (&buffer);
    
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    std::cout << "\t\tTRAZA:\n";
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    
    std::cout << "\n\tCadena de entrada: " << str << "\n";
    ways(q, buffer, str, -1, get_qstart(), aceptada, n_way);
    
    std::cout<<"\n\tDecision que se ha elegido:\n";
    std::cout<<"\t---------------\n";
    
    if(aceptada)    std::cout<<"\tCadena ACEPTADA";
    else    std::cout<<"\tCadena NO ACEPTADA";
    
    std::cout << "\n";
    
    std::cout << "\n\tPulse Enter para volver al menu...";
    std::cin.ignore();
    std::cin.ignore();
}


void Nfa_t::menu()
{
    int option = 0;
	char fn[20];
	bool inserted;

	do
	{
		system("clear");
		std::cout << "\t\t- - - M E N U - - -\n";
		std::cout << "\t1 - Leer NFA\n";
		std::cout << "\t2 - Mostrar NFA\n";
		std::cout << "\t3 - Identificar estados de muerte\n";
        std::cout << "\t4 - Identificar estados importantes\n";
        std::cout << "\t5 - Identificar DFA\n";
		std::cout << "\t6 - Analizar cadena\n";
		std::cout << "\t0 - Salir\n";
		std::cout << "\t\t>>> Introduzca una opcion: ";

	    std::cin >> option;

        system("clear");

	    switch (option)
	    {
	    	case 1:
            {
				int count = 0;

	    		std::cout << "\t\t- - - Lector de NFA - - -\n";

				do{
	            	if ( count != 0 )
						std::cout << "\n\tPor favor, Introduzca un archivo correcto: ";
	            	else
						std::cout << "\n\tIntroduzca un archivo: ";
	            	
					std::cin >> fn;
	            
					destroy();
					build(fn);
					count++;
				
				}while( get_error() );

	            std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

	            break;
			}
	        case 2:

	        	std::cout << "\t\t- - - Mostrar NFA - - -\n\n";

				write();

	            std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

	            break;

	        case 3:

	        	std::cout << "\t\t- - - Identificar estados de muerte - - - \n";

	            dead_state();

	            break;

	        case 4:

                std::cout << "\t\t- - - Identificar estados importantes - - - \n";
            
                important_state();

                break;
            
            case 5:
            {
                std::cout << "\t\t- - - Identificar DFA - - - \n";
                bool dfa = its_dfa();

                if( dfa )
                    std::cout << "\tEl automata es un DFA\n";
                else
                    std::cout << "\tEl automata no es un DFA\n";
                
                std::cout << "\n\tPulse enter para ir al menu...";
	            std::cin.ignore();
	            std::cin.ignore();

                break;
            }

            case 6:
	        {
	            std::cout << "\t\t- - - Analizar cadena - - - \n\n";

	            std::string c;

	            std::cout << "\n\tIntroduzca una cadena: ";
	            std::cin >> c;

	            check_user(c);

	            break;
	        }
	    }

	} while (option != 0);
}


std::ostream &operator<<(std::ostream &os, const Nfa_t& nfao){
    
    os << nfao.get_nstates() << "\n";
    os << nfao.get_qstart() << "\n";
    
    std::set<state_t> p = nfao.get_dfa();
    std::set<char> alf = nfao.get_alphabet();
    
    for (std::set<state_t>::iterator i = p.begin(); i != p.end(); i++) 
        os << *i << "\n";

    os << "Alfabeto: ";
    for (std::set<char>::iterator j = alf.begin(); j != alf.end(); j++)
        os << *j << " ";
    
    
    return os;
}