#ifndef ESTADISTICA_HPP_
#define ESTADISTICA_HPP_

#pragma once

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<ctime>

#include"abb.hpp"
#include"DNI.hpp"
#include"Datos.hpp"


template <class T>
class Estadistica_t
{
	private:

		abb<T> arbol_;
		Datos_t calculadora;

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

	int contador;
	T aux;

	vector<T> banco(2*elementos, aux);

	srand (time(NULL));

	for(int i = 0; i < 2*elementos; i++)
	{
	    DNI aux( rand() % 50000 + 30001, 'F');
	    banco[i] = aux;
	}

	for (int i = 0; i < elementos; i++)
	    arbol_.insertar(banco[i]);

	arbol_.impresionNiveles();
	std::cout << std::endl;

	calculadora.reset();

	std::cout << std::setw(10) << " " << std::setw(8) << "elementos" << std::setw(8) << "pruebas"  << std::setw(8) << "Minimo" << std::setw(8) << "Media" << std::setw(8) << "Maximo" << std::endl;

	for (int i = 0; i < elementos; i++)
	{
	    arbol_.buscar(banco[i], contador);

	    calculadora.minimo(contador);
	    calculadora.maximo(contador);

	    calculadora.SumadorMedia(contador);

	    contador = 0;
	}

	std::cout << left << std::setw(10) << "Busqueda";
	std::cout << right << std::setw(8) << elementos << std::setw(8) << pruebas  << std::setw(8)
	<< calculadora.get_min() << std::setw(8) << calculadora.get_media() << std::setw(8) << calculadora.get_max() << std::endl;

	calculadora.reset();

	for (int i = elementos; i < 2*elementos; i++)
	{
	    arbol_.buscar(banco[i], contador);

	    calculadora.minimo(contador);
	    calculadora.maximo(contador);

	    calculadora.SumadorMedia(contador);

	    contador = 0;
	}

	std::cout << left << std::setw(10) << "Insercion";
	std::cout << right << std::setw(8) << elementos << std::setw(8) << pruebas  << std::setw(8)
	<< calculadora.get_min() << std::setw(8) << calculadora.get_media() << std::setw(8) << calculadora.get_max() << std::endl;
}




#endif /* ESTADISTICA_HPP_ */
