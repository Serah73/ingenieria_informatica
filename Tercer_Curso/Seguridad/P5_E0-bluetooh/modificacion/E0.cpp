#include "E0.hpp"


e0_t::e0_t()
{
    lfsr1_.resize(25);
    lfsr2_.resize(31);
    lfsr3_.resize(33);
    lfsr4_.resize(39);
    
    lfsr5_.resize(39);      //MODIFICACION
    
    r1_.resize(2);
    r2_.resize(2);
    t1_.resize(2);
    t2_.resize(2);
    
    message_ = "message";
}
e0_t::~e0_t(){}

void e0_t::Start( ) //done, si cambio el generate y el work, este ultimo era solo mensajes, no preocupante(en teoria)
{
    key_.clear();
    
    std::cout << "\t- - E0 / Bluetooth - -\n\n";
    
    SeedKey();
    AskMessage();
    
    for ( int i = 0; i < message_.size()*8; i++)
    {   
        std::cout << "\n\n--------------------------------------------------------\n";
        std::cout << "\tI T E R A C I O N\t" << i+1 << "\n";
        std::cout << "--------------------------------------------------------\n";

        Write();
        UpdateBox();
        Box();
        Lfsr();
    }
    std::cout << "\tSecuencia cifrante: ";
    
    for ( int i = 0; i < key_.size(); i++)
        std::cout << key_[i] << " ";
    std::cout << "\n";
    
    Encryption();
    
    
    std::cout << "mensaje cifrado:    " << messageBin_ << "\n";
    std::cout << "llave:              ";
    
    for ( int i = 0; i < key_.size(); i++)
        std::cout << key_[i];
        
    for ( int i = 0; i < messageBin_.size(); i++)
    {
        if (Xor( messageBin_[i], key_[i]) == 1 )
            messageBin_[i] = '1';
        else
            messageBin_[i] = '0';
    }
    
    
    std::cout << "\nmensaje descifrado: " << messageBin_ << "\n";
    
}



void e0_t::SeedKey( )   //done
{
    std::string lfsr1, lfsr2, lfsr3, lfsr4, lfsr5, r1;
    /*
    std::cout << "Introduzca el lfsr1:\n";
    std::getline(std::cin, lfsr1);
    
    std::cout << "\nIntroduzca el lfsr2:\n";
    std::getline(std::cin, lfsr2);
    
    std::cout << "\nIntroduzca el lfsr3:\n";
    std::getline(std::cin, lfsr3);
    
    std::cout << "\nIntroduzca el lfsr4:\n";
    std::getline(std::cin, lfsr4);
    
    std::cout << "\nIntroduzca el R1:\n";
    std::getline(std::cin, r1);
    */
    lfsr1 = "0111111111111111111111111";
    lfsr2 = "0111111111111111111111111111111";
    lfsr3 = "011111111111111111111111111111111";
    lfsr4 = "010101010101010101010101010101010101010";
    lfsr5 = "111111111111111111111111111111111111111";
    
    r1 = "01";
    
    std::cout << "LFSR1: " << lfsr1 << "\nLFSR2: " << lfsr2 << "\nLFSR3: " << lfsr3 << "\nLFSR4: " << lfsr4 << "\nLFSR5: " << lfsr5 
              << "\nR1: " << r1 << "\n\n";
    
    
    Standard( lfsr1, lfsr2, lfsr3, lfsr4 );
    lfsr5_ = Standard( lfsr5 );
    r1_ = Standard( r1 );
    StartBox();
}

void e0_t::AskMessage( )    //DONE
{
    std::cout << "\nIntroduzca el mensaje a cifrar: ";
    std::getline(std::cin, message_ );
    std::cout << "\n";
}





//encargado del xor del mensaje
void e0_t::Encryption( )      //modificar solo el tema de los mensajes(cifrado y descifrado)
{
    messageBin_.clear();
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
        messageBin_.append(dummy);
    }
    message_ = out;
    
    std::cout << "Resultado del mensaje cifrado(ASCII): " << message_ << "\n";
    
}

void e0_t::Box( )
{   
    
    key_.push_back( Xor( r1_[1], Xor() ));
    
    r1_ = Invert(r1_);
    
    int suma = lfsr1_[24] + lfsr2_[30] + lfsr3_[32] + lfsr4_[38];
    
    int r1D = BinToInt( r1_ );

    suma += r1D;    
    
    std::string binSuma = intToBinaryBi( suma );
    std::string auxZ;
    auxZ.push_back( binSuma[0] );
    auxZ.push_back( binSuma[1] );
    
    std::vector<int> z = Standard( auxZ );
    
    r1_ = Xor( Xor( z, t2_), t1_ );
    r1_ = Invert( r1_ );
    
    
    
}
void e0_t::StartBox( )
{
    r1_ = Invert( r1_ );
    t1_ = r1_;
    
    r2_ = r1_;
    r2_ = Invert( r2_ );
    
    t2_[0] = r2_[1];
    t2_[1] = Xor( r2_[0], r2_[1] );
}
void e0_t::UpdateBox( )
{
    t1_ = r1_;
    
    r2_ = r1_;
    r2_ = Invert( r2_ );
    
    t2_[0] = r2_[1];
    t2_[1] = Xor( r2_[0], r2_[1] );
}

void e0_t::Lfsr( )
{
    Lfsr( lfsr1_ );
    Lfsr( lfsr2_ );
    Lfsr( lfsr3_ );
    Lfsr( lfsr4_ );
    Lfsr_modi( lfsr5_ );        //MODIFICACION
}
void e0_t::Lfsr( std::vector<int> &v )
{
    if ( v.size() == 25 )
    {
        int x25 = lfsr1_[/*25 - */24],
            x20 = lfsr1_[/*25 - */19],
            x12 = lfsr1_[/*25 - */11],
            x8  = lfsr1_[/*25 - */ 7];
        int z = Xor( x25, x20 );

        z = Xor( z, x12 );
        z = Xor( z, x8 );
        
        v.erase(v.begin()+24);
        
        v = Push( z, v );
    }
    else if ( v.size() == 31 )
    {
        int x31 = lfsr2_[/*31 - */30],
            x24 = lfsr2_[/*31 - */23],
            x16 = lfsr2_[/*31 - */15],
            x12 = lfsr2_[/*31 - */11]; 
        int z = Xor ( Xor( x31, x24 ) , Xor( x16, x12 ) );
        
        v.erase(v.begin()+30);
        v = Push( z, v );
    }
    else if ( v.size() == 33 )
    {
        int x33 = lfsr3_[/*33 - */32],
            x28 = lfsr3_[/*33 - */27],
            x24 = lfsr3_[/*33 - */23],
            x4  = lfsr3_[/*33 - */ 3];
        int z = Xor ( Xor( x33, x28 ) , Xor( x24, x4 ) );
        
        v.erase(v.begin()+32);
        v = Push( z, v );
    }
    else if ( v.size() == 39 )
    {
        int x39 = lfsr4_[/*39 - */38],
            x36 = lfsr4_[/*39 - */35],
            x28 = lfsr4_[/*39 - */27],
            x4  = lfsr4_[/*39 - */ 3];
        int z = Xor ( Xor( x39, x36 ) , Xor( x28, x4 ) );
        
        v.erase(v.begin()+38);
        v = Push( z, v );
    }

}
void e0_t::Lfsr_modi( std::vector<int> &v )         //MODIFICACION
{
    int x25 = lfsr5_[/*39 - */24],
        x15 = lfsr5_[/*39 - */14],
        x10 = lfsr5_[/*39 - */ 9],
        x5  = lfsr5_[/*39 - */ 4];
    int z = Xor ( Xor( x25, x15) , Xor( x10, x5 ) );
    
    v.erase(v.begin()+38);
    v = Push( z, v );
}
void e0_t::Write()      //modi
{
    std::cout << "\t\tLFSR1" << std::endl;
    int j = 0;
    
    for ( int i = 0; i < lfsr1_.size(); i++ )
    {
        if( j != 3 )
        {
            std::cout << lfsr1_[i];
            j++;

        }else
        {
            std::cout << lfsr1_[i] << " ";
            j = 0;
        }
    }
    
    std::cout << "\n\n\t\tLFSR2" << std::endl;
    j = 0;
    
    for ( int i = 0; i < lfsr2_.size(); i++ )
    {
        if( j != 3 )
        {
            std::cout << lfsr2_[i];
            j++;

        }else
        {
            std::cout << lfsr2_[i] << " ";
            j = 0;
        }
    }
    
    std::cout << "\n\n\t\tLFSR3" << std::endl;
    j = 0;
    
    for ( int i = 0; i < lfsr3_.size(); i++ )
    {
        if( j != 3 )
        {
            std::cout << lfsr3_[i];
            j++;

        }else
        {
            std::cout << lfsr3_[i] << " ";
            j = 0;
        }
    }
    
    std::cout << "\n\n\t\tLFSR4" << std::endl;
    j = 0;
    
    for ( int i = 0; i < lfsr4_.size(); i++ )
    {
        if( j != 3 )
        {
            std::cout << lfsr4_[i];
            j++;

        }else
        {
            std::cout << lfsr4_[i] << " ";
            j = 0;
        }
    }
    
    std::cout << "\n\n\t\tLFSR5" << std::endl;      //MODIFICACION
    j = 0;
    
    for ( int i = 0; i < lfsr5_.size(); i++ )
    {
        if( j != 3 )
        {
            std::cout << lfsr5_[i];
            j++;

        }else
        {
            std::cout << lfsr5_[i] << " ";
            j = 0;
        }
    }
    
    std::cout << "\n\nR1: ";
    for ( int i = 0; i < r1_.size(); i++)
        std::cout << r1_[i];
        
    std::cout << "\n\n\n";
    
}

//AUXLIARES
std::vector<int> e0_t::Invert( std::vector<int> v )
{
    std::vector<int> out;
    out.clear();
    
    for( int i = v.size() - 1; i >= 0 ; i-- )
        out.push_back( v[i] );
    
    return out;
}
std::string e0_t::invertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
}

std::string e0_t::intToBinary( int N ) //DONE
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
std::string e0_t::intToBinaryBi( int N )
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
    
    return invertString( Str );
}    
int e0_t::BinToInt( std::string Str )   //DONE
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
int e0_t::BinToInt( std::vector<int> v )    //TEST
{/*
    std::cout << "v:  ";
    for( int i = 0; i < v.size(); i++)
        std::cout << v[i];
*/
    v = Invert(v);
    /*
    std::cout << "\nvI: ";
    for( int i = 0; i < v.size(); i++)
        std::cout << v[i];
    std::cout << "\n";
*/
    int count = 0;
    
    for ( int i = 0; i < v.size(); i++ )
        if( v[i] == 1 )
            count += pow(2, i);
    
    return count;
}


std::vector<int> e0_t::Push( int n, std::vector<int> v )
{
    std::vector<int> out;
    out.push_back( n );
    
    for (int i = 0; i < v.size(); i++)
        out.push_back( v[i] );
    
    return out;
}

void e0_t::Standard( std::string lfsr1, std::string lfsr2, std::string lfsr3, std::string lfsr4 )   //done
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
    
    for ( int i = 0; i < lfsr4.size(); i++ )
    {
        if ( lfsr4[i] == '1' ) lfsr4_[i] = 1;
        else if ( lfsr4[i] == '0' ) lfsr4_[i] = 0;
    }
}
std::vector<int> e0_t::Standard( std::string stand )
{
    std::vector<int> out;
    out.resize( stand.size() );
    
    for ( int i = 0; i < stand.size(); i++ )
    {
        if ( stand[i] == '1' ) out[i] = 1;
        else if ( stand[i] == '0' ) out[i] = 0;
    }
    
    return out;
}


//XOR

int e0_t::Xor( )
{
    int a = lfsr1_[24],
        b = lfsr2_[30],
        c = lfsr3_[32],
        d = lfsr4_[38],
        e = lfsr5_[38];
    
    int out = Xor( a, b );
    int aux = Xor( c, d );
        aux = Xor( aux, e );
    out = Xor( out, aux );
    
    return out;
}
int e0_t::Xor( int a, int b )   //done
{
    if ( a == b )
        return 0;
    else if ( a != b )
        return 1;
}
int e0_t::Xor( char a, int b )  //cambiado por si peta, mirar  A Q U I
{
    int c;
    
    if ( a == '1' )
        c = 1;
    else
        c = 0;
    
    return Xor(c, b);
    /*
    if ( c == b )
        return 0;
    else if ( c != b )
        return 1;*/
}
std::vector<int> e0_t::Xor( std::vector<int> v1, std::vector<int> v2 )
{
    //if ( v1.size() != v2.size() )  throw("Error tamaños de vectores diferentes en la XOR");
    std::vector<int> out;
    
    for( int i = 0; i < v1.size(); i++ )
        out.push_back( Xor(v1[i], v2[i]) );
    
    return out;
}