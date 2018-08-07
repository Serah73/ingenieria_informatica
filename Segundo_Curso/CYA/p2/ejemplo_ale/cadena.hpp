#ifndef cadena_t_H_
#define cadena_t_H_

#include <cassert>
#include "simbolo.hpp"


class cadena_t {

private:

	simbolo_t* cadena_;
	int sz_;

public:

	cadena_t(void);
	cadena_t(int sz);
	cadena_t(const cadena_t& cad);
	~cadena_t(void);

private:

	void destruye_cadena(void);

public:

	char get_simb(int pos) const;
	void set_simb(int pos, char c);

	bool empty(void) const;
	int get_sz(void) const;
	void resize(int sz);

	cadena_t& concat(const cadena_t& cad1, const cadena_t& cad2);
	cadena_t& inversa(const cadena_t& cad);
	bool igual(const cadena_t& cad) const;

	ostream& write(ostream& os) const;
	istream& read(istream& is, int sz);

	cadena_t& operator=(const cadena_t& cad);
	bool operator==(const cadena_t& cad) const;
	bool operator<(const cadena_t& cad) const;

};

#endif
