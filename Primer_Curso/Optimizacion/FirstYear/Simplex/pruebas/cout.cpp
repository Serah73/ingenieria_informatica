#include<iostream>
#include<iomanip>
using namespace std;


void PROBLEM::actualizar_valores(unsigned s, unsigned r)			//acabar de escribir el pseudo-codigo del guion. 1ºcosa declarar variables que aqui no estan.
{
	
	ivb[r] = s;
	temp = A[r][s];

	ACTUALIZAR FILA A[r]: A[r]/temp;								//dividir ,la fila por temp pero esta mal sintacticamente, sustituir por el correcto bucle.
	b[r] /= temp;													//dividir ,la fila por temp pero esta mal sintacticamente, sustituir por el correcto bucle.

	PARA TODA FILA i CON i != r Y A[i][s] != 0 HACEMOS				//hacer bien el bucle.
	{
		temp = A[i][s];
		A[i] -= A[r] * temp;  // la fila entera de i
		b[i] -= b[r] * temp;
	}
	Vo -= b[r]*c[s]; //Actualizamos Vo
	
	c[i] -= c[s]*A[r][i]; // para todo i != s		
	
	c[s]= 0;
}