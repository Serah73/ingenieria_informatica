#pragma once

#include "Demostracion.hpp"
#include "Datos.hpp"
#include "DNI.hpp"
#include "AVLsimple.hpp"

#include <iostream>
#include <vector>

typedef DNI T;

vector<T> do_banco(std::vector<T> banco, int elementos)
{
    srand (time(NULL));
    
    for(int i = 0; i < 2*elementos; i++)
    {
        DNI aux( rand() % 50000 + 30001, 'F');
        banco[i] = aux;
    }
    return banco;
}

void arbol_pruebas(std::vector<T> banco, AVL<T>& arbol, int N)
{
    for(int i = 0; i < N; i++)
        arbol.Insertar(banco[i]);
}

void impresion(int tipo, bool busqueda, Calculadora C, int elementos, int pruebas)
{
    switch(tipo)
    {
        case 1: 
            std::cout << std::setw(10) << " "       << std::setw(8) << "elementos" <<
                         std::setw(8)  << "pruebas" << std::setw(8) << "Minimo"    << 
                         std::setw(8)  << "Media"   << std::setw(8) << "Maximo"    << std::endl;
    
        break;
        
        case 2:
            if(busqueda)
            {
                std::cout << left    << std::setw(10) << "Busqueda";
                std::cout << right   << std::setw(8)  << elementos   << std::setw(8) << 
                             pruebas << std::setw(8)  << C.get_min() << std::setw(8) << 
                   C.Request_media() << std::setw(8)  << C.get_max() << std::endl;
            }
            else{
                std::cout << left    << std::setw(10) << "Insercion";
                std::cout << right   << std::setw(8)  << elementos   << std::setw(8) << 
                             pruebas << std::setw(8)  << C.get_min() << std::setw(8) << 
                   C.Request_media() << std::setw(8)  << C.get_max() << std::endl;    
            }
            
    
    }
}
