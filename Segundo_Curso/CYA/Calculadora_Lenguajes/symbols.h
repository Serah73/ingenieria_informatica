/*
 * symbols.h
 *
 *  Created on: 10 nov. 2018
 *      Author: Serah
 */

#ifndef SYMBOLS_H_
#define SYMBOLS_H_

#include <iostream>
#include <ostream>
#include <string>



class symbols_t
{
private:
	std::string symbol_;


public:
	symbols_t();
	symbols_t(std::string symbol);
	symbols_t(const symbols_t &symbol);

	virtual ~symbols_t();

	void set_symbol(std::string symbol);
	std::string get_symbol();
	std::string get_symbol() const;

	std::string add_symbol(symbols_t &a, symbols_t &b);

	symbols_t &operator=(const symbols_t &symbol);
	bool operator<(const symbols_t &symbol) const;
	bool operator==(const symbols_t &symbol) const;
	symbols_t& operator+(const symbols_t &symbol);
};

std::ostream& operator<<(std::ostream &os, const symbols_t& symbol);

#endif /* SYMBOLS_H_ */
