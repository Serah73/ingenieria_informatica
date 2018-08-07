#include "abb.hpp"
#include"Demostracion.hpp"
#include"Estadistica.hpp"
#include"DNI.hpp"

typedef DNI T;

int main(void)
{
	Demostracion_t<T> demostracion;
	Estadistica_t<T> estadistica;
	abb<T> arbol;

    int opcion = 0;
    do{
        cout << "//---------------------------------------------------//" << endl;
        cout << "Menu principal" << endl;
        cout << "[0] Salir" << endl;
        cout << "[1] Demostracion" << endl;
        cout << "[2] Estadistico" << endl;
        cout << "Opcion deseada: ";
        cin >> opcion;
        switch(opcion){
            case 1:{
                demostracion.demostrar(arbol);
            }
            break;

            case 2:{
            	int elementosArbol, numeroPruebas;

            	cout << "Introduzca el numero de elementos a insertar en el arbol: ";
            	cin >> elementosArbol;

            	cout << "Introduzca el numero de pruebas a realizar: ";
            	cin >> numeroPruebas;

                estadistica.estadisticas(elementosArbol, numeroPruebas);
            }
            break;

            case 0:{
                cout << "Saliendo..." << endl;
                cout << "//---------------------------------------------------//" << endl;
            }
            break;
            default:
                cout << "Opcion fuera de rango. Introduzca una opcion valida" << endl;
        }
    }while(opcion);
    return 0;
}

