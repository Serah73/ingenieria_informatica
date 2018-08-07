#include <iostream>
#include <iomanip>
#include "tablahash.hpp"
#include "dni.hpp"

typedef long int T;

int main (void)
{
    int nc = 0, nb = 0, td = 0, te = 0;
    float factor = 0;

    std::cout << "Bienvenido" << std::endl;
    std::cout << "Numero de celdas de la tabla hash: ";
    cin >> nc;

    std::cout << "Numero de bloques por celda: ";
    cin >> nb;

    do
    {
        std::cout << "Tipo de dispersion a aplicar: " << std::endl;
        std::cout << "0. Dispersion por modulo" << std::endl;
        std::cout << "1. Dispersion pseudo-aleatoria" << std::endl;
        std::cout << "Tipo: ";
        
        cin >> td;
        
    }while(td < 0 || td > 1);
    
    do
    {
        std::cout << "Tipo de exploracion a aplicar: " << std::endl;
        std::cout << "0. Exploracion lineal" << std::endl;
        std::cout << "1. Exploracion cuadratica" << std::endl;
        std::cout << "2. Exploracion por dispersion doble" << std::endl;
        std::cout << "3. Exploracion por redispersion" << std::endl;
        std::cout << "Tipo: ";
        
        cin >> te;
        
        std::cout << std::endl;
        
    }while(te < 0 || te > 3);
    
    do
    {
        std::cout << "Factor de carga: ";
        
        cin >> factor;
        
    }while(factor < 0 || factor > 1);
    
    int nPruebas = 0;
    std::cout << "Numero de pruebas: ";
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
        
    std::cout << std::endl;
    
    tabla.limpiarPrueba();
    
    std::cout << std::setw(10) << "celdas" << std::setw(10) << "Bloques" << std::setw(10) << "Carga" << std::setw(10) << "Pruebas" << std::endl;
    std::cout << std::setw(10) << nc << std::setw(10) << nb << std::setw(10) << factor << std::setw(10) << nPruebas << std::endl;
    std::cout << "Numero de comparaciones" << std::endl << std::endl;
    
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
    
    std::cout << "          " << std::setw(10) << "Minimo" << std::setw(10) << "Maximo" << std::setw(10) << "Media" << std::endl;
    
    for(int i = 0; i < nc; i++)
    {
        if(min > vPruebas[i])
            min = vPruebas[i];

        if(max < vPruebas[i])
            max = vPruebas[i];

        media = media + vPruebas[i];
    }
    media = media / nc;
    std::cout << std::setw(10) << "Busqueda" << std::setw(10) << min << std::setw(10) << max << std::setw(10) << media << std::endl;
    
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
    std::cout << std::setw(10) << "Insercion" << std::setw(10) << min << std::setw(10) << max << std::setw(10) << media << std::endl;

}