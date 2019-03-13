/*
 * symbols_t.cpp
 *
 *  Created on: 10 nov. 2018
 *      Author: Serah
 */

#include "symbols.h"

symbols_t::symbols_t()
{}

symbols_t::symbols_t(std::string symbol):
symbol_(symbol)
{}

symbols_t::symbols_t(const symbols_t &symbol):
symbol_(symbol.symbol_)
{}

symbols_t::~symbols_t()
{}

void symbols_t::set_symbol(std::string symbol)
{
	symbol_ = symbol;
}

std::string symbols_t::get_symbol()
{
	return symbol_;
}

std::string symbols_t::get_symbol() const
{
	return symbol_;
}

std::string add_symbol(symbols_t &a, symbols_t &b)
{
	std::string aux;	
	aux = a.get_symbol() + b.get_symbol();
	
	return aux;
}


//////////////OPERATOR/////////////////
symbols_t& symbols_t::operator=(const symbols_t &symbol)
{
	this->symbol_ = symbol.symbol_;

	return *this;
}

bool symbols_t::operator<(const symbols_t &symbol) const
{
    if( this->symbol_ < symbol.symbol_)	return true;

    return false;
}

bool symbols_t::operator==(const symbols_t &symbol) const
{
	if( this->symbol_ == symbol.symbol_) return true;

	return false;
}

symbols_t& symbols_t::operator+(const symbols_t &a)
{
	this->symbol_ = this->get_symbol() + a.get_symbol();
	
	return *this;
}

std::ostream& operator<<(std::ostream &os,const symbols_t& symbol)
{
	os << symbol.get_symbol();

	return os;
}

