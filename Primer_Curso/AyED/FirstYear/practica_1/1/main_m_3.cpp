#include "matrices_3.hpp"

int main(void)
{
	matrix_t A;
	matrix_t B;

	cout << endl;
	A.read(cin);
	cout << "---  MATRIZ ORIGINAL  ---" << endl;
	A.mostrarMatriz();

	cout << "---  PRECISIÓN 0.0001 ---" << endl;
	A.filtra(B,5.254,1E-4);
	B.mostrarMatriz();

	cout << "---  PRECISIÓN 0.001  ---" << endl;
	A.filtra(B,5.254,1E-3);
	B.mostrarMatriz();

	cout << "---  PRECISIÓN 0.01   ---" << endl;
	A.filtra(B,5.254,1E-2);
	B.mostrarMatriz();

	cout << "---  PRECISIÓN 0.1    ---" << endl;
	A.filtra(B,5.254,1E-1);
	B.mostrarMatriz();

	cout << "---  PRECISIÓN 1.0    ---" << endl;
	A.filtra(B,5.254,1.0);
	B.mostrarMatriz();

	cout << "contador de contar_entre" << endl;
	A.contar_entre(0, 5.9,1E-4);
	cout << A.contar_entre(0, 5.9,1E-4) << endl;
}

