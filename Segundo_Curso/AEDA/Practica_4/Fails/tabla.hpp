#pragma once

#include <iostrean>
#include <vector>
#include "celda.cpp"
#include "clave.hpp"


class tabla_t
{
    private:
        
        vector<clave> vcelda_;       //contiene nceldas que le llegan por el constructor
        
    public:
        
        bool buscar(clave x);
        bool insertar(clave x);
        int fDispersion(clave x);
        int fExploracion(clave x, int i);
};