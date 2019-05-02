#include "DH.hpp"

dh_t::dh_t()
{
    k = 0;
}

dh_t::~dh_t(){}


void dh_t::Ask()
{
    std::cout << "Introduce el valor secreto de A:\n";
    std::cin >> xa;
    
    std::cout << "Introduce el valor secreto de B:\n";
    std::cin >> xb;
    
    bool primo = false;
    int i = 0;
    
    while(!primo)
    {
        std::cout << "\nIntroduce el valor del modulo(intento " << i << "):\t";
        std::cin >> p;
        //primo = Check(p); funcion para ver si es primo
        primo = true;
        i++;
    }
    
    bool check = false;
    i = 0;
    
    while(!check)
    {
        std::cout << "\nIntroduce el valor de la base/alfa (intento " << i << "):\t";
        std::cin >> alfa;
        std::cout << "\n";
        i++;
        
        if( alfa < p) check = true;
    }   
}






int dh_t::Expo(int a, int b)    //b es xa o xb //a es la base(alfa)
{
    int x = 1;
    int y = a % p;
    
    while( (b > 0) && (y > 1) )
    {
        if ( (b%2) == 1 )
        {
            x = (x*y) % p;
            b = b - 1;
        }
        else{
            y = (y*y) % p;
            b = b/2;
        }
    }
    return x;
}


bool dh_t::Check( int primo )
{
    int divisor = 1;
    int divisores = 0;
    
    do{ 
        if(primo % divisor == 0) 
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


void dh_t::menu()
{
    int option = 9;
    
    do{
        std::cout << "\n- - - -  Diffie - Hellman  - - - -\n\n";
        std::cout << "1-\tPedir datos.\n";
        std::cout << "2-\tCalcular con Xa.\n";
        std::cout << "3-\tCalcular con Xb.\n";
        std::cout << "4-\tCalcular ambos.\n";
        std::cout << "0-\tSalir\n";
        
        std::cout << "\t\tOpcion: ";
        std::cin >> option;
        std::cout << "\n";
        
        if( option == 0 )
        {
            option = 10;
            std::cout << "Saliendo...\n";
        }
        else if( option == 1 )
        {
            Ask();
        }
        else if( option == 2 )
        {
            int ya = Expo(alfa, xa);
            
            std::cout << "Valor de yA:\t\t" << ya << "\n";
            int yb = Expo(alfa, xb);
            k = Expo(yb, xa);
            
            std::cout << "El resultado es:\t" << k << "\n";
        }
        else if( option == 3 )
        {
            int yb = Expo(alfa, xb);
            
            std::cout << "Valor de yB:\t\t" << yb << "\n";
            
            int ya = Expo(alfa, xa);
            k = Expo(ya, xb);
            
            std::cout << "El resultado es:\t" << k << "\n";
        }
        else if( option == 4 )
        {
            int k;
            int yb = Expo(alfa, xb);
            
            std::cout << "Valor de yB:\t\t" << yb << "\n";
            
            int ya = Expo(alfa, xa);
            k = Expo(ya, xb);
            
            
            int ya2 = Expo(alfa, xa);
            
            std::cout << "Valor de yA:\t\t" << ya2 << "\n";
            yb = Expo(alfa, xb);
            int k2 = Expo(yb, xa);
            
            
            if ( k != k2)
                std::cout << "Hubo un error en el calculo.\n";
            else 
                std::cout << "El resultado es:\t" << k << "\n";
        }
        
    }while(option < 10);
}