#ifndef nfa_t_H_
#define nfa_t_H_

#include "estado.h"
#include "transicion.h"

const char EPSILON = '~';


class nfa_t {

private:

	int num_estados_;
	int est_inicial_;
	set<estado_t> estados_;
	set<char> alfabeto_;

public:

	nfa_t (void);
	nfa_t (const nfa_t& nfa);
	~nfa_t (void);

	void clear (void);
	void estados_muerte (void) const;
	bool es_dfa (void) const;
	void analizar_cadena (const string& cadena, ostream& os) const;

	istream& read (istream& is);
	ostream& write (ostream& os);

private:
	bool caminos_rec (vector<transicion_t>& camino, int& num_camino, int estado, const string& cadena, int n, ostream& os) const;
	ostream& print_camino(vector<transicion_t>& camino, ostream& os) const;

};

#endif
