#ifndef ESTADISTICA_HPP_
#define ESTADISTICA_HPP_

#pragma once

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<ctime>

#include"Datos.hpp"
#include"Metodos.hpp"
//#include"QuickSort.hpp"
//#include"HeapSort.hpp"
//#include"ShellSort.hpp"
//#include"Burbuja.hpp"
//#include"Insercion.hpp"

template <class T>
class Estadistica_t
{
	private:

		Datos_t calculadora_;
		Metodos_t<T> ordena_;

	public:

		Estadistica_t();
		~Estadistica_t();

		void estadisticas(int elementos, int pruebas);
};

template <class T>
Estadistica_t<T>::Estadistica_t(){}

template <class T>
Estadistica_t<T>::~Estadistica_t(){}

template <class T>
void Estadistica_t<T>::estadisticas(int elementos, int pruebas)
{
	int acumulador = 0;
	float alfa = 0;

	std::cout << "Introduzca constante de reduccion alfa: ";
	std::cin >> alfa;

	while(alfa < 0 || alfa > 1)
	{
		std::cout << "Constante de reduccion alfa fuera de rango (0-1)" << std::endl;
		std::cout << "Introduzca la constante de reduccion alfa: ";
		std::cin >> alfa;
	}

	if(alfa == 0 || alfa == 1)	alfa = 0.5;

	std::cout << std::setw(12) << "Estadistico:" << std::setw(10) << "Minimo" << std::setw(10) << "Media" << std::setw(10) << "Maximo" << std::endl;

	srand(time(NULL));

	for(int i = 0; i < pruebas; i++)
	{
		vector<T> v(elementos);

		for(int j = 0; j < v.size(); j++)
		{
			int x = rand() % 5000001 + 30000000;
			DNI aux(x, 65 + (x % 23) );
			v[j] = aux;
	    }
	    ordena_.resetC();
		acumulador = ordena_.Insert(v, 0);

		calculadora_.minimo(acumulador);
		calculadora_.maximo(acumulador);
		calculadora_.mediaSumador(acumulador);
	}
	calculadora_.mediaMath(pruebas);

	std::cout << std::setw(12) << "Insercion:" << std::setw(10) << calculadora_.get_min() << std::setw(10) << calculadora_.get_media() << std::setw(10) << calculadora_.get_max() << std::endl;

	calculadora_.reset();

	for(int i = 0; i < pruebas; i++)
	{
		vector<T> v(elementos);

		for(int j = 0; j < v.size(); j++)
		{
			int x = rand() % 5000001 + 30000000;
			DNI aux(x, 65 + (x % 23) );
			v[j] = aux;
		}
		ordena_.resetC();
		acumulador = ordena_.Burbuja(v, 0);
		
		calculadora_.minimo(acumulador);
		calculadora_.maximo(acumulador);
		calculadora_.mediaSumador(acumulador);
	}
	calculadora_.mediaMath(pruebas);

	std::cout << std::setw(12) << "Burbuja:" << std::setw(10) << calculadora_.get_min() << std::setw(10) << calculadora_.get_media() << std::setw(10) << calculadora_.get_max() << std::endl;

	calculadora_.reset();

	for(int i = 0; i < pruebas; i++)
	{
		vector<T> v(elementos);

		for(int j = 0; j < v.size(); j++)
		{
			int x = rand() % 5000001 + 30000000;
			DNI aux(x, 65 + (x % 23) );
			v[j] = aux;
		}
		ordena_.resetC();
		acumulador = ordena_.QuickSort(v, 0, v.size() - 1, 0);

		calculadora_.minimo(acumulador);
		calculadora_.maximo(acumulador);
		calculadora_.mediaSumador(acumulador);
	}
	calculadora_.mediaMath(pruebas);

	std::cout << std::setw(12) << "QuickSort:" << std::setw(10) << calculadora_.get_min() << std::setw(10) << calculadora_.get_media() << std::setw(10) << calculadora_.get_max() << std::endl;

	calculadora_.reset();

	for(int i = 0; i < pruebas; i++){
		vector<T> v(elementos);
		for(int j = 0; j < v.size(); j++){
			int x = rand() % 5000001 + 30000000;
			DNI aux(x, 65 + (x % 23) );
			v[j] = aux;
		}
		acumulador = ordena_.HeapSort(v, v.size() - 1, 0);

		calculadora_.minimo(acumulador);
		calculadora_.maximo(acumulador);
		calculadora_.mediaSumador(acumulador);
	}
	ordena_.resetC();
	calculadora_.mediaMath(pruebas);

	std::cout << std::setw(12) << "HeapSort:" << std::setw(10) << calculadora_.get_min() << std::setw(10) << calculadora_.get_media() << std::setw(10) << calculadora_.get_max() << std::endl;

	calculadora_.reset();

	for(int i = 0; i < pruebas; i++){
		vector<T> v(elementos);
		for(int j = 0; j < v.size(); j++){
			int x = rand() % 5000001 + 30000000;
			DNI aux(x, 65 + (x % 23) );
			v[j] = aux;
		}
		ordena_.resetC();
		acumulador = ordena_.ShellSort(v, alfa, 0);

		calculadora_.minimo(acumulador);
		calculadora_.maximo(acumulador);
		calculadora_.mediaSumador(acumulador);
	}
	calculadora_.mediaMath(pruebas);

	std::cout << std::setw(12) << "ShellSort:" << std::setw(10) << calculadora_.get_min() << std::setw(10) << calculadora_.get_media() << std::setw(10) << calculadora_.get_max() << std::endl;
}







#endif /* ESTADISTICA_HPP_ */
