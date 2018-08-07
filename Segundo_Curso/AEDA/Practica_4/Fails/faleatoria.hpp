#include "fdispersion.hpp"

template<class T> 
class faleatoria_t
{
    public:
        faleatoria_t(T x, int n);
        ~faleatoria_t();
        int dispersion();
};

template<class T>
faleatoria_t<T>::faleatoria_t(T x, int n):
fdispersion_t<T>(x, n){}

template<class T>
faleatoria_t<T>::~faleatoria_t(){}

template<class T>
int faleatoria_t<T>::dispersion()
{
    srand(fdispersion_t<T>::get_clave());
    return (rand() % fdispersion_t<T>::get_nceldas());
}