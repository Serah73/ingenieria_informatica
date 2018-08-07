#ifndef dfa_t_H_
#define dfa_t_H_

#include "estado.h"
#include <set>


class dfa_t {

private:

	int num_estados_;
	int est_inicial_;
	set<estado_t> estados_;
	set<char> alfabeto_;

public:

	dfa_t(void);
	dfa_t(const dfa_t& dfa);
	~dfa_t(void);

	void clear(void);
	void estados_muerte(void);
	void analizar_cadena(const string& cadena, ostream& os) const;

	istream& read(istream& is);
	ostream& write(ostream& os);

};

#endif
