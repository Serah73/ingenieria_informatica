#include "ant.h"
#pragma once

class antx_t:public ant_t
{
    private:
    
        int colorX_;
        
    public:
        
        antx_t(int x, int y, char way, int colour);
        virtual ~antx_t();
        
        int get(void);
        
        int move(int color);
};