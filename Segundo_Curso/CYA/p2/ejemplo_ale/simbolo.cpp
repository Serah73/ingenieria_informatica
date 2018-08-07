#include "simbolo.hpp"


simbolo_t::simbolo_t(void) {
	set_s('0');
}


simbolo_t::simbolo_t(char c) {
	set_s(c);
}


simbolo_t::simbolo_t(const simbolo_t& simb) {
    c_ = simb.c_;
}


simbolo_t::~simbolo_t(void) {}


char simbolo_t::get_s(void) {
	return c_;
}

void simbolo_t::set_s(char c) {
	switch(c) {
		case ' ':
		case ',':
		case '{':
		case '}':
		case '&':
		case '(':
		case ')':
		case '|':
		case '*':
		case '.': cout << "Caracter no valido" << endl; break;
		default: c_ = c;
	}
}


ostream& simbolo_t::write(ostream& os) {
    os << get_s();
    return os;
}


istream& simbolo_t::read(istream& is) {
    char aux;
    is >> aux;
    set_s(aux);

    return is;
}














