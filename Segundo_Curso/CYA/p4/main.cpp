#include "dfa.h"
#include <fstream>


int main (void) {
	ifstream fich;
	bool opened = false;
	char* cad = new char [30];
	string str;
	dfa_t A;
	int option;

	do {
		cout << endl << "1.- Leer DFA" << endl;
		cout << "2.- Mostrar DFA" << endl;
		cout << "3.- Identficar estados de muerte" << endl;
		cout << "4.- Analizar cadena" << endl;
		cout << "0.- Salir" << endl;
		cout << " > Introduzca una opcion: ";

		cin >> option;
		switch(option) {
			case 1:
				if(opened) {
					fich.close();
					A.clear();
				}
				cout << "Introduzca el nombre del fich .dfa: ";
				cin >> cad;
				fich.open(cad);
				opened = true;
				A.read(fich);
				break;
			case 2:
				A.write(cout);
				break;
			case 3:
				A.state_death();
				break;
			case 4:
				cout << "Introduzca la cadena: ";
				cin >> str;
				A.check_string(str, cout);
				break;
			case 0:
				break;
			default: cout << "opcion no reconocida" << endl;
		}
	} while(option);

	fich.close();
}
