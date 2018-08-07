#include "grafo.hpp"

using namespace std;

GRAFO :: ~GRAFO (void){		//Destructor

	n = 0;
	m = 0;
	dirigido = 0;
	LS.clear();
	LP.clear();

}



void GRAFO :: actualizar (char nombrefichero[85], int &errorapertura){		//Esta funcion es la encargada de poder cargar otro fichero con
										//otro grafo distinto sin necesidad de cerrar el programa.
	ElementoLista dummy;
	ElementoLista anotherdummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	errorapertura = 0;

	if (textfile.is_open()){

		unsigned i, j, k, c;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.clear();
		LS.resize(n); 
		// leemos los m arcos y creamos las listas de sucesores LS

		if (dirigido == 1){

			for (k=0; k<m; k++){

				textfile >> (unsigned &) i >> (unsigned &) dummy.j >> (unsigned &) dummy.c;
				dummy.j--;
				dummy.c--;
				LS[i-1].push_back(dummy);
			}
			textfile.close();
            		ListaPredecesores();
        	}
		else{
			
			for (k=0; k<m; k++){

				textfile >> (unsigned &) i >> (unsigned &) dummy.j;
				dummy.j--;
				LS[i-1].push_back(dummy);

				if(dummy.j != i-1){

					anotherdummy.j = i-1;
					LS[dummy.j].push_back(anotherdummy);
				}
			}
			textfile.close();
        	}
		errorapertura = 0;
	}
	else{
		errorapertura = 1;
    	}
}



void GRAFO :: Info_Grafo (void){	//Esta funcion muestra por pantalla la informacion basica del grafo elegido para trabajar
	
	cout << "\n\t-> El grafo cargado tiene " << n << " nodos, ";

	if(dirigido == 1){

		cout << m << " Arcos, es dirigido" << endl << endl;
	}
	else{
		cout << m << " Aristas, es no dirigido" << endl << endl;
	}
}


unsigned GRAFO :: Es_dirigido (void){		//Funcion que indica si es o no es dirigido el grafo
	return dirigido;
}


void GRAFO :: Mostrar_Lista (vector<LA_nodo> L){		//Funcion que muestra por pantalla la lista que se le pase como parametro.
	cout << endl;
	for(int i=0; i<n; i++){
		cout << "\t·nodo[" << i+1 << "]: ";
		for(int j=0; j<L[i].size(); j++){
			cout << L[i][j].j+1 << " (" << LS[i][j].c << ")"<< "|";
		}
		cout << endl;
	}
}



void GRAFO :: Mostrar_Listas (int l){

	switch(l){

		case 3: 

			Mostrar_Lista(LS);

			break;

		case 4:

			Mostrar_Lista(LP);

			break;

		default:

			break;

	}
       
}



void GRAFO :: ListaPredecesores (void){			//Esta funcion es la encargada de rellenar la lista de predecesores

	ElementoLista dummy;

	LP.clear();
	LP.resize(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<LS[i].size(); j++){
			dummy.j = i;		
			dummy.c=LS[i][j].c;
			LP[LS[i][j].j].push_back(dummy);
		}
	}	
}


void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
	visitado[i] = true;
	cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++)
		if (visitado[LS[i][j].j] == false)
			dfs(LS[i][j].j, visitado);
}

void GRAFO::ComponentesConexas(void)
{
	int contador=0;
	vector<bool>visitado;
	visitado.resize(n,false);	//Se redimensiona el vector booleano al número de nodos
	//Se inicializa todo el vector booleano a false

	for(unsigned i=0;i<n;i++)
	{
		if(visitado[i]==false)		//Si hay un nodo que no se ha visitado, es que hay una componente conexa 
		{
			contador++;  	 /*aumento del contador*/
			cout<<"Componente conexa "<<contador<<": ";
			cout <<"(";
			dfs(i,visitado);
			cout<<" }"; //Se llama al método dfs para que haga el recorrido por la componente conexa donde se encuentra el nodo que no había sido visitado
			cout<<endl;
		}
	}
	if(contador!=1)			 //Si hay más de una componente conexa, entonces el grafo ya no es conexo
		cout<<"El grafo N0 es conexo."<<endl;
	else
		cout<<"El grafo SI es conexo."<<endl;
}

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred){
	if (i != s){
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
	vector<int> d;
	vector<unsigned> pred;
	unsigned s, numeromejoras = 0;
	bool mejora;
	unsigned i, j;

	//Inicialmente todas las etiquetas distancias son infinito
	d.resize(n,maxint);
	//Inicialmente el pred es null
	pred.resize(n,UERROR);

	//Solicitamos al usuario nodo origen
	cout << endl;
	cout << "Caminos minimos: Bellman – End - Moore" << endl;
	cout << "Nodo de partida? [1-"<< n << "]: ";
	cin >> (unsigned &) s;
	//La etiqueta distancia del nodo origen es 0, y es su propio pred
	d[--s]=0; pred[s]=s;
	do{
		//Recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i] + cij, y actualizamos d y pred
		//si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos terminado;
		//contabilizamos los ciclos en los que ha habido mejoras
		mejora = false;
		for(i = 0; i < n; i++){
			for(j = 0; j < LS[i].size(); j++){
				if(d[LS[i][j].j] > d[i]+LS[i][j].c){
					d[LS[i][j].j] = d[i]+LS[i][j].c;
					pred[LS[i][j].j] = i;
					numeromejoras++;
					mejora = true;
				}
			}
		}
	}
	//para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos realizado n+1 veces la relajacion con mejora;
	//si mejora es false, pues tenemos solucion
	while ((numeromejoras < n) && (mejora == true));

	cout << endl << "Soluciones:" << endl;
	//Mostramos los caminos mínimos que se puedan haber encontrado, o advertimos de la existencia de un ciclo de coste negativo.
	cout << "Caminos mínimos desde el nodo: " << s << endl;	
	if(mejora == false){
		if(numeromejoras == 0){
			cout << "NO HAY CAMINOS" << endl;
		}
		else{
			for(i = 0; i < n; i++){
				if((i != s) and (d[i] < maxint)){
					cout << "Distancia = " << d[i] << "\tCamino: ";
					MostrarCamino(s, i, pred);
					cout << i << endl;
				}
			}
		}
	}
	else{
		cout << "EL GRAFO CONTIENE UN CICLO DE COSTE NEGATIVO" << endl;
	}
}

GRAFO :: GRAFO (char nombrefichero[85], int &errorapertura){		//Constructor

	actualizar(nombrefichero, errorapertura);

}