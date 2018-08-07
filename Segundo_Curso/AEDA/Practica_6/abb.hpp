#pragma once

#include"cola.hpp"
#include "node.hpp"

template<class T>
class abb
{
    private:
    
        node_abb<T>* raiz;
    
    public:
    
        abb();
        ~abb(); 
        
        void podar(node_abb<T>* &node);//
        bool vacio(node_abb<T> *node);//
        bool hoja(node_abb<T> *node);
        
        const int tam();
        const int tamRama(node_abb<T>* node);
        
        const int altura();
        const int alturaN(node_abb<T>* node);
        
        node_abb<T>* buscar(T clave_dada, int &conteo);
        node_abb<T>* buscarRama(node_abb<T>* node, T clave_dada, int &conteo);
        
        void insertar(T clave_dada);
        void insertarRama(node_abb<T>* &node, T clave_dada);
        
        void eliminar(T clave_dada);
        void eliminarRama(node_abb<T>* &node, T clave_dada);
        
        void sustituye(node_abb<T>* &eliminado, node_abb<T>* &node_sust);
        void impresionNiveles();
};


template<class T>
abb<T>::abb():
raiz(NULL){}

template<class T>
abb<T>::~abb()
{
    podar(raiz);
}

template<class T>
void abb<T>::podar(node_abb<T>* &node)
{
    if(node == NULL) return;
    
    podar(node->izq);
    podar(node->der);
    
    delete node;
    node = NULL;
}

template<class T>
bool abb<T>::vacio(node_abb<T> *node)
{
    return node==NULL;
}

template<class T>
bool abb<T>::hoja(node_abb<T> *node)
{
    return (!node->der) && (!node->izq);
}

template<class T>
const int abb<T>::tam()
{
    return tamRama(raiz);
}

template<class T>
const int abb<T>::tamRama(node_abb<T>* node)
{
    if (node == NULL) return 0;

    return (1 + tamRama(node->izq) + tamRama(node->der));
}

template<class T>
const int abb<T>::altura()
{
    return alturaN(raiz);
}

template<class T>
const int abb<T>::alturaN(node_abb<T>* node)
{
    if (node == NULL) return 0;
    
    int alt_izq = alturaN(node->izq);
    int alt_der = alturaN(node->der);
    
    if (alt_der > alt_izq)
    {
        alt_der++;
        return alt_der;
    }
    else
    {
        alt_izq++;
        return alt_izq;
    }
}

template<class T>
node_abb<T>* abb<T>::buscar(T clave_dada, int &conteo)
{
    return buscarRama(raiz, clave_dada, conteo);
}

template<class T>
node_abb<T>* abb<T>::buscarRama(node_abb<T>* node, T clave_dada, int &conteo)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(clave_dada == node->clave)
    {
        conteo++;
        return node;
    }
    if(clave_dada < node->clave)
    {
        conteo++;
        return buscarRama(node->izq, clave_dada, conteo);
    }
    else if (clave_dada > node->clave)
    {
        conteo++;
        return buscarRama(node->der, clave_dada, conteo);
    }
    return NULL;
}

template<class T>
void abb<T>::insertar(T clave_dada)
{
    int conteo = 0;
    
    if(buscar(clave_dada, conteo)) return;

    insertarRama(raiz, clave_dada);
}

template<class T>
void abb<T>::insertarRama(node_abb<T>* &node, T clave_dada)
{
    if (node == NULL)
        node = new node_abb<T>(clave_dada, clave_dada);

    else if (clave_dada < node->clave)
        insertarRama(node->izq, clave_dada);

    else
        insertarRama(node->der, clave_dada);
}

template<class T>
void abb<T>::eliminar(T clave_dada)
{
    eliminarRama(raiz, clave_dada);
}

template<class T>
void abb<T>::eliminarRama(node_abb<T>* &node, T clave_dada)
{
    if (node == NULL) return;
    
    if (clave_dada < node->clave)
        eliminarRama(node->izq, clave_dada);
        
    else if(clave_dada > node->clave)
        eliminarRama(node->der, clave_dada);
    
    else{
        node_abb<T>* eliminado = node;
        
        if(node->der == NULL)
            node = node->izq;
        
        else if(node->izq == NULL)
            node = node->der;
        
        else
            sustituye(eliminado, node->izq);
        
        delete eliminado;
    }
}

template<class T>
void abb<T>::sustituye(node_abb<T>* &eliminado, node_abb<T>* &node_sust)
{
    if(node_sust->der != NULL)
        sustituye(eliminado, node_sust->der);

    else
    {
        eliminado->dato = node_sust->dato;
        eliminado->clave = node_sust->clave;
        eliminado = node_sust;
    
        node_sust = node_sust->izq;
    }
}

template<class T>
void abb<T>::impresionNiveles()
{
    int nivel, nivel_actual = 0;

    cola< node_abb<T>* > Q;
    node_abb<T>* node;
     
    Q.insertar(raiz, 0);
        
    cout << "nivel " << nivel_actual << ": ";
    
    while(!Q.vacia())
    {
        bool primero = 0;
        Q.extraer(node, nivel);
        
        if (nivel > nivel_actual)
        {
            primero  = true;
            nivel_actual = nivel;
            cout << endl;
        }
        
        if(primero)
            cout << "nivel " << nivel_actual << ": ";

        if(node != NULL)
        {
            cout << "[" << node->clave << "]" << " ";
            Q.insertar(node->izq, nivel + 1);
            Q.insertar(node->der, nivel + 1);
        }
        else
            cout << "[.] ";
    
    }
    cout << endl;
}
