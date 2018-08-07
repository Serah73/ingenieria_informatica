#include "dfa.h"
#include <fstream>


int main (void) {
	ifstream fichero;
	bool abierto = false;
	char* cad = new char [30];
	string str;
	dfa_t A;
	int opcion;

	do {
		cout << endl << "1.- Leer DFA" << endl;
		cout << "2.- Mostrar DFA" << endl;
		cout << "3.- Identficar estados de muerte" << endl;
		cout << "4.- Analizar cadena" << endl;
		cout << "0.- Salir" << endl;
		cout << " > Introduzca una opcion: ";

		cin >> opcion;
		switch(opcion) {
			case 1:
				if(abierto) {
					fichero.close();
					A.clear();
				}
				cout << "Introduzca el nombre del fichero .dfa: ";
				cin >> cad;
				fichero.open(cad);
				abierto = true;
				A.read(fichero);
				break;
			case 2:
				A.write(cout);
				break;
			case 3:
				A.estados_muerte();
				break;
			case 4:
				cout << "Introduzca la cadena: ";
				cin >> str;
				A.analizar_cadena(str, cout);
				break;
			case 0:
				break;
			default: cout << "Opcion no reconocida" << endl;
		}
	} while(opcion);

	fichero.close();
}
