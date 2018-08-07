#include "lenguaje.hpp"
#include <stdio.h>


int main(void) {
	lenguaje_t A;
	lenguaje_t B;
	lenguaje_t C;

	int opcion;
	do {
		cout << endl << "1.- Inversa" << endl;
		cout << "2.- Concatenacion" << endl;
		cout << "3.- Union" << endl;
		cout << "4.- Interseccion" << endl;
		cout << "5.- Diferencia" << endl;
		cout << "6.- Sublenguajes" << endl;
		cout << "7.- Igualdad de lenguajes" << endl;
		cout << "8.- Potencia" << endl;
		cout << "9.- Cierre de Kleene" << endl;
		cout << "0.- Salir" << endl;
		cout << " - Introduzca una opcion: ";
		cin >> opcion;

		if(opcion) {
			printf("\nDefina el lenguaje: ");
			scanf("\n");
		}

		switch(opcion) {
			case 1: 
				A.read(cin);
				C.inversa(A); 
				C.write(cout); break;
			case 2: 
				A.read(cin);
				cout << "Defina el lenguaje: ";
				B.read(cin);
				C.concatenacion(A, B); 
				C.write(cout); break;
			case 3:
				A.read(cin);
				cout << "Defina el lenguaje: ";
				B.read(cin);
				C.unir(A, B); 
				C.write(cout); break;
			case 4:
				A.read(cin);
				cout << "Defina el lenguaje: ";
				B.read(cin);
				C.interseccion(A, B); 
				C.write(cout); break;
			case 5:
				A.read(cin);
				cout << "Defina el lenguaje: ";
				B.read(cin);
				C.diferencia(A, B); 
				C.write(cout); break;
			case 6: 
				A.read(cin);
				A.sublenguajes(); break;
			case 7: 
				A.read(cin);
				cout << "Defina el lenguaje: ";
				B.read(cin);
				if(A.igualdad(B)) 
					cout << "Son iguales" << endl;
				else
					cout << "No son iguales" << endl;
				break;
			case 8: 
				A.read(cin);
				cout << "Potencia: ";
				int n;
				cin >> n;
				C.potencia(A, n); 
				C.write(cout); break;
			case 9: 
				A.read(cin);
				C.kleene(A);  
				C.write(cout); break;
			case 0: break;
			default: cout << "Esa no es una opcion" << endl;
		}
		A.clear();
		B.clear();
		C.clear();
	} while(opcion);
}

