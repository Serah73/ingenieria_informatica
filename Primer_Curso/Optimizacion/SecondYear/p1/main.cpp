#include "grafo.h"

int main(int argc, char const *argv[])
{
	int opcion = -1;
	int errorapertura = -1;
	char* nombrefichero;
	nombrefichero = new char[100];



	cout << "Introduce el nombre del fichero: ";
	cin >> nombrefichero;
	cout << endl;
	GRAFO G(nombrefichero, errorapertura);
	cout << "Fichero cargado correctamente." << endl << endl;
	bool bucle = false;
	while (!bucle){
	
		if (errorapertura == 0){
		
			if (G.Es_dirigido() == 0){ //no dirigido
				cout << "-------------------------------------------------" << endl;
				cout << "1. Cargar grafo desde fichero." << endl;
				cout << "2. Mostrar informacion basica del grafo." << endl;
				cout << "3. Mostrar lista de adyacencia del grafo." << endl;
				cout << "4. Mostrar componentes conexas." << endl;
				cout << "0. Finalizar el programa." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Introduce el numero a la izquierda de la opcion: ";
			
				cin >> opcion;
				
				cout << endl << endl;
				
				switch (opcion)
				{
					case 1:
						cout << "Introduce el nombre del fichero";
						cin >> nombrefichero;
						cout << endl;
						G.actualizar(nombrefichero, errorapertura);
						break;
					case 2:
						G.Info_Grafo();
						break;
					case 3:
						G.Mostrar_Listas(0);
						break;
					case 4:
						
						break;
					case 0:
						exit(0);
					default:	
						cout << "Opcion no valida." << endl;
				}
			}
			if (G.Es_dirigido() == 1) //dirigido
			{
				cout << "-------------------------------------------------" << endl;
				cout << "1. Cargar grafo desde fichero." << endl;
				cout << "2. Mostrar informacion basica del grafo." << endl;
				cout << "3. Mostrar lista de sucesores del grafo." << endl;
				cout << "4. Mostrar lista de predecesores del grafo." << endl;
				cout << "5. Mostrar componentes conexas." << endl;
				cout << "0. Finalizar el programa." << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Introduce el numero a la izquierda de la opcion: ";
			
				cin >> opcion;
	
				switch (opcion)
				{
					case 1:
						cout << "Introduce el nombre del fichero: ";
						cin >> nombrefichero;
						cout << endl;
						G.actualizar(nombrefichero, errorapertura);
						break;
					case 2:
						G.Info_Grafo();
						break;
					case 3:
						G.Mostrar_Listas(1);
						break;
					case 4:
						G.Mostrar_Listas(2);
						break;
					case 5:
					
						break;
					case 0:
						exit(0);
					default:	
						cout << "Opcion no valida." << endl;
				}
			}
		}
		else{
			cout <<"Error en la apertura de fichero" << endl;
			return 0;
		}
	}
	return 0;
}