#include "fdispersion.hpp"

template<class T>
class fmodulo_t: public fdispersion_t<T>
{
    public:
        fmodulo_t(T x, int n);
        ~fmodulo_t();
        
        int dispersion();
};


template<class T>
fmodulo_t<T>::fmodulo_t(T x, int n):
fdispersion_t<T>(x, n){}

template<class T>
fmodulo_t<T>::~fmodulo_t(){}

template<class T>
int fmodulo_t<T>::dispersion()
{
    int x = fdispersion_t<T>::get_clave() % fdispersion_t<T>::get_nceldas();
    return x;
}