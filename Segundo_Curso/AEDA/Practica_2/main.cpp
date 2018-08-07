#include <iostream>
#include "machine.h"
#include "ant.h"
#include "grid.h"


int main(void)
{
	ant_t hormi(10, 10, '<');
	grid_t grid(20, 20, 0);
	machine_t M(hormi, grid);

	M.walk();
}