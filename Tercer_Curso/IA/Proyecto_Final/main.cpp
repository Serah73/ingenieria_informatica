#include <iostream>
#include "machine.h"
#include "car.hpp"
#include "grid.h"
#include <ctime>

void continuar()
{
    std::cout << "Pulse enter para continuar..." << std::endl;
    std::cin.ignore();

    system("clear");
}

int main(void)  //main test
{
    system("clear");
    
    clock_t reloj;
    reloj = std::clock();
    
//////////////////////////////////////////////////////////////
/////////   20  x   20  //////////////
//20x20 -> (0,0)org / (12,7)dest
    system("clear");
    std::cout << "\t --- 20 x 20 ---" << std::endl;
   
    grid_t grid(20, 20);
    car_t car(0,0);
    car.set_destiny(12, 7);
   

    machine_t motor(car, grid);
    motor.random_obstacles(0.2f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 20x20 al 20%" << std::endl;
    std::cin.ignore();

    
    motor.write();
    continuar();
    
///////////////////////////////////////////////// 
//20x20 -> (0,0)org / (12,7)dest
    std::cout << "\t --- 20 x 20 ---" << std::endl;
    
    grid(20, 20);
    car(0,0);
    car.set_destiny(12, 7);
   

    motor(car, grid);
    motor.random_obstacles(0.3f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 20x20 al 30%" << std::endl;
    std::cin.ignore();

    
    motor.write();
    continuar();
 

    
/////////////////////////////////////////////////   
//20x20 -> (2,1)org / (10,6)dest
    std::cout << "\t --- 20 x 20 ---" << std::endl;
    
    grid(20, 20);
    car(2,1);
    car.set_destiny(10, 6);
   

    motor(car, grid);
    motor.random_obstacles(0.3f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 20x20 al 40%" << std::endl;
    std::cin.ignore();

    
    motor.write();
    continuar();
    
    
//////////////////////////////////////////////////////////////
/////////   30  x   30  //////////////
//30x30 -> (3,3)org / (14,13)dest    

    std::cout << "\t --- 30 x 30 ---" << std::endl;
    
    grid(30,30);
    car(3,3);
    car.set_destiny(14, 13);
   

    motor(car, grid);
    motor.random_obstacles(0.2f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 30x30 al 20%" << std::endl;
    std::cin.ignore();

    
    motor.write();
    continuar();
    
/////////////////////////////////////////////////
//30x30 -> (3,3)org / (14,13)dest    
    std::cout << "\t --- 30 x 30 ---" << std::endl;

    grid(30,30);
    car(3,3);
    car.set_destiny(14, 13);
   

    motor(car, grid);
    motor.random_obstacles(0.3f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 30x30 al 30%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();

/////////////////////////////////////////////////
//30x30 -> (3,3)org / (14,13)dest    
    std::cout << "\t --- 30 x 30 ---" << std::endl;

    grid(30,30);
    car(3,3);
    car.set_destiny(14, 13);
   

    motor(car, grid);
    motor.random_obstacles(0.4f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 30x30 al 40%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();
    
    
//////////////////////////////////////////////////////////////   
/////////   50  x   50  //////////////
//50x50 -> (38,18)org / (27,25)dest  
    std::cout << "\t --- 50 x 50 ---" << std::endl;

    grid(50,50);
    car(38,18);
    car.set_destiny(27, 25);
   

    motor(car, grid);
    motor.random_obstacles(0.2f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 50x50 al 20%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();
    
/////////////////////////////////////////////////  
//50x50 -> (38,18)org / (27,25)dest    
    std::cout << "\t --- 50 x 50 ---" << std::endl;
    
    grid(50,50);
    car(38,18);
    car.set_destiny(27, 25);
   

    motor(car, grid);
    motor.random_obstacles(0.3f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 50x50 al 30%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();

///////////////////////////////////////////////// 
//50x50 -> (38,18)org / (27,25)dest     
    std::cout << "\t --- 50 x 50 ---" << std::endl;
    
    grid(50,50);
    car(38,18);
    car.set_destiny(27, 25);
   

    motor(car, grid);
    motor.random_obstacles(0.4f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 50x50 al 40%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();
    
//////////////////////////////////////////////////////////////
/////////   100  x   100  //////////////
//100x100 -> (14,18)org / (35,29)dest  
    std::cout << "\t --- 50 x 50 ---" << std::endl;

    grid(100,100);
    car(14,18);
    car.set_destiny(35, 29);
   

    motor(car, grid);
    motor.random_obstacles(0.2f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 100x100 al 20%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();
    
/////////////////////////////////////////////////
//100x100 -> (14,18)org / (35,29)dest    
    std::cout << "\t --- 50 x 50 ---" << std::endl;
    
    grid(100,100);
    car(14,18);
    car.set_destiny(35, 29);
    

    motor(car, grid);
    motor.random_obstacles(0.3f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 100x100 al 30%" << std::endl;
    std::cin.ignore();
    
    motor.write();
    continuar();

/////////////////////////////////////////////////
//100x100 -> (14,18)org / (35,29)dest    
    std::cout << "\t --- 50 x 50 ---" << std::endl;
    
    grid(100,100);
    car(14,18);
    car.set_destiny(35, 29); 

    motor(car, grid);
    motor.random_obstacles(0.4f);

    //inicio de machine
    motor.start();
    
    std::cout << "Pulse enter para visualizar la malla 100x100 al 40%" << std::endl;
    std::cin.ignore();

    
    motor.write();
    continuar();
    
    
    
    
    
    
    
    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
    
    //acaba machine y lo imprimimos
    motor.write();
    
    std::cout << "\nTiempo de calculo: " << reloj_final << std::endl;



}

 //grid.read(std::cin);