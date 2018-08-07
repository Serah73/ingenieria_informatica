#pragma once

#include <iostream>

template<class T>
class node_abb
{
    public:

        T dato;
        T clave;
        node_abb<T>* izq;
        node_abb<T>* der;
        
        node_abb();
        node_abb(T data, T cl);
};

template<class T>
node_abb<T>::node_abb():
dato(0),
clave(0),
izq(NULL),
der(NULL){}

template<class T>
node_abb<T>::node_abb(T data, T cl):
dato(data),
clave(cl),
izq(NULL),
der(NULL){}
