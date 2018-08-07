//#include "lenguaje.hpp"
#include <stdio.h>
#include <iostream>



int main(void){
    
  //  lenguaje_t A;
  //  lenguaje_t B;
  //  lenguaje_t C;

    int number;

    do{
        std::cout << '\n';
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
		
		std::cout <<'\n'<< "Introduce una opción: ";
        std::cin >> number;
        std::cout<<'\n';
        
        switch(number){
            
            case 0:
                
                std::cout << "Cerrando.." << std::endl;
                break;
                
            case 1:
                
                std::cout << "Inversa" << std::endl;
                std::cout << "Definir el lenguaje: ";
                //scanf('\n');
              //  A.read(std::cin);
            //    C.inversa(A); 
              //  C.write(std::cout); 
                break;

            case 2:
                
                std::cout << "Concatenación" << std::endl;
                std::cout << "Definir el lenguaje: ";
                //scanf('\n');
            //    A.read(std::cin);
                std::cout << "Definir el lenguaje: ";
            //    B.read(std::cin);
           //    C.concatenacion(A, B); 
           //     C.write(std::cout); 
                break;
                
            case 3:
                
                std::cout << "union" << std::endl;
                std::cout << "Definir el lenguaje: ";
            //    scanf('\n');
           //     A.read(std::cin);
               std::cout << "Definir el lenguaje: ";
          //      B.read(std::cin);
           //     C.unir(A, B); 
          //      C.write(std::cout);
                break;
                
            case 4:
                
                std::cout << "interseccion" << std::endl;
                std::cout << "Definir el lenguaje: ";
           //     scanf('\n');
             //   A.read(std::cin);
                std::cout << "Definir el lenguaje: ";
          //      B.read(std::cin);
          //      C.interseccion(A, B); 
          //      C.write(std::cout); 
                break;
                
            case 5:
                
                std::cout << "diferencia" << std::endl;
                std::cout << "Definir el lenguaje: ";
          //      scanf('\n');
          //      A.read(std::cin);
                std::cout << "Definir el lenguaje: ";
          //      B.read(std::cin);
          //      C.diferencia(A, B); 
         //       C.write(std::cout); 
                break;
                
            case 6:
                
                std::cout << "sublenguaje" << std::endl;
                std::cout << "Definir el lenguaje: ";
         //       scanf('\n');
         //       A.read(std::cin);
        //        A.sublenguajes(); 
                break;
                
            case 7:
                
                std::cout << "igualdad de lenguajes" << std::endl;
                std::cout << "Definir el lenguaje: ";
           //     scanf('\n');
             //   A.read(std::cin);
                std::cout << "Definir el lenguaje: ";
              //  B.read(std::cin);
        //        if(A.igualdad(B)) 
          //          std::cout << "Son iguales" << std::endl;
            //    else
              //      std::cout << "No son iguales" << std::endl;
                break;
                
            case 8:
                
                std::cout << "potencia" << std::endl;
                std::cout << "Definir el lenguaje: ";
    //            scanf('\n');
      //          A.read(std::cin);
                std::cout << "Potencia: ";
                int n;
                std::cin >> n;
        //        C.potencia(A, n); 
          //      C.write(std::cout);
                break;
                
            case 9:
                
                std::cout << "cierre de kleene" << std::endl;
                std::cout << "Definir el lenguaje: ";
              //  scanf('\n');
              //  A.read(std::cin);
            //    C.kleene(A);  
          //      C.write(std::cout); 
                break;
            default: std::cout<<"No introdujo una opcion valida"<<std::endl;
                
        }
     //   A.clear();
    //    B.clear();
//        C.clear();
        
    }while(number);  
}