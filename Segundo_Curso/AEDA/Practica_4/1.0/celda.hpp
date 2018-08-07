#pragma once

#include <iostream>

template<class T>
class celda_t
{
    private:
    
        unsigned int nbloques;
        T* vBloques;
        int comparaciones;
        int inserciones;
        
    public:
    
        celda_t();
        celda_t(int n);
        ~celda_t();
        
        int get_nbloques() const;
        int& get_nbloques();
        T get_bloque(int pos) const;
        T& get_bloque(int pos);
        int get_comparaciones() const;
        int get_inserciones() const;
        
        void limpiar_comparaciones();
        void limpiar_inserciones();
        
        void resize(int n);
        bool full();
        bool existe(T x);
        
        void insertar(T x);
        void limpiar();
        void mostrar();
};


template<class T>
celda_t<T>::celda_t():
comparaciones(0){}

template<class T>
celda_t<T>::celda_t(int n):
nbloques(n),
comparaciones(0)
{
    vBloques = new T [nbloques];
    
    for(int i = 0; i > nbloques; i++)
        vBloques[i] = 0;
}
    
template<class T>
celda_t<T>::~celda_t()
{
    if (vBloques != NULL)
    {
        nbloques = 0;
        delete[] vBloques;
        vBloques = NULL;
    }
}
    
template<class T>
int celda_t<T>::get_nbloques() const
{
    return nbloques;
}
    
template<class T>
int& celda_t<T>::get_nbloques()
{
    return nbloques;
}
    
template<class T>
T celda_t<T>::get_bloque(int pos) const
{
    return vBloques[pos];
}
    
template<class T>
T& celda_t<T>::get_bloque(int pos)
{
    return vBloques[pos];
}
    
template<class T>
int celda_t<T>::get_comparaciones() const
{
    return comparaciones;
}
    
template<class T>
int celda_t<T>::get_inserciones() const
{
    return inserciones;
}
    
template<class T>
void celda_t<T>::limpiar_comparaciones()
{
    comparaciones = 0;
}
    
template<class T>
void celda_t<T>::limpiar_inserciones()
{
    inserciones = 0;
}
    
template<class T>
void celda_t<T>::resize(int n)
{
    nbloques = n;
    vBloques = new T [n];
}
    
template<class T>
bool celda_t<T>::full()
{
    for (int i = 0; i < nbloques; i++)
        if (vBloques[i] == 0)
            return false;
    return true;
}
    
template<class T>
bool celda_t<T>::existe(T x)
{
    for(int i = 0; i < nbloques; i++)
    {
        comparaciones++;
        
        if(x == vBloques[i])
            return true;
    }
    return false;
}
    
template<class T>
void celda_t<T>::insertar(T x)
{
    if(existe(x))
    {
        inserciones++;
        return true;
    }
    if(!full())
    {
        for(int i = 0; i < nbloques; i++)
        {
            inserciones++;
            
            if(vBloques[i] == 0)
            {
                vBloques[i] = x;
                return true;
            }
        }
    }
    inserciones++;
    return false;
}
    
template<class T>
void celda_t<T>::limpiar()
{
    for (int i = 0; i < nbloques; i++)
        vBloques[i] = 0;
}
    
template<class T>
void celda_t<T>::mostrar()
{
    std::cout << "numero de bloques: " << nbloques << std:: endl;
    
    for(int i = 0; i < nbloques; i++)
        std:: cout << vBloques[i] << " ";
    
    std::cout << std::endl;
}