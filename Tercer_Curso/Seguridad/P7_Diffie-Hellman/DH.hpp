#ifndef DH_T_
#define DH_T_

#include <iostream>
#include <cmath>
#include <vector>

class dh_t
{
    private:
        int p, alfa, xa, xb;
        int k;
    
    public:
    
        dh_t();
        ~dh_t();
        
        void Ask();
        int Expo( int a, int b );
        bool Check( int );
        
        void menu();
};



#endif