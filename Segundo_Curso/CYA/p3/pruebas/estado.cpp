#include "estado.h"


estado_t::estado_t (void) {}

estado_t::estado_t (int id) {
	id_ = id;
}


estado_t::estado_t (const estado_t& estado) {
	id_ = estado.id_;
	aceptacion_ = estado.aceptacion_;
	next_ = estado.next_;
}

estado_t::~estado_t(void) {}


int estado_t::get_id (void) const {
	return id_;
}


int estado_t::num_transiciones (void) const {
	return next_.size();
}


char estado_t::get_simb (int a) const {
	return next_[a].simb;
}


int estado_t::aceptacion (void) const {
	return aceptacion_;
}


bool estado_t::estado_muerte (void) const {
	bool est_muerte = true;
	if(aceptacion_)
		est_muerte = false;
	else {
		int i = 0;
		while((i < next_.size()) && est_muerte) {
			if(next_[i].est != id_)
				est_muerte = false;
			i++;
		}
	}

	return est_muerte;
}


bool estado_t::comprobar_simbolo (char simbolo) const {
	int cont = 0;
	bool correcto;
	for(int i = 0; i < next_.size(); i++)
		if(next_[i].simb == simbolo)
			cont++;
	
	if(cont == 1) correcto = true;
	else correcto = false;

	return correcto;
}


int estado_t::get_next (char simbolo) const {
	bool found;
	int next = -1;
	int i = 0;

	do {
		if(next_[i].simb == simbolo) {
			next = next_[i].est;
			found = true;
		}
		i++;
	} while((!found) && (i < next_.size()));

	return next;
}


istream& estado_t::read (istream& is) {
	int sz, a;
	char c;
	is >> id_ >> aceptacion_ >> sz;
	next_.resize(sz);

	for(int i = 0; i < next_.size(); i++) {
		is >> c >> a;
		next_[i].simb = c;
		next_[i].est = a;
	}

	return is;
}


ostream& estado_t::write (ostream& os) const {
	os << id_ << ' ' << aceptacion_ << ' ' << next_.size();
	for(int i = 0; i < next_.size(); i++)
		os << ' ' << next_[i].simb << ' ' << next_[i].est;

	return os;
}


estado_t& estado_t::operator= (const estado_t& estado) {
	id_ = estado.id_;
	aceptacion_ = estado.aceptacion_;
	next_ = estado.next_;
}


bool estado_t::operator== (const estado_t& estado) const {
	return(id_ == estado.id_);
}


bool estado_t::operator< (const estado_t& estado) const {
	return(id_ < estado.id_);
}








