#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class DNI
{
    private:

        long int num;
        char letter;
        int entero;
        float flotante;
        std::string cadena;

    public:

        DNI();
        DNI(long int n, char c);
        DNI(const DNI& b);
        ~DNI();
        
        long int get_num() const;
        char get_letter() const;
        long int& get_num();
        char& get_letter();
        
        void reconstruir(long int n, char c);
        
        void operator=(DNI b);
        bool operator==(DNI b);
        bool operator!=(DNI b);
        bool operator<(DNI b);
        bool operator>(DNI b);
        
};

istream& operator>>( istream& in, DNI& x);
ostream& operator<<( ostream& out, DNI x);