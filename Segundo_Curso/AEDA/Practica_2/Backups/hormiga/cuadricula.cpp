#include "cuadricula.hpp"

cuadricula::cuadricula(int width, int height) {
	width_ = width;
	height_ = height;
	grid_ = new vector(0);
	for(int i = 0; i < height; i++) 
		grid_.add(new vector(width));
}

cuadricula::~cuadricula() {
	width_ = 0;
	height_ = 0;
	while(grid_.size() > 0) {
		while(grid_[0].size() > 0) {
			grid_[0].erase(0);
		}
		grid_.erase(0);
	}
	delete grid_;
}

int cuadricula::get(int x, int y) {
	return grid_[x][y];
}

void cuadricula::set(int x, int y, int colour) {
	grid_[x][y] = colour;
}


