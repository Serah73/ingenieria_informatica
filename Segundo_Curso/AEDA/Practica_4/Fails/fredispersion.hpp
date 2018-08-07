#include "fexploracion.hpp"

template<class T>
class fredispersion_t: public fexploracion_t<T> 
{
    public:
        fredispersion_t(T x, int nit, int n);
        ~fredispersion_t();
        int exploracion();
};

template<class T>
fredispersion_t<T>::fredispersion_t(T x, int nit, int n):
fexploracion_t<T>(x, nit, n){}

template<class T>
fredispersion_t<T>::~fredispersion_t(){}

template<class T>
int fredispersion_t<T>::exploracion()
{
    int f = 0;
    
    switch(fexploracion_t<T>::get_try() % 2){
        case 0:
            fdispersion_t<T> * fd = new fmodulo_t<T>(fexploracion_t<T>::get_clave(), fexploracion_t<T>::get_nCeldas());
            f = fd->dispersion();
            break;

        case 1:
            fdispersion_t<T> * fd = new faleatoria_t<T>(fexploracion_t<T>::get_clave(), fexploracion_t<T>::get_nCeldas());
            f = fd->dispersion();
            break;

        default:
            cout << "Problema en el switch fredispersion_t" << endl;
    }
    return f;
}