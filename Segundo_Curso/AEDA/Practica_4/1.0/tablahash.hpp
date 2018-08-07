#pragma once

#include <iostream>
#include <cstdlib>

#include "celda.hpp"
#include "fdispersion.hpp"
#include "fexploracion.hpp"

using namespace std;

template<class T>
class tablaHash
{
    private:
    
        unsigned int nCeldas;
        unsigned int nBloques;
        unsigned int disp_type;
        unsigned int expl_type;
        
        celda_t<T>* vCeldas;
        
        fdispersion_t<T> * fd;
        fexploracion_t<T> * fe;
        
    public:
    
        tablaHash(int numceldas, int numbloques, int t_d, int t_e);
        ~tablaHash();
        
        bool insertar(T x);
        bool buscar(T x);
        
        int get_comparaciones(int i);
        int get_inserciones(int i);
        
        void mostrar();
        void limpiarPrueba();
};


template<class T>
tablaHash<T>::tablaHash(int numceldas, int numbloques, int t_d, int t_e):
nCeldas(numceldas),
nBloques(numbloques),
disp_type(t_d),
expl_type(t_e)
{
    vCeldas = new celda_t<T> [nCeldas];

    for(int i = 0; i < nCeldas; i++){
        vCeldas[i].resize(nBloques);
        vCeldas[i].limpiar();
    }
}

template<class T>
tablaHash<T>::~tablaHash(){}

template<class T>
bool tablaHash<T>::insertar(T x)
{
    int d = 0;
    
    switch(disp_type)
    {
        case 0:
            fd = new fmodulo_t<T>(x, nCeldas);
            d = fd->dispersion();
            break;
        
        case 1:
            fd = new faleatoria_t<T>(x, nCeldas);
            d = fd->dispersion();
            break;

        default:
            cout << "Error en la eleccion de dispersion. Reconstruir tabla" << endl;
    }
    
    if(vCeldas[d].insertar(x))
        return true;

    else
    {
        int f = 0;
        int i = 0;
        bool insertado = false;
    
        while(insertado == false && i < nCeldas)
        {
            switch(expl_type)
            {
                case 0:
                    fe = new flineal_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                case 1:
                    fe = new fcuadratica_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                case 2:
                    fe = new fdoble_t<T>(x, i,  nCeldas);
                    f = fe->exploracion();
                    break;

                case 3:
                    fe = new fredispersion_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                default:
                    cout << "Error en la eleccion de exploracion. Reconstruir tabla" << endl;
                
            }
            if(vCeldas[(d + f) % nCeldas].insertar(x)){
                insertado = true;
                return true;
            }
            i++;
        }
    }
    return false;
}


template<class T>
bool tablaHash<T>::buscar(T x)
{
    int d = 0;
    
    switch(disp_type)
    {
        case 0:
            fd = new fmodulo_t<T>(x, nCeldas);
            d = fd->dispersion();
            break;

        case 1:
            fd = new faleatoria_t<T>(x, nCeldas);
            d = fd->dispersion();
            break;

        default:
            cout << "Error en la eleccion de dispersion. Reconstruir tabla" << endl;
    }
    if(vCeldas[d].existe(x))
        return true;

    if(!vCeldas[d].full())
        return false;

    else{
        int f = 0;
        int i = 0;
        bool encontrado = false;

        while(encontrado == false && i < nCeldas)
        {
            switch(expl_type)
            {
                case 0: 
                    fe = new flineal_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                case 1:
                    fe = new fcuadratica_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                case 2:
                    fe = new fdoble_t<T>(x, i,  nCeldas);
                    f = fe->exploracion();
                    break;

                case 3:
                    fe = new fredispersion_t<T>(x, i, nCeldas);
                    f = fe->exploracion();
                    break;

                default:
                    cout << "Error en la eleccion de exploracion. Reconstruir tabla" << endl;
                
            }
            if(vCeldas[(d + f) % nCeldas].existe(x)){
                encontrado = true;
                return true;
            }
            i++;
        }
        return false;
    }
}

template<class T>
int tablaHash<T>::get_comparaciones(int i)
{
    int sum = 0;
    
    sum = vCeldas[i].get_comparaciones();
    vCeldas[i].limpiarComparaciones();
    
    return sum;
}

template<class T>
int tablaHash<T>::get_inserciones(int i)
{
    int sum = 0;
    
    sum = vCeldas[i].get_inserciones();
    vCeldas[i].limpiarInserciones();
    
    return sum;
}

template<class T>
void tablaHash<T>::mostrar()
{
    for (int i = 0; i < nCeldas; i++)
        vCeldas[i].mostrar();

    cout << endl;
}

template<class T>
void tablaHash<T>::limpiarPrueba()
{
    for(int i = 0; i < nCeldas; i++)
    {
        vCeldas[i].limpiarComparaciones();
        vCeldas[i].limpiarInserciones();
    }
}