#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class funcDispersion
{
    private:
    
        T clave;
        int nCeldas;
    
    public:
    
        funcDispersion<T>(T x, int n):
        clave(x),nCeldas(n){};
        
        ~funcDispersion<T>(){};
        
        virtual int dispersion() = 0;
        
        int get_nCeldas() const
        {
            return nCeldas;
        }
        
        int& get_nCeldas()
        {
            return nCeldas;
        }
        
        T get_clave() const
        {
            return clave;
        }
        
        T& get_clave()
        {
            return clave;
        }
};

template <class T>
class funcModulo: public funcDispersion<T>
{
    public:

        funcModulo(T x ,int n):
        funcDispersion<T>(x, n){};

        ~funcModulo(){};

        int dispersion ()
        {
            int x = funcDispersion<T>::get_clave() % funcDispersion<T>::get_nCeldas();
            return x;
        }
};

template <class T>
class funcAleatoria: public funcDispersion<T>
{
    public:

        funcAleatoria(T x, int n):
        funcDispersion<T>(x, n){};

        ~funcAleatoria(){};

        int dispersion ()
        {
            srand(funcDispersion<T>::get_clave());
            return (rand() % funcDispersion<T>::get_nCeldas());
        }
};