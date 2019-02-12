#include "ant.h"


ant_t::ant_t():
x_(0),
y_(0),
way_(' ')
{}


ant_t::ant_t(int x, int y, char way)
{
	x_ = x;
	y_ = y;
	way_ = way;
}


ant_t::ant_t(int x, int y)
{
	x_ = x;
	y_ = y;
	way_ = '^';
}


ant_t::ant_t(const ant_t &ant):
x_(ant.x_),
y_(ant.y_),
way_(ant.way_)
{}


ant_t::~ant_t()
{}

////////////////////////////////////////////////////////////////////////////////
int ant_t::get_x(void)
{
	return x_;
}


int ant_t::get_y(void)
{
	return y_;
}


char ant_t::get_way(void)
{
    return way_;
}

////////////////////////////////////////////////////////////////////////////////
void ant_t::set_x(int x)
{
	x_ = x;
}


void ant_t::set_y(int y)
{
	y_ = y;
}


void ant_t::set_way(char way)
{
	way_ = way;
}


////////////////////////////////////////////////////////////////////////////////


void ant_t::right(void)
{
	set_x(get_x() + 1);
	set_way('>');	
}


void ant_t::left(void)
{
	set_x(get_x() - 1);
	set_way('<');
}


void ant_t::up(void)
{
	set_y(get_y() - 1);
	set_way('^');
}


void ant_t::down(void)
{
	set_y(get_y() + 1);
	set_way('v');	
}


int ant_t::move(int color)
{
	switch (way_)
	{
		case '^':	//arriba
			switch (color)
			{
				case 0:/*
					rejilla.set(get_x(), get_y(), 1);*/
					left();
					return 1;
					break;
				case 1:/*
					rejilla.set(get_x(), get_y(), 0);*/
					right();
					return 0;
					break;
				default:
					std::cout << "error en el color de la rejilla en la hormiga" << std::endl;
					break;
			}
			break;
		case '<':	//izquierda
			switch (color)
			{
				case 0:
					//rejilla.set(get_x(), get_y(), 1);
					down();
					return 1;
					break;
				case 1:
					//rejilla.set(get_x(), get_y(), 0);
					up();
					return 0;
					break;
				default:
					std::cout << "error en el color de la rejilla en la hormiga" << std::endl;
					break;
			}
			break;
		case '>':	//derecha
			switch (color)
			{
				case 0:
					//rejilla.set(get_x(), get_y(), 1);
					up();
					return 1;
					break;
				case 1:
					//rejilla.set(get_x(), get_y(), 0);
					down();
					return 0;
					break;
				default:
					std::cout << "error en el color de la rejilla en la hormiga" << std::endl;
					break;
			}
			break;
		case 'v':	//abajo
			switch (color)
			{
				case 0:
					//rejilla.set(get_x(), get_y(), 1);
					right();
					return 1;
					break;
				case 1:
					//rejilla.set(get_x(), get_y(), 0);
					left();
					return 0;
					break;
				default:
					std::cout << "error en el color de la rejilla en la hormiga" << std::endl;
					break;
			}
			break;
		default:
			std::cout << "orientacion no recogida" << std::endl;
			break;
	}
}