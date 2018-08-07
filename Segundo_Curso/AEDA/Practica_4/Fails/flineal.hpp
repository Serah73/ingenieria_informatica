#include "fexploracion.hpp"

template<class T>
class flineal_t: public fexploracion_t<T>
{
    public:
        
        flineal_t(T x, int nit, int n);
        ~flineal_t();
        int exploracion();
};


template<class T>
flineal_t<T>::flineal_t(T x, int nit, int n):
fexploracion_t<T>(x, nit, n){}

template<class T>
flineal_t<T>::~flineal_t(){}

template<class T>
int flineal_t<T>::exploracion()
{
    return (fexploracion_t<T>::get_try());
}