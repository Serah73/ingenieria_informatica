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
    
    float factor = 0;

    
    do{
        cout << "Factor de carga: ";
        cin >> factor;
    }while(factor < 0 || factor > 1);
    
    int nPruebas = 0;
    cout << "Numero de pruebas: ";
    cin >> nPruebas;
    
    int  N = factor * nc * nb;
    DNI bancoDePruebas[2*N];

    for(int i = 0; i < 2*N; i++)
    {
        int x = rand() % 5000001 + 30000000;
        DNI aux(x, 65 + (x % 23) );
        bancoDePruebas[i] = aux;
    }
    
    tablaHash<T> tabla(nc, nb, td, te);
    
    for(int i = 0; i < N; i++)
        tabla.insertar(bancoDePruebas[i].get_num());
    
    cout << endl;
    tabla.limpiarPrueba();
    
    cout << setw(10) << "celdas" << setw(10) << "Bloques" << setw(10) << "Carga" << setw(10) << "Pruebas" << endl;
    cout << setw(10) << nc << setw(10) << nb << setw(10) << factor << setw(10) << nPruebas << endl;
    cout << "Numero de comparaciones" << endl << endl;
    
    int vPruebas[nPruebas];
    for (int i = 0; i < nc; i++)
        vPruebas[i] = 0;
    
    int min = 9999, max = 0; 
    float media = 0;
    
    for (int i = 0; i < nPruebas; i++)
    {
        tabla.buscar(bancoDePruebas[rand() % N].get_num());
        vPruebas[i] = tabla.get_comparaciones(i);
    }
    
    cout << "          " << setw(10) << "Minimo" << setw(10) << "Maximo" << setw(10) << "Media" << endl;
    
    for(int i = 0; i < nc; i++)
    {
        if(min > vPruebas[i])
            min = vPruebas[i];
        
        if(max < vPruebas[i])
            max = vPruebas[i];
        
        media = media + vPruebas[i];
    }
    media = media / nc;
    cout << setw(10) << "Busqueda" << setw(10) << min << setw(10) << max << setw(10) << media << endl;
    
    min = 0;
    max = 0;
    media = 0;
    for (int i = 0; i < nc; i++)
        vPruebas[i] = 0;
    
    for (int i = 0; i < nPruebas; i++)
    {
        tabla.insertar(bancoDePruebas[rand() % N + N].get_num());
        vPruebas[i] = tabla.get_inserciones(i);
    }
    
    for(int i = 0; i < nc; i++)
    {
        if(min > vPruebas[i])
            min = vPruebas[i];
        
        if(max < vPruebas[i])
            max = vPruebas[i];
        
        media = media + vPruebas[i];
    }
    media = media / nc;
    cout << setw(10) << "Insercion" << setw(10) << min << setw(10) << max << setw(10) << media << endl;

}