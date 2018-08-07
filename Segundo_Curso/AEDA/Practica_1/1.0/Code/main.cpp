#include "stack.h"
#include "list_s.h"
#include "vector.h"


int main(void)
{
    
    
    lista_s lista_pila;

    
//  10
    stack pila_10;
    vector pair_10[2];
    
    pila_10.push(10);
    pila_10.push(5);
    pila_10.push(2);
    pila_10.push(1);
    
    pair_10[1] = pila_10;
    pair_10[0] = 10;
    
    lista_pila.insert_head(pair_10);
    
//  9
    stack pila_9;
    vector pair_9[2];
        
    pila_9.push(9);
    pila_9.push(3);
    pila_9.push(1);
    
    pair_9[1] = pila_9;
    pair_9[0] = 9;
    
    lista_pila.insert_head(pair_9);
    
//  8
    stack pila_8;
    vector pair_8[2];
        
    pila_8.push(8);
    pila_8.push(4);
    pila_8.push(2);
    pila_8.push(1);
    
    pair_8[1] = pila_8;
    pair_8[0] = 8;
    
    lista_pila.insert_head(pair_8);
    
//  7
    stack pila_7;
    vector pair_7[2];
        
    pila_7.push(7);
    pila_7.push(3);
    pila_7.push(1);
    
    pair_7[1] = pila_7;
    pair_7[0] = 7;
    
    lista_pila.insert_head(pair_7);
    
//  6
    stack pila_6;
    vector pair_6[2];
        
    pila_6.push(6);
    pila_6.push(3);
    pila_6.push(2);
    pila_6.push(1);
    
    pair_6[1] = pila_6;
    pair_6[0] = 6;
    
    lista_pila.insert_head(pair_6);
    

//  5
    stack pila_5;
    vector pair_5[2];
        
    pila_5.push(5);
    pila_5.push(1);
    
    pair_5[1] = pila_5;
    pair_5[0] = 5;
    
    lista_pila.insert_head(pair_5);
    
//  4
    stack pila_4;
    vector pair_4[2];
        
    pila_4.push(4);
    pila_4.push(2);
    pila_4.push(1);
    
    pair_4[1] = pila_4;
    pair_4[0] = 4;
    
    lista_pila.insert_head(pair_4);
    
    
//  3
    stack pila_3;
    vector pair_3[2];
        
    pila_3.push(3);
    pila_3.push(1);
    
    pair_3[1] = pila_3;
    pair_3[0] = 3;
    
    lista_pila.insert_head(pair_3);
    
    
//  2
    stack pila_2;
    vector pair_2[2];
        
    pila_2.push(2);
    pila_2.push(1);
    
    pair_2[1] = pila_2;
    pair_2[0] = 2;
    
    lista_pila.insert_head(pair_2);
    
//  1
    stack pila_1;
    vector pair_1[2];
    
    pila_3.push(1);
    
    pair_1[1] = pila_1;
    pair_1[0] = 1;
    
    lista_pila.insert_head(pair_1);
    
    return 0;
}