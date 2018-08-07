#pragma once

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<class T>
class cola
{
    private:

		vector< pair<T,int> > q;

    public:

		cola(){};
        ~cola(){};

        void insertar(T dato, int id);
        void extraer(T& data, int& entero);
        void imprimir();

        bool vacia();
};

template<class T>
void cola<T>::insertar(T dato, int id)
{
	pair<T,int> par(dato, id);
	q.insert(q.end(), par);
}

template<class T>
void cola<T>::extraer(T& data, int& entero)
{
	data = q[0].first;
	entero = q[0].second;
	q.erase(q.begin());
}

template<class T>
void cola<T>::imprimir()
{
	for (int i = 0; i < q.size(); i++)
    	cout << q[i].first << " " << q[i].second << endl;
}

template<class T>
bool cola<T>::vacia ()
{
	if (q.size() == 0)	return true;

	return false;
}
