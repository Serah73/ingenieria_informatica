#pragma once

#include <algorithm>
#include <math.h>
#include <bitset>
#include <cmath>
#include <vector>
#include <string>



std::string invertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
}

std::string intToBinary ( int N ) //DONE
{
    std::string Str;
    char C;
    
    while( N >= 2 )
    {
        int Count = N % 2;
        
        if ( Count == 1)
            C = 49;
        
        else if ( Count == 0 )
            C = 48;
        
        Str += C;
        
        N = N/2;
    }
    if ( N == 1 )
    {
        C = 49;
        Str += C;
    }
    else if ( N == 0 )
    {
        C = 48;
        Str += C;
    }
    
    return invertString( Str ); //Ordered
}

int stringToAsciiInt( std::string msg )
{
    int N = -1;
    if ( msg.size() != 8 ) std::cout << "StringToAsciiInt Error: Failure of dimension\n";
    else
        N = msg[0];
    
    return N;
}

std::string portXOR( std::string msg, std::string key ) //pos es la posicion de la clave con el respectivo modulo
{
    std::bitset<8> s ( msg );
    std::bitset<8> t ( key );
    
    s = (t ^ s);
    //probar usar el mismo string sin tener que declarar el mystring
    std::string mystring = s.to_string();

    return mystring;
}

int binToInt( std::string str )
{
    str = invertString( str );
    int count = 0;
    
    for ( int i = 0; i < str.size(); i++ )
    { 
        int N = 0;
        
        if ( str[i] == '1' )
            N = 1;
        else if ( str[i] == '0' )
            N = 0;
            
        count += pow(2, i) * N;
    }
    
    return count;
}