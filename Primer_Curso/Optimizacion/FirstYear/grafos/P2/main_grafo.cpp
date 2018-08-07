#include "grafo.hpp"


using namespace std;


int main (void){


	system("clear");


	char nombrefichero[100];
	int errorapertura = 0;
	unsigned opcion = 1;
	
	cout << "\n\tIntroduce el nombre del fichero: ";
	cin >> nombrefichero;

	GRAFO A(nombrefichero, errorapertura);	

	do{

		if(errorapertura == 0){

			if(A.Es_dirigido()){			

                cout << "\n- Carga de Grafo dirigido" << endl << endl;
				cout << "\tOpciones:" << endl << "\t\t1. Cargar un nuevo grafo desde fichero." << endl;
				cout << "\t\t2. Información básica del grafo." << endl << "\t\t3. Mostrar sucesores del grafo." << endl;
				cout << "\t\t4. Mostrar predecesores del grafo." << endl << "\t\t0. Finalizar el programa." << endl;
				cout << "\n\t\t·Introduce una opción: ";
				cin >> opcion;

				switch(opcion){

					case 0:	

						cout << endl << "Saliendo del programa..." << endl << endl;

						break;

					case 1:

						cout << "\n\tIntroduzca el nombre del fichero del siguiente grafo: ";
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

						cout << "\n\tOpción introducida incorrecta, introduzca una opción disponible" << endl << endl;

						break;

				}

			}


		}

		else{

			cout << endl << endl << "\tSe ha producido un error en la apertura del fichero." << endl << "\tAsegúrese de que el fichero existe o que ha introducido el nombre correctamente" << endl <<endl << endl;

			cout << "\n\tIntroduce el nombre del fichero desde el que se cargarán los datos del grafo: ";
			cin >> nombrefichero;

			A.actualizar(nombrefichero, errorapertura);


		}

	}while(opcion != 0);	

	return(0);

}

	
