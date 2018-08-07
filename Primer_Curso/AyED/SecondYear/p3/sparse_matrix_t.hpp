#pragma once

#include <iostream>
#include <cmath>
#include "template_matrix_t.hpp"
#include "dll_pair_t.hpp"

using namespace std;

namespace AED{

enum {COL_CONF, ROW_CONF};

	class sparse_matrix_t {
	private:
		int m_;		//ROW
		int n_;		//col
		int conf_;

		dll_rara_pair_t Lista_;
	public:
		sparse_matrix_t(const matrix_t<double>& M, double eps, int conf):
		m_(M.get_m()),
		n_(M.get_n()),
		conf_(conf),
		Lista_()
		{
		
			node_pair_t* nodo_listaN = NULL;												//raro 
			node_raro_t* nodo_listaR = NULL;
			if(!conf){																		//conf columnas
				for(int i=1; i<=n_; i++){
					dll_pair_t lista_normal;												//lista que cuelga
					for(int j=1; j<=m_; j++){
						if(!fabs(M.get(j, i) < eps)){													//posicion x,y distinto de 0 metodo del 'template_matrix_t'
							nodo_listaN = new node_pair_t(sparse_pair_t(j,M.get(j, i)));	//lista dentro de la lista RARA, vamos
							//comprobador de QUE OBTENGO?		cout<<M.get(j,i)<<"  i: "<<i<< "; j: "<<j<<" ;"<< endl;
							lista_normal.insert_tail(nodo_listaN);							//Inserto el nodo no nulo hallado 'nodo_listaN' verificado antes por 'if(M.pos[i,j]!=0)'
						}
					}
					nodo_listaR = new node_raro_t(raro_pair_t(i, lista_normal));				//creas nodo de RARA e insertas la listaN, con todos los nodos encontrados por fila
					Lista_.insert_tail(nodo_listaR);										//lista RARA, donde metes el nodo anterior con el '(indice, lista)'
				}
			}
			else{																			//conf filas
				for(int i=1; i<=m_; i++){
					dll_pair_t lista_normal;
					for(int j=1; j<=n_; j++){
						if(!fabs(M.get(i, j) < eps)){													//posicion x,y distinto de 0 metodo del 'template_matrix_t'
							nodo_listaN = new node_pair_t(sparse_pair_t(j,M.get(i, j)));	//lista dentro de la lista RARA, vamos
							lista_normal.insert_tail(nodo_listaN);							//Inserto el nodo no nulo hallado 'nodo_listaN' verificado antes por 'if(M.pos[i,j]!=0)'
						}
					}
					nodo_listaR = new node_raro_t(raro_pair_t(i, lista_normal));				//creas nodo de RARA e insertas la listaN, con todos los nodos encontrados por fila
					Lista_.insert_tail(nodo_listaR);										//lista RARA, donde metes el nodo anterior con el '(indice, lista)'
				}
				
			}
		}
		~sparse_matrix_t(void) {}

		ostream& write(ostream& os)
		{
			os << m_ << endl;
			os << n_ << endl;
			Lista_.write(os);
			os << endl;
			return os;
		}
		
		
/////////////////////////////////////////////////////		PRUEBAS				/////////////////////////////////////////
			
		double prueba(void){
			double contador=0;
			node_raro_t* dato = Lista_.get_head();
			while(Lista_.get_head() != NULL)
			{
				raro_pair_t pair_lista = dato -> Lista_.get_data();
				dll_pair_t lista_val = dato
				if(pair_lista.get_val() != 0)
					contador++;
				lista_cont = Lista_.get_next();
			}
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	};

}
