#pragma once

#include <iostream>
#include <cstdlib>
#include "funcDispersion.hpp"

using namespace std;

template <class T>
class funcExploracion
{
    private:

        T clave;
        int intento;
        int nCeldas;

    public:

        funcExploracion<T>(T x, int nit, int n): 
        clave(x),
        intento(nit),
        nCeldas(n){}
        
        ~funcExploracion(){}
        
        virtual int exploracion() = 0;
        
        int get_nCeldas() const
        {
            return nCeldas;
        }
        
        int& get_nCeldas()
        {
            return nCeldas;
        }
        
        int get_try() const
        {
            return intento;
        }
        
        int& get_try()
        {
            return intento;
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
class funcLineal: public funcExploracion<T>
{
    public:

        funcLineal(T x, int nit, int n):
        funcExploracion<T>( x, nit, n){}
        
        ~funcLineal(){}

        int exploracion()
        {
            return funcExploracion<T>::get_try();
        }
};

template <class T>
class funcCuadratica: public funcExploracion<T>
{
    public:

        funcCuadratica(T x, int nit, int n):
        funcExploracion<T>( x, nit, n){}

        ~funcCuadratica(){}
        
        int exploracion()
        {
            return (funcExploracion<T>::get_try()*funcExploracion<T>::get_try());
        }
};

template <class T>
class funcDoble: public funcExploracion<T>
{
    public:

        funcDoble(T x, int nit, int n):
        funcExploracion<T>( x, nit, n){}

        ~funcDoble(){}

        int exploracion()
        {
            srand(funcExploracion<T>::get_clave());
            return ( funcExploracion<T>::get_try() * ( rand() ) % funcExploracion<T>::get_nCeldas() );
        }
};

template <class T>
class funcReDispersion: public funcExploracion<T>
{
    public:

        funcReDispersion(T x, int nit, int n):
        funcExploracion<T>( x, nit, n){}

        ~funcReDispersion(){}

        int exploracion()
        {
            int f = 0;
        
            switch(funcExploracion<T>::get_try() % 2)
            {
                case 0: {
                    funcDispersion<T> * fd = new funcModulo<T>(funcExploracion<T>::get_clave(), funcExploracion<T>::get_nCeldas());
                    f = fd->dispersion();
                    break;
                }
                case 1: {
                    funcDispersion<T> * fd = new funcAleatoria<T>(funcExploracion<T>::get_clave(), funcExploracion<T>::get_nCeldas());
                    f = fd->dispersion();
                    break;
                }
                default:
                    cout << "Problema en el switch funcReDispersion" << endl;
            }
            return f;
        }
};




