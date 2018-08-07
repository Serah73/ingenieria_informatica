#pragma once

#include <iostream>


class Datos_t
{
    protected:
        
        int min_;
        int max_;
        float media_;
        float mediaSum_;
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

        void mediaSumador(float media);
        void mediaSumador(int media);

        void mediaMath(float media, float sz);
        void mediaMath(float media, int sz);
        void mediaMath(float sz);
        void mediaMath(int sz);

        void reset(void);
};
