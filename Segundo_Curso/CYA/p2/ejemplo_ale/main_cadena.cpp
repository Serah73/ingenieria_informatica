#include "cadena.hpp"


int main () {
	cadena_t a(4);
	a.set_simb(1, 'a');
	a.set_simb(3, 'z');
	a.write(cout);
	cout << endl;

	cadena_t b = a;
	b.set_simb(0, 'D');
	b.write(cout) << endl;

	cadena_t c;
	c.concat(a, b);
	c.write(cout);
	cout << endl;

	cadena_t d;
	d.inversa(c);
	d.write(cout) << endl;

	if(a == b)
		cout << "hola" << endl;
	if(a < c)
		cout << "a < c" << endl;
	if(c < d)
		cout << "c < d" << endl;
	if(d < c)
		cout << "d < c" << endl;
	if(c == d)
		cout << "c == d" << endl;

}

