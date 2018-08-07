#pragma once

#include <iostream>
#include "grid.h"

class ant_t
{
	private:

		int x_;
		int y_;
		char way_;

	public:
		
		ant_t();
		ant_t(int x, int y, char way);
		ant_t(int x, int y);
		ant_t(const ant_t &ant);
		virtual ~ant_t();
		
		int get_x(void);
		int get_y(void);
		char get_way(void);
		
		void set_x(int x);
		void set_y(int y);
		void set_way(char way);
		
		int changecolour(int color);
		
		void right(void);
		void left(void);
		void up(void);
		void down(void);

		virtual int move(int color);
};

