#pragma once

#include <iostream>
#include <cstdlib>

template<class T>
class fdispersion_t
{
    private:
    
        T clave;
        int nceldas;
        
    public:
    
        fdispersion_t(T x, int n);
        ~fdispersion_t();
        virtual int dispersion();
        
        int get_nceldas()const;
        int& get_nceldas();
        T get_clave() const;
        T& get_clave();
};


template<class T>
fdispersion_t<T>::fdispersion_t(T x, int n):
clave(x),
nceldas(n){}

template<class T>
fdispersion_t<T>::~fdispersion_t(){}

template<class T>
int fdispersion_t<T>::dispersion(){}

template<class T>
int fdispersion_t<T>::get_nceldas() const
{
    return nceldas;
}

template<class T>
int& fdispersion_t<T>::get_nceldas()
{
    return nceldas;
}

template<class T>
T fdispersion_t<T>::get_clave() const
{
    return clave;
}

template<class T>
T& fdispersion_t<T>::get_clave()
{
    return clave;
}



/////////////modulo//////////////////
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



/////////////////////aleatoria///////////////////
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