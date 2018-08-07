#ifndef ESTADISTICA_HPP_
#define ESTADISTICA_HPP_

#pragma once

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<vector>

#include"AVLsimple.hpp"
#include"DNI.hpp"
#include"Datos.hpp"
#include"Utilidad.hpp"

template <class T>
class Estadistica_t
{
	private:

		AVL<T> arbol_;
		Calculadora calculadora;

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

	int contador = 0;
    
    DNI aux;
	vector<T> banco(2*elementos, aux);
    
    banco = do_banco(banco, elementos);
    
    arbol_pruebas(banco, arbol_, elementos);
/*
	srand (time(NULL));

	for(int i = 0; i < 2*elementos; i++)
	{
	    DNI aux( rand() % 50000 + 30001, 'F');
	    banco[i] = aux;
	}

	for (int i = 0; i < elementos; i++)
	    arbol_.insertar(banco[i]);
*/

	arbol_.impresionNiveles();
	std::cout << std::endl;

    impresion(1, false, calculadora, elementos, pruebas);

	calculadora.Reset();
    
	for (int i = 0; i < elementos; i++)
	{
	    arbol_.buscar(banco[i], contador);

        calculadora.do_min(contador);
        calculadora.do_max(contador);
        calculadora.cont_media(contador);
        
        contador = 0;
	}
/*
	std::cout << left << std::setw(10) << "Busqueda";
	std::cout << right << std::setw(8) << elementos << std::setw(8) << pruebas  << std::setw(8)
	<< calculadora.get_min() << std::setw(8) << calculadora.get_media() << std::setw(8) << calculadora.get_max() << std::endl;
*/
    impresion(2, true, calculadora, elementos, pruebas);
    
	calculadora.Reset();

	for (int i = elementos; i < 2*elementos; i++)
	{
	    arbol_.buscar(banco[i], contador);

        calculadora.do_min(contador);
        calculadora.do_max(contador);
        calculadora.cont_media(contador);
        
        contador = 0;
	}

    impresion(2, false, calculadora, elementos, pruebas);
/*
	std::cout << left << std::setw(10) << "Insercion";
	std::cout << right << std::setw(8) << elementos << std::setw(8) << pruebas  << std::setw(8)
	<< calculadora.get_min() << std::setw(8) << calculadora.get_media() << std::setw(8) << calculadora.get_max() << std::endl;
*/
}




#endif /* ESTADISTICA_HPP_ */
