#include "dfa.h"


dfa_t::dfa_t(void) {
	num_estados_ = 0;
}


dfa_t::dfa_t(const dfa_t& dfa) {
	num_estados_ = dfa.num_estados_;
	est_inicial_ = dfa.est_inicial_;
	estados_ = dfa.estados_;
	alfabeto_ = dfa.alfabeto_;
}


dfa_t::~dfa_t(void) {
	clear();
}


void dfa_t::clear(void) {
	estados_.clear();
	alfabeto_.clear();
	num_estados_ = 0;
}


void dfa_t::estados_muerte(void) {
	bool hay = false;
	for(set<estado_t>::iterator it = estados_.begin(); it != estados_.end(); it++)
		if(it->estado_muerte()) {
			hay = true;
			cout << it->get_id() << ", ";
		}

	if(!hay)
		cout << "No hay estados de muerte";
	cout << endl;
}


void dfa_t::analizar_cadena(const string& cadena, ostream& os) const {
	os << "Cadena de entrada: " << cadena << endl;
	if(num_estados_ == 0)
		os << "Cadena de entrada NO ACEPTADA" << endl;
	else {
		os << "Estado actual    Entrada    Siguiente estado" << endl;
		set<estado_t>::iterator it;
		int siguiente = est_inicial_;
		int i = 0;
		bool error = false;

		while((i < cadena.size()) && (!error)) {
			os << siguiente << "\t\t " << cadena[i];
			it = estados_.find(siguiente);
			siguiente = it->get_next(cadena[i]);
			os << "\t   " << siguiente << endl;
			i++;
			if(siguiente == -1) {
				cout  << "Caracter no perteneciente al alfabeto" << endl;
				error = true;
			}
		}

		it = estados_.find(siguiente);
		os << "Cadena de entrada ";
		if((it->aceptacion()) && (!error))
			os << "ACEPTADA" << endl;
		else
			os << "NO ACEPTADA" << endl;

	}

}


istream& dfa_t::read(istream& is) {
	is >> num_estados_;
	if(num_estados_ > 0) {
		is >> est_inicial_;
		estado_t aux;
		for(int i = 0; i < num_estados_; i++) {
			aux.read(is);
			estados_.insert(aux);
		}
	}

	for(set<estado_t>::iterator it = estados_.begin(); it != estados_.end(); it++)
		for(int i = 0; i < it->num_transiciones(); i++)
			alfabeto_.insert(it->get_simb(i));

	bool correcto = true;
	for(set<estado_t>::iterator it = estados_.begin(); it != estados_.end(); it++)
		for(set<char>::iterator it2 = alfabeto_.begin(); it2 != alfabeto_.end(); it2++)
			if(!it->comprobar_simbolo(*it2))
				correcto = false;

	if(!correcto)
		cout << "Error en la definicion del automata" << endl;

	return is;
}


ostream& dfa_t::write(ostream& os) {
	os << num_estados_ << endl << est_inicial_ << endl;
	for(set<estado_t>::iterator it = estados_.begin(); it != estados_.end(); it++)
		it->write(os) << endl;

	return os;
}










