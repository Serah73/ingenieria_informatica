#ifndef DEMOSTRACION_HPP_
#define DEMOSTRACION_HPP_

#pragma once

#include<iostream>
#include"AVLsimple.hpp"

template <class T>
class Demostracion
{
	private:

		AVL<T> arbol_;

	public:

		Demostracion();
		~Demostracion();

		void demostrar(AVL<T>& pino);
};

template <class T>
Demostracion<T>::Demostracion(){}

template <class T>
Demostracion<T>::~Demostracion(){}

template <class T>
void Demostracion<T>::demostrar(AVL<T>& pino)
{
	int opcion;
	T elemento;

    do{
    	std::cout << "Elija una opcion:" << std::endl;
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Eliminar" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "Introduzca la opcion: ";
        std::cin >> opcion;

        switch(opcion){
        	case 0:{
        		std::cout << "Saliendo..." << std::endl;
            }
        	break;

            case 1:{
            	std::cout << "Opcion 1: Introducir el elemento deseado para añadir: ";
            	std::cin >> elemento;

            	arbol_.Insertar(elemento); 
            	arbol_.impresionNiveles();
            }
            break;

            case 2:{
            	std::cout << "Opcion 2: Introducir el elemento deseado para desechar: ";
            	std::cin >> elemento;

            	arbol_.eliminar(elemento);
            	arbol_.impresionNiveles();
            }
            break;

            default:{
            	std::cout << "Opcion fuera de rango, pruebe de nuevo" << std::endl;
            	opcion = 3;
            }
        }
    }while(opcion);
}



#endif /* DEMOSTRACION_HPP_ */
