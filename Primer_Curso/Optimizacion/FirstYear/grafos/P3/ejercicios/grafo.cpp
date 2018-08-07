#include "grafo.h"

using namespace std;

/*El constructor GRAFO(char nombrefichero[], int &errorapertura) 
se encarga de leer el problema del fichero de texto nombrefichero 
de tipo ifstream y de asignar los atributos de la clase GRAFO, 
devolviendo 0 en errorapertura si no ha habido incidencia alguna, 
y 1 si la ha habido.*/

GRAFO::GRAFO(char nombrefichero[], int &errorapertura)
{
		actualizar(nombrefichero,errorapertura);
}
GRAFO::~GRAFO(){
		LS.clear();
		LP.clear();
}
void GRAFO::actualizar(char nombrefichero[], int &errorapertura){
	LS.clear();
    LP.clear();
    int i, j, k;
    ElementoLista dummy;
    ifstream textfile;
	
	textfile.open(nombrefichero);
    if (textfile.is_open()) {
    	errorapertura = 0;
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		if(dirigido == 1){//si el grafo es dirigido
		    LS.resize(n);
		    LP.resize(n);
		    for(int contador = 0;contador < m;contador++){
		        textfile >>  i >> j >> k;
		        i = i -1;
		        j = j -1;
		        dummy.j = j;
		        dummy.c = k;
		        LS[i].push_back(dummy);
		        dummy.j = i;
		        dummy.c = k;
		        LP[j].push_back(dummy);
		    }
		}
		else{
		    LS.resize(n);
		    for(int contador = 0; contador < m; contador ++){
		        textfile >>  i >>  j;
		        i = i - 1;
		        j = j - 1;
		        dummy.j = j;
		        dummy.c = k;
		        LS[i].push_back(dummy);
		        if(i != j){
		            dummy.j = i;
		            dummy.c = k;
		            LS[j].push_back(dummy);
		        }
		    }
		}

		textfile.close();
		
	}
	else {
		cout << "Fichero no reconocido"<< endl;
		errorapertura = 1;
	}

}

void GRAFO::Info_Grafo(){
	cout << "Numero de nodos:" << " " << n << endl;
	cout << "Numero de arcos:" << " " << m << endl;

	if (dirigido == 0)
	{
		cout << "No es dirigido" << endl;
	}
	else
		cout << "Es dirigido" << endl;
}
void GRAFO::Mostrar_Listas(int l){
	if (l == 0)
	{
		cout << "Es dirigido" << endl;
		cout << "Lista de sucesores" << endl;
	
		for (int i = 0; i < n; i++)
		{
			cout << "Nodo " << "[ " << i+1 << " ] = ";
			if(LS[i].size()==0)
			cout << "NULL ";
			for (int j = 0; j < LS[i].size(); j++)
				cout << LS[i][j].j+1 << " ";
			cout << endl;
		}
	}
	if (l == 1)
	{
		cout << "Es dirigido" << endl;
		cout << "Lista de predecesores" << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Nodo " << "[ " << i+1 << " ] = ";
			if(LP[i].size()==0)
			cout << "NULL";
			for (int j = 0; j < LP[i].size(); j++)
				cout << LP[i][j].j+1 << " ";
			cout << endl;
		}
	}
	if (l == 2)
	{
		cout << "Es no dirigido" << endl;
		cout << "Lista de adyacencia" << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Nodo " << "[ " << i+1 << " ] = ";
			if(LS[i].size()==0)
			cout << "NULL";
			for (int j = 0; j < LS[i].size(); j++)
				cout << LS[i][j].j+1 << " ";
			cout << endl;
		}
	}
}
void GRAFO::ListaPredecesores()
{
	LP.resize(n);
	ElementoLista dummy;

	if (dirigido == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int k = 0; k < LS[i].size(); ++k)
			{
				dummy.j=i;
				LP[LS[i][k].j].push_back(dummy);
			}
		}
	}
}
unsigned GRAFO::Es_dirigido(void){
    return dirigido;
}



void GRAFO::dfs(unsigned i, vector<bool> &visitado){
visitado[i] = true;
 cout << i+1 << ", ";
for (unsigned j=0;j<LS[i].size();j++)
 if (visitado[LS[i][j].j] == false)
 dfs(LS[i][j].j, visitado);
}

void GRAFO::ComponentesConexas() {

	unsigned i=0;
	int cc=0;
	
	visitado.resize(n); // dimensionar el vector visitado.

	for(int i=0;i<n;i++)
		visitado[i] = false;   	//marcamos a false todos los nodos para decir que no estan visitados
	

	for(int i=0;i<n;i++) {                 //n-->nodos

		if(visitado[i]==false) {

		    ++cc;
		    cout << "Componente conexa" << " #" << cc << " son :{ ";
		    dfs(i,visitado);
		    cout << " } " << endl;
		}
		
	}
	if (cc > 1)
	{
		cout << "No conexo" << endl;
	}
	else
		cout << "Conexo" << endl;
}



void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)
{
	if (i != s) {
	    MostrarCamino(s,pred[i],pred);
	    cout << pred[i]+1 << " -> ";
	}
}



void GRAFO::Dijkstra()
{
vector<bool> PermanentementeEtiquetado;//vector de las distancias minimas
vector<int> d;//vector de distancias
vector<unsigned> pred;//vector de predecesores
int min;
unsigned s, candidato;

PermanentementeEtiquetado.resize(n,false);//Inicialmente no hay ningun nodo permanentemente etiquetado

d.resize(n,maxint);//Inicialmente todas las etiquetas distancias son infinito

pred.resize(n,UERROR);//Inicialmente el pred es null

	cout << endl;
	cout << "Caminos minimos: Dijkstra" << endl;
	cout << "¿Nodo de partida? [1-"<< n << "]: ";
	cin >> (unsigned &) s;
	s--;
	unsigned t=s;
	unsigned y;

//La etiqueta distancia del nodo origen es 0, y es su propio pred
	d[s]=0; pred[s]=s;

//Hemos preparado d y permanentemente etiquetado para que el primer nodo en ser candidato sea s.
do{
	min = maxint; //Todos estan inicializados a infinito.
	for (y=0; y<n; y++){

		if((!PermanentementeEtiquetado[y]) && (d[y]!=maxint)){//Si PE y la distancia es distinta de infinito.

			if(min > d[y]){//si min es mayor que la distancia nueva entonces min pasa a tener valor mas pequeño.
				min = d[y];
				candidato = y;//nodo permanentemente etiquetado.
			}
		}
	}


	PermanentementeEtiquetado[candidato] = true;//Ya esta el valor y el nodo permanentemente etiquetado.
	for (int k=0;k<LS[candidato].size();k++){//Aqui recorremos la lista de sucesores

		if (!PermanentementeEtiquetado[LS[candidato][k].j]){

			if (d[candidato]+ LS[candidato][k].c <= d[LS[candidato][k].j]){//Sumamos las distancias y el valor del nodo

					d[LS[candidato][k].j] = d[candidato]+ LS[candidato][k].c;
					pred[LS[candidato][k].j] = candidato;

			}
		}
	}

}

while (min < maxint);//Si los nodos valen menos que infinito.

	cout << "Soluciones:" << endl;
			//En esta parte del código, mostramos los caminos mínimos, si los hay.

	for (y=0;y<n;y++){//Recorremos uno a uno los nodos.

		if (pred[y]==UERROR)//Si los predecesores estan inicializados a null.
			cout << "No existe forma de llegar al nodo "<< y+1<<" desde el nodo "<<t+1<<"."<< endl;
		else{
			cout << "desde el nodo "<<t+1<<" hasta el nodo "<<y+1<<": "; 
			MostrarCamino(t, y, pred);
			cout << y+1<<" con coste: "<<d[y] <<endl;
		}
	}
}
void GRAFO::BellmanEndMoore(){

	    vector <int> d;
	    vector <unsigned> pred;
	    unsigned s;
	    unsigned numeromejoras=0;
	    bool mejora;
	    int maxint = 9999;
	    unsigned UERROR = 6500;
 
	    d.resize(n, maxint);
	    pred.resize(n, UERROR);
	
	    cout << endl
	         << "Caminos minimos: Bellman- Ford - Moore" << endl
	         << "Nodo de partida? [1-" << n << "]: ";
	    cin >> (unsigned &) s;
 
	    d[--s]=0;	//nuestro nodo por teclado -1
	    pred[s]=s;
 
	    do{
 
                mejora = false;
 
                for (unsigned i = 0; i < n; i++){
                        for (unsigned k = 0; k < LS[i].size(); k++){
 
                                if (( d[LS[i][k].j]) > (d[i] + LS[i][k].c)){ 
                                       
                                        d[LS[i][k].j] = (d[i] + LS[i][k].c);
                                        pred[LS[i][k].j] = i;
                                        mejora = true;
                                }
                        }
                }
 
                numeromejoras++;
 
        } while ((numeromejoras <= n + 1) && (mejora == true));
       
       
	    if (mejora == true)
	    	cout << "No hay solucion posible al detectarse un ciclo de coste negativo en el grafo" << endl;
   
	    else{
       
	    cout << "La solucion es" << endl;
               
                for (unsigned i = 0; i < n; i++){
             
                        if (i!=s){
                                if (pred[i] != UERROR){
                                        cout << "El camino  " << s + 1 << " a " << i + 1 << " es: ";
                                        MostrarCamino(s,i,pred);
                                        cout << i + 1 << " de longitud " << d[i] << endl;                
                                }
           
                                else
                                        cout <<"No hay camino desde: " << s + 1 <<" al nodo " << i + 1 <<endl;
                        }        
                }
        }
}
