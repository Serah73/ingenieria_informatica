#ifndef M_H_
#define M_H_

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

class m_t
{
    private:
        std::string AES;
        std::string SNOW;
        std::string a_, b_;
        std::string result_;
        std::vector<std::string> table_;
        
    public:
    
        m_t();
        ~m_t();
        
        //First
        int Ask( );
        void Calculate( );
        void TableT( int, int, std::string);

        //Operators/Aux
        int IterMax( std::string );
        void Displace( std::string& );
        void Xor( std::string &, int );
        char Xor( char a, char b );
        void Write();
        
        std::string Test( std::string&, std::string& );
        
        //Converter
        std::string intToBinary ( int );
        int HexToInt(std::string );
        std::string HexToBin(std::string );
        std::string invertString( std::string );
        
        
};






#endif