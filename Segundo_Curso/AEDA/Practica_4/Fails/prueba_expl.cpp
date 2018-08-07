#include <iostream>

#include "funcExploracion.hpp"
typedef long int T;
using namespace std;

class prueba{
    private:
        int nCeldas;
        int nBloques;
        
        funcExploracion<T> * fe;
    public:
        prueba(int n, int nB):nCeldas(n), nBloques(nB){}
        ~prueba(){}
        void insertar(T x){
            fe = new funcDoble<T>(x, 3, 50);
            int e = fe->exploracion();
            cout << e << endl;
        }
};

int main (void){
    prueba a(50, 50);
    a.insertar(43379824);
}