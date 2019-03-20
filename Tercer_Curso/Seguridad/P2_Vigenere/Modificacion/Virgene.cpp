#include "Virgene.h"


Virgene_t::Virgene_t()
{
    M_ = 30;
    Message_ = "ESTE MENSAJE SE AUTODESTRUIRA";
    Key_ = "MISION";
}

Virgene_t::~Virgene_t()
{}


void Virgene_t::AskMessage()
{
    std::string Msg, Key;
    
    std::cout << "Enter a message:" << std::endl;
    std::getline(std::cin, Msg);
    //std::cin.ignore();
    
    std::cout << "\nEnter a key:" << std::endl;
    std::getline(std::cin, Key);
    
    Message_ = Msg; Key_ = Key;
    
    std::cout << "\nPress enter to continue..." << std::endl;
    std::cin.ignore();
    
}

void Virgene_t::Start()
{
    Message_.clear();
    Key_.clear();
    
    AskMessage();
   
    Message_.erase(remove_if(Message_.begin(), Message_.end(), isspace), Message_.end());
    
    CVirgene();
    DVirgene();
}

void Virgene_t::CVirgene( )
{
    int KeySize = Key_.size();

    for ( int i = 0; i < Message_.size(); i++ )
    {
        int aux = 209; //D de drew
        
        aux = OperatorMod( i , i % KeySize );
        Message_[i] = aux;
    }
    
    std::cout << "\t\tMessage Encrypted" << std::endl;
    std::cout << Message_ << std::endl;
}

void Virgene_t::DVirgene( )
{
    int KeySize = Key_.size();

    for ( int i = 0; i < Message_.size(); i++ )
    {
        int aux = 209; //D de drew
        
        aux = OperatorUMod( i , i % KeySize );
        Message_[i] = aux;
    }
    
    std::cout << "\t\tMessage Decrypted" << std::endl;
    std::cout << Message_ << std::endl;
}


int Virgene_t::OperatorMod( int InxMsg, int InxKey )
{
    int a = Message_[ InxMsg ] - 61;
    int b = Key_[ InxKey ] - 61;
    int c = ( a + b ) % M_;
    
    return c + 61;
}

int Virgene_t::OperatorUMod( int InxMsg, int InxKey)
{
    int a = Message_[ InxMsg ] - 61;
    int b = Key_[ InxKey ] - 61;
    int c = a - b;
    
    if( c < 0 ) c += M_;
    
    return c + 61;
}

/*
void Virgene_t::Menu()
{
    int option = 0;

    do{
        std::cout << "\t\t- - - M E N U - - -\n\n";
        std::cout << "\t1 - Enter a Key.\n";
        
        if ( !MessageInside )
            std::cout << "\t2 - Enter a Message.\n";
        else
            std::cout << "\t2 - Change the Message.\n";
            std::cout << "\t3 - Encryption.\n";
            std::cout << "\t4 - Decrypting.\n";
        }
        
        if ( KeyActivated )
            std::cout << "\t5 - See the Key\n";
        std::cout << "\t\tOption:\t";
        
        std::cin >> option;
        
        system("clear");        
        
        switch( option )
        {
            case 1:
                break;
            
            case 2:
            
                break;
                
            case 3:
            
                break;
                
            case 4:
            
                break;
        
            case 5:

                break;
        }
        
    }while( option != 0 );
}*/