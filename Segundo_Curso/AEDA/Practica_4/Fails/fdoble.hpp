#include "fexploracion.hpp"

template<class T>
class fdoble_t: public fexploracion_t<T>
{
    public:
        fdoble_t(T x, int nit, int n);
        ~fdoble_t();
        int exploracion();
};


template<class T>
fdoble_t<T>::fdoble_t(T x, int nit, int n):
fexploracion_t<T>(x, nit, n){}

template<class T>
fdoble_t<T>::~fdoble_t(){}

template<class T>
int fdoble_t<T>::exploracion()
{
    srand(fexploracion_t<T>::get_clave());
    return (fexploracion_t<T>::get_try() * (rand()) % fexploracion_t<T>::get_nceldas());
}