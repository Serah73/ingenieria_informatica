/*
 * transition.h
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

#pragma once

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class transition_t {
private:

	char symbol_;
	int next_;

public:

	transition_t();
	transition_t(char a, int n);
	transition_t(const transition_t &tr);
	virtual ~transition_t();

	char get_symbol() const;
	char get_symbol();
	int get_next() const;
	int get_next();

//	bool operator==(std::string);
//	transition_t operator=(const transition_t &tr);


};

std::ostream &operator<<(std::ostream &os, const transition_t& transition);

#endif /* TRANSITION_H_ */
