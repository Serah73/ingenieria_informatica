#include <cstdlib>
#include <iostream>
#include <iomanip>

#define BIT_SET_SIZE 80
#define N_RANDOM_BITS 40

#define N_RANDOM_LETTERS 5
#define N_LETTERS 26

using namespace std;

#include "p6bitset_t.hpp"

int main(void)
{
	bitset_t<long int, BIT_SET_SIZE> A;
	bitset_t<long int, BIT_SET_SIZE> B;
	bitset_t<long int, BIT_SET_SIZE> C;
	bitset_t<long int, BIT_SET_SIZE> V;
	//bitset_t<long int, BIT_SET_SIZE> E; 


	for(int i = 0; i < N_RANDOM_BITS; i++){
	
		A.insert(rand() % BIT_SET_SIZE + 1);	
		
	}
	
	for(int i = 0; i < N_RANDOM_BITS; i++){
		
		B.insert(rand() % BIT_SET_SIZE + 1);
		
	}
	
	for(int i = 0; i < N_RANDOM_BITS; i++){
		
		V.insert(rand() % BIT_SET_SIZE + 1);
		
	}
		

	cout << endl;
	cout << "<<<< Contenido del conjunto A >>>>" << endl;
	cout << endl;
	cout << A << endl;
	cout << endl;

	cout << "Cardinalidad del conjunto A: " << setw(3) << A.cardinality() << endl;
	cout << "Mayor elemento del conjunto A: " << setw(3) << A.last_item()   << endl;
	cout << "Menor elemento del conjunto A: " << setw(3) << A.first_item()  << endl;

	cout << endl;

	cout << "<<<< Contenido del conjunto B >>>>" << endl;
	cout << endl;
	cout << B << endl;
	cout << endl;

	cout << "Cardinalidad del conjunto B: " << setw(3) << B.cardinality() << endl;
	cout << "Mayor elemento del conjunto B: " << setw(3) << B.last_item()   << endl;
	cout << "Menor elemento del conjunto B: " << setw(3) << B.first_item()  << endl;

	cout << endl;

	cout << "<<<< Contenido del conjunto C >>>>" << endl;
	
	A.union_set(B,C);

	cout << endl;
	
	cout << C << endl;
	//cout << endl;

	A.intersec_set(B,C);

	cout << C << endl;
	cout << endl;
	
	//Fase 3
	cout << "<<<<<Inteseccion entre A y B>>>>>>>>"<<endl;
	cout << endl;
	A.insersect_set_clase(B,C);
	
	cout << C << endl;
	
	
	
	//MODIFICACION
	cout << "modi: " << endl;
	cout << V << endl;
	cout << "cardinalidad: " << setw(3) << V.n_pares() << endl;
	
//	for(int i = 0; i < N_RANDOM_LETTERS; i++)
//		D.insert('a' + rand() % N_LETTERS);

//	for(int i = 0; i < N_RANDOM_LETTERS; i++)
//		D.insert('A' + rand() % N_LETTERS);

//	cout << endl;
//	cout << "<<<< Contenido del conjunto D >>>>" << endl;
//	D.wite(cout);
//	cout << endl;

	return 0;
}
