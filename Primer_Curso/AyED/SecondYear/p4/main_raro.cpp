#include <cstudio>
#include <iostream>

#include "stack_v_t.hpp"


bool equilibrada(const char* cadena)
{
    bool equi = true;
    int i=0;
    
    while((cadena[i] != '\0')&& (equi))
    {
        if(cadena[i] == '(')
            pila.push(0);
        else{
            if(cadena[i] == ')')
                if(pila.empty())
                    equi = false;
                else
                    pila.pop();
        }
    }
}



















/*tenemos que mirar una cadena y ver que los '(' y ')' esten en equilibrio ves ( y lo metes en la pila pero si ves un ) sacas el ( de la pila
si la pila esta vacia, tiene equilibrio si no pues no.
NOTA antes de sacar preguntar si esta vacia
*/
