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

		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.clear();
		LS.resize(n); 
		// leemos los m arcos y creamos las listas de sucesores LS

		if (dirigido == 1){

			for (k=0; k<m; k++){

				textfile >> (unsigned &) i >> (unsigned &) dummy.j;
				dummy.j--;
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

			cout << L[i][j].j+1 << "|";

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


GRAFO :: GRAFO (char nombrefichero[85], int &errorapertura){		//Constructor

	actualizar(nombrefichero, errorapertura);

}
