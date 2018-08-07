#pragma once

#include<vector>
#include<iostream>
#include<ostream>
#include<iomanip>
#include<cstdlib>

#include"DNI.hpp"
#include"Datos.hpp"

template <class T>
class Metodos_t
{
private:
	Datos_t calculadora_;

public:

	//ordenaciones
	int HeapSort(vector<T>& secuencia, int n, bool tipo);
    void baja(vector<T>& secuencia, int n, int i);
    void swap(T x, T y);

    int Insert(vector<T>& secuencia, bool tipo);
    int Burbuja(vector<T>& secuencia, bool tipo);
    int QuickSort(vector<T>& secuencia, int inicial, int fin, bool tipo);
    int ShellSort(vector<T>& secuencia, float alfa, bool tipo);
    //otros
    void traza(int ini, int a, int b, vector<T>& secuencia);
    
    void resetC();
};

template <class T>
int Metodos_t<T>::HeapSort(vector<T>& secuencia, int n, bool tipo)
{
    int acumulador = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        baja(secuencia, n, i);
    }
    for (int i=n-1; i>=0; i--)
    {
        
        swap(secuencia[0], secuencia[i]);
        baja(secuencia, i, 0);
    }
    return calculadora_.get_contador();
}

template <class T>
void Metodos_t<T>::baja(vector<T>& secuencia, int n, int i)
{
	int largo = i;
	int izquierda = 2*i + 1;
	int derecha = 2*1 + 2;
	
	if(izquierda < n && secuencia[izquierda] > secuencia[largo])
	        largo = izquierda;

	if (derecha < n && secuencia[derecha] > secuencia[largo])
		largo = derecha;

	if (largo != i)
	{
		swap(secuencia[i], secuencia[largo]);
		calculadora_.shift();
		baja(secuencia, n, largo);
	}
}

template <class T>
void Metodos_t<T>::swap(T x, T y)
{
	T aux;
	aux = x;
	x = y;
	y = aux;
}

template <class T>
int Metodos_t<T>::Insert(vector<T>& secuencia, bool tipo)
{
    for(int i = 1; i < secuencia.size(); i++)
    {
    	int j = i;
    	T x = secuencia[i];
    	secuencia.insert(secuencia.begin(), x);
    
    	if(tipo)    traza(1, j, j + 1, secuencia);

    	while(x < secuencia[j])
    	{
    		secuencia[j + 1] = secuencia[j];
    		j--;
        	calculadora_.shift();
    	}
    	secuencia[j + 1] = x;
    	secuencia.erase(secuencia.begin());
    }
    return calculadora_.get_contador();
}


template <class T>
int Metodos_t<T>::Burbuja(vector<T>& secuencia, bool tipo)
{
    for(int i = 1; i < secuencia.size(); i++)
    {
    	for(int j = secuencia.size()-1; j >= i; j--)
    	{
    		if(tipo)    traza(0, j - 1, j, secuencia);
    		
    		if(secuencia[j] < secuencia[j-1])
    		{
    			calculadora_.shift();
    			T x = secuencia[j-1];
    			secuencia[j] = x;
    		}
    	}
    }
    return calculadora_.get_contador();
}

template <class T>
int Metodos_t<T>::QuickSort(vector<T>& secuencia, int inicial, int fin, bool tipo)
{
	int i = inicial;
	int f = fin;
	T p = secuencia[(i+f)/2];

	while(i < f)
	{
		while(secuencia[i] < p)	i++;
		while(secuencia[f] > p)	f--;

		calculadora_.shift();
		
	    if(tipo)    traza(0, i, f, secuencia);

		if(i < f)
		{
			T x = secuencia[i];
			secuencia[i] = secuencia[f];
			secuencia[f] = x;
		}
		i++; f--;

		if(inicial < f)
		{
		    calculadora_.shift();
			QuickSort(secuencia, inicial, f, tipo);
		}
		if(fin > i)
		{
		    calculadora_.shift();
			QuickSort(secuencia, i, fin, tipo);
		}

		return calculadora_.get_contador();
	}
}

template <class T>
int Metodos_t<T>::ShellSort(vector<T>& secuencia, float alfa, bool tipo)
{
	int gap, i, j;
    T temp;

    for (gap = secuencia.size()*alfa; gap > 0; gap *= alfa)
    {
    	for(i = gap; i < secuencia.size(); i++)
    	{
    		if(tipo)    traza(0, i - gap, i, secuencia);

    		for(j = i - gap; (j >= 0) && (secuencia[j] > secuencia[j+gap]); j -= gap)
    		{
    			calculadora_.shift();
    			temp = secuencia[j];
    			secuencia[j] = secuencia[j + gap];
    			secuencia[j + gap] = temp;
    		}

    	}
    }
    return calculadora_.get_contador();
}

template <class T>
void Metodos_t<T>::traza(int ini, int a, int b, vector<T>& secuencia)
{
    if(ini == a || ini == b){
        std::cout << secuencia[ini] << "<--";
    }
    else{
        std::cout << "   " << secuencia[ini];
    }
    for (int i = ini + 1; i < secuencia.size(); i++){
        if(i == a || i == b){
            std::cout << std::setw(17) << secuencia[i] << "<--";
        }
        else{
            std::cout << std::setw(20) << secuencia[i];
        }
    }
    std::cout << std::endl;
}

template <class T>
void Metodos_t<T>::resetC()
{
    calculadora_.resetC();
}