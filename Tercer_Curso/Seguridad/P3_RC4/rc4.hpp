#ifndef RC4_H_
#define RC4_H_

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <bitset>
#include <cmath>

//#include "utility.hpp"


class Rc4_t
{
    private:
        
        std::vector<int> seed_;
        std::vector<int> key_;
        std::string message_;
        std::vector<int> msg_;
        
    public:
    
        Rc4_t();
        Rc4_t( const Rc4_t & );
        ~Rc4_t();
        
        std::vector<int> Get_key();
        std::vector<int> Get_key() const;
        
        
        void Start();
        
        void GenerateStart( );
        std::vector<int> Generate( );

        void Info();

        void Encrypted( );
        
        void swap( int&, int& );
        
        //utility
        std::string invertString( std::string );
        std::string intToBinary( int );
        int stringToAsciiInt( std::string );
        std::string portXOR( std::string, std::string );
        int binToInt( std::string );
        std::string AsciiToChar( int );
        
        
};

std::ostream& operator<<( std::ostream& , const Rc4_t& );











#endif