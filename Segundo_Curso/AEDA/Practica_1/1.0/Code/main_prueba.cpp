#include "list_s.h"
#include "common_types.h"
#include <iostream>
#include <cstdio>


int main()
{
	std::cout << "ritooo"<< std::endl;
    lista_s list_a;
    TDATO a = 4;
    if (list_a.empty())
        std::cout << "vacia" << std::endl;
    else
        std::cout << " no vacia " << std::endl;
    
    list_a.insert_head(a);
    
    list_a.write(std::cout);
}

