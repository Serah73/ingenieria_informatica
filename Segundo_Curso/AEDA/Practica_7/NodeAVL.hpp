#pragma once

#include <iostream>
#include <stdlib.h>

template<class T>
class node_AVL 
{
    public:

        T dato;
        T clave;
        int bal;

        node_AVL<T>* izq;
        node_AVL<T>* der;
        node_AVL(T d, T c): dato(d), clave(c), bal(0), izq(NULL), der(NULL){};
};
