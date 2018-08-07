#include "Datos.hpp"

Datos_t::Datos_t()
{
    min_ = 9999;
    max_ = 0;
    media_ = 0;
    SumMedia_ = 0;
    contador_ = 0;
}

Datos_t::~Datos_t(){}

int Datos_t::get_min(void) const
{
    return min_;
}

int Datos_t::get_max(void) const
{
    return max_;
}

float Datos_t::get_media(void) const
{
    return media_;
}

int Datos_t::get_contador() const
{
    return contador_;    
}

void Datos_t::shift()
{
    contador_++;
}

void Datos_t::resetC()
{
    contador_ = 0;
}

void Datos_t::minimo(int &min)
{
	if(min_ >= min) min_ = min;
}

void Datos_t::maximo(int &max)
{
	if(max_ <= max) max_ = max;
}

void Datos_t::SumadorMedia(float media)
{
	SumMedia_ += media;
	shift();
}

void Datos_t::SumadorMedia(int media)
{
	SumMedia_ += media;
	shift();
}

void Datos_t::mediaMath()
{
	media_ = SumMedia_ / contador_;
}

void Datos_t::reset(void)
{
    min_ = 9999;
    max_ = 0;
    media_ = 0;
    SumMedia_ = 0;
}
