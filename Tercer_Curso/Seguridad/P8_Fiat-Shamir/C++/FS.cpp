#include "FS.hpp"

fs_t::fs_t()
{
    p = 0;
    q = 0;
    s = 0;
    x = 0;
    y = 0;
    e = 0;
    a_ = 0;
}

fs_t::~fs_t(){}
void fs_t::AskStart( long int &a, char b)
{
    std::cout << "Introduzca el valor de '" << b << "': ";
    std::cin >> a;
    std::cout << "\n";
    
    if( b != 's' )
        while(!CheckPrime(a))
        {
            std::cout << "Por favor, introduzca un numero primo, sin factores comunes a los anteriores:\n";
            std::cin >> a;
        }    
    else
        while(!Prime(N, a))
        {
            std::cout << "Por favor, introduzca un numero primo:" << std::endl;
            std::cin >> a;
        }
}
void fs_t::AskStart()
{
    AskStart(p, 'p');
    AskStart(q, 'q');
    N = p*q;
    
    AskStart(s, 's');
    std::cout << "Identificacion publica de A:\n  "<< fmod(pow(s, 2), N) << std::endl;
}


long int fs_t::AskSecret()
{
    std::cout << "Introduce el valor de 'x'(compromiso secreto):" << std::endl;
    long int out;
    std::cin >> out;
    
    return out;
}



bool fs_t::Prime(long int a, long int b)
{
    if( b > a)
        return false;
    else if( fmod(a, b) == 0)
        return false;
    else
        return true;
}

long int fs_t::Algorithm()
{
    x = AskSecret();
    a_ = fmod( pow(x, 2), N);
    
    std::cout << "Escoge el valor de 'e':" << std::endl;
    std::cin >> e;

    int y;

    if(e == 1)
        y = fmod( (s*x), N);
    else
        y = fmod(x,  N);
        
    return y;
}

bool fs_t::CheckPrime( int primo )
{
    int divisor = 1;
    int divisores = 0;
    
    do{ 
        if(fmod(primo, divisor) == 0) 
            divisores++; 
        divisor++;
        
        if (divisores > 2 )
            return false;
        
    }while(divisor <= primo); 
    
    if(divisores == 2) 
        return true;
    else
        return false;
}

bool fs_t::Check( long int y )
{
    long int dummy, v = pow(s, 2);
    if ( e == 0 )
        dummy = fmod(a_, N);
    else 
        dummy = fmod( (a_*v), N);
        
    //std::cout << "dummy = " << dummy << "\nv = "<< v << std::endl;
    long int test = fmod( pow(y, 2), N);
    
    if ( dummy == test) return true;
    else
        return false;
}


void fs_t::Run()
{
    AskStart();
    
    std::cout << "numero de iteraciones:" << std::endl;
    int max = 0;
    std::cin >> max;
    
    bool check = true;
    
    int i = 1;
    
    std::cout << "\nN = " << N << std::endl;
    
    while( (i <= max) && check )
    {
        long int y = Algorithm();
        check = Check( y );
        std::cout << i << "º iteracion:" << std::endl;
        std::cout << "a = " << a_ << "\ty = " << y << "\nComprobacion de " << y << "² igual a: ";
        std::cout << a_ << " (mod " << N << ")" << std::endl;
        
        if (check)
            std::cout << "\tCorrecto. Iteracion valida" << std::endl;
        else
            std::cout << "Incorrecto. Parando algoritmo." << std::endl;
        i++;
    }
}

