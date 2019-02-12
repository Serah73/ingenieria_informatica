#include "machine.h"

machine_t::machine_t(ant_t hormiga, grid_t rejilla)
{
	hormiga_ = hormiga;
	rejilla_ = rejilla;
}

machine_t::~machine_t()
{}


void machine_t::walk(void)
{
	int turn = 0;
	while((hormiga_.get_x() > 0) && (hormiga_.get_x() < rejilla_.get_width()) && (hormiga_.get_y() > 0) && (hormiga_.get_y() < rejilla_.get_height()))
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n";
		//system("clear"); //sugiero usar esto
		write();
		hormiga_.move(rejilla_);
		usleep(250000);
	}
}



void machine_t::write(void)
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	
	for(int i = 0; i < rejilla_.get_height(); i++) 
	{
		for(int j = 0; j < rejilla_.get_width(); j++) 
		{
			if((hormiga_.get_x() == i) && (hormiga_.get_y() == j))
				std::cout << hormiga_.get_way() << "  ";
			else
				switch(rejilla_.get(i, j)) 
				{
					case 0:
						std::cout << ' ' << "  ";
						break;
					case 1:
						std::cout << 'x' << "  ";
						break;
				}
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------" << std::endl;
}