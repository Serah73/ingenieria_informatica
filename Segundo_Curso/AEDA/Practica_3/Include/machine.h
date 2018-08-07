#pragma once

#include <vector>
#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#include "ant.h"
#include "antx.h"
#include "antr.h"
#include "antb.h"
#include "anto.h"
#include "grid.h"

class machine_t
{
	private:

		std::vector<ant_t*> hormiga_;
		grid_t rejilla_;

	public:
		
		//machine_t(ant_t hormiga, grid_t rejilla);
		machine_t(grid_t rejilla);
		~machine_t();

		void build(void);

		void walk(void);
		bool overflo(void);

		void write(void);
};