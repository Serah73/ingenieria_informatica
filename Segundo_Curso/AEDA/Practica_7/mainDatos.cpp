#include"Datos.hpp"
#include<iostream>

int main(void)
{
    Calculadora calculadora;
    
    int numero = 5;
    int maximo = 7;
    int media = 10;
    
    calculadora.do_min(numero);
    calculadora.do_max(maximo);
    
    for(int i = 0; i < 10; i++)
    {
        calculadora.do_media(i);
    }
        
    std::cout << "min: " << calculadora.get_min() << std::endl;
    std::cout << "max: " << calculadora.get_max() << std::endl;
    std::cout << "media manual: " << calculadora.manual_media(media, 3) << std::endl;
    std::cout << "media elaborada: " << calculadora.Request_media() << std::endl;
    
}