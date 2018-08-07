#include "ant.h"
#pragma once

class antb_t:public ant_t
{
    private:
    
        int colorX_;
        
    public:
        
        antb_t(int x, int y, char way, int colour);
        virtual ~antb_t();
        
        int get(void);
        
        int move(int color);
};