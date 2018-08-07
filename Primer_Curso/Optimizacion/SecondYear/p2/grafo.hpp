
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdio>


using namespace std;

typedef struct{
        unsigned j;	        //Nodo
	    int      c;	        //Atributo para expresar su peso, longitud, coste...
}ElementoLista;

typedef vector<ElementoLista> LA_nodo;  

const unsigned UERROR = 65000;
const int maxint = 1000000;


class GRAFO{
    
	unsigned n;			//nº de nodos
	unsigned m;			//nº de arcos
	unsigned dirigido;		//0 si es no dirigido y 1 eoc
	vector<LA_nodo> LS;		//Lista de sucesores y adyacencia
	vector<LA_nodo> LP;		//Lista de predecesores
	
	public:
	
	//unsigned dirigido;		//0 si es no dirigido y 1 eoc
	GRAFO(char nombrefichero[], int &errorapertura);
	~GRAFO();
	void actualizar(char nombrefichero[], int &errorapertura);
	unsigned Es_dirigido();		//revisar cabecera
	void Info_Grafo();
	void Mostrar_Listas(int l);
	void ListaPredecesores();	
	void dfs(unsigned i, vector<bool> &visitado);
	void ComponentesConexas();
};
