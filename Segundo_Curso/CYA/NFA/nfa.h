/** @file nfa.h
 *  @brief Clase Nfa_t encargada de manipular un NFA
 *  a traves de herencia, recibiendo dfa_t.
 *
 *  Contiene los metodos para cargar un NFA a traves de un fichero
 *  para su lectura, interpretacion y analizar las cadenas que quiera 
 *  el usuario. Reutilizando la clase dfa_t para ahorrar trabajo(herencia)
 *
 *  @author Jose Ramon Rodriguez Hernandez
 */


#ifndef NFA_H_
#define NFA_H_


#pragma once

#include "dfa.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <ios>

class Nfa_t: public dfa_t
{
    public:

/** @brief Constructor
 */	
        Nfa_t();

/** @brief Constructor de copia
 *
 * @param char[] fichero que se usara para crear la clase
 */	
	    Nfa_t(char[]);

/** @brief Constructor de copia.
 *
 * @param Nfa_t Recibe la clase para crear una copia de si misma.
 */
	    Nfa_t(const Nfa_t &nfa);

/** @brief Destructor.
 */
        virtual ~Nfa_t();


    ////Main

/** @brief Mira cuales son los estados importantes del automata
 */    
        void important_state();

/** @brief Mira si es un dfa
 *
 * @return si lo es o no
 */   
        bool its_dfa();

/** @brief Recursividad para mirar los recorridos posibles
 * para el automata
 * 
 * @param state_t estado a comprobar
 * @param std::stringbuf impresion de la traza
 * @param std::string cadena que se va a analizar
 * @param int la posicion donde esta de la cadena
 * @param int id_ del siguiente estado
 * @param bool para saber si ha sido aceptada la cadena en algun recorrido
 * @param int saber que recorrido esta haciendo
 */   
        void ways(state_t, const std::stringbuf&, std::string, int, int, bool&, int&);  

/** @brief analiza la cadena que le manda el usuario
 * 
 * @param std::string cadena a analizar
 */   
        void check_user(std::string);      

/** @brief menu que interactua con el usuario y maneja las opciones
 */   
        void menu();
};

/** @brief impresion del automata
 *
 * @param sts::ostream lo que usara para la impresion
 * 
 * @param Nfa_t usado para la impresion
 * 
 * @return el buffer con la forma de impresion
 */	
std::ostream &operator<<(std::ostream &os, const Nfa_t& nfao);

#endif /** NFA_H_ */