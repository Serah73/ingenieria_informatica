#ifndef estado_t_H_
#define estado_t_H_

#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>

using namespace std;

struct grupo_transiciones {
	char simb;
	set<int> ests;
};


class estado_t {

private:

	int id_;
	int aceptacion_;
	vector<grupo_transiciones> transiciones_;
	int num_transiciones_;

public:

	estado_t (void);
	estado_t (int id);
	estado_t (const estado_t& estado);
	~estado_t (void);

	void clear (void);
	int get_id (void) const;
	int num_simbolos (void) const;
	char get_simb (int a) const;

	int aceptacion (void) const;
	bool estado_muerte (void) const;

	bool comprobar_simbolo (char simbolo) const;
	set<int> get_next (char simbolo) const;

	istream& read (istream& is);
	ostream& write (ostream& os) const;

	estado_t& operator= (const estado_t& estado);
	bool operator== (const estado_t& estado) const;
	bool operator< (const estado_t& estado) const;

};

#endif
