#include "ant.h"
#pragma once

class antr_t:public ant_t
{
    private:
    
        int colorX_;
        
    public:
        
        antr_t(int x, int y, char way, int colour);
        virtual ~antr_t();
        
        int get(void);
        
        int move(int color);
};