#include "fexploracion.hpp"

template<class T>
class fcuadratica_t: public fexploracion_t<T>
{
    public:
        
        fcuadratica_t(T x, int nit, int n);
        ~fcuadratica_t();
        int exploracion();
};

template<class T>
fcuadratica_t<T>::fcuadratica_t(T x, int nit, int n):
fexploracion<T>( x, nit, n){}

template<class T>
fcuadratica_t<T>::~fcuadratica_t(){}

template<class T>
int fcuadratica_t<T>::exploracion(){
    return (fexploracion_t<T>::get_try()*fexploracion_t<T>::get_try());
}