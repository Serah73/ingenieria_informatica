#include "A5.hpp"


a5_t::a5_t()
{
    lfsr1_.resize(19);
    lfsr2_.resize(22);
    lfsr3_.resize(23);
    message_ = "message";
}
a5_t::~a5_t(){}

void a5_t::Start( )
{
    key_.clear();
    
    std::cout << "\t- - A 5 / 1 - -\n\n";
    
    SeedKey();
    AskMessage();
    
    for ( int i = 0; i < message_.size()*8; i++)
    {   
        std::cout << "\n\n--------------------------------------------------------\n";
        std::cout << "\tI T E R A C I O N\t" << i+1 << "\n";
        std::cout << "--------------------------------------------------------\n";

        Write();
        Generate();
    }
    std::cout << "\tSecuencia cifrante: ";
    
    for ( int i = 0; i < key_.size(); i++)
        std::cout << key_[i] << " ";
    std::cout << "\n";
    
    Work();
    
}


void a5_t::Info( )
{
    std::cout << "lfsr1: ";
    
    for ( int i = 0; i < lfsr1_.size(); i++ )
        std::cout << lfsr1_[i] << ", ";
    
    std::cout << "\nlfsr2: ";
    
    for ( int i = 0; i < lfsr2_.size(); i++ )
        std::cout << lfsr2_[i] << ", ";
        
    std::cout << "\nlfsr3: ";
    
    for ( int i = 0; i < lfsr3_.size(); i++ )
        std::cout << lfsr3_[i] << ", ";
    
    std::cout << std::endl;
}

void a5_t::SeedKey( )
{
    std::string lfsr1, lfsr2, lfsr3;
    
    std::cout << "Introduzca el lfsr1:\n";
    std::getline(std::cin, lfsr1);
    
    std::cout << "\nIntroduzca el lfsr2:\n";
    std::getline(std::cin, lfsr2);
    
    std::cout << "\nIntroduzca el lfsr3:\n";
    std::getline(std::cin, lfsr3);

    Standard( lfsr1, lfsr2, lfsr3 );
}

void a5_t::AskMessage( )
{
    std::cout << "\nIntroduzca el mensaje a cifrar: ";
    std::getline(std::cin, message_ );
    std::cout << "\n";
}

void a5_t::Standard( std::string lfsr1, std::string lfsr2, std::string lfsr3 )
{
    for ( int i = 0; i < lfsr1.size(); i++ )
    {
        if ( lfsr1[i] == '1' ) lfsr1_[i] = 1;
        else if ( lfsr1[i] == '0' ) lfsr1_[i] = 0;
    }
    
    for ( int i = 0; i < lfsr2.size(); i++ )
    {
        if ( lfsr2[i] == '1' ) lfsr2_[i] = 1;
        else if ( lfsr2[i] == '0' ) lfsr2_[i] = 0;
    }
    
    for ( int i = 0; i < lfsr3.size(); i++ )
    {
        if ( lfsr3[i] == '1' ) lfsr3_[i] = 1;
        else if ( lfsr3[i] == '0' ) lfsr3_[i] = 0;
    }
}

int a5_t::Xor( )
{
    int a = lfsr1_[0],
        b = lfsr2_[0],
        c = lfsr3_[0];
    
    int out = Xor( a, b );
    out = Xor( out, c );
    
    return out;
}

int a5_t::Xor( int a, int b )
{
    if ( a == b )
        return 0;
    else if ( a != b )
        return 1;
}

int a5_t::Xor( char a, int b )
{
    int c;
    
    if ( a == '1' )
        c = 1;
    else
        c = 0;
        
    if ( c == b )
        return 0;
    else if ( c != b )
        return 1;
}

void a5_t::Generate( )
{
    std::vector<int> F = Mayoria();
    int xorIter = Xor();
    int outMayoriaResult = MayoriaF();
    
    if ( F[0] == 1 )
        Lfsr( lfsr1_ );
    if ( F[1] == 1 )
        Lfsr( lfsr2_ );
    if ( F[2] == 1 )
        Lfsr( lfsr3_ );
    
    key_.push_back( xorIter );
    
    
    std::cout << outMayoriaResult << "\n";
}

void a5_t::Work( )
{
    std::string out;
    
    for( int i = 0; i < message_.size(); i++ )
    {
        int aux = message_[i];
        out.append( intToBinary( aux ) );
    }
    
    message_.clear();
    
    for ( int i = 0; i < key_.size(); i++)
    {
        if ( Xor(out[i], key_[i]) == 1 )
            message_.push_back('1');
        else
            message_.push_back('0');
    }
    
    std::cout << "\nResultado del mensaje cifrado(binario): " << message_ << "\n";
    std::cout << "Pulse enter para continuar...\n";
    std::cin.ignore();
    
    out.clear();
    
    for(int i = 0; i < message_.size(); i += 8 )
    {
        std::string dummy;
        
        for ( int j = 0; j < 8; j++)
        {
            dummy.push_back(message_[i+j]);
        }
        int a = BinToInt( dummy );
        char b = a;
        out.push_back(b);
    }
    message_ = out;
    
    std::cout << "Resultado del mensaje cifrado(ASCII): " << message_ << "\n";
    
}


std::vector<int> a5_t::Mayoria( )
{
    std::vector<int> out;
    out.resize(3);
    
    int rg1 = lfsr1_[(19 - 9)],   //19 tamaño del registro, 9 posicion de donde sacamos la mayoria(-1 porque empezamos de 0)
        rg2 = lfsr2_[(22 - 11)],
        rg3 = lfsr3_[(23 - 11)];
    
    int mayoria = rg1 * rg2 + rg1 * rg3 + rg2 * rg3;
    
    if ( rg1 == mayoria ) 
        out[0] = 1;
    else
        out[0] = 0;
        
    if ( rg2 == mayoria ) 
        out[1] = 1;
    else
        out[1] = 0;
    
    if ( rg3 == mayoria ) 
        out[2] = 1;
    else
        out[2] = 0;
    
    std::cout << "\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\t";
    std::cout << "\t\tF( " << rg1 << ", " << rg2 << ", " << rg3 << " ) = ";

    
    return out;
}

int a5_t::MayoriaF( )
{
    int rg1 = lfsr1_[19 - 9],   //19 tamaño del registro, 8 posicion de donde sacamos la mayoria(-1 porque empezamos de 0)
        rg2 = lfsr2_[22 - 11],
        rg3 = lfsr3_[23 - 11];
    int out = (rg1 * rg2 + rg1 * rg3 + rg2 * rg3);
    
    return out;
}

void a5_t::Lfsr( std::vector<int> &v )
{
    if ( v.size() == 19 )
    {
        int x19 = lfsr1_[19 - 19],
            x18 = lfsr1_[19 - 18],
            x17 = lfsr1_[19 - 17],
            x14 = lfsr1_[19 - 14];
        int z = Xor( x19, x18 );

        z = Xor( z, x17 );
        z = Xor( z, x14 );
        
        v.erase(v.begin());
        v.push_back(z);
    }
    else if ( v.size() == 22 )
    {
        int x22 = lfsr2_[22 - 22],
            x21 = lfsr2_[22 - 21];
        int z = Xor( x22, x21 );
        
        v.erase(v.begin());
        v.push_back(z);
    }
    else if ( v.size() == 23 )
    {
        int x23 = lfsr3_[23 - 23],
            x22 = lfsr3_[23 - 22],
            x21 = lfsr3_[23 - 21],
            x8 = lfsr3_[23 - 6];
        int z = Xor( x23, x22 );
        z = Xor( z, x21 );
        z = Xor( z, x8 );
        
        v.erase(v.begin());
        v.push_back(z);
    }
}

void a5_t::Write()
{
    std::cout << "\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\t";
    
    for ( int i = 22; i >= 0; i-- )
        std::cout << i+1 << "\t";
        
    std::cout << "\n\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    std::cout << "\n\t";
    std::cout << "\t\t\t\t"; //23 - 19 = 4 --> tabulaciones para ajustar el imprimir
    
    for ( int i = 0; i < lfsr1_.size(); i++ )
        std::cout << lfsr1_[i] << "\t";
    
    std::cout << "\n\t";
    std::cout << "\t";
    
    for ( int i = 0; i < lfsr2_.size(); i++ )
        std::cout << lfsr2_[i] << "\t";
        
    std::cout << "\n\t";
    
    for ( int i = 0; i < lfsr3_.size(); i++ )
        std::cout << lfsr3_[i] << "\t";
    
    std::cout << "\n";

    
}

//Conversiones

std::string a5_t::invertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
}

std::string a5_t::intToBinary ( int N ) //DONE
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

int a5_t::BinToInt( std::string Str )
{
    Str = invertString( Str );
    int count = 0;
    
    for ( int i = 0; i < Str.size(); i++ )
    { 
        int N = 0;
        
        if ( Str[i] == '1' )
            N = 1;
        else if ( Str[i] == '0' )
            N = 0;
            
        count += pow(2, i) * N;
    }
    
    return count;
}