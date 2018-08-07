#ifndef lenguaje_t_H_
#define lenguaje_t_H_

#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include "cadena.hpp"

class lenguaje_t {

private:

	set<cadena_t> lenguaje_;
	string exp_reg_;
	bool vacio_;
	bool infinito_;

public:

	lenguaje_t(void);
	lenguaje_t(const lenguaje_t& leng);
	~lenguaje_t(void);

	lenguaje_t& unir(lenguaje_t& leng1, lenguaje_t& leng2);
	lenguaje_t& interseccion(lenguaje_t& leng1, lenguaje_t& leng2);
	lenguaje_t& inversa(lenguaje_t& leng);
	lenguaje_t& concatenacion(lenguaje_t& leng1, lenguaje_t& leng2);
	lenguaje_t& diferencia(lenguaje_t& leng1, lenguaje_t& leng2);

	void sublenguajes(void);
	bool igualdad(lenguaje_t& leng);
	lenguaje_t& potencia(lenguaje_t& leng, int n);
	lenguaje_t& kleene(lenguaje_t& leng);

	ostream& write(ostream& os);
	istream& read(istream& is);

	void clear(void);

};

#endif
