/*
 *  prob.h - definicion de clase PROBLEM y m�todos para la implementaci�n del  simplex light
 *
 *  Autor : Antonio Sede�o Noda
 *  Fecha : 1-DIC-2014
 */

#ifndef _PROB_H
#define _PROB_H

#include <vector>
#include <cstdlib>
#include <iostream>
#pragma once

#include <cstring>
#include <fstream>
#include <iomanip>				//biblioteca para el setw()


const double CEROPOS = 1.0e-15; /*Cero Positivo*/
const double CERONEG = -1.0e-15;/*Cero Negativo*/
const double INFR = 1.0e+10;/*Infinito Real*/
const unsigned UERROR = 65000;/*error para variables unsigned*/

using namespace std;

typedef vector<double> fila;

class PROBLEM
 {
	char         clase[4];        /* Clase del problema : max o min */
	unsigned            m;        /* n� de restricciones */
	unsigned            n;        /* n� de variables */
	unsigned           nh;        /* n� de variables de holgura */
	vector<double>      c;        /* vector de costes unitarios */
	vector<fila>        A;        /* matriz de coeficientes tecnol�gicos */
	vector<double>      b;        /* vector de terminos independientes */
	// atributos para el simplex	
	vector <unsigned> ivb;        /* vector de variables b�sicas */
	double             Vo;        /* valor de la funcion objetivo */
 public:
      PROBLEM(char nombrefichero[]);
	~PROBLEM();
	void Volcar_problema();
      //m�todos propios del simplex
	unsigned entrante();
	unsigned saliente(unsigned s);
	void actualizar_valores(unsigned s, unsigned r);
	void mostrar_solucion();
	void volcar_tabla();
	void Simplex_Light();
};


 	
void Formato_fichero(void);

#endif
