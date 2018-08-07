#include <iostream>
#include <stdlib.h>

#include "cola.hpp"

using namespace std;

template<class T> class node_AVL {
    public:
        T dato;
        T clave;
        int bal;
        node_AVL<T>* izq;
        node_AVL<T>* der;
        node_AVL(T d, T c): dato(d), clave(c), bal(0), izq(NULL), der(NULL){};
};

template<class T> class AVL {
    private:
        node_AVL<T>* raiz;
    public:
        AVL():raiz(NULL){}
        ~AVL(){
            podar(raiz);
        }
        
        void podar(node_AVL<T>* &node){
            if(node == NULL) return;
            podar(node->izq);
            podar(node->der);
            delete node;
            node = NULL;
        }
        bool vacio(node_AVL<T>* node){
            return node == NULL;
        }
        bool hoja(node_AVL<T>* node){
            return (!node->der) && (!node->izq);
        }
        
        const int tam(){
            return tamRama(raiz);
        }
        const int tamRama(node_AVL<T>* node){
            if (node == NULL) return 0;
            return (1 + tamRama(node->izq) + tamRama(node->der) );
        }
        
        const int altura(){
            return alturaN(raiz);
        }
        const int alturaN(node_AVL<T>* node){
            if (node == NULL) return 0;
            int alt_izq = alturaN(node->izq);
            int alt_der = alturaN(node->der);
            
            if (alt_der > alt_izq){
                alt_der++;
                return alt_der;
            }
            else{
                alt_izq++;
                return alt_izq;
            }
        }
        
        node_AVL<T>* buscar(T clave_dada, int &conteo){
            return buscarRama(raiz, clave_dada, conteo);
        }
        node_AVL<T>* buscarRama(node_AVL<T>* node, T clave_dada, int &conteo){
            if(clave_dada == node->clave){
                conteo++;
                return node;
            }
            if(clave_dada < node->clave){
                conteo++;
                return buscarRama(node->izq, clave_dada, conteo);
            }
            else if (clave_dada > node->clave){
                conteo++;
                return buscarRama(node->der, clave_dada, conteo);
            }
            return NULL;
        }
        
        void rotacion_II(node_AVL<T>* &node){
            node_AVL<T>* node_aux_1 = node->izq;
            node->izq = node_aux_1->der;
            node_aux_1->der = node;
            if (node_aux_1->bal == 1) {
                node->bal = 0;
                node_aux_1->bal = 0;
            }
            else { 
                node->bal = 1;
                node_aux_1->bal = -1;
            }
            node = node_aux_1;
        }
        void rotacion_DD (node_AVL<T>* &node) {
            node_AVL<T>* node_aux_1 = node->der;
            node->der = node_aux_1->izq;
            node_aux_1->izq = node ;
            if (node_aux_1->bal == -1) {
                node->bal = 0;
                node_aux_1->bal = 0;
            }
            else { // node_aux_1->bal == 0
                node->bal = -1;
                node_aux_1->bal = 1;
            }
            node = node_aux_1;
        }
        void rotacion_ID (node_AVL<T>* &node) {
            node_AVL<T>* node_aux_1 = node->izq;
            node_AVL<T>* node_aux_2 = node_aux_1->der;
            
            node->izq = node_aux_2->der;
            node_aux_2->der = node;
            node_aux_1->der = node_aux_2->izq;
            node_aux_2->izq = node_aux_1;
            
            if (node_aux_2->bal == -1)
                node_aux_1->bal = 1;
            else 
                node_aux_1->bal = 0;
            
            if (node_aux_2->bal == 1)
                node->bal = -1;
            else 
                node->bal = 0;
            
            node_aux_2->bal = 0;
            node = node_aux_2;
        }
        void rotacion_DI (node_AVL<T>* &node) {
            node_AVL<T>* node_aux_1 = node->der;
            node_AVL<T>* node_aux_2 = node_aux_1->izq;
            
            node->der = node_aux_2->izq;
            node_aux_2->izq = node;
            node_aux_1->izq = node_aux_2->der;
            node_aux_2->der = node_aux_1;
            
            if (node_aux_2->bal == 1)
                node_aux_1->bal = -1;
            else 
                node_aux_1->bal = 0;
 
            if (node_aux_2->bal == -1)
                node->bal = 1;
            else 
                node->bal = 0;
 
            node_aux_2->bal = 0;
            node = node_aux_2;
        }
        
        void Insertar( T clave_dada) {
            node_AVL<T>* nuevo = new node_AVL<T>( clave_dada, clave_dada );
            bool crece = false;
            inserta_bal(raiz, nuevo, crece);
        }
        void inserta_bal( node_AVL<T>* &node, node_AVL<T>* nuevo, bool& crece) {
            if (node == NULL) {
                node = nuevo;
                crece = true;
            }
            else if (nuevo->clave < node->clave) {
                inserta_bal(node->izq,nuevo,crece);
                if (crece) 
                    insert_re_balancea_izda(node, crece);
            }
            else {
                inserta_bal(node->der,nuevo,crece);
                if (crece) 
                    insert_re_balancea_dcha(node, crece);
            }
        }
        
        void insert_re_balancea_izda(node_AVL<T>* &node, bool &crece) {
            switch (node->bal) {
                case -1: 
                    node->bal = 0;
                    crece = false;
                break;
                case 0: 
                    node->bal = 1 ;
                break;
                case 1: 
                    node_AVL<T>* node1 = node->izq;
                    if (node1->bal == 1)
                        rotacion_II(node);
                    else rotacion_ID(node);
                    crece = false;
            }
        }
        void insert_re_balancea_dcha (node_AVL<T>* &node, bool &crece) {
            switch (node->bal) {
                case 1: 
                    node->bal = 0;
                    crece = false;
                break;
                case 0: 
                    node->bal = -1;
                break;
                case -1: 
                    node_AVL<T>* node1 = node->der;
                    if (node1->bal == -1)
                        rotacion_DD(node);
                    else 
                        rotacion_DI(node);
                    crece = false;
            }
        }
        
        void eliminar( T clave_dada) {
            bool decrece = false;
            elimina_rama(raiz, clave_dada, decrece);
        }
        void elimina_rama( node_AVL<T>* &node, T clave_dada, bool& decrece) {
            if (node == NULL) return;
            
            if (clave_dada < node->clave) {
                elimina_rama(node->izq,clave_dada,decrece);
                if (decrece)
                    eliminar_re_balancea_izda(node,decrece);
            }
            else if (clave_dada > node->clave) {
                elimina_rama(node->der,clave_dada,decrece);
                if (decrece)
                    eliminar_re_balancea_dcha(node,decrece);
            }
            else { // node->clave == clave_dada(encontrado)
                node_AVL<T>* Eliminado = node;
                if (node->izq == NULL) {
                    node = node->der;
                    decrece = true;
                }
                else if (node->der == NULL) {
                    node = node->izq;
                    decrece = true;
                }
                else {
                    sustituye(Eliminado,node->izq,decrece);
                
                    if (decrece)
                        eliminar_re_balancea_izda(node,decrece);
                }
                delete Eliminado;
            }
        }
        void sustituye(node_AVL<T>* &eliminado, node_AVL<T>* &sust, bool &decrece) {
            if (sust->der != NULL) {
                sustituye(eliminado, sust->der, decrece);
                if (decrece)
                    eliminar_re_balancea_dcha(sust, decrece);
            }
            else {
                eliminado->dato = sust->dato;
                eliminado->clave = sust->clave;
                eliminado = sust;
                sust = sust->izq;
                decrece = true;
            }
        }
        
        void eliminar_re_balancea_izda (node_AVL<T>* &node, bool& decrece) {
            switch (node->bal) {
                case -1:{ 
                    node_AVL<T>* node1 = node->der;
                    if (node1->bal > 0)
                        rotacion_DI(node);
                    else {
                        if (node1->bal == 0)
                            decrece = false;
                        rotacion_DD(node);
                    }
                }
                break;
                case 0:{ 
                    node->bal = -1;
                    decrece = false;
                }
                break;
                case 1:{ 
                    node->bal = 0;
                }
            }
        }
        void eliminar_re_balancea_dcha (node_AVL<T>* &node, bool& decrece) {
            switch (node->bal) {
                case 1:{ 
                    node_AVL<T>* node1 = node->izq;
                    if (node1->bal < 0)
                        rotacion_ID(node);
                    else {
                        if (node1->bal == 0)
                            decrece = false;
                        rotacion_II(node);
                    }
                }
                break;
                case 0:{ 
                    node->bal = 1;
                    decrece = false;
                }
                break;
                case -1:{ 
                    node->bal = 0;
                }
            }
        }
        
        void impresionNiveles(){
            cola< node_AVL<T>* > Q;
            node_AVL<T>* node;
            int nivel, nivel_actual = 0;
            
            Q.insertar(raiz, 0);
            int alt = 0;
            
            cout << "nivel " << nivel_actual << ": ";
            while(!Q.vacia()){
                bool primero = 0;
                Q.extraer(node, nivel);
                if (nivel > nivel_actual){
                    primero  = true;
                    nivel_actual = nivel;
                    cout << endl;
                }
                if(primero){
                    cout << "nivel " << nivel_actual << ": ";
                }
                if(node != NULL){
                    cout << "[" << node->clave << "]" << " ";
                    Q.insertar(node->izq, nivel + 1);
                    Q.insertar(node->der, nivel + 1);
                }
                else{
                    cout << "[.] ";
                }
            }
            cout << endl;
        }
        
};
