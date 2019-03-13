/*
 * dfa.cpp
 *
 *  Created on: 19 nov. 2018
 *      Author: Serah
 */

#include "dfa.h"

dfa_t::dfa_t():
nstates_(0),
qstart_(0),
error_state_(0),
type_error_(0)
{}

dfa_t::dfa_t(char file[])
{
	destroy();
	
	build(file);
}

dfa_t::dfa_t(const dfa_t &dfa):
nstates_(dfa.nstates_),
qstart_(dfa.qstart_),
dfa_(dfa.dfa_),
alphabet_(dfa.alphabet_),
error_state_(dfa.error_state_),
type_error_(dfa.type_error_)
{}

dfa_t::~dfa_t(){}

void dfa_t::build(char file[])
{
	bool format;
	std::string linea;
	std::ifstream input;
	std::vector<transition_t> t_aux;
	int sum = 0;

	format = check_format(file);

	if(format)
	{
		input.open(file);

		if (input.is_open())
		{
			input >> (int &) nstates_ >> (int &) qstart_;
	    	linea.clear();

	    	while(getline(input, linea))
	    	{
	    		if(sum != 0)
	    		{
	    	    	state_t e_aux(linea);
	    	        dfa_.insert(e_aux);
	    	        t_aux = e_aux.get_transition();

	    	        int size_t = t_aux.size();

	    	        for ( int i = 0; i < t_aux.size(); i++ )
	    	        	alphabet_.insert(t_aux[i].get_symbol() );
		       		
	    	   		linea.clear();	
	    	    }
	    	    sum++;
	    	}
	    	
	    	if ( !(check_states(dfa_)) )
				error_menu();
	    	else
				std::cout << "\n\t- - - Se ha instalado correstamente - - -\n";

		}else
		{
			set_error(true, 3);
			error_menu();
		}
		input.close();
	}
	else
		error_menu();
		//std::cout << "Error: Revise el formato del archivo\n";
}

void dfa_t::destroy()
{
	error_ = false;
	nstates_ = 0;
	qstart_ = 0;
	error_state_ = 0;
	type_error_ = 0;
	dfa_.clear();
	alphabet_.clear();
}

//Get's
bool dfa_t::get_error()
{
	return error_;
}
bool dfa_t::get_error() const
{
	return error_;
}
int dfa_t::get_nstates()
{
	return nstates_;
}
int dfa_t::get_nstates() const
{
	return nstates_;
}
int dfa_t::get_qstart()
{
	return qstart_;
}
int dfa_t::get_qstart() const
{
	return qstart_;
}
int dfa_t::get_error_state()
{
	return error_state_;
}
int dfa_t::get_error_state() const
{
	return error_state_;
}
int dfa_t::get_type_error()
{
	return type_error_;
}
int dfa_t::get_type_error() const
{
	return type_error_;
}
std::set<char> dfa_t::get_alphabet()
{
	return alphabet_;
}
std::set<char> dfa_t::get_alphabet() const
{
	return alphabet_;
}
std::set<state_t> dfa_t::get_dfa()
{
	return dfa_;
}
std::set<state_t> dfa_t::get_dfa() const
{
	return dfa_;
}

state_t dfa_t::get_state(int q)
{
	state_t dummy;

	for ( std::set<state_t>::iterator i = dfa_.begin(); i != dfa_.end(); i++)
	{
		dummy = *i;

		if (dummy.get_id() == q)	return dummy;
	}

	return dummy;
}
//Set's
void dfa_t::set_error(bool error, int type)
{
	error_ = error;
	type_error_ = type;
}
void dfa_t::set_nstates(int n)
{
	nstates_ = n;
}
void dfa_t::set_qstart(int n)
{
	qstart_ = n;
}
void dfa_t::set_dfa(std::set<state_t> setty)
{
	dfa_ = setty;
}
void dfa_t::set_alphabet(std::set<char> setty)
{
	alphabet_ = setty;
}
void dfa_t::set_error_state(int est)
{
	error_state_= est;
}
//Checked's
bool dfa_t::check_states(std::set<state_t> setty)
{
	for(std::set<state_t>::iterator it = setty.begin(); it != setty.end(); it++)
	{
		state_t dummy = *it;

		for(int i = 0; i < dummy.get_transition().size(); i++)
			if ( dummy.get_transition()[i].get_next() >= get_nstates() )
			{
				set_error_state(dummy.get_transition()[i].get_next());
				set_error(true, 2);
				return false;
			}
	}
	set_error(false, 0);
	return true;
}

bool dfa_t::check_format(char file[])
{
	int line = 0;
	std::string str; str.clear();
	int size = str.size();
	std::ifstream in;


	in.open(file);

	if (in.is_open() )
	{
		while( getline(in, str) )
		{
			if ( ( line == 1 ) && ( size > 1 ) )
			{
				std::cout << "\tExiste mas de un estado inicial, no es apto para este DFA.";
				in.close();
				set_error(false, 1);
				return false;
			}
			else if ( line > 1 )
				for (int i = 7; i < size; i++)
					if( str[6] == str[i] )
					{
						std::cout << "\tExiste mas de una transicion para un caracter, no es apto para este DFA.";
						in.close();
						set_error(true, 1);
						return false;
					}
			line++;
		}
	}
	in.close();
	set_error(false, 0);

	return true;
}

void dfa_t::dead_state()
{

    std::vector<int> dead_ids; dead_ids.clear();

    for ( std::set<state_t>::iterator i = dfa_.begin(); i != dfa_.end(); i++)
    {
        state_t dummy = *i;

        if(dummy.check_dead())
            dead_ids.push_back(dummy.get_id());
    }
    int size = dead_ids.size();

    if( !dead_ids.empty() )
    {
    	if (size == 1 )
    		std::cout << "\tEstado de muerte:";
    	else
    		std::cout << "\tEstados de muerte:";

        for (int j = 0; j < size; j++)
        {
        	if (j == 0)
        		std::cout << "\n\t\tq" << dead_ids[j];
        	else
            	std::cout << ", q" << dead_ids[j];
        }

        std::cout << "\n\n\tPulse enter para ir al menu...";
        std::cin.ignore();
        std::cin.ignore();

    }else{

    	std::cout << "\tNo hay estados de muerte.\n";

    	std::cout << "\n\tPulse enter para ir al menu...";
    	std::cin.ignore();
    	std::cin.ignore();
    }
}

void dfa_t::error_menu()
{
	if ( get_error() )
	{
		if ( get_type_error() ==  1)
			std::cout << "\n\t- - - Error: Revise el formato del archivo - - -\n";
		else if ( get_type_error() == 2 )
		{
			std::cout << "\n\t- - - Error: Revise los estados - - -\n";
			std::cout << "\n\t----> Especificamente la transicion al estado: " << get_error_state() << ".\n";
		}
		else if( get_type_error() == 3 )
			std::cout << "\n\t- - - Error: Ha fallado la instalacion del automata - - -\n";
		else
			std::cout << "\n\t- - - Error: No esta catalogado el error - - -\n";
	}
	else
		std::cout  << "\n\t- - - Error: Llamada al menu error erronea - - -\n";
}

//Others
void dfa_t::write()
{
		std::cout << get_nstates() << "\n";
		std::cout << get_qstart() << "\n";

	    std::set<state_t> p = get_dfa();

	    for ( std::set<state_t>::iterator i = p.begin(); i != p.end(); i++ )
	        std::cout << *i << "\n";
}

//Main
void dfa_t::menu()
{
	int option = 0;
	char fn[20];
	bool inserted;

	do
	{
		system("clear");
		std::cout << "\t\t- - - M E N U - - -\n";
		std::cout << "\t1 - Leer DFA\n";
		std::cout << "\t2 - Mostrar DFA\n";
		std::cout << "\t3 - Identificar estados de muerte\n";
		std::cout << "\t4 - Analizar cadena\n";
		std::cout << "\t0 - Salir\n";
		std::cout << "\t\t>>> Introduzca una opcion: ";

	    std::cin >> option;

        system("clear");

	    switch (option)
	    {
	    	case 1:
			{
				int count = 0;

	    		std::cout << "\t\t- - - Lector de DFA - - -\n";

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

	        	std::cout << "\t\t- - - Mostrar DFA - - -\n\n";

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



void dfa_t::check_user(std::string str)
{
	//bool accepted;
	int i = 0, next = qstart_, size = str.size();
	state_t q;

	std::cout << "\tCadena de entrada: " << str << "\n";
	std::cout << "\tEstado actual   " << "Entrada" << "    Siguiente Estado\n";

	while ( i < size )
	{
		q = get_state(next);		//la primera iteracion al ser next = qstart, sera el nodo 0
		
		std::vector<transition_t> trans = q.get_transition();

		for ( int j = 0; j < trans.size(); j++)
		{
			if ( str[i] == trans[j].get_symbol()  )
			{
				std::cout << "\t" << next << std::setw(16) << str[i];
				next = trans[j].get_next();
				std::cout << std::setw(11) << next << "\n";
			}
		}
		i++;
	}
	q = get_state(next);

	if ( q.get_state() == 1 )
		std::cout << "\tCadena: ACEPTADA\n";
	else
		std::cout << "\tCadena: NO ACEPTADA\n";

	std::cout << "\n\tPulse enter para ir al menu...";
	std::cin.ignore();
	std::cin.ignore();
}

void dfa_t::operator()(char file[])
{
	build(file);
}


std::ostream &operator<<(std::ostream &os, const dfa_t& dfa)
{
	   os << dfa.get_nstates() << "\n";
	    os << dfa.get_qstart() << "\n";

	    std::set<state_t> p = dfa.get_dfa();

	    for ( std::set<state_t>::iterator i = p.begin(); i != p.end(); i++ )
	        os << *i << "\n";

	    return os;
}

