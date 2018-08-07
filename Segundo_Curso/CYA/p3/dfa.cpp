#include "dfa.h"


dfa_t::dfa_t(void) 
{
	num_states_ = 0;
}


dfa_t::dfa_t(const dfa_t& dfa) 
{
	num_states_ = dfa.num_states_;
	state_ini_ = dfa.state_ini_;
	states_ = dfa.states_;
	alpha_ = dfa.alpha_;
}


dfa_t::~dfa_t(void) 
{
	clear();
}


void dfa_t::clear(void) 
{
	states_.clear();
	alpha_.clear();
	num_states_ = 0;
}


void dfa_t::state_death(void) 
{
	bool exist = false;
	
	for(set<state_t>::iterator it = states_.begin(); it != states_.end(); it++)
	
		if(it->stateDeath()) {
			exist = true;
			cout << it->get_id() << ", ";
		}

	if(!exist)
		cout << "No existe estado/s de muerte";
	
	cout << endl;
}


void dfa_t::check_string(const string& chain, ostream& os) const 
{
	os << "Cadena de entrada: " << chain << endl;

	if(num_states_ == 0)
		os << "Cadena de entrada NO ACEPTADA" << endl;
	
	else {
		os << "Estado actual    Entrada    Siguiente estado" << endl;
		set<state_t>::iterator it;
		int next = state_ini_, i = 0;
		bool error = false;

		while((i < chain.size()) && (!error)) 
		{
			os << next << "\t\t " << chain[i];
			it = states_.find(next);
			next = it->get_next(chain[i]);
			os << "\t   " << next << endl;
			i++;
		
			if(next == -1) 
			{
				cout  << "No existe transicion con este caracter" << endl;
				error = true;
			}
		}

		it = states_.find(next);
		os << "Cadena de entrada ";
	
		if((it->acceptance()) && (!error))
			os << "ACEPTADA" << endl;
	
		else
			os << "NO ACEPTADA" << endl;
	}

}


istream& dfa_t::read(istream& is) 
{
	is >> num_states_;
	
	if(num_states_ > 0) 
	{
		is >> state_ini_;
		state_t aux;
		
		for(int i = 0; i < num_states_; i++) 
		{
			aux.read(is);
			states_.insert(aux);
		}
	}

	for(set<state_t>::iterator it = states_.begin(); it != states_.end(); it++)
		for(int i = 0; i < it->num_transitions(); i++)
			alpha_.insert(it->get_symb(i));

	bool sure = true;
	
	for(set<state_t>::iterator it = states_.begin(); it != states_.end(); it++)
		for(set<char>::iterator it2 = alpha_.begin(); it2 != alpha_.end(); it2++)
			if(!it->check_sym(*it2))
				sure = false;

	if(!sure)
		cout << "Error en la definicion del automata" << endl;

	return is;
}


ostream& dfa_t::write(ostream& os) 
{
	os << num_states_ << endl << state_ini_ << endl;
	
	for(set<state_t>::iterator it = states_.begin(); it != states_.end(); it++)
		it->write(os) << endl;

	return os;
}