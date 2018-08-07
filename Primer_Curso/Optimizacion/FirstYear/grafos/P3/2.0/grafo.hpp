#ifndef _GRAPH_H
#define _GRAPH_H


#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

const unsigned UERROR = 65000;
const int maxint = 1000000;

// definicion de un elemento de la lista de adyacencia

typedef struct
{
	unsigned j; // nodo
	int      c; // atributo para expresar el peso, la longitud, el coste, la inversion, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo;


class GRAFO{

	unsigned            n;         // numero de NODOS //
	unsigned            m;         // numero de ARCOS //
	unsigned	    dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	vector<LA_nodo>     LS;        // Lista de adyacencia de los sucesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
	vector<LA_nodo>     LP;        // Lista de adyacencia de los predecesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//

 public:
     GRAFO(char nombrefichero[], int &errorapertura);
     void actualizar (char nombrefichero[], int &errorapertura);
     unsigned Es_dirigido (void);  //devuelve 0 si el grafo es no dirigido y 1 si es dirigido
     void Info_Grafo (void);
     void Mostrar_Listas(int l);
     void Mostrar_Lista (vector<LA_nodo> L);
     void ListaPredecesores (void);
     ~GRAFO(void);
     void dfs(unsigned i, vector<bool> &visitado);
     void ComponentesConexas();
     void Dijkstra();
	 void BellmanEndMoore();
	 void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred);
};


#endif
