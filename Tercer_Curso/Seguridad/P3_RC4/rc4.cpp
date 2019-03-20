#include "rc4.hpp"

Rc4_t::Rc4_t()
{
    message_ = "message";
}

Rc4_t::Rc4_t(const Rc4_t &a):
seed_(a.seed_),
key_(a.key_),
message_(a.message_)
{}

Rc4_t::~Rc4_t(){}

std::vector<int> Rc4_t::Get_key()
{
    return key_;
}
std::vector<int> Rc4_t::Get_key() const
{
    return key_;
}

void Rc4_t::Start( )
{
    int sz, k;
    
    std::cout << "¿cuantos elementos tiene la semilla? ";
    std::cin >> sz;
    seed_.resize(sz);
    
    for (int i = 0; i < sz; i++)
    {
        std::cout << "\nIntroduzca el elemento (" << i+1 << "): ";
        std::cin >> k;
        
        seed_[i] = k;
    }
    
    std::cout << "\nComenzando la inicializacion\n";
    GenerateStart();
    
    int tammsg;
    std::cout << "Introduzca el tamaño del mensaje a cifrar: ";
    
    /*std::cin.ignore();
    std::getline(std::cin, message_);
    */
    std::cin >> tammsg;
    msg_.resize(tammsg);
    
    for (int i = 0; i < tammsg; i++ )
    {
        std::cout << "Introduce elemento '" << i << "': ";
        int dummy;
        std::cin >> dummy;
        
        msg_[i] = dummy;
    }
    
    std::cout << "\nFin de inicializacion\n";
}


void Rc4_t::GenerateStart()
{
    std::vector<int> s;
    s.resize(256);
    
    std::vector<int> dummy;
    dummy.resize(256);
    
    
    for ( int i = 0; i < 256; i++ )
    {
        s[i] = i;
        dummy[i] = seed_[ i%seed_.size() ];
    }
    
    int j = 0;
    
    for ( int i = 0; i < 256; i++ )
    {
        j = ( j + s[i] + dummy[i] ) % 256;
        swap( s[i], s[j] );
    }
    
    key_ = s;
}

std::vector<int> Rc4_t::Generate( )
{
    std::vector<int> aux;
    int i = 0, j = 0;
    
    for ( int k = 0; k < msg_.size(); k++ )
    {
        i = (i + 1) % 256;
        j = (j + key_[i]) % 256;
        swap( key_[i], key_[j]);
        
        int t = (key_[i] + key_[j]) % 256;
        
        aux.push_back( key_[t] );
        //std::cout << "k: " << k << "\nkey[" << t << "] = " << key_[t] << std::endl;
    }        
    return aux;
}

void Rc4_t::Info()
{
    std::cout << "seed sz: " << seed_.size() << std::endl;

    for( int i =  0; i < seed_.size(); i++ )
        std::cout << "seed[" << i << "]: " << seed_[i] << std::endl;
        
    std::cout << "Mensaje\n" << message_ << std::endl;
    std::cout << "mensaje sz: " << message_.size() << std::endl;
    
    for( int i =  0; i < message_.size(); i++ )
        std::cout << "message[" << i << "]: " << message_[i] << std::endl;
}

void Rc4_t::Encrypted( )
{
    int sz = msg_.size();
    std::vector<int> v;
    
    std::vector<int> secuenciaCifrante = Generate( );
    
    

    for( int i = 0; i < sz; i++ )
    {
        //string con el binario de la secuencia cifrante
      
        
        std::string t = intToBinary( secuenciaCifrante[i] );    //intToBinary( Generate( i ) );
        
        int aux = msg_[i];
        //binario con el mensaje
        std::string s = intToBinary( aux );
        
        std::string testing = portXOR(s, t);
        
        int outXor = binToInt( testing );
        v.push_back( outXor );
        
        //std::cout << "tamano msg: " << message_.size() << "\ntamano secuencia: " << secuenciaCifrante.size() << std::endl;
        
        std::cout << "\n\nsecuenciaCifrante[" << i << "] = " << secuenciaCifrante[i] << "\nEn binario: " << t << "\n\n";
        std::cout << "Mensaje original, M[" << i << "] = " << aux << "\nEn binario: " << s << "\n\n";
        std::cout << "Mensaje Cifrado, S[" << i << "] = " << outXor << "\nEn binario: " << testing << "\n\n";
        std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    }
    /*
    std::string outAux;
    
    for ( int i = 0; i < v.size(); i++)
        outAux.append( AsciiToChar( v[i] ));
    
    key_ = v;
    message_ = outAux;

    
    std::cout << "mensaje sz: " << message_.size() << std::endl;
    std::cout << "Mensaje tratado:\n\t" << message_ << "\n";*/
}


void Rc4_t::swap( int& a, int& b)
{
    int c = a;
    
    a = b;
    b = c;
}


std::string Rc4_t::invertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
}

std::string Rc4_t::intToBinary ( int N ) //DONE
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

int Rc4_t::stringToAsciiInt( std::string msg )
{
    int N = -1;
    if ( msg.size() != 8 ) std::cout << "StringToAsciiInt Error: Failure of dimension\n";
    else
        N = msg[0];
    
    return N;
}

std::string Rc4_t::portXOR( std::string msg, std::string key ) //pos es la posicion de la clave con el respectivo modulo
{
    std::bitset<8> s ( msg );
    std::bitset<8> t ( key );
    
    s = (t ^ s);
    //probar usar el mismo string sin tener que declarar el mystring
    std::string mystring = s.to_string();

    return mystring;
}

int Rc4_t::binToInt( std::string str )
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

std::string Rc4_t::AsciiToChar( int N )
{
    char aux = N;
    std::string dummy;
    dummy.push_back(aux);
    return dummy;
}

std::ostream& operator<<( std::ostream &os, const Rc4_t& a)
{
    std::vector<int> dummy = a.Get_key();
    
    for (int i = 0; i < dummy.size(); i++ )
    {
        os << dummy[i] << " ";
    }
    os << "\n";
    
    return os;
}