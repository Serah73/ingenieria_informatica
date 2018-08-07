#include <iostream>

#include "sparse_matrix_t.hpp"
#include "template_matrix_t.hpp"

using namespace std;
using namespace AED;


int main (void)
{
	matrix_t<double> M;

	M.read(cin);

	sparse_matrix_t SM(M, 1E-3, COL_CONF);

	SM.write(cout);
	
	SM.prueba();
}