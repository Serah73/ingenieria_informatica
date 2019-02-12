#include <iostream>
#include "machine.h"
#include "car.hpp"
#include "grid.h"



int main(void)  //main test
{

    
    grid_t grid(90,90);
    
    //car_t car(2,5);
    car_t car;
    
    //grid.read(std::cin);
    
    car.set_destiny(87, 28);
    
    //car.move(20, 20);
    
    machine_t motor(car, grid);
    motor.random_obstacles(0.5f);
    
    //inicio de machine
    motor.start();
    

    //acaba machine y lo imprimimos
    motor.write();





/*
 //   grid_t grid(20,20,0);
    grid_t grid(100,100,0);
    machine_t motor(car, grid);
   
    motor.random_obstacles(20);
    motor.write();
    std::cin.ignore();

    motor.random_obstacles(0.2f);
    motor.write();
    //std::cin.ignore();

    motor.manual_obstacles();
    motor.write();
    std::cin.ignore();    
  
    motor.manual_obstacles(2);
    motor.write();
    std::cin.ignore();
    
    
    
    //motor.write();
*/
    return 0;    
}