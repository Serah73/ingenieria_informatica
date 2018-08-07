#include"AVLsimple.hpp"
#include"Demostracion.hpp"
#include"Estadistica.hpp"
#include"DNI.hpp"
#include"Utilidad.hpp"
#include"Datos.hpp"

typedef DNI T;

int main(void)
{
	Demostracion<T> demostracion;
	Estadistica_t<T> estadistica;
	AVL<T> arbol;

    int opcion = 0;
    do{
        std::cout << "//---------------------------------------------------//" << std::endl;
        std::cout << "Menu principal" << std::endl;
        std::cout << "[0] Salir" << std::endl;
        std::cout << "[1] Demostracion" << std::endl;
        std::cout << "[2] Estadistico" << std::endl;
        std::cout << "Opcion deseada: ";
        std::cin >> opcion;
        
        switch(opcion)
        {
            case 1:
            {
                demostracion.demostrar(arbol);
            }
            break;

            case 2:
            {
            	int elementosArbol, numeroPruebas;

            	std::cout << "Introduzca el numero de elementos a insertar en el arbol: ";
            	std::cin >> elementosArbol;

            	std::cout << "Introduzca el numero de pruebas a realizar: ";
            	std::cin >> numeroPruebas;

                estadistica.estadisticas(elementosArbol, numeroPruebas);
            }
            break;

            case 0:
            {
                std::cout << "Saliendo..." << std::endl;
                std::cout << "//---------------------------------------------------//" << std::endl;
            }
            break;
            
            default:
                std::cout << "Opcion fuera de rango. Introduzca una opcion valida" << std::endl;
        }
    }while(opcion);
    return 0;
}

