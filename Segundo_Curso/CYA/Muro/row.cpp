/*
 * row.cpp
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */

#include "row.h"

row_t::row_t():
row_(0)
{}

row_t::row_t(std::vector<int> brick )
{
	row_.clear();
	int size_aux = brick.size();

	for ( int i = 0; i < size_aux; i++ )
	{
		brick_t aux;
		aux.set(brick[i]);
		row_.push_back(aux);
	}
}

row_t::~row_t() {}

int row_t::get_size()
{
	return row_.size();
}

int row_t::get_val(int inx)
{
	return row_[inx].get();
}

void row_t::push_back(brick_t a)
{
	row_.push_back(a);
}


std::ostream &operator<<(std::ostream &os, row_t& row)
{
	brick_t brick;

	for ( int i = 0; i < row.get_size(); i++)
	{
		brick = row.get_val(i);
		os << "|" << brick;
	}

	os << "|";
	return os;
}
