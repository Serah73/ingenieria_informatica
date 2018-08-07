#include "grafo.hpp"


using namespace std;


int main (void){


	system("clear");


	char nombrefichero[100];
	int errorapertura = 0;
	unsigned opcion = 1;
	
	cout << "\n\tIntroduzca nombre del fichero a cargar:" << endl;
	cin >> nombrefichero;

	GRAFO A(nombrefichero, errorapertura);	

	do{

		if(errorapertura == 0){

			if(A.Es_dirigido()){			

				cout << "\nOpciones de carga de grafo dirigido desde fichero:"<< endl;	
				cout << "\t\t1. Cargar un nuevo grafo desde fichero." << endl;
				cout << "\t\t2. Mostrar información básica del grafo." << endl; 
				cout << "\t\t3. Mostrar la lista de sucesores del grafo." << endl;
				cout << "\t\t4. Mostrar la lista de predecesores del grafo." << endl;
				cout << "\t\t5. Camino mínimo con algoritmo de Dijkstra." << endl;
				cout << "\t\t6. Camino mínimo con algoritmo de Bellman-End-Moore." << endl;
				cout << "\t\t0. Finalizar el programa." << endl;
				
				cout << "\n\t\t·Introduzca una opción: ";
				cin >> opcion;

				switch(opcion){

					case 0:	

						cout << "¡Adiós!" << endl;
						
						break;

					case 1:

						cout << "\n\tIntroduzca el nombre del fichero desde el que va a cargar el siguiente grafo: ";
						cin >> nombrefichero;

						A.actualizar(nombrefichero, errorapertura);

						break;

					case 2:				

						A.Info_Grafo ();

						break;

					case 3:

						A.Mostrar_Listas(3);

						break;

					case 4:

						A.Mostrar_Listas(4);

						break;
						
					case 5:
					
					    A.Dijkstra();
					    
					    break;
					    
					case 6:
					
					    A.BellmanEndMoore();
					    break;

					default: 

						cout << "\n\tEsta opción no existe, elija una de las mostradas."<< endl;	

						break;

				}

			}

			else{

				cout << " Opciones de carga de Grafo no dirigido desde fichero" << endl;	
				cout << "\t1. Cargar nuevo grafo desde fichero." << endl;
				cout << "\t2. Mostrar información básica del grafo." << endl; 
				cout << "\t3. Mostrar la lista de adyacencias del grafo." << endl;
				cout<<  "\t4. Mostrar componentes conexas del grafo."<<endl;
				cout << "\t0. Finalizar el programa." << endl << endl;
				
				cout << "\tIntroduzca una opción: ";
				cin >> opcion;

				switch(opcion){

					case 0:

						cout << "¡Adiós!" << endl;
							
                        break;

					case 1:

						cout << "\n\tIntroduzca nombre del fichero a cargar: ";
						cin >> nombrefichero;

						A.actualizar(nombrefichero, errorapertura);						

						break;

					case 2:				

						A.Info_Grafo ();

						break;

					case 3:

						A.Mostrar_Listas(3);

						break;
						
					case 4:
                 
                       				 A.ComponentesConexas();
                        
                        			break;	

					default: 

						cout << "\n\tEsa opción no existe, elija una de las mostradas." << endl << endl;

						break;

				}

			}


		}

		else{

			           cout << "\n\tERROR DE APERTURA\n\n\n" << endl;
                       exit(0);


		}

	}while(opcion != 0);	

	return(0);

}

	
