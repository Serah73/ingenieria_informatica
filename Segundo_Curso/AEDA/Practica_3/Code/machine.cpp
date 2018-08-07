#include "machine.h"
/*
machine_t::machine_t(ant_t hormiga, grid_t rejilla)
{
	hormiga_ = hormiga;
	rejilla_ = rejilla;
}*/

machine_t::machine_t(grid_t rejilla)
{
	build();
	rejilla_ = rejilla;
}

machine_t::~machine_t()
{
	hormiga_.clear();
}


void machine_t::build(void)
{
	hormiga_.push_back(new antb_t(10, 20, '>', 4));
	hormiga_.push_back(new anto_t(20, 10, '^', 1));
	hormiga_.push_back(new antx_t(18, 20, '<', 2));
	hormiga_.push_back(new antr_t(40, 30, 'v', 3));
}


void machine_t::walk(void)
{
	stop(25, 25);
	stop(25, 26);
	stop(25, 27);
	int colorDummy = 0;
	while(!overflo())
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n";
		
		for(int i = 0; i < hormiga_.size(); i++)
		{
			colorDummy = hormiga_[i]->move(rejilla_.get(hormiga_[i]->get_x(), hormiga_[i]->get_y()));
			if(!overflo())
				rejilla_.set(hormiga_[i]->get_x(), hormiga_[i]->get_y(), colorDummy);
		}
		write();
		usleep(250000);
	}
	std::cout << "Fin de ejecucion" << std::endl;
}

bool machine_t::overflo(void)
{
	int i = 0;
	bool overflow = false;
	
	while((i < hormiga_.size()) && (!overflow))
	{
		if((hormiga_[i]->get_x() > 0) && (hormiga_[i]->get_x() < rejilla_.get_width()) && (hormiga_[i]->get_y() > 0) && (hormiga_[i]->get_y() < rejilla_.get_height()))
		{
			overflow = false;
			i++;
		}
		else
			overflow = true;
	}
	return overflow;
}


void machine_t::write(void)
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	
	for(int i = 0; i < rejilla_.get_height(); i++) 
	{
		for(int j = 0; j < rejilla_.get_width(); j++) 
		{
			char casilla = 'P';
			for(int k = 0; k < hormiga_.size(); k++)					//// 1-No, 2-Si
			{
				if((hormiga_[k]->get_x() == i) && (hormiga_[k]->get_y() == j))
					casilla = hormiga_[k]->get_way();
				else if (casilla == 'P')
				{
					switch(rejilla_.get(i, j)) 
					{
						case 0://blanco
							casilla = ' ';
							break;

						case 1://oscuro
							casilla = 'o';
							break;
	
						case 2://X
							casilla = 'x';
							break;

						case 3://rojo
							casilla = 'r';
							break;
							
						case 4://blanco hormiga
							casilla = 'u';
							break;
						
						case 9://bloque
							casilla = 'B';
					}
				}
			}
		std::cout << casilla << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------" << std::endl;
}


void machine_t::stop(int x, int y)
{
	rejilla_.set(x, y, 9);
}