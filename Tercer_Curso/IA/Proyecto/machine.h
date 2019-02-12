#pragma once

#include "car.hpp"
#include "grid.h"
#include "termcolor.hpp"

#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <random>  // para generar de forma aleatoria (uniform_real_distribution) y (default_random_engine )r
#include <utility> // para los pares
#include <vector>  // para los array que contiene el conjunto de puntos que recibirá el método manual_obstacles
#include <thread>       
#include <chrono> 

class machine_t
{
	private:
		car_t coche_;
		grid_t rejilla_;

	public:
		
		machine_t(car_t car, grid_t rejilla);
		~machine_t();
		
		void start(void);
		
		void random_obstacles(int cantidad);    	// aleatorio si recibe un numero entero	
		void random_obstacles(float porcentaje); 	// aleatorio si recibe un número decimal
		void manual_obstacles(int opcion);			//pedimos que quiere insertar y la cantidad(main) y llamamos a manual para ver donde los quiere
		
		void eyecar();
		
		void write(void);
};