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
/*
bool transition_t::operator==(std::string str)
{
	if ( this->symbol_ == str ) return true;

	else return false;
}

transition_t transition_t::operator=(const transition_t &tr)
{
	this->symbol_ = tr.symbol_;
	this->next_ = tr.next_;
	return *this;
}
*/
std::ostream &operator<<(std::ostream &os, const transition_t& transition)
{
    os << transition.get_symbol() << " " << transition.get_next() << " ";
    return os;
}
