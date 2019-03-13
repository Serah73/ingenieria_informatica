//Created by Jose Ramon Rodriguez Hernandez
//User: Serah
//Year: 2018

#include <iostream>
#include <algorithm>

#include "nfa.h"


int main(void)
{
	Nfa_t d;
	
	d.menu();

	std::set<char> setty = d.get_alphabet();

	std::cout << "alphabet: \n";

	for ( std::set<char>::iterator it = setty.begin(); it != setty.end(); it++)
		std::cout << *it << ", ";

	std::cout << "\n";	

	return 0;
}
