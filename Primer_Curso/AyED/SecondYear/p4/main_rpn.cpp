#include <cstdio>
#include <iostream>


#include "stack_v_t.hpp"
#include "stack_l_t.hpp"
#include <stack>

#include "RPN_calc_t.hpp"

using namespace std;
using namespace AED;

typedef stack_v_t<int> stack_vector;
typedef stack_l_t<int> stack_lista  ;  
typedef stack<int>     stack_stl  ;

int main(void)
{

	RPN_calc_t<stack_vector> calculadora_vector;
	const int result_vector = calculadora_vector.compute(cin);
	cout << "Calculadora vector: " << result_vector << endl;

	cin.clear();
	cin.seekg(0, ios::beg);

	RPN_calc_t<stack_lista> calculadora_lista;
	const int result_lista = calculadora_lista.compute(cin);
	cout << "Calculadora lista:  " << result_lista << endl;

	cin.clear();
	cin.seekg(0, ios::beg);

	RPN_calc_t<stack_stl> calculadora_stl;
	const int result_stl = calculadora_stl.compute(cin);
	cout << "Calculadora stl:    " << result_stl << endl;


	return 0;

}
