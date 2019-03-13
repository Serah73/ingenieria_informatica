/*
 * transition.h
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
 */

/** @file transition.h
 *  @brief Clase transition_t encargada de manejar los posibles recorridos
 * 	de un state_t.
 *
 *  Contiene los metodos para manejar que simbolo va a consumir para
 *  ir a otro state_t
 *
 *  @author Jose Ramon Rodriguez Hernandez
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

	void set_symbol( char );
	void set_next( int );

};

std::ostream &operator<<(std::ostream &os, const transition_t& transition);

#endif /* TRANSITION_H_ */
