/*
 *  Lsimplex.cpp - Simplex Primal Light.
 *
 *
 *               Autor : 
 *               Fecha : 
 */

#include "prob.h"

using namespace std;


//Incompleto!!
int main(int argc, char *argv[])
{
//	ASIGNAR EL NOMBRE DEL FICHERO DE DATOS A LA VARIRABLE nombrefichero
	
	PROBLEM p(argv[1]);
	p.Volcar_problema();
	p.Simplex_Light();
	return(0);
}
