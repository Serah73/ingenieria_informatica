#include "ant.h"
#pragma once

class anto_t:public ant_t
{
    private:
    
        int colorX_;
        
    public:
        
        anto_t(int x, int y, char way, int colour);
        virtual ~anto_t();
        
        int get(void);
        
        int move(int color);
};