#pragma once

#include "ant.h"
#include <iostream>

class car_t: public ant_t   ///si llega al fin de la cuadricula no puede hacer ese movimiento, esta prohibido.
{
    public:
        /*
        std::vector<int> north();
        std::vector<int> south();
        std::vector<int> west();
        std::vector<int> east();
        */
        int move(int colour);
};

//tamaño tope 600x128
//100x100 es aceptable

///meter obstaculos por ficheros, //estrella, informada, maybe.