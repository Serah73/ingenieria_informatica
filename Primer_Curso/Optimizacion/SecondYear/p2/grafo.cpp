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
	ElementoLista dummy;
	
	textfile.open(nombrefichero);

	if (textfile.is_open()){
	    
		//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){
			    
				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				
				dummy.j =--j;													//dummy.j es j-1
				LS[--i].push_back(dummy);										//Trabajamos con un conjunto de nodos{1,2,3,4,...n}
																				//Por tanto poner: LS[--i] implica trabajar con un conjunto de nodos{0,1,2,3,...n-1}
                if ( (dirigido == 0) && (i!=j) ){
                    
				    dummy.j=i;                  //
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
		ElementoLista dummy;
	
		textfile.open(nombrefichero);

		if (textfile.is_open()){
	    
		//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){
			    
				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				
				dummy.j =--j;													//dummy.j es j-1
				LS[--i].push_back(dummy);										//Trabajamos con un conjunto de nodos{1,2,3,4,...n}
			}
																				//Por tanto poner: LS[--i] implica trabajar con un conjunto de nodos{0,1,2,3,...n-1}
                if ( (dirigido == 0) && (i!=j) ){
                    
				    dummy.j=i;                  //
				    LS[j].push_back(dummy);     // Añado i a LS[j]
			    }
			   
			
			
			
			errorapertura=0;
			
			if(dirigido == 1){
			    ListaPredecesores();
			    
			}
			textfile.close();
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
	        
		    cout << "El grafo es dirigido" << endl;
		    cout << "Lista de sucesores: " << endl;

		    for (int i = 0; i < n; i++){  //Bucle que se realiza un número de veces igual al número de nodos que hayan
		        
			    cout << "Nodo " << "[ " << i+1 << " ] = ";		//Imprime los nodos
                for (int j = 0; j < LS[i].size(); j++){			//Realiza un segundo bucle que se repite en función del tamaño del sucesor
				    cout << LS[i][j].j+1 << " ";								//Imprime el contenido del sucesor ¿j+1?
				    }
			    cout << endl;
		    }																	//LS[0] -> contiene sucesores del nodo 1 en las posiciones LS[0][0], LS[0][1], LS[0][2],..
	    }																		//LS[0][0].j sirve para acceder al registro y conocer el valor
	    																		//LS[0][0].j almacena el valor nº1, por lo que se refiere al nodo 2 (Ya que hablamos de sucesores)
	    if (l == 1){
	        
		    cout << "El grafo es dirigido" << endl;
		    cout << "Lista de predecesores: " << endl;

		    for (int i = 0; i < n; i++){
		        																//Lo mismo que lo de arriba pero con los predecesores
			    cout << "Nodo " << "[ " << i+1 << " ] = ";
                for (int j = 0; j < LP[i].size(); j++){
				    cout << LP[i][j].j+1 << " ";								
                }
			    cout << endl;
		    }
	    }
	    if (l == 2){
	    	
			cout << "El grafo es no dirigido" << endl;
			cout << "Lista de adyacencia: " << endl;

			for (int i = 0; i < n; i++){
																				//Lo mismo que el primer IF
				cout << "Nodo " << "[ " << i+1 << " ] = ";						//LP permanece sin uso, todo se almacena en LS

				for (int j = 0; j < LS[i].size(); j++){
					cout << LS[i][j].j+1 << " ";
				}
				cout << endl;
			}
		}
	}
	
	void GRAFO::ListaPredecesores()
	{											//METODO PARA CREAR LA LISTA DE PREDECESORES
	    
	    LP.resize(n);															//Realiza un resize de la lista de predecesores
		ElementoLista dummy;													//Declaramos un tipo de dato ElementoLista y lo llamamos dummy

		if (dirigido == 1){														//Si el grafo es dirigo
			
			for (int i = 0; i < n; ++i){										//Bucle para recorrer todos los nodos
				
				for (int k = 0; k < LS[i].size(); ++k){							//Bucle para recorrer cada nodo un número de veces igual al tamaño de ese nodo
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