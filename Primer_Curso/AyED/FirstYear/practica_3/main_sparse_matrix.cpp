#include <iostream>

#include "sparse_matrix_v_t.hpp"

using namespace std;


int main (void)
{
	matrix_double_t M;

	M.read(cin);

	sparse_matrix_t SM(M, 1E-3, COL_CONF);

	SM.write(cout);
}
