#pragma once

#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "ant.h"
#include "grid.h"

class machine_t
{
	private:

		ant_t hormiga_;
		grid_t rejilla_;

	public:
		
		machine_t(ant_t hormiga, grid_t rejilla);
		~machine_t();

		void walk(void);

		void write(void);
};