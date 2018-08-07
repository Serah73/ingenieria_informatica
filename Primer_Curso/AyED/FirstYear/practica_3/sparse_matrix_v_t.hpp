/*
La configuración sea de filas en este vector habrá una entrada por cada fila que tenga al menos un elemento no nulo. 
Dicha entrada constará de un índice que indica el número de dicha columna, y un valor, que es un vector de pares. 
Los elementos de este vector de pares son índices indicando la columna del elemento no nulo, el valor de dicho elemento no nulo
*/

#pragma once
#include<iostream>
#include<vector_pair_t>
#include <cmath>

class sparse_matrix_v_t{

private:
	int			m_;	//numero de filas matriz original.
	int			n_;	//numero de columnas matriz original.
	vector_pair_vp_t	M_;	//vector de pair de vector de pair.
	int			conf_;	//contendra los valores de COL_CONF(configuracion de columnas) o ROW_CONF(configuracion de filas).
public:
	sparse_matrix_v_t(matrix_t M, double epsilon,  int conf){
        int filas_no_cero=0;
        int no_cero_de_cada_fila[m_];
        m_ = M.get_m(); n_ = M.get_n();     //asignar a m_ y n_ el valor de la matriz original.
		for(int i=0; i<M.get_m(); i++){      //recorrer filas de M.
			no_cero_de_cada_fila[i] = 0;
		    for(int j=0; j<M.get_n(); j++){    //recorrer columnas de M.
		        if(!zero(M.get_set(i,j), epsilon))
	                no_cero_de_cada_fila[i]++;
	        }
	        if(no_cero_de_cada_fila[i] > 0)
		    	filas_no_cero++;
		}
		M_.resize(filas_no_cero);		//le das a M_ el tamaño del nº de filas que tienen algun no cero(filas_no_cero).
		
		for...						//bucle no hecho  ///////////MIRAR/////////////
			M_.get_set_v(i).get_val().resize(no_cero_de_cada_fila[i]); 
/*para cada fila se reserva el espacio para guardar las parejas (indice y valor) de los valores que no son cero, precisamente los que contamos antes
*/
}


	~sparse_matrix_v_t{}

	
    bool zero(double v, double epsilon)
    {
        return(fabs(v)<epsilon)
    }
}


/*
0	0	0   decadafila[0] = 0 filas no suma

0	0	1	decadafila[1] = 1 filas suma 	

4	0	0	decadafila

 de cada filas = {0,1,1} filas = 2
 */