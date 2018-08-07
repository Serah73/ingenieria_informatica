
#pragma once

#include <stdio.h>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas

using namespace std;


//========================================================================================
// Definición de tipos
//========================================================================================

/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef double 		matrix_item_t;	
/** Tipo de dato para índices de la matriz.                 */
typedef unsigned short int 	matrix_inx_t;	
/** Tipo de dato para índices del vector  .                 */
typedef unsigned short int 	vector_inx_t;	


class matrix_t {    //	Clase que representa una matriz de mxn elementos

//========================================================================================
// Atributos privados.
//========================================================================================

private:

	matrix_item_t*	M_;	/**< Puntero que apunta al comienzo del vector conteniendo los elementos de la matriz. */

	matrix_inx_t  	m_;	/**< Número de filas.   */
	matrix_inx_t	n_;	/**< Número de columnas.*/

//========================================================================================
// Métodos públicos.
//========================================================================================

public:

	matrix_t(matrix_inx_t m,matrix_inx_t n); //	Constructor. Reserva memoria para una matriz de mxn elementos.


	matrix_t(void); //	Constructor por defecto. Construye una matriz de dimensión 0x0.	


	~matrix_t(void); //	Destructor. Libera la memoria de la matriz.


	void  mostrarMatriz(void); //	Muestra la matriz formateada.


	matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j); //	Devuelve el elemento de la posición (i,j) de la matriz.


	void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it); //	Asigna un valor al elemento (i,j) de la matriz.
	

	matrix_inx_t get_m(void); // 	Devuelve el número de filas.


	matrix_inx_t get_n(void); //	Devuelve el número de columnas.


// 	Lee una matriz desde el flujo de entrada.El formato es el siguiente:
//			m_ n_
//			elemento(1,1) elemento (1,2) ... elemento(1,n_)
//			elemento(2,1) elemento (2,2) ... elemento(2,n_)
//			...
//			elemento(m_,1) ...		 elemento(m_,n_)

	istream& read(istream& is);

// 	Escribe una matriz en el flujo de salida.El formato es el siguiente:
//			m_ n_
//			elemento(1,1) elemento (1,2) ... elemento(1,n_)
//			elemento(2,1) elemento (2,2) ... elemento(2,n_)
//			...
//			elemento(m_,1) ...		 elemento(m_,n_)

	ostream& write(ostream& os);

	void filtra(matrix_t& M, matrix_item_t it, double precision);

	int contar_entre(matrix_item_t min, matrix_item_t max, double precision);

//========================================================================================
// Métodos privados.
//========================================================================================

private:



// * @param  	i fila del elemento.
// * @param  	j columna del elemento.
// * @see 		matrix_inx_t.
// * @return 	el índice k.
// * @see 		vector_inx_t.
	vector_inx_t pos(matrix_inx_t i,matrix_inx_t j); //	Devuelve la posición k dentro del vector M_ del elemento (i,j) de la matriz.


//       * @param 	m número de filas del tipo matrix_inx_t.       
//       * @param 	n número de columnas del tipo matrix_inx_t.       
//       * @see 		matrix_inx_t.

	void crearMatriz(void); //	Reserva memoria para una matriz de mxn elementos.



	void destruirMatriz(void); //	\details 	Libera la memoria de la matriz.

//       * @param  	m nuevo número de filas.
//       * @param  	n nuevo número de columnas.
//       * @see 		matrix_inx_t.   

	void redimensiona(matrix_inx_t m,matrix_inx_t n); //	Redimensiona la matriz. Destruye la anterior, borrando su contenido, y construye una nueva matriz con la dimensión especificada.

	bool igual(matrix_item_t a, matrix_item_t b, double precision);
	bool mayor(matrix_item_t a, matrix_item_t b, double precision); 
	bool menor(matrix_item_t a, matrix_item_t b, double precision);
	bool zero(matrix_item_t a, double precision);
};