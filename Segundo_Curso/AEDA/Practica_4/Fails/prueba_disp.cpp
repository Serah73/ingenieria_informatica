#include <iostream>

#include "funcDispersion.hpp"
typedef long int T;
using namespace std;

class prueba{
    private:
        int nCeldas;
        int nBloques;
        
        funcDispersion<T> * fd;
    public:
        prueba(int n, int nB):nCeldas(n), nBloques(nB){}
        ~prueba(){}
        void insertar(T x){
            fd = new funcModulo<T>(x, 50);
            int d = fd->dispersion();
            cout << d << endl;
        }
};

int main (void){
    prueba a(50, 50);
    a.insertar(43379824);
}