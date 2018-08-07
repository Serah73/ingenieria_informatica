#pragma once

class Calculadora
{
    private:
    
        int min_;
        int max_;
        float media_;
        
        float conteoMedia_;
        
    public:
        
        Calculadora();
        ~Calculadora();
        
        //comprobar que valor es menor o mayor
        void do_min(int valor);
        void do_max(int valor);
        
        int get_min() const;
        int get_max() const;
        
        float manual_media(float valor, int repeticiones);
        float manual_media(int valor, int repeticiones);
        
        //calcular la media con valores que se le van pasando
        void cont_media(int valor);
        //devuelve la media operada
        float Request_media() const;
        
        //reset a los valores solo de la media
        void ResetMedia();
        //vuelta al estado inicial
        void Reset();
};

Calculadora::Calculadora()
{
    Reset();
}

Calculadora::~Calculadora()
{}

void Calculadora::do_min(int valor)
{
    min_ > valor ? min_ = valor : min_;
}

void Calculadora::do_max(int valor)
{
    max_ < valor ? max_ = valor : max_;
}

int Calculadora::get_min() const
{
    return min_;
}

int Calculadora::get_max() const
{
    return max_;
}

float Calculadora::manual_media(float valor, int repeticiones)
{
    float repeticionesA = repeticiones;

    return valor/repeticionesA;
}

float Calculadora::manual_media(int valor, int repeticiones)
{
    float valorA = valor;
    float repeticionesA = repeticiones;

    return valorA/repeticionesA;
}

void Calculadora::cont_media(int valor)
{
    conteoMedia_++;
    media_ += valor;
}

float Calculadora::Request_media() const
{
    return media_/conteoMedia_;
}

void Calculadora::ResetMedia()
{
    media_ = 0;
    conteoMedia_ = 0;
}

void Calculadora::Reset()
{
    min_ = 9999;
    max_ = 0;
    media_ = 0;
    conteoMedia_ = 0;
}
