/*
 * brick.cpp
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */

#include "brick.h"

brick_t::brick_t():
width_(0)
{}

brick_t::brick_t(int width):
width_(width)
{}

brick_t::~brick_t() {}

int brick_t::get()
{
	return width_;
}

void brick_t::set(int width)
{
	width_ = width;
}
std::ostream &operator<<(std::ostream &os, brick_t& brick)
{
	for ( int i = 0; i < brick.get(); i++)
			os << 'X';
	return os;
}
