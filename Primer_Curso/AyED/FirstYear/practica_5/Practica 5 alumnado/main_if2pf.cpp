#include <cstdio>
#include <iostream>

#include "stack/stack_l_t.hpp"
#include "if2pf/if2pf_t.hpp"

using namespace std;
using namespace AED;

typedef stack_l_t<int> stack_lista;  

int main(void)
{
	if2pf_t<stack_lista> if2pf;
	if2pf.compute(cin,cout);

	return 0;
}
