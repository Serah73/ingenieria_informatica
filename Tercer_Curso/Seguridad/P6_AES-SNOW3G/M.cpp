#include "M.hpp"


m_t::m_t()
{
    a_ = "AA";
    b_ = "34";
    AES = "00011011";
    SNOW  = "10101001";
    result_ = "00000000";
    table_.clear();
}


m_t::~m_t(){}

int m_t::Ask( )
{
    std::cout << "Introduzca con que quiere operar:\n\t1- AES.\n\t2- SNOW.\nElección: ";
    int type;
    std::cin >> type;
    
    std::cout << "Introduzca el primer número(hexadecimal):\n";
    std::cin.ignore();
    std::getline(std::cin, a_ );
    
    std::cout << "Introduzca el segundo número(hexadecimal):\n";
    //std::cin.ignore();
    std::getline(std::cin, b_ );
    
    
    std::cout << "\nvalores\n\t1) " << a_ << "\n\t2) "<< b_ << "\n";
    
    return type;
}
void m_t::Calculate( )
{
    int type = Ask();
    
    std::string aBin = HexToBin( a_ ),
                bBin = HexToBin( b_ );
    int max = IterMax( bBin );
    
    TableT( type, max, aBin );
    
    int j = 0;
    for ( int i = bBin.size() - 1; i >=0;  i--)
    {
        if ( bBin[i] == '1' )
        {
            //std::cout << "table_[i] << "\n";
            std::string aux = table_[j];
            result_ = Test( result_, aux );
        }
        j++;
    }
}

void m_t::TableT( int type, int max, std::string b )
{
    bool nextXor = false;
    
    for ( int i = 0; i <= max; i++ )
    {
        if( !nextXor )
        {
            
            if ( b[0] == '1' )
            {
                nextXor = true;
            }else{
                nextXor = false;
            }
            
            table_.push_back( b );
        
            Displace( b );
        }
        else
        {
            Xor( b, type );
            
            if ( b[0] == '1' )
            {
                nextXor = true;
            }else{
                nextXor = false;
            }
            
            table_.push_back( b );
            Displace( b );
        }
    }
}


int m_t::IterMax( std::string str )
{
    int pos = str.find('1');
    pos++;
    pos = fabs(str.size() - pos);
    
    return pos;
}
void m_t::Displace( std::string &b )
{
    b.erase(b.begin());
    b.push_back('0');
}

void m_t::Xor( std::string &str, int type )
{
    std::string out;
    
    if ( type == 1 )
        out = Test( str, AES );
            
    else if ( type == 2 )
        out = Test( str, SNOW );
        
    str = out;
}
char m_t::Xor( char a, char b )
{
    if ( a == b )
        return '0';
    else 
        return '1';
}

std::string m_t::Test( std::string& a, std::string& b )
{
    std::string out;
    
    for (int i = 0; i < a.size(); i++ )
        out.push_back( Xor( a[i], b[i]) );
        
    return out;
}


void m_t::Write()
{
    std::cout << "\n";
    
    for ( int i = 0; i < table_.size(); i++ )
    {
        std::cout << "tabla posicion - " << i << "\n";
        std::cout << "\t" << table_[i] << "\n\n";
    }
    std::cout << "Resultado: " << result_ << "\n";
}
//Converter

std::string m_t::HexToBin( std::string str )
{
    int hexInt = HexToInt( str );
    std::string out = intToBinary( hexInt );
    
    return out;
}

int m_t::HexToInt( std::string Str )
{
    Str = invertString( Str );
    int count = 0;
    
    for ( int i = 0; i < Str.size(); i++ )
    { 
        int N = 0;
        
        if ( Str[i] == '0' )
            N = 0;
        else if ( Str[i] == '1' )
            N = 1;
        else if ( Str[i] == '2' )
            N = 2;
        else if ( Str[i] == '3' )
            N = 3;
        else if ( Str[i] == '4' )
            N = 4;
        else if ( Str[i] == '5' )
            N = 5;
        else if ( Str[i] == '6' )
            N = 6;
        else if ( Str[i] == '7' )
            N = 7;
        else if ( Str[i] == '8' )
            N = 8;
        else if ( Str[i] == '9' )
            N = 9;
        else if ( Str[i] == 'A' )
            N = 10;
        else if ( Str[i] == 'B' )
            N = 11;
        else if ( Str[i] == 'C' )
            N = 12;
        else if ( Str[i] == 'D' )
            N = 13;
        else if ( Str[i] == 'E' )
            N = 14;
        else if ( Str[i] == 'F' )
            N = 15;
            
        count += pow(16, i) * N;
    }
    
    return count;
}


std::string m_t::invertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
}

std::string m_t::intToBinary ( int N ) //DONE
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
    std::bitset<8> aux ( invertString( Str ) );
    std::string out = aux.to_string();
    
    return out; //Ordered
}