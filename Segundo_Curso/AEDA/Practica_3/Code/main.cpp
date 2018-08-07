#include <iostream>
#include "machine.h"
#include "ant.h"
#include "grid.h"
#include "antx.h"
#include "antb.h"
#include "anto.h"
#include "antr.h"

int main(void)
{
	grid_t grid(50, 50, 0);
	machine_t M(grid);

	M.walk();
}