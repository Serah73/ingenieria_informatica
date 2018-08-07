#pragma once

#include <iostream>


class Datos_t
{
    protected:
        
        int min_;
        int max_;
        float media_;
        float SumMedia_;
        int contador_;
        
    public:
    
        Datos_t();
        ~Datos_t();
        
        int get_min(void) const;
        int get_max(void) const;
        float get_media(void) const;
        int get_contador(void) const;
        
        void shift();
        void resetC();
        
        void minimo(int &min);
        void maximo(int &max);

        void SumadorMedia(float media);
        void SumadorMedia(int media);

        void mediaMath();

        void reset(void);
};
