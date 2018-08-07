#include <iostream>
#include <cstdlib>

#include "celda.hpp"
#include "funcDispersion.hpp"
#include "funcExploracion.hpp"

#pragma once

using namespace std;

template <class T> class tablaHash
{
    private:

        unsigned int nCeldas;
        unsigned int nBloques;
        unsigned int disp_type;
        unsigned int expl_type;
        
        celda<T>* vCeldas;
        
        funcDispersion<T> * fd;
        funcExploracion<T> * fe;

    public:

        tablaHash(int numceldas, int numbloques, int t_d, int t_e):
        nCeldas(numceldas), 
        nBloques(numbloques), 
        disp_type(t_d), 
        expl_type(t_e)
        {
            vCeldas = new celda<T> [nCeldas];
            for(int i = 0; i < nCeldas; i++)
            {
                vCeldas[i].resize(nBloques);
                vCeldas[i].limpiar();
            }
        }
        ~tablaHash(){}
        
        bool insertar(T x)
        {
            int d = 0;
            switch(disp_type)
            {
                case 0: 
                    fd = new funcModulo<T>(x, nCeldas);
                    d = fd->dispersion();
                    break;
                
                case 1: 
                    fd = new funcAleatoria<T>(x, nCeldas);
                    d = fd->dispersion();
                    break;
                
                default:
                    cout << "Error en la eleccion de dispersion. Reconstruir tabla" << endl;
            }
            
            if(vCeldas[d].insertar(x))
                return true;
                
            else{
                int f = 0;
                int i = 0;
                bool insertado = false;
                while(insertado == false && i < nCeldas)
                {
                    switch(expl_type)
                    {
                        case 0: 
                            fe = new funcLineal<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 1: 
                            fe = new funcCuadratica<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 2: 
                            fe = new funcDoble<T>(x, i,  nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 3: 
                            fe = new funcReDispersion<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        default:
                            cout << "Error en la eleccion de exploracion. Reconstruir tabla" << endl;
                        
                    }
                    if(vCeldas[(d + f) % nCeldas].insertar(x))
                    {
                        insertado = true;
                        return true;
                    }
                    i++;
                }
            }
            return false;
        }
        
        bool buscar(T x)
        {
            int d = 0;
            switch(disp_type)
            {
                case 0: 
                    fd = new funcModulo<T>(x, nCeldas);
                    d = fd->dispersion();
                    break;
                
                case 1: 
                    fd = new funcAleatoria<T>(x, nCeldas);
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
                            fe = new funcLineal<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 1: 
                            fe = new funcCuadratica<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 2: 
                            fe = new funcDoble<T>(x, i,  nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        case 3: 
                            fe = new funcReDispersion<T>(x, i, nCeldas);
                            f = fe->exploracion();
                            break;
                        
                        default:
                            cout << "Error en la eleccion de exploracion. Reconstruir tabla" << endl;
                    }
                    if(vCeldas[(d + f) % nCeldas].existe(x))
                    {
                        encontrado = true;
                        return true;
                    }
                    i++;
                }
                return false;
            }
        }
        int get_comparaciones(int i)
        {
            int sum = 0;
            sum = vCeldas[i].get_comparaciones();
            vCeldas[i].limpiarComparaciones();
            return sum;
        }
        
        int get_inserciones(int i)
        {
            int sum = 0;
            
            sum = vCeldas[i].get_inserciones();
            vCeldas[i].limpiarInserciones();
            return sum;
        }
        void mostrar()
        {
            for (int i = 0; i < nCeldas; i++)
                vCeldas[i].mostrar();
            cout << endl;
        }
        
        void limpiarPrueba(){
            for(int i = 0; i < nCeldas; i++)
            {
                vCeldas[i].limpiarComparaciones();
                vCeldas[i].limpiarInserciones();
            }
        }
};