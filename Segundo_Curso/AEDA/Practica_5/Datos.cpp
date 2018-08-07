#include "Datos.hpp"

Datos_t::Datos_t()
{
    min_ = 9999;
    max_ = 0;
    media_ = 0;
    mediaSum_ = 0;
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

void Datos_t::mediaSumador(float media)
{
	mediaSum_ += media;
}

void Datos_t::mediaSumador(int media)
{
	mediaSum_ += media;
}

void Datos_t::mediaMath(float media, float sz)
{
	media_ = mediaSum_ / sz;
}

void Datos_t::mediaMath(float media, int sz)
{
    media_ = mediaSum_ / sz;
}

void Datos_t::mediaMath(float sz)
{
    media_ = mediaSum_ / sz;
}

void Datos_t::mediaMath(int sz)
{
	media_ = mediaSum_ / sz;
}

void Datos_t::reset(void)
{
    min_ = 9999;
    max_ = 0;
    media_ = 0;
    mediaSum_ = 0;
}


