#include "grafo.hpp"

GRAFO::~GRAFO(){
	n=0;
	m=0;
	dirigido=0;
	LS.clear();
	LP.clear();
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura){
	LS.clear();
	LP.clear();
	ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if(textfile.is_open()){
		unsigned i, j, k, c;
		//leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		//los nodos internamente se numeran desde 0 a n-1
		//creamos las n listas de sucesores
		LS.resize(n); 
		//leemos los m arcos y creamos las listas de sucesores LS
		for (k=0;k<m;k++){
			textfile >> (unsigned &) i >> (unsigned &) j >> (unsigned &) c;
			dummy.j=j;
			dummy.c=c;
			LS[i-1].push_back(dummy);
			if(dirigido==0){
				dummy.j=i;
				LS[j-1].push_back(dummy);
			}
		}
		textfile.close();
		ListaPredecesores();
		errorapertura = 0;
	}
	else{
		errorapertura = 1;
		cout << "Error en la apertura del archivo, intentelo de nuevo" << endl;
	}
}

void GRAFO::Info_Grafo(){
	if(dirigido==1){
		cout << "- Grafo dirigido"<< endl;
	}
	else{
		cout << "- Grafo no dirigido" << endl;
	}
	cout << "- Numero de nodos: " << n << endl;
	cout << "- Numero de arcos: " << m << endl;
}

unsigned GRAFO::Es_dirigido(){
	return dirigido;
}

void GRAFO::Mostrar_Listas(int l){
	if(l==0){
		if(dirigido==1){
			cout << "LISTA DE SUCESORES:" << endl;
		}
	else 
		cout<< "LISTA DE ADYACENCIA:" << endl;
	for(int i=0;i<n;i++){
		cout << i+1 << " =";
		for(int j=0;j<LS[i].size();j++){
			cout << " " << LS[i][j].j << " (" << LS[i][j].c << ")";
		}
		cout << endl;
	}
} //?
  
	if(l==1){
		cout<<"LISTA DE PREDECESORES:"<<endl;
		for(int i=0;i<n;i++){
			cout << i+1 << " =";
			for(int j=0;j<LP[i].size();j++){
				cout << " " << LP[i][j].j << " (" << LP[i][j].c << ")";
			}
			cout << endl;
		}
	}
}

void GRAFO::ListaPredecesores(){
	LP.resize(n);
	ElementoLista dummy;
	for(int i=0; i<n; i++){
		for( int j=0; j<LS[i].size(); j++){ 
			dummy.j=i+1;
			dummy.c=LS[i][j].c;
			LP[LS[i][j].j-1].push_back(dummy);
		}
	}
}

void GRAFO::dfs(unsigned i, vector<bool> &visitado){
	visitado[i] = true;
	cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++)
		if (visitado[(LS[i][j].j)-1] == false)
			dfs(LS[i][j].j-1, visitado);
}

void GRAFO::ComponentesConexas(){
	unsigned i;
	unsigned componentes = 0;
	vector<bool> visitado;
	visitado.resize(n);
	for(i=0; i<n; i++){
		visitado[i] = false;
	}
	cout << "Nodos de las componentes conexas:" << endl;
	for(i=0;i<n;i++){
		if(visitado[i] == false){
			componentes++;
			cout << "Componente conexa " << componentes << " : <";
			dfs(i, visitado);
			cout << ">" << endl;
		}
	}
	if(componentes > 1){
		cout << "El grafo NO es conexo" << endl;
	}
	else{
		cout << "El grafo es conexo" << endl;
	}
}

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred){
	if (i != s){
		MostrarCamino(s,pred[i],pred);
		cout << pred[i]+1 << " -> ";
	}
}


void GRAFO::Dijkstra(){
	
	vector<bool> PermanentementeEtiquetado;                                     // Vector donde llevamos los registros de los nodos etiquetados.
	vector<int> d;																// Vector donde almacenamos los costes de cada arista.
	vector<unsigned> pred;                                                      // Vector donde almacenamos los predecesores de cada nodo.
	
	int min;
	unsigned s;                                                                 // Índice para los vectores.
	
	
	unsigned candidato;                                                         // Candidato a ser parte del camino mínimo.

	//Inicialmente no hay ningun nodo permanentemente etiquetado
	
	PermanentementeEtiquetado.resize(n,false);                                  // Redimensionamos el vector PermanentementeEtiquetado dándole el número de nodos y poniendo cada posición a false.
	
	d.resize(n,infinito);													    // Redimensionamos el vector de costes y ponemos los costes muy altos.
	
	pred.resize(n,UERROR);                                                      // Redimensionamos el vector de predecesores.

	cout << "\nAlgoritmo de Dijkstra para hallar el camino mínimo." << endl;
	cout << "Nodo de partida [1-"<< n << "]: ";
	cin >> (unsigned &) s;                                                      // Indicamos por teclado el nodo de partida.

    d[--s]=0;                                                                   // Reducimos el índice introducido por el usuario para adaptarlo al vector.
    pred[s]=s;
	
	do{                                                                         // Hacemos esto mientras se cumpla el while.
		min = infinito;
		for(int i = 0; i < n; i++){
			if((PermanentementeEtiquetado[i] == false) and (d[i] < min)){       // Si no ha sido etiquetado y la etiqueta distancia es menor a min:
				min = d[i];                                                     // El mínimo será ahora esa etiqueta distancia.
				candidato = i;                                                  // El candidato será ese nodo.
			}
		}
		if(min < infinito){
			PermanentementeEtiquetado[candidato] = true;                        // Si la etiqueta distancia es menor que infinito etiquetamos el nodo.     
			for(int i = 0; i < LS[candidato].size(); i++){                          // Ahora pasamos a buscar en la lista de sucesores del candidato.
				if(d[LS[candidato][i].j-1] > d[candidato]+LS[candidato][i].c && PermanentementeEtiquetado[LS[candidato][i].j-1] == false){
					d[LS[candidato][i].j-1] = d[candidato]+LS[candidato][i].c;
					pred[LS[candidato][i].j-1] = candidato;                     // El predecesor de ese candidato se convierte en el candidato.
				}
			}
		}
	}
	
	while (min < infinito);

	cout << "\nSoluciones:" << endl;
	
	bool solucion = false;	
	
	cout << "Caminos minimos desde el nodo[" << s+1 << "]" << endl;          // Mostramos el camino mínimo hallado.
	
	for(int i = 0; i < n; i++){
		if((i != s) and (d[i] < infinito)){                                     // Si el nodo es distinto del elegido y la etiqueta distancia es menor que infinito:
			
			solucion = true;                                                    
			
			cout << "Distancia= " << d[i] << "\tCamino: ";
			
			MostrarCamino(s, i, pred);                                          // Llamamos a la función MostrarCamino.          
			
			cout << i+1 << endl;
		}
		if(!solucion){
		cout << "NO HAY CAMINO MÍNIMO." << endl;
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
				if(d[LS[i][j].j-1] > d[i]+LS[i][j].c){
					d[LS[i][j].j-1] = d[i]+LS[i][j].c;
					pred[LS[i][j].j-1] = i;
					numeromejoras++;
					mejora = true;
				}
			}
		}
	}
	//para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos realizado n+1 veces la relajacion con mejora;
	//si mejora es false, pues tenemos solucion
	while ((numeromejoras < n+1) && (mejora == true));

	cout << endl << "Soluciones:" << endl;
	//Mostramos los caminos mínimos que se puedan haber encontrado, o advertimos de la existencia de un ciclo de coste negativo.
	cout << "Caminos mínimos desde el nodo: " << s+1 << endl;	
	if(mejora == false){
		if(numeromejoras == 0){
			cout << "NO HAY CAMINOS" << endl;
		}
		else{
			for(i = 0; i < n; i++){
				if((i != s) and (d[i] < maxint)){
					cout << "Distancia = " << d[i] << "\tCamino: ";
					MostrarCamino(s, i, pred);
					cout << i+1 << endl;
				}
			}
		}
	}
	else{
		cout << "EL GRAFO CONTIENE UN CICLO DE COSTE NEGATIVO" << endl;
	}
}

GRAFO::GRAFO(char nombrefichero[], int &errorapertura){
	ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()){
		unsigned i, j, k, c;
		//leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		//los nodos internamente se numeran desde 0 a n-1
		//creamos las n listas de sucesores
		LS.resize(n); 
		//leemos los m arcos y creamos las listas de sucesores LS
		for (k=0;k<m;k++){
		  		    textfile >> (unsigned &) i >> (unsigned &) j >> (unsigned &) c;
		    dummy.j =j;
		    dummy.c =c;
		    LS[i-1].push_back(dummy);
		    
		  if( dirigido==0){
		      dummy.j=i;
		      if(i!=j)
		      LS[j-1].push_back(dummy);
		  }
		}
		textfile.close();
		ListaPredecesores();
		errorapertura = 0;
	}else{
		errorapertura = 1;
		cout << "Error en la apertura del archivo, intentelo de nuevo" << endl;
	}
};

