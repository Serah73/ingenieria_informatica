#ifndef FS_T_
#define FS_T_


#include <iostream>
#include <cmath>
#include <math.h>


class fs_t
{
    private:
    
        long int p, q, s, x, y, a_, e, N;
        
    public:
    
        fs_t();
        ~fs_t();
        
        void AskStart(long int&, char);
        void AskStart();
        long int AskSecret();
        
        bool Prime( long int, long int);
        long int Algorithm( );
        bool Check( long int );
        
        bool CheckPrime( int );
        
        void Run();
};


#endif