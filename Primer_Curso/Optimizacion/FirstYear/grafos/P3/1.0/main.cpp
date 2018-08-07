#include "grafo.hpp"

using namespace std;

int main (void){

	unsigned opcion=1;
	char fichero[85];
	int error=0;

	cout << "\n\tIntroduce el nombre del fichero: ";
	cin >> fichero;
	GRAFO fich(fichero,error);
	do{

		if(error == 0){

			if(fich.Es_dirigido()){			

                cout << "\n- Carga de Grafo dirigido" << endl << endl;
				cout << "\tOpciones:" << endl << "\t\t1. Cargar un nuevo grafo desde fichero." << endl;
				cout << "\t\t2. Información básica del grafo." << endl << "\t\t3. Mostrar sucesores del grafo." << endl;
				cout << "\t\t4. Mostrar predecesores del grafo." << endl << "\t\t0. Finalizar el programa." << endl;
				cout << "\t\t5. Caminos minimos: Dijkstra." << endl << "\t\t6. Caminos minimos: Bellman-End-Moore." << endl;
				cout << "\n\t\t·Introduce una opción: ";
				cin >> opcion;

				switch(opcion){

					case 0:	

						cout << endl << "Saliendo del programa..." << endl << endl;

						break;

					case 1:

						cout << "\n\tIntroduzca el nombre del fichero del siguiente grafo: ";
						cin >> fichero;

						fich.actualizar(fichero,error);

						break;

					case 2:				

						fich.Info_Grafo ();

						break;

					case 3:

						fich.Mostrar_Listas(0);

						break;

					case 4:

						fich.Mostrar_Listas(1);

						break;
						
					case 5:
						
						fich.Dijkstra();
						
						break;
					
					case 6:
						
						fich.BellmanEndMoore();
						
						break;

					default: 

						cout << "\n\tOpción introducida incorrecta, introduzca una opción disponible" << endl << endl;	

						break;

				}

			}
			else{

                cout << endl << "- Carga de Grafo no dirigido" << endl << endl;
				cout << "Opciones:" << endl << endl << "\t1. Cargar nuevo grafo desde fichero." << endl;
				cout << "\t2. Información básica del grafo." << endl << "\t3. Mostrar adyacencia del grafo." << endl;
				cout << "\t4. Mostrar componentes conexas del grafo"<< endl << "\t0. Finalizar el programa." << endl << endl;
				cout << "\tIntroduce una opción: ";
				cin >> opcion;

				switch(opcion){

					case 0:

                        cout << endl << "Saliendo del programa..." << endl << endl;


						break;

					case 1:

						cout << "\n\tIntroduzca el nombre del fichero desde el que va a cargar el siguiente grafo: ";
						cin >> fichero;

						fich.actualizar(fichero, error);						

						break;

					case 2:				

						fich.Info_Grafo ();

						break;

					case 3:

						fich.Mostrar_Listas(0);

						break;
					
					case 4:
						fich.ComponentesConexas();
						
						break;

					default: 

						cout << "\n\tOpción introducida incorrecta, introduzca una opción disponible" << endl << endl;

						break;

				}

			}


		}

		else{

			cout << endl << endl << "\tSe ha producido un error en la apertura del fichero." << endl << "\tAsegúrese de que el fichero existe o que ha introducido el nombre correctamente" << endl <<endl << endl;

			cout << "\n\tIntroduce el nombre del fichero desde el que se cargarán los datos del grafo: ";
			cin >> fichero;

			fich.actualizar(fichero, error);
		}
	}while(opcion != 0);
}
