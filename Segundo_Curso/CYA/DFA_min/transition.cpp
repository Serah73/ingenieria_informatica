/*
 * transition.cpp
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
 */

#include "transition.h"

transition_t::transition_t():
symbol_(' '),
next_(0)
{}

transition_t::transition_t(char a, int n):
symbol_(a),
next_(n)
{}

transition_t::transition_t(const transition_t &tr):
symbol_(tr.symbol_),
next_(tr.next_)
{}

transition_t::~transition_t()
{}

char transition_t::get_symbol() const
{
	return symbol_;
}
char transition_t::get_symbol()
{
	return symbol_;
}
int transition_t::get_next() const
{
	return next_;
}
int transition_t::get_next()
{
	return next_;
}

void transition_t::set_symbol( char symbol )
{
	symbol_ = symbol;
}

void transition_t::set_next( int next )
{
	next_ = next;
}
std::ostream &operator<<(std::ostream &os, const transition_t& transition)
{
    os << transition.get_symbol() << " " << transition.get_next() << " ";
    return os;
}
