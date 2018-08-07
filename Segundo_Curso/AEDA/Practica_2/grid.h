#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>


class grid_t
{
	private:

		std::vector<std::vector<int> > grid_;
		int height_;
		int width_;

	public:
		grid_t();
		grid_t(int x, int y);
		grid_t(int x, int y, int colour);
		grid_t(const grid_t &grid);
		~grid_t();

		int get_height(void);
		int get_width(void);
		
		int get(int x, int y);		//el color
		void set(int x, int y, int colour);
};