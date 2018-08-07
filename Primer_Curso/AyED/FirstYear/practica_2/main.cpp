#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
#include <fstream>
using namespace std;

#define V_SZ 10000
#define EPS  1E-3

int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << " vector1.txt vector2.txt" << endl;
		return -1;
	}

	ifstream vector1;
	ifstream vector2;

	vector1.open(argv[1]);
	vector2.open(argv[2]); 

	vector_t v1;
	sparse_vector_t v2;		

	v1.read(vector1);
	v2.read(vector2);

	v1.write(cout);			//saca pantalla
        cout << endl;
	v2.write(cout);
	cout << endl;
	const double sp = v2.scal_prod(v1);

	cout << "La maquina de la verdad dice que el producto escalar es: " << sp << endl;

	vector1.close();
	vector2.close();

}