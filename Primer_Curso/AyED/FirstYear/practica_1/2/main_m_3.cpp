#include "matrices_3.hpp"

int main(void)
{
	matrix_t A;
	matrix_t B;

	cout << endl;
	A.read(cin);
	cout << "---  MATRIZ ORIGINAL  ---" << endl;
	A.write();

	cout << "---  PRECISIÓN 0.0001 ---" << endl;
	A.filtra(B,5.254,1E-4);
	B.write();

	cout << "---  PRECISIÓN 0.001  ---" << endl;
	A.filtra(B,5.254,1E-3);
	B.write();

	cout << "---  PRECISIÓN 0.01   ---" << endl;
	A.filtra(B,5.254,1E-2);
	B.write();

	cout << "---  PRECISIÓN 0.1    ---" << endl;
	A.filtra(B,5.254,1E-1);
	B.write();

	cout << "---  PRECISIÓN 1.0    ---" << endl;
	A.filtra(B,5.254,1.0);
	B.write();
	
	cout << "---  MATRIZ ORIGINAL TRASPUESTA---" << endl;
	A.trasponer();
	A.write();
	A.trasponer();
	A.write();
}
