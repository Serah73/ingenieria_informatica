#include "antr.h"


antr_t::antr_t(int x, int y, char way, int colour)
{
    set_x(x);
    set_y(y);
    set_way(way);
    colorX_ = colour;
}
    
antr_t::~antr_t(){}

////////////////////////////////////////////////////////////////////////////////

int antr_t::get(void)
{
    return colorX_;
}

int antr_t::move(int color)
{
    bool bloque = false;
    switch(color)
    {
        case 0:
            switch(get_way())
            {
                case '^':
                    right();
                    break;
                
                case '<':    
                    up();
                    break;
            
                case '>':
                    down();
                    break;
                
                case 'v':
                    left();
                    break;
            }
            break;
            
        case 1:
            switch(get_way())
            {
                case '^':
                    left();
                    break;
            
                case '<':    
                    down();
                    break;
            
                case '>':    
                    up();
                    break;
                
                case 'v':    
                    right();
                    break;
            }
            break;
        
        case 2:
            switch(get_way())
            {
                case '^':
                    right();
                    break;

                case '<':    
                    up();
                    break;

                case '>':    
                    down();
                    break;
                
                case 'v':    
                    left();
                    break;
            }
            break;
            
        case 3:
            switch(get_way())
            {
                case '^':
                    left();
                    break;

                case '<':    
                    up();
                    break;

                case '>':    
                    up();
                    break;
                
                case 'v':    
                    right();
                    break;
            }
            break;
        
        case 4:
            switch(get_way())
            {
                case '^':
                    right();
                    break;

                case '<':    
                    up();
                    break;

                case '>':    
                    down();
                    break;
                
                case 'v':    
                    left();
                    break;
            }
            break;
            
        case 9:
            switch(get_way())
            {
                case '^':
                    set_way('v');
                    break;
                case '<':
                    set_way('>');
                    break;
                case '>':
                    set_way('<');
                    break;
                case 'v':
                    set_way('^');
                    break;
            }
            bloque = true;
            break;
    }
    if (bloque) return 9;
    else return get();
}