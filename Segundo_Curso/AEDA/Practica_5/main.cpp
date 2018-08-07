#include<iostream>

#include"DNI.hpp"
#include"Metodos.hpp"
#include"Demostracion.hpp"
#include"Estadistica.hpp"

typedef DNI T;

int main(void)
{
	int opcion = 0;
	Estadistica_t<T> estadistica;
	Demostracion_t<T> demostracion;

		do{
			std::cout << "Menu principal" << std::endl;
	        std::cout << "1. Demostracion" << std::endl;
	        std::cout << "2. Estadistico" << std::endl;
	        std::cout << "0. Salir" << std::endl;
	        std::cout << "Introduzca la opcion deseada: ";
	        std::cin >> opcion;
	        std::cout << "//-------------------------------------------------------------------------//" << std::endl;

	        switch(opcion)
	        {
	            case 0:{
	                std::cout << "Saliendo..." << std::endl;
	            }
	            break;

	            case 1:{
	                int lonv = 0;

	                std::cout << "Introduzca el numero de elementos del vector(maximo = 25, minimo = 2): ";
	                std::cin >> lonv;

	                if(lonv > 25) lonv = 25;
	                if(lonv < 2) lonv = 2;

	                std::cout << "Se procederá a crear un vector aleatorio para la prueba" << std::endl;

	                srand(time(NULL));
	                vector<DNI> v(lonv);

	                for(int j = 0; j < v.size(); j++)
	                {
	                    int x = rand() % 5000001 + 30000000;
	                    DNI aux(x, 65 + (x % 23) );
	                    v[j] = aux;
	                }
	                demostracion.demostrar(v);
	            }
	            break;

	            case 2:{
	                int elementos = 0, pruebas = 0;
	                std::cout << "Introduzca el numero de elementos del vector: ";
	                std::cin >> elementos;
	                if(elementos <= 1) elementos = 2;

	                std::cout << "Introduzca el numero de pruebas a realizar: ";
	                std::cin >> pruebas;

	                estadistica.estadisticas(elementos, pruebas);
	            }
	            break;

	            default:
	                std::cout << "Opcion fuera de rango, pruebe de nuevo" << std::endl;
	        }
	    }while(opcion);
}
