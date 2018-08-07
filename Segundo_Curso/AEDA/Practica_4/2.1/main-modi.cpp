#include <iostream>
#include <iomanip>
#include "tablaHash.hpp"
#include "DNI.hpp"

using namespace std;

typedef long int T;

int main (void){
    
    int nc = 0, nb = 0, td = 0, te = 0;

    

    cout << "Bienvenido" << endl;
    cout << "Numero de celdas de la tabla hash: ";
    cin >> nc;

    cout << "Numero de bloques por celda: ";
    cin >> nb;

    do{
        cout << "Tipo de dispersion a aplicar: " << endl;
        cout << "0. Dispersion por modulo" << endl;
        cout << "1. Dispersion pseudo-aleatoria" << endl;
        cout << "Tipo: ";
        cin >> td;
    }while(td < 0 || td > 1);
    
    do{
        cout << "Tipo de exploracion a aplicar: " << endl;
        cout << "0. Exploracion lineal" << endl;
        cout << "1. Exploracion cuadratica" << endl;
        cout << "2. Exploracion por dispersion doble" << endl;
        cout << "3. Exploracion por redispersion" << endl;
        cout << "Tipo: ";
        cin >> te;
        cout << endl;
    }while(te < 0 || te > 3);

    tablaHash<T> tabla(nc, nb, td, te);
    

    DNI primero(11223344, 'a', "nombre", "apellido");
    DNI segundo(44332211, 'b', "bbb", "bbb");
    DNI tercero(11334422, 'c', "ccc", "ccc");
    DNI cuarto(77889944, 'd', "ddd", "ddd");

    tabla.insertar(primero.get_num());
    tabla.insertar(segundo.get_num());
    tabla.insertar(tercero.get_num());
    tabla.insertar(cuarto.get_num());
    
    tabla.buscar(primero.get_num());
    tabla.buscar(segundo.get_num());
    tabla.buscar(tercero.get_num());
    tabla.buscar(cuarto.get_num());
    
    tabla.mostrar();
    
    tabla.buscar(11223344);
}