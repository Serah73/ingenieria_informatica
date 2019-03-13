//Created by Jose Ramon Rodriguez Hernandez
//User: Serah
//Year: 2018

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "wall.h"



int main(void)
{
	double time = 0;
	system("clear");
	wall_t muro;

	muro.print_data();

	clock_t start = std::clock();

	muro.start();

	time = (std::clock() - start) /(double) CLOCKS_PER_SEC;
	std::cout << "\nTiempo que ha tardado:  " << time << "\n";
	return 0;
}
