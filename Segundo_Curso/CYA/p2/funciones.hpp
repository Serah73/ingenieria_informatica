#include <iostream>
#include <set>
#include <cstring>
#include <iterator>
#include <algorithm>


class cadena_t
{
	friend ostream &operator<<(ostream &, const cadena_t &);
public:
    string sum;
	string s;
	
	cadena_t();
	cadena_t(const char*);
	cadena_t(const cadena_t &);
	virtual ~cadena_t();
	cadena_t &operator=(const cadena_t &rhs);
	int operator==(const cadena_t &rhs) const;
	int operator<(const cadena_t &rhs) const;
};

class lenguaje_t
{
    
        std::set<cadena_t> lenguaje_;
        std::set<cadena_t> expresion_regular_;
        bool chain_empty;
        bool infinite_;
        
        lenguaje_t(void);
        
        ~lenguaje_t();
        
    public:
        
        istream& read(istream& is);
};
	
/*	
class calculadora_t
{
        lenguaje_t lengua_1;
        lenguaje_t lengua_2;
    
    public:

        void potencia(lenguaje_t lengua_1);
        void kleene(lenguaje_t lengua_1);
        void inversa(lenguaje_T lengua_1);

        void concatenacion(lenguaje_t lengua_1, lenguaje_t lengua_2);
        void unio(lenguaje_t lengua_1, lenguaje_t lengua_2);
        void interseccion(lenguaje_t lengua_1, lenguaje_t lengua_2);
        void diferencia(lenguaje_t lengua_1, lenguaje_t lengua_2);
        void sublenguajes(lenguaje_t lengua_1, lenguaje_t lengua_2);
        void igualdad(lenguaje_t lengua_1, lenguaje_t lengua_2);

}
*/