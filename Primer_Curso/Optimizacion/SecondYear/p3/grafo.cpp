#include<iostream>
#include<vector>
#include<fstream>
#include<cstdio>

#include "grafo.hpp"


using namespace std;

	GRAFO::GRAFO(char nombrefichero[], int &errorapertura)
	{
		ifstream textfile;
		unsigned i,j,k;
		int coste;
		ElementoLista dummy;

		textfile.open(nombrefichero);

		if (textfile.is_open()){
	
			//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){

				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				textfile >> (int &)coste;

				dummy.j =--j;			//dummy.j es j-1
				dummy.c =coste;
				LS[--i].push_back(dummy);//Trabajamos con un conjunto de nodos{1,2,3,4,...n}
																//Por tanto poner: LS[--i] implica trabajar con un conjunto de nodos{0,1,2,3,...n-1}
		    	if ( (dirigido == 0) && (i!=j) ){
					dummy.j=i;
					dummy.c=coste;
					LS[j].push_back(dummy);     // Añado i a LS[j]
				}
			}

			textfile.close();
			errorapertura=0;

			if(dirigido == 1){
			    ListaPredecesores();
			}
		}
		else {
		    errorapertura = 1;
		}
	}

	void GRAFO::actualizar(char nombrefichero[], int &errorapertura){

		LS.clear();
		LP.clear();

		ifstream textfile;
		unsigned i,j,k;
		int coste;
		ElementoLista dummy;

		textfile.open(nombrefichero);

		if (textfile.is_open()){
	
			//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){

				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				textfile >> (int &)coste;

				dummy.j =--j;			//dummy.j es j-1
				dummy.c =coste;
				LS[--i].push_back(dummy);//Trabajamos con un conjunto de nodos{1,2,3,4,...n}
																//Por tanto poner: LS[--i] implica trabajar con un conjunto de nodos{0,1,2,3,...n-1}
		    	if ( (dirigido == 0) && (i!=j) ){
					dummy.j=i;
					dummy.c=coste;
					LS[j].push_back(dummy);     // Añado i a LS[j]
				}
			}

			textfile.close();
			errorapertura=0;

			if(dirigido == 1){
			    ListaPredecesores();
			}
		}
		else {
		    errorapertura = 1;
		}
	}//Cierre de actualizar





  unsigned GRAFO::Es_dirigido()
  {
  	return dirigido;
  }


	void GRAFO::Info_Grafo()
	{
	        cout << endl;
	        cout << "La informacion del grafo es la siguiente: " << endl;
	        cout << "El número de nodos es: " << n << endl;
	        cout << "El número de arcos es: " << m << endl;

	        if (dirigido == 0){
		        cout << "El grafo es no dirigido" << endl;
	        }
	        else{
		        cout << "El grafo es dirigido" << endl;
	        }
	        cout << endl;
	}

	void GRAFO::Mostrar_Listas(int l)
	{

	    if (l == 0){

		    cout << endl << "El grafo es dirigido" << endl;
		    cout << "Lista de sucesores: " << endl;

		    for (int i = 0; i < n; i++){  //Bucle que se realiza un número de veces igual al número de nodos que hayan

			    cout << "Nodo " << "[ " << i+1 << " ] = ";		//Imprime los nodos
        		for (int j = 0; j < LS[i].size(); j++){			//Realiza un segundo bucle que se repite en función del tamaño del sucesor
				  	
				  	cout << LS[i][j].j+1 << "(" << LS[i][j].c << ")";	//Imprime el contenido del sucesor ¿j+1?
					int aux=LS[i].size() - 1;
        			if(j != aux)
        				cout << ", ";
        		}
			    cout << endl;
		    }
		    cout << endl;
	    }																	
	    																		
	    if (l == 1){

		    cout << endl << "El grafo es dirigido" << endl;
		    cout << "Lista de predecesores: " << endl;

		    for (int i = 0; i < n; i++){
			    cout << "Nodo " << "[ " << i+1 << " ] = ";
			    
        		for (int j = 0; j < LP[i].size(); j++){
				    cout << LP[i][j].j+1;
				    int aux=LS[i].size() - 1;
        			if(j != aux)
        				cout << ", ";
        		}
			    cout << endl;
		    }
		    cout << endl;
	    }
	    if (l == 2){

			cout << endl << "El grafo es no dirigido" << endl;
			cout << "Lista de adyacencia: " << endl;

			for (int i = 0; i < n; i++){
																				//Lo mismo que el primer IF
				cout << "Nodo " << "[ " << i+1 << " ] = ";						//LP permanece sin uso, todo se almacena en LS

				for (int j = 0; j < LS[i].size(); j++){
					cout << LS[i][j].j+1 << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	void GRAFO::ListaPredecesores()
	{											//METODO PARA CREAR LA LISTA DE PREDECESORES

		LP.resize(n);															//Realiza un resize de la lista de predecesores
		ElementoLista dummy;													//Declaramos un tipo de dato ElementoLista y lo llamamos dummy

		if (dirigido == 1){														//Si el grafo es dirigo

			for (int i = 0; i < n; ++i){										//Bucle para recorrer todos los nodos

				for (int k = 0; k < LS[i].size(); ++k){//Bucle para recorrer cada nodo un número de veces igual al tamaño de ese nodo
																				//dummy.j es i
					dummy.j=i;													//Asigno i, que es el numero del nodo ¿?¿?¿?
					LP[LS[i][k].j].push_back(dummy);							//Meto un sucesor en la lista de predecesores ¿?¿?¿?¿?
				}																//Vector de vectores
			}
		}
	}



    GRAFO::~GRAFO()
    {

            LS.clear();															//Limpia la lista de sucesores
	        LP.clear();															//Limpia la lista de predecesores
    }


    void GRAFO::dfs(unsigned i, vector<bool> &visitado)
	{
		visitado[i] = true;
		cout << i+1 << ", ";

		for (unsigned j=0;j<LS[i].size();j++)

			if (visitado[LS[i][j].j] == false)
				dfs(LS[i][j].j, visitado);

		if(dirigido == 1)

			for (unsigned j=0;j<LP[i].size();j++)

				if (visitado[LP[i][j].j] == false)
					dfs(LP[i][j].j, visitado);
	}


	void GRAFO::ComponentesConexas(void)
	{
			int contador=0;
			vector<bool> visitado;
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
				cout<<")"; //Se llama al método dfs para que haga el recorrido por la componente conexa donde se encuentra el nodo que no había sido visitado
				cout<<endl;
			}
		}

		if(contador!=1)			 //Si hay más de una componente conexa, entonces el grafo ya no es conexo
			cout<<"El grafo no es conexo."<<'\n';
		else
			cout<<"El grafo es conexo."<<'\n';

		cout << endl;
	}


	void GRAFO::Dijkstra()
	{
		vector<bool> PermanentementeEtiquetado;
		vector<int> d;
		vector<unsigned> pred;
		int min;
		unsigned s, candidato;
		//Inicialmente no hay ningun nodo permanentemente etiquetado
		PermanentementeEtiquetado.resize(n,false);
		//Inicialmente todas las etiquetas distancias son infinito
		d.resize(n,maxint);
		//Inicialmente el pred es null
		pred.resize(n,UERROR);
		//Solicitamos al usuario nodo origen
		cout << endl;
		cout << "Caminos minimos: Dijkstra" << endl;
		cout << "Nodo de partida? [1-"<< n << "]: ";
		cin >> (unsigned &) s;
		//La etiqueta distancia del nodo origen es 0, y es su propio pred
		d[--s]=0; pred[s]=s;
		candidato=UERROR;
		
		do
		{
			min=maxint;

			for(int i=0; i<n; i++)
			{
				if((!PermanentementeEtiquetado[i]) && (d[i] != maxint) && (d[i]<min)) 
				{
					min=d[i];
					candidato=i;
				}
			}
			
			PermanentementeEtiquetado[candidato]=true;
			
			for(int j=0; j<LS[candidato].size(); j++)
			{
				if((d[LS[candidato][j].j] > d[candidato]+LS[candidato][j].c) && (PermanentementeEtiquetado[LS[candidato][j].j]==false))
				{
					d[LS[candidato][j].j]=d[candidato]+LS[candidato][j].c;
					pred[LS[candidato][j].j]=candidato;
				}
			}
		/*
			- Buscamos un nodo candidato a ser permanentemente etiquedado: aquel de
				entre los no permanentemente etiquetados con menor etiqueta
				distancia no infinita.
			- Si existe ese candidato, lo etiquetamos permanentemente y usamos los
				arcos de la lista de sucesores para buscar atajos.
			- Esto lo hacemos mientras haya candidatos
		*/}while (min < maxint);

		cout << "Soluciones:" << endl;
			//En esta parte del código, mostramos los caminos mínimos, si los hay
		
		for(int i=0; i<n; i++)
			
			if(d[i]==maxint)
				cout << "No hay camino al nodo: " << i + 1 << endl;
			else if(i!=s)
			{
				cout << "El camino  " << s + 1 << " a " << i + 1 << " es: ";
				MostrarCamino(s,i,pred);
				cout << i + 1 << " con coste '" << d[i] << "'" << endl;
			}
		cout << endl;
	}

	void GRAFO::BellmanEndMoore()
	{
 		vector<int> d;
 		vector<unsigned> pred;
 		unsigned s, numeromejoras = 0;
 		bool mejora;

		//Idem que en el algoritmo de Dijkstra
 		d.resize(n,maxint);
 		pred.resize(n,UERROR);
 		cout << endl;
 		cout << "Caminos minimos: Bellman – End - Moore" << endl;
 		cout << "Nodo de partida? [1-"<< n << "]: ";
 		cin >> (unsigned &) s;
 		d[--s]=0; pred[s]=s;

		do
 		{
 			 
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
 			/*recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i] +
 			cij, y actualizamos d y pred
 			si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos
 			terminado; contabilizamos los ciclos en los que ha habido mejoras
			*/
		} while ((numeromejoras < n) && (mejora == true));

	    if (mejora == true)
	    	cout << "No hay solucion posible al detectarse un negativo en el grafo" << endl;
		else{
       
	    	cout << "La solucion es" << endl;
               
            for (unsigned i = 0; i < n; i++){
             
                if (i!=s){
                    if (pred[i] != UERROR){
                        cout << "El camino  " << s + 1 << " a " << i + 1 << " es: ";
                        MostrarCamino(s,i,pred);
                        cout << i + 1 << " con coste " << d[i] << endl;                
                    }
                	else
                    	cout <<"No hay camino desde: " << s + 1 <<" al nodo " << i + 1 <<endl;
                }        
            }
        }
        cout << endl;
		/*para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos
 		realizado n+1 veces la relajacion con mejora; si mejora es false, pues
 		tenemos solucion
 		Mostramos los caminos mínimos que se puedan haber encontrado, o advertimos
 		de la existencia de un ciclo de coste negativo.
		*/
		}

	void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)
	{
			if (i != s)
			{
				MostrarCamino(s,pred[i],pred);
				cout << pred[i]+1 << " -> ";
			}
	}
