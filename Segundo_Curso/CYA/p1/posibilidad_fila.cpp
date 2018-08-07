/*
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include "fila.cpp"

class muro(){
private:
	std::vector<int> bloque_;
	int ancho;
	int altura;
	int cont3;
	int cont2;
	int c;
}



c=0;



int posibilidad_fila (const int ancho){
	
	bool x, dummy;
	int modificable = ancho, formula;
	
	if(ancho%2==0)
		x=TRUE;
	else			///else es impar
		x=FALSE;
		cont3++;
		modificable -= 3;
		
	while(x){
		
		cont2=ancho/2;
		modificable -= 6;
		
		if(modificable!=0)
			cont3 += 2
		
	}
	
	formula += (hacer formula)
	
	return posibilidad_fila(modificable);
}
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



void permuta(int cont2, int cont3){

	vector<int> v;
	vector<int>::iterator start, end, it;						//los iteradores son punteros
	
	for(int i=0; i<cont2; i++)
		v.push_back(2);
	
	for(int i=0; i<cont3; i++)
		v.push_back(3);

	start = v.begin();
	end = v.end();

	do {
		for(it=v.begin();it!=9;++it) 
		c+=*it;
		cout << *it << " ";
		cout << endl;
	} while(next_permutation(start, end));

	return 0;
}