#include <iostream>

#include <cstdlib>
#include <time.h>

#include "vector_t.hpp"
#include "quicksort.hpp"
#include "quick.hpp"

using namespace std;
using namespace AED;

#define MAX_SZ   20
#define MAX_VAL 200
#define MAX_TEST  5

int main(void)
{
	vector_t<int> v(MAX_SZ);
	srand (time(NULL));

 for(int j=0; j<MAX_TEST; j++){}

	for(int i = 0; i < MAX_SZ; i++)
		v[i] = rand() % MAX_VAL + 1;

	cout << v << endl;

	sort(v);

	const int x = rand() % MAX_VAL + 1;

	cout << "buscando: " << x << endl;

	const int pos = buscal(v, x);
	if(pos == -1) cout << "no encontrado"<< endl;
	else cout << "encontrado en: "<< x << endl;

	cout << v << endl;


	for(int i = 0; i < MAX_SZ; i++)
		v[i] = rand() % MAX_VAL + 1;

	cout << v << endl;

	sort2(v);

	cout << v << endl;
}
