#pragma once

#include "car.hpp"
#include "grid.h"
#include "termcolor.hpp"

#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <random>  
#include <utility> 
#include <vector>  
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
		
		void random_obstacles(int cantidad);    
		void random_obstacles(float porcentaje); 	
		void manual_obstacles(int opcion);	
		
		void eyecar();
		
		void write(void);
};