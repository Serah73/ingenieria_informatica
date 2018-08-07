#pragma once
 
#include <iostream>
#include <cstdlib>

template<class T>
class fexploracion_t
{
    private:
    
        T clave;
        int intento;
        int nceldas;
    
    public:
        
        fexploracion_t<T>(T x, int nit, int n);
        ~fexploracion_t();
        
        virtual int exploracion();
        
        int get_nceldas() const;
        int& get_nceldas();
        int get_try() const;
        int& get_try();
        T get_clave() const;
        T& get_clave();
};

template<class T>
fexploracion_t<T>::fexploracion_t(T x, int nit, int n):
clave(x),
intento(nit),
nceldas(n){}

template<class T>
fexploracion_t<T>::~fexploracion_t(){}

template<class T>
int fexploracion_t<T>::exploracion(){}

template<class T>
int fexploracion_t<T>::get_nceldas() const
{
    return nceldas;
}

template<class T>
int& fexploracion_t<T>::get_nceldas()
{
    return nceldas;
}

template<class T>
int fexploracion_t<T>::get_try() const
{
    return intento;
}

template<class T>
int& fexploracion_t<T>::get_try()
{
    return intento;
}

template<class T>
T fexploracion_t<T>::get_clave() const
{
    return clave;
}

template<class T>
T& fexploracion_t<T>::get_clave()
{
    return clave;
}



//////////////////lineal///////////////////////////
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



/////////////////fcuadratica////////////
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
fexploracion_t<T>( x, nit, n){}

template<class T>
fcuadratica_t<T>::~fcuadratica_t(){}

template<class T>
int fcuadratica_t<T>::exploracion(){
    return (fexploracion_t<T>::get_try()*fexploracion_t<T>::get_try());
}



//////////////////////doble///////////////
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



////////////redispersion/////////////
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
        case 0: {
            fdispersion_t<T> * fd = new fmodulo_t<T>(fexploracion_t<T>::get_clave(), fexploracion_t<T>::get_nCeldas());
            f = fd->dispersion();
            break;
        }
        case 1: {
            fdispersion_t<T> * fd = new faleatoria_t<T>(fexploracion_t<T>::get_clave(), fexploracion_t<T>::get_nCeldas());
            f = fd->dispersion();
            break;
        }
        default:
            std::cout << "Problema en el switch funcReDispersion" << std::endl;
    }
    return f;
}