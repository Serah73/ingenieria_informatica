#include "antx.h"


antx_t::antx_t(int x, int y, char way, int colour)
{
    set_x(x);
    set_y(y);
    set_way(way);
    colorX_ = colour;
}
    
antx_t::~antx_t(){}

////////////////////////////////////////////////////////////////////////////////

int antx_t::get(void)
{
    return colorX_;
}

int antx_t::move(int color)
{
    if(color != 9)
    {
    switch(color)
    {
        case 0:
            switch(get_way())
            {
                case '^':
                    right();
                    break;

                case '<':    
                    down();
                    break;

                case '>':    
                    down();
                    break;
                
                case 'v':    
                    right();
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
                    up();
                    break;

                case '>':    
                    up();
                    break;
                
                case 'v':    
                    left();
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
                    down();
                    break;

                case '>':    
                    down();
                    break;
                
                case 'v':    
                    right();
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
                    left();
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
                    down();
                    break;

                case '>':    
                    down();
                    break;
                
                case 'v':    
                    right();
                    break;
            }
            break;
    
       

    }//switch
    return get();
    }//if
    if(color == 9)
    {
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
        return color;
    }
}