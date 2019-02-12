#include "grid.h"

grid_t::grid_t(){
	width_ = 0;
	height_ = 0;
	grid_ = std::vector< std::vector<int> > (); 
}

grid_t::grid_t(int height, int width)
{
	resize(height, width);
}

grid_t::grid_t(int height, int width, int colour)
{
	resize(height, width, colour);
}


grid_t::grid_t(const grid_t &grid):
grid_(grid.grid_),
height_(grid.height_),
width_(grid.width_)
{}



grid_t::~grid_t()
{}


int grid_t::get_height(void)
{
	return height_;
}

int grid_t::get_width(void)
{
	return width_;
}


int grid_t::get(int x, int y)
{
	return grid_[x][y];
}

void grid_t::set(int x, int y, int colour)
{
	grid_[x][y] = colour;
}

void grid_t::resize(int height, int width)
{
	width_ = width;
	height_ = height;
	grid_.resize(width);
	
	for(int i = 0; i < width; i++){
		grid_[i].resize(height);
	}
	
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			grid_[i][j] = 0;
}

void grid_t::resize(int height, int width, int colour)
{
	width_ = width;
	height_ = height;
	grid_.resize(width);
	
	for(int i = 0; i < width; i++){
		grid_[i].resize(height);
	}
	
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			grid_[i][j] = colour;
}
//modificar el write

void grid_t::write(void)
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


