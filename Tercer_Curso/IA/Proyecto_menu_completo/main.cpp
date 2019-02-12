#include <iostream>
#include "machine.h"
#include "car.hpp"
#include "grid.h"
#include <ctime>
#include <fstream>



int main(void)  //main test
{

    int malla, obstaculos, opcion;
    
    do
    {
        obstaculos = 0;
        malla = 0;
        system("clear");
        std::cout << "\n\n-------------------------------------------------------------" << std::endl;
        std::cout << "\tBienvenido a la práctica de heurística" << std::endl;
        std::cout << "-------------------------------------------------------------\n" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "\tDispone de las siguientes opciones: " << std::endl;
        std::cout << "---------------------------------------------------\n" << std::endl;
        std::cout << "1 -\tCasos Predefinidos\n2 -\tManual\n3 -\tFichero\n0 -\tExit" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "\tOpcion: ";
        std::cin >> opcion;
        std::cout << "\n";
        std::cout << "--------------------------------" << std::endl;
        
        if(opcion == 1)
        {
            do
            {
                
                std::cout << "--------------------------------" << std::endl;
                std::cout << "\tTipo de malla " << std::endl;
                std::cout << "--------------------------------\n" << std::endl;
                std::cout << "1 -\t20  x 20\n2 -\t30  x 30\n3 -\t50  x 50\n4 -\t100 x 100\n0 -\tExit" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "\tOpcion: ";
                
                std::cin >> malla;
                std::cout << "\n";
                std::cout << "--------------------------------" << std::endl;
                
                if(malla == 1)
                {
                    std::cout << "Porcentaje de obstaculos: " << std::endl;
                    std::cout << "1 -\t20%\n2 -\t30%\n3 -\t40%" << std::endl;
                    std::cout << "--------------------------------" << std::endl;
                    std::cin >> obstaculos;
                    grid_t grid(20,20);
                    if(obstaculos == 1 || obstaculos == 2)
                    {
                        car_t car(0,0);
                        car.set_destiny(12, 7);
                        machine_t motor(car, grid);
                        if(obstaculos == 1)
                            motor.random_obstacles(0.2f);
                        if(obstaculos == 2)
                            motor.random_obstacles(0.3f);
                        if(obstaculos == 3)
                            motor.random_obstacles(0.4f);
                        clock_t reloj;
                        reloj = std::clock();
                        motor.start();
                        double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                        motor.write();
                        std::cout << "-------------------------------------------------------------" << std::endl;
                        std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                        std::cout << "-------------------------------------------------------------\n" << std::endl;
                        std::cout << "\tPulse enter para continuar..." << std::endl;
                        std::cin.ignore();
                        std::cin.ignore();
                    }
                    if(obstaculos == 3)
                    {
                        car_t car(2,1);
                        car.set_destiny(10, 6); 
                        machine_t motor(car, grid);
                        if(obstaculos == 1)
                            motor.random_obstacles(0.2f);
                        if(obstaculos == 2)
                            motor.random_obstacles(0.3f);
                        if(obstaculos == 3)
                            motor.random_obstacles(0.4f);
                        clock_t reloj;
                        reloj = std::clock();
                        motor.start();
                        double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                        motor.write();
                        std::cout << "-------------------------------------------------------------" << std::endl;
                        std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                        std::cout << "-------------------------------------------------------------\n" << std::endl;
                        std::cout << "\tPulse enter para continuar..." << std::endl;
                        std::cin.ignore();
                        std::cin.ignore();
                    }
                }
                if(malla == 2)
                {
                    grid_t grid(30,30);
                    car_t car(3,3);
                    car.set_destiny(14, 13);
                    machine_t motor(car, grid);
                    std::cout << "Porcentaje de obstaculos: " << std::endl;
                    std::cout << "1- 20%\n2- 30%\n3- 40%" << std::endl;
                    std::cin >> obstaculos;
                    if(obstaculos == 1)
                        motor.random_obstacles(0.2f);
                    if(obstaculos == 2)
                        motor.random_obstacles(0.3f);
                    if(obstaculos == 3)
                        motor.random_obstacles(0.4f);
                    
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                    
                }
                if(malla == 3)
                {
                    grid_t grid(50,50);
                    car_t car(38,18);
                    car.set_destiny(27, 25);
                    machine_t motor(car, grid);
                    std::cout << "Porcentaje de obstaculos: " << std::endl;
                    std::cout << "1- 20%\n2- 30%\n3- 40%" << std::endl;
                    std::cin >> obstaculos;
                    if(obstaculos == 1)
                        motor.random_obstacles(0.2f);
                    if(obstaculos == 2)
                        motor.random_obstacles(0.3f);
                    if(obstaculos == 3)
                        motor.random_obstacles(0.4f);
                    
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                    
                }
                if(malla == 4)
                {
                    grid_t grid(100,100);
                    car_t car(14,18);
                    car.set_destiny(35, 29);
                    machine_t motor(car, grid);
                    std::cout << "Porcentaje de obstaculos: " << std::endl;
                    std::cout << "1- 20%\n2- 30%\n3- 40%" << std::endl;
                    std::cin >> obstaculos;
                    if(obstaculos == 1)
                        motor.random_obstacles(0.2f);
                    if(obstaculos == 2)
                        motor.random_obstacles(0.3f);
                    if(obstaculos == 3)
                        motor.random_obstacles(0.4f);
                    
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                    
                }
                if(malla != 1 && malla != 2 && malla != 3 && malla != 4 && malla != 0)
                    std::cout << "Introduzca una opción valida por favor" << std::endl;
            }while(malla != 0);
        }
        if(opcion == 2)
        {
            do
            {
                std::cout << "--------------------------------" << std::endl;
                std::cout << "\tTipo de malla " << std::endl;
                std::cout << "--------------------------------\n" << std::endl;
                std::cout << "1 -\t20  x 20\n2 -\t30  x 30\n3 -\t50  x 50\n4 -\t100 x 100\n0 -\tExit" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "\tOpcion: ";
                
                std::cin >> malla;
                std::cout << "\n";
                std::cout << "--------------------------------" << std::endl;
                
                
                if(malla == 1)
                {
                    grid_t grid(20,20);
                
                    int x,y;
                    std::cout << "Seleccione el origen: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x;
                    std::cout << "Y: ";
                    std::cin >> y;
                    
                    car_t car(x,y);
                    
                    int x_d, y_d;
                    std::cout << "Seleccione el destino: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x_d;
                    std::cout << "Y: ";
                    std::cin >> y_d;
                    
                    car.set_destiny(x_d,y_d);
                    machine_t motor(car,grid);
                    
                    int obstaculos_manual;
                    std::cout << "Numero de obstaculos: ";
                    std::cin >> obstaculos_manual;
                    
                    motor.random_obstacles(obstaculos_manual);
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                }
                if(malla == 2)
                {
                    grid_t grid(30,30);
                
                    int x,y;
                    std::cout << "Seleccione el origen: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x;
                    std::cout << "Y: ";
                    std::cin >> y;
                    
                    car_t car(x,y);
                    
                    int x_d, y_d;
                    std::cout << "Seleccione el destino: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x_d;
                    std::cout << "Y: ";
                    std::cin >> y_d;
                    
                    car.set_destiny(x_d,y_d);
                    machine_t motor(car,grid);
                    
                    int obstaculos_manual;
                    std::cout << "Numero de obstaculos: ";
                    std::cin >> obstaculos_manual;
                    
                    motor.random_obstacles(obstaculos_manual);
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                }
                if(malla == 3)
                {
                    grid_t grid(50,50);
                
                    int x,y;
                    std::cout << "Seleccione el origen: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x;
                    std::cout << "Y: ";
                    std::cin >> y;
                    
                    car_t car(x,y);
                    
                    int x_d, y_d;
                    std::cout << "Seleccione el destino: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x_d;
                    std::cout << "Y: ";
                    std::cin >> y_d;
                    
                    car.set_destiny(x_d,y_d);
                    machine_t motor(car,grid);
                    
                    int obstaculos_manual;
                    std::cout << "Numero de obstaculos: ";
                    std::cin >> obstaculos_manual;
                    
                    motor.random_obstacles(obstaculos_manual);
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                }
                if(malla == 4)
                {
                    grid_t grid(100,100);
                
                    int x,y;
                    std::cout << "Seleccione el origen: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x;
                    std::cout << "Y: ";
                    std::cin >> y;
                    
                    car_t car(x,y);
                    
                    int x_d, y_d;
                    std::cout << "Seleccione el destino: " << std::endl;
                    std::cout << "X: ";
                    std::cin >> x_d;
                    std::cout << "Y: ";
                    std::cin >> y_d;
                    
                    car.set_destiny(x_d,y_d);
                    machine_t motor(car,grid);
                    
                    int obstaculos_manual;
                    std::cout << "Numero de obstaculos: ";
                    std::cin >> obstaculos_manual;
                    
                    motor.random_obstacles(obstaculos_manual);
                    clock_t reloj;
                    reloj = std::clock();
                    motor.start();
                    double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                    motor.write();
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                    std::cout << "-------------------------------------------------------------\n" << std::endl;
                    std::cout << "\tPulse enter para continuar..." << std::endl;
                    std::cin.ignore();
                    std::cin.ignore();
                }
                if(malla != 1 && malla != 2 && malla != 3 && malla != 4 && malla != 0)
                    std::cout << "Introduzca una opción valida por favor" << std::endl;
            }while(malla != 0);
                
        }
        if(opcion == 3)
        {
            car_t car;
            grid_t grid;
            std::filebuf fb;
            if(fb.open("datos.txt",std::ios::in))
            {
                std::iostream is(&fb);
                grid.read(is);
                car.set_destiny(12,12);
                machine_t motor(car,grid);
                clock_t reloj;
                reloj = std::clock();
                motor.start();
                double reloj_final = (std::clock() - reloj) / (double) CLOCKS_PER_SEC;
                motor.write();
                std::cout << "-------------------------------------------------------------" << std::endl;
                std::cout << "Tiempo de calculo: " << reloj_final << std::endl;
                std::cout << "-------------------------------------------------------------\n" << std::endl;
                std::cout << "\tPulse enter para continuar..." << std::endl;
                std::cin.ignore();
                std::cin.ignore();
                fb.close();
            }
        }
                
    }while(opcion != 0);
}
