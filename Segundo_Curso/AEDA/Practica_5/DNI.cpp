#include "DNI.hpp"

DNI::DNI():
num(0),
letter('A'){}

DNI::~DNI(){}

DNI::DNI(long int n, char c):
num(n),
letter(c){}

DNI::DNI(const DNI& b):
num(b.num),
letter(b.letter){}

long int DNI::get_num() const
{
    return num;
}

char DNI::get_letter() const
{
    return letter;
}

long int& DNI::get_num()
{
    return num;
}
char& DNI::get_letter()
{
    return letter;
}

void DNI::reconstruir(long int n, char c)
{
    this->get_num() = n;
    this->get_letter() = c;
}

void DNI::operator=(DNI b)
{
    num = b.get_num();
    letter = b.get_letter();
}

bool DNI::operator ==(DNI b)
{
    if(num != b.get_num() || letter != b.get_letter())
        return false;
    
    return true;
}
bool DNI::operator!=(DNI b)
{
    if(num != b.get_num() || letter != b.get_letter())
        return true;
    
    return false;
}

bool DNI::operator<(DNI b)
{
    if(num < b.get_num())
        return true;
    
    else if(num == b.get_num() && letter < b.get_letter())
        return true;
    
    return false;
}

bool DNI::operator>(DNI b)
{
    if(num > b.get_num())
        return true;
    
    else if(num == b.get_num() && letter > b.get_letter())
        return true;
    
    return false;
}

std::istream& operator>>(std::istream& in, DNI& x)
{
    in >> x.get_num() >> x.get_letter();
    return in;
}

std::ostream& operator<<(std::ostream& out, DNI x)
{
    out << x.get_num() << x.get_letter();
    return out;
}