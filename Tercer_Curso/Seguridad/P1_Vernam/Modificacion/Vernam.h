#ifndef VERNAM_T_
#define VERNAM_T_

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <math.h>

class Vernam_t
{
    private: 
        std::string Key_;
        std::string Message_;
        
    public:
    
        Vernam_t();
        ~Vernam_t();
        
        std::string GetKey();
        std::string GetKey() const;
        std::string GetMessage();
        std::string GetMessage() const;
        
        std::string CharToBinary( std::string); //
        
        void AskMessage();
        void CreateKey();
        void EVernam( );
        
        //String -> Other
        std::vector<int> StringToAsciiVect( std::string );  //
        int StringToAsciiInt( std::string );    //
        std::vector<std::string> IntToString( std::vector<int> );   //
        std::string IntToBinary ( int );    //
        
        //Bin -> Other
        int BinToInt( std::string );
        std::string AsciiToChar( int );
        
        std::string InvertString( std::string );    //
        std::string SubKey(std::string , int , int );
        
        //bitset
        std::string PortXOR( std::string, std::string );    //Falta ajustar la clave para que sea 100%
        std::string BitToBit( std::string, std::string );
        
        
        void Menu();
        
};
#endif