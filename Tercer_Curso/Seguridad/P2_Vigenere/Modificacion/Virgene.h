#ifndef VIRGENE_T_
#define VIRGENE_T_

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Virgene_t
{
    private:
    
        std::string Message_;
        std::string Key_;   //Modulo 26 --- se coge el correspondiente y se obtiene la vocal entre 0 o 26 sumandole 65 para obterner el mensaje
        int M_;
        
    public:
    
        Virgene_t();
        ~Virgene_t();
        
        void Start();
        void AskMessage( );
        void CVirgene( );
        void DVirgene( );
        
        int OperatorMod( int, int );
        int OperatorUMod( int, int );
        //void Menu();
};


#endif