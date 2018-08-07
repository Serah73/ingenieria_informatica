#pragma once

#include <iostream>

using namespace std;

template<class T>
class celda
{
    private:

        unsigned int nbloques;
        T* vBloques;
        int comparaciones;
        int inserciones;

    public:

        celda<T>():
        comparaciones(0){}

        celda<T>(int n): nbloques(n), comparaciones(0)
        {
            vBloques = new T [nbloques];
            
            for(int i = 0; i < nbloques; i++)
                vBloques[i] = 0;
        }
        
        ~celda<T>()
        {
            if (vBloques != NULL)
            {
                nbloques = 0;
                delete[] vBloques;
                vBloques = NULL;
            }
        }
        
        int get_nBloques() const
        {
            return nbloques;
        }
        
        int& get_nBloques()
        {
            return nbloques;
        }
        
        T get_bloque(int pos) const
        {
            return vBloques[pos];
        }
        
        T& get_bloque(int pos)
        {
            return vBloques[pos];
        }
        
        void resize(int n)
        {
            nbloques = n;
            vBloques = new T [n];
        }
        
        bool full()
        {
            for (int i = 0; i < nbloques; i++)
                if (vBloques[i] == 0)
                    return false;
            return true;
        }
        
        bool existe(T x)
        {
            for( int i = 0; i < nbloques; i++)
            {
                comparaciones++;
                
                if (x == vBloques[i])
                    return true;
            }
            return false;
        }
        
        bool insertar(T x)
        {
            if(existe(x))
            {
                inserciones++;
                return true;
            }
            if(!full())
            {
                for (int i = 0; i < nbloques; i++)
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
        
        void limpiar()
        {
            for (int i = 0; i < nbloques; i++)
                vBloques[i] = 0;
        }
       
        void mostrar()
        {
            cout << "numero de bloques: " << nbloques << endl;
        
            for (int i = 0; i < nbloques; i++)
                cout << vBloques[i] << " ";
            
            cout << endl;
        
        }
        
        int get_comparaciones()
        {
            return comparaciones;
        }
        
        void limpiarComparaciones()
        {
            comparaciones = 0;
        }
        
        int get_inserciones()
        {
            return inserciones;
        }
        
        void limpiarInserciones()
        {
            inserciones = 0;
        }
};