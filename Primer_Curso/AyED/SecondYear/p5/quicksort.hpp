#pragma once

#include "vector_t.hpp"
#include "stack_v_t.hpp"

using namespace AED;

int divide(vector_t<int>& v, int i, int d) {

	int pivot = v[i];
	int izq = i;
	int dch = d;
 
	while (izq < dch) {

		while (v[dch] > pivot) 
		    dch--;
 
		while ((izq < dch) && (v[izq] <= pivot)) 
		    izq++;
 
		if (izq < dch) 
			swap(v[izq], v[dch]);   
	}
 
	swap(v[i], v[dch]);			
 
	return dch;
}

void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}
 
void quicksort(vector_t<int>& v, int i, int d)
{
	if (i < d) {

		const int pivot = divide(v, i, d);
 
		quicksort(v, i, pivot - 1);
		quicksort(v, pivot + 1, d);
	}
}

void quicksort2(vector_t<int>& v, int i, int d)
{
	stack_v_t<int> pila(2 * v.get_sz());

	pila.push(i);
	pila.push(d);

	while(!pila.empty()){

		const int dch = pila.top(); pila.pop(); 
		const int izq = pila.top(); pila.pop();

		if (izq <= dch){
			const int pivot = divide(v, izq, dch);

			pila.push(izq); pila.push(pivot - 1);
			pila.push(pivot + 1); pila.push(dch);
		}
	} 
}

void sort(vector_t<int>& v)
{
	quicksort(v, 0, v.get_sz() - 1);
}

void sort2(vector_t<int>& v)
{
	quicksort2(v, 0, v.get_sz() - 1);
}


