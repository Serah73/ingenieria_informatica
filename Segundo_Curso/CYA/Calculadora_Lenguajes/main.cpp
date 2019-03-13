//Created by Jose Ramon Rodriguez Hernandez
//User: Serah
//Year: 2018

#include <iostream>
#include <algorithm>

#include "calculator.h"
#include "language.h"
#include "symbols.h"


int main(void)
{
	/*language_t l;
	std::string next;

	std::cout << "epa\n";
	std::getline(std::cin, next);
	l(next);

	std::cout << "Prueba:\n";
	std::cout << l;
*/
	calculator_t cal;
	cal.menu();

	return 0;
}
