#ifndef DEMOSTRACION_HPP_
#define DEMOSTRACION_HPP_

#pragma once

#include<iostream>


#include"Datos.hpp"
#include"Metodos.hpp"
//#include"QuickSort.hpp"
//#include"HeapSort.hpp"
//#include"ShellSort.hpp"
//#include"Burbuja.hpp"
//#include"Insercion.hpp"

template <class T>
class Demostracion_t
{
	private:

		Datos_t calculadora_;
		Metodos_t<T> ordena_;

	public:

		Demostracion_t();
		~Demostracion_t();

		void demostrar(vector<T>& v);
		void write(vector<T>& v);
};

template <class T>
Demostracion_t<T>::Demostracion_t(){}

template <class T>
Demostracion_t<T>::~Demostracion_t(){}

template <class T>
void Demostracion_t<T>::demostrar(vector<T>& v)
{
	vector<T> aux;
	int acumulador, opcion;

    do{
    	std::cout << "Elija metodo de ordenacion:" << std::endl;
        std::cout << "1. Insercion" << std::endl;
        std::cout << "2. BubbleSort" << std::endl;
        std::cout << "3. QuickSort" << std::endl;
        std::cout << "4. HeapSort" << std::endl;
        std::cout << "5. ShellSort" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Introduzca la opcion: ";
        std::cin >> opcion;

        switch(opcion){
        	case 0:{
        		std::cout << "Saliendo..." << std::endl;
            }
        	break;

            case 1:{
            	aux = v;
            	std::cout << std::endl << "Secuencia inicial:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	acumulador = ordena_.Insert(aux, true);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	std::cout << "Secuencia final:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            }
            break;

            case 2:{
            	aux = v;
            	std::cout << std::endl << "Secuencia inicial:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	acumulador = ordena_.Burbuja(aux, true);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	std::cout << "Secuencia final:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            }
            break;
            case 3:{
            	aux = v;
            	std::cout << std::endl << "Secuencia inicial:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	acumulador = ordena_.QuickSort(aux, 0, aux.size()-1, true);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	std::cout << "Secuencia final:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            }
            break;

            case 4:{
            	aux = v;
            	std::cout << std::endl << "Secuencia inicial:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	acumulador = ordena_.HeapSort(aux, aux.size()-1, true);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	std::cout << "Secuencia final:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            }
            break;

            case 5:{
            	aux = v;
            	float alfa;
            	std::cout << "Introduzca constante de reduccion alfa: ";
            	std::cin >> alfa;

            	while(alfa < 0 || alfa > 1)
            	{
            		std::cout << "Constante de reduccion alfa fuera de rango (0-1)" << std::endl;
            		std::cout << "Introduzca la constante de reduccion alfa: ";
            		std::cin >> alfa;
            	}

            	if(alfa == 0 || alfa == 1)
            		alfa = 0.5;

            	std::cout << std::endl << "Secuencia inicial:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	acumulador = ordena_.ShellSort(aux, alfa, true);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            	std::cout << "Secuencia final:" << std::endl;
            	write(aux);
            	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
            }
            break;

            default:{
            	std::cout << "Opcion fuera de rango, pruebe de nuevo" << std::endl;
            	opcion = 6;
            }
        }
    }while(opcion);
    v = aux;
}

template <class T>
void Demostracion_t<T>::write(vector<T>& v)
{
	for(int i = 0; i < v.size(); i++)
		std::cout << "   " << v[i];
	std::cout << std::endl;
}






#endif /* DEMOSTRACION_HPP_ */
