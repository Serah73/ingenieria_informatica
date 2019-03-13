#include "Vernam.h"

Vernam_t::Vernam_t()
{
    Message_ = "t";
    Key_ = "!";
}

Vernam_t::~Vernam_t(){}
        
std::string Vernam_t::GetKey()
{
    return Key_;
}
std::string Vernam_t::GetKey() const
{
    return Key_;
}
std::string Vernam_t::GetMessage()
{
    return Message_;
}
std::string Vernam_t::GetMessage() const
{
    return Message_;
}

std::string Vernam_t::CharToBinary( std::string Str )
{
    int N = StringToAsciiInt( Str );
    //std::vector<std::string> Vstr = IntToBinary( N );
    
    return IntToBinary( N );         //Vstr;
}

void Vernam_t::AskMessage()
{
    std::string Msg;
    
    std::cout << "Enter a Message: ";
    std::getline( std::cin, Msg );
    
    Message_ = Msg;
}


void Vernam_t::CreateKey()
{
    Key_.clear();
    std::vector<int> aux ;
    
    for ( int i = 0; i < Message_.size(); i++ )
        for ( int j = 0; j < 8; j++)
            aux.push_back( rand() % 2);
            
    for ( int i = 0; i < aux.size(); i++ )
        Key_.push_back(aux[i] + 48);
}


void Vernam_t::EVernam()
{
    std::vector<int> VMsg = StringToAsciiVect( Message_ );
    
    std::vector<int> VOut;
    std::string SubStrKey;
    
    std::cout << VMsg.size() << std::endl;    
    
    for ( int i = 0; i < VMsg.size(); i++ )
    {
        SubStrKey = SubKey( Key_, (i + 1)*8 - 8, (i + 1)*8);
        std::cout << "Subkey: " << SubStrKey << std::endl;
        
        std::string StrMsg = IntToBinary( VMsg[i] );
        
        std::string aux = BitToBit( StrMsg, SubStrKey );
        
        VOut.push_back( BinToInt( aux ) );
}
    
    std::string OutAux;
    
    for ( int i = 0; i < VOut.size(); i++ )
        OutAux.append( AsciiToChar( VOut[i] ) );

    std::cout << "Cifrado" << std::endl;
    std::cout << OutAux << std::endl;
    Message_ = OutAux;
}



//String -> Other
std::vector<int> Vernam_t::StringToAsciiVect ( std::string Msg )    //DONE
{
    std::vector<int> V;
    
    for ( int i = 0; i < Msg.size(); i++)
        V.push_back( Msg[i] );

    return V;
}
int Vernam_t::StringToAsciiInt( std::string Msg)
{
    int N = -1;
    if ( Msg.size() != 8 ) std::cout << "StringToAsciiInt Error: Failure of dimension\n";
    else
        N = Msg[0];
    
    return N;
}


std::vector<std::string> Vernam_t::IntToString( std::vector<int> V) //DONE
{
    std::vector<std::string> Vstr;
    
    for ( int i = 0; i < V.size(); i++ )
        Vstr.push_back( IntToBinary( V[i] ) );

    return Vstr;
}


std::string Vernam_t::IntToBinary ( int N ) //DONE
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
    
    return InvertString( Str ); //Ordered
}

//Bin -> Other

int Vernam_t::BinToInt( std::string Str )
{
    Str = InvertString( Str );
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

std::string Vernam_t::AsciiToChar( int N )
{
    char aux = N;
    std::string dummy;
    dummy.push_back(aux);
    return dummy;
}

std::string Vernam_t::InvertString( std::string Str )   //DONE
{
    std::string aux; 
    
    for ( int i = Str.size() - 1; i >= 0; i-- )
        aux.push_back( Str[i] );
    
    return aux;
    
}

std::string Vernam_t::SubKey(std::string SubStr, int i , int n )
{
    std::string dummy;
    
    for ( i; i < n; i++ )
    {
        //std::string aux = SubStr[i];
        dummy.push_back( SubStr[i] );
    }
    
    return dummy;
}



std::string Vernam_t::PortXOR( std::string Msg, std::string KeyP ) //pos es la posicion de la clave con el respectivo modulo
{
    std::bitset<8> Message ( Msg );
    std::bitset<8> Key ( KeyP );
    
    Message = (Message ^ Key);
    //probar usar el mismo string sin tener que declarar el mystring
    std::string mystring = Message.to_string();

    return mystring;
}

std::string Vernam_t::BitToBit( std::string Msg, std::string KeyP )
{
    std::string dummy;
    
    for ( int i = 0; i < Msg.size(); i++ )
    {
        if ( ( Msg[i] == '1' ) && (KeyP[i] == '1' ) )
            dummy.push_back('0');
        else if ( ( Msg[i] == '0' ) && (KeyP[i] == '1' ) )
            dummy.push_back('1');
        else if ( ( Msg[i] == '1' ) && (KeyP[i] == '0' ) )
            dummy.push_back('1');
        else
            dummy.push_back('0');
    }
    
    return dummy;
}






void Vernam_t::Menu()
{
    int option = 0;
    bool KeyActivated = false,
         MessageInside = false;
    system("clear");
    
    do{
        std::cout << "\t\t- - - M E N U - - -\n\n";
        
        std::cout << "\t1 - Enter a Key.\n";
        std::cout << "\t2 - Enter a Message.\n";
        std::cout << "\t3 - Encryption.\n";
        std::cout << "\t4 - Decrypting.\n";
        std::cout << "\t5 - See the Key\n";
        std::cout << "\t0 - Exit\n";
        std::cout << "\t\tOption:\t";
        
        std::cin >> option;
        
        system("clear");        
        
        switch( option )
        {
            case 1:
            {/*
                std::string BinKey;
                
                std::cout << "\tEnter a Manual Key(binary):\n";
                std::cin >> BinKey;
                
                Key_ = BinKey;
                */
                CreateKey();
                
                std::cout << "\nKey created.\n";
                std::cout << "\tPress Enter for continue...\n";
                std::cin.ignore();
                
                break;
            }
            
            case 2:
            {
                //AskMessage();
                std::string Msg;
    
                std::cout << "Enter a Message: ";
                std::cin >> Msg;
                
                Message_ = Msg;
                
                
                break;
            }    
            case 3:
        
                std::cout << "\tE N C R Y P T I O N\n";
                std::cout <<"Input Message(Original):\t" << Message_ << "\n";
                EVernam();
                
                
                std::cout << "\tPress Enter for continue...\n";
                std::cin.ignore();
                break;
                
            case 4:
            
                std::cout << "\tD E C R Y P T I O N\n";
                std::cout <<"Input Message(Original):\t" << Message_ << "\n";
                EVernam();
                
                
                std::cout << "\tPress Enter for continue...\n";
                std::cin.ignore();
                break;
        
            case 5:
                std::cout << "\tKey: " << Key_ << "\n";
                std::cout << "\tKey: " << Message_ << "\n";
                break;
        }
  
    }while( option != 0 );
}