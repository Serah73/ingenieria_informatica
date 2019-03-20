#ifndef A5_H_
#define A5_H_

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>


class a5_t
{
    private:
    
        std::vector <int> lfsr1_, lfsr2_, lfsr3_, key_;
        std::string message_;
        
        
    public:
    
        a5_t();
        ~a5_t();
        
        void Start( );
        void Info( );
        void SeedKey( );
        void AskMessage();
        void Standard( std::string, std::string, std::string );
        int Xor( );
        int Xor( int, int );
        int Xor( char, int );
        
        //Principales del algoritmo
        void Generate( );
        void Work();
        
        void Lfsr( std::vector<int>& );
        std::vector<int> Mayoria( );
        int MayoriaF();
        void Write();
        
        //Conversiones
        std::string invertString( std::string );
        std::string intToBinary ( int );
        int BinToInt( std::string );

};





#endif