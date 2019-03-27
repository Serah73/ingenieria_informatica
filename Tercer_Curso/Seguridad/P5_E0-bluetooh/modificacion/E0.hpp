#ifndef A5_H_
#define A5_H_

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>


class e0_t
{
    private:
    
        std::string message_, messageBin_;
        std::vector <int>   lfsr1_, lfsr2_, lfsr3_, lfsr4_, lfsr5_,     //MODIFICACION "lfsr5_"
                            r1_, r2_, t1_, t2_,
                            key_;
        
    public:
    
        e0_t();
        ~e0_t();
        
        void Start( );  //done
        void SeedKey( );    //done
        void AskMessage();  //done

        //Principales del algoritmo
        
        void Encryption();    //cambiar disposicion de mensajes
        
        void Box( );
        void StartBox( );
        void UpdateBox( );
        
        void Lfsr( );                                   //MODIFICACION
        void Lfsr( std::vector<int>& );
        void Lfsr_modi( std::vector<int>& );            //MODIFICACION
        void Write();                                   //MODIFICACION
        
        //Auxiliares
        std::vector<int> Invert( std::vector<int> );
        std::string invertString( std::string );    //done
        
        std::string intToBinary ( int );    //done
        std::string intToBinaryBi ( int );
        int BinToInt( std::string );    //done
        int BinToInt( std::vector<int> );    // done
        
        std::vector<int> Push( int, std::vector<int> );
        
        void Standard( std::string, std::string, std::string, std::string );    //done
        std::vector<int> Standard( std::string );
        
        //XOR 
        int Xor( ); //ajustar con el e0 del a5
        int Xor( int, int );    //done
        int Xor( char, int );   //done, aunque tener en cuenta que lo hice mas eficiente por si peta algo
        std::vector<int> Xor( std::vector<int>, std::vector<int> );

};





#endif