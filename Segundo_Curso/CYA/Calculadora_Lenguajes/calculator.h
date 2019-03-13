/*
 * calculator.h
 *
 *  Created on: 12 nov. 2018
 *      Author: Serah
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#pragma once

#include <cstdlib>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <set>

#include "language.h"

class calculator_t
{
private:

	language_t language_;
	language_t language2_;

public:

	calculator_t();
	virtual ~calculator_t();

	void inverse();
	void inverse_aux(language_t language);
	
	void concatenation();
	symbols_t prueba_concatenacion(symbols_t a, symbols_t b);
	
	void unionl();
	void intersection();
	void diference();
	void sublanguage();
	void equality();
	void potency();
	void kleene(std::set<symbols_t> language);

	std::string request_language();
	void menu();
};

#endif /* CALCULATOR_H_ */
