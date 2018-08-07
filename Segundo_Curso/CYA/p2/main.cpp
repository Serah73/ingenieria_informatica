#include "funciones.hpp"



int main(void){
    
    int number=0;

    do{
        
		std::cout << "1. Inversa" << std::endl;
		std::cout << "2. Concatenación " << std::endl;
		std::cout << "3. Unión" << std::endl;
		std::cout << "4. Intersección" << std::endl;
		std::cout << "5. Diferencia" << std::endl;
		std::cout << "6. Sublenguajes" << std::endl;
		std::cout << "7. Igualdad de lenguajes" << std::endl;
		std::cout << "8. Potencia" << std::endl;
		std::cout << "9. Cierre de Kleene" << std::endl;
		std::cout << "0. Finalizar" << std::endl;
		
		std::cout << "\n\t·Introduce una opción: ";
        std::cin >> number;
        
        switch(number){
            
            case 0:
                
                std::cout << "Cerrando.." << std::endl;
                break;
                
            case 1:
                
                std::cout << "Inversa" << std::endl;
                break;

            case 2:
                
                std::cout << "Concatenación" << std::endl;
                break;
                
            case 3:
                
                std::cout << "union" << std::endl;
                break;
                
            case 4:
                
                std::cout << "interseccion" << std::endl;
                break;
                
            case 5:
                
                std::cout << "diferencia" << std::endl;
                break;
                
            case 6:
                
                std::cout << "sublenguaje" << std::endl;
                break;
                
            case 7:
                
                std::cout << "igualdad de lenguajes" << std::endl;
                break;
                
            case 8:
                
                std::cout << "potencia" << std::endl;
                break;
                
            case 9:
                
                std::cout << "cierre de kleene" << std::endl;
                break;
        }
    std::cout << "\n" << std::endl;
    }while(number != 0);
    
    return(0);
    
}