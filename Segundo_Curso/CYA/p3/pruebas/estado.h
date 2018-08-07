#ifndef estado_t_H_
#define estado_t_H_

#include<iostream>
#include<vector>

using namespace std;

struct transicion{
	char simb;
	int est;
};


class estado_t {

private:

	int id_;
	int aceptacion_;
	vector<transicion> next_;

public:

	estado_t (void);
	estado_t(int id);
	estado_t (const estado_t& estado);
	~estado_t (void);

	int get_id (void) const;
	int num_transiciones (void) const;
	char get_simb (int a) const;

	int aceptacion (void) const;
	bool estado_muerte (void) const;

	bool comprobar_simbolo (char simbolo) const;
	int get_next (char simbolo) const;

	istream& read (istream& is);
	ostream& write (ostream& os) const;

	estado_t& operator= (const estado_t& estado);
	bool operator== (const estado_t& estado) const;
	bool operator< (const estado_t& estado) const;

};

#endif
