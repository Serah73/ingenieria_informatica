#include "cadena.hpp"


cadena_t::cadena_t(void) {
	cadena_ = NULL;
	sz_ = 0;
}


cadena_t::cadena_t(int sz) {
	cadena_ = new simbolo_t [sz];
	sz_ = sz;
}


cadena_t::cadena_t(const cadena_t& cad) {
	cadena_ = new simbolo_t [cad.get_sz()];
	sz_ = cad.get_sz();
	for(int i = 0; i < cad.get_sz(); i++)
		set_simb(i, cad.get_simb(i));
}


cadena_t::~cadena_t(void) {
	destruye_cadena();
}


void cadena_t::destruye_cadena(void) {
	if(cadena_ != NULL) {
		delete[] cadena_;
		cadena_ = NULL;
	}
}


char cadena_t::get_simb(int pos) const {
	assert((pos >= 0) && (pos < get_sz()));

	return(cadena_[pos].get_s());
}


void cadena_t::set_simb(int pos, char c) {
	assert((pos >= 0) && (pos < get_sz()));

	cadena_[pos].set_s(c);
}


bool cadena_t::empty(void) const {
	return(sz_ == 0);
}


int cadena_t::get_sz(void) const {
	return sz_;
}


void cadena_t::resize(int sz) {
	destruye_cadena();
	cadena_ = new simbolo_t [sz];
	sz_ = sz;
}


cadena_t& cadena_t::concat(const cadena_t& cad1, const cadena_t& cad2) {
	resize(cad1.get_sz() + cad2.get_sz());

	for(int i = 0; i < cad1.get_sz(); i++)
		set_simb(i, cad1.get_simb(i));
	for(int i = 0; i < cad2.get_sz(); i++)
		set_simb(i + cad1.get_sz(), cad2.get_simb(i));
	
	return *this;
}


cadena_t& cadena_t::inversa(const cadena_t& cad) {	
	resize(cad.get_sz());

	if(!cad.empty()) {
		for(int i = 0; i <= get_sz() / 2; i++) {
			set_simb(i, cad.get_simb(get_sz()-1-i));
			set_simb(get_sz()-1-i, cad.get_simb(i));
		}
	}

	return *this;
}


bool cadena_t::igual(const cadena_t& cad) const {
	bool igual = true;
	if(get_sz() != cad.get_sz())
		igual = false;
	else
		for(int i = 0; i < get_sz(); i++)
			if(get_simb(i) != cad.get_simb(i))
				igual = false;
	
	return igual;
}


ostream& cadena_t::write(ostream& os) const {
	if(empty())
		os << '&';
	else
		for(int i = 0; i < get_sz(); i++)
			cadena_[i].write(os);

	return os;
}


istream& cadena_t::read(istream& is, int sz) {
	resize(sz);
	for(int i = 0; i < get_sz(); i++)
		cadena_[i].read(is);

	return is;
}


cadena_t& cadena_t::operator=(const cadena_t& cad) {
	resize(cad.get_sz());
	for(int i = 0; i < cad.get_sz(); i++)
		set_simb(i, cad.get_simb(i));
	return *this;
}


bool cadena_t::operator==(const cadena_t& cad) const {
	return igual(cad);
}


bool cadena_t::operator<(const cadena_t& cad) const {
	if(get_sz() < cad.get_sz())
		return true;
	if(get_sz() > cad.get_sz())
		return false;

	int i = 0;
	while(i < get_sz()) {
		if(get_simb(i) < cad.get_simb(i))
			return true;
		if(get_simb(i) > cad.get_simb(i))
			return false;
		i++;
	}

	return false;
}


	








