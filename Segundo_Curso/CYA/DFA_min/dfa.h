/**
 * dfa.h
 *
 *  Created on: 19 nov. 2018
 *      Author: Serah
 */

/** @file dfa.h
 *  @brief Clase dfa_t encargada de manipular un DFA.
 *
 *  Contiene los metodos para cargar un DFA a traves de un fichero
 *  para su lectura, interpretacion y analizar las cadenas que quiera 
 *  el usuario.
 *
 *  @author Jose Ramon Rodriguez Hernandez
 */

#ifndef DFA_H_
#define DFA_H_

#pragma once

#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>

#include "state.h"


class dfa_t
{
private:

	bool error_;
	int nstates_, qstart_, error_state_, type_error_;
	std::set<state_t> dfa_;
	std::set<char> alphabet_;

public:
/** @brief Constructor base.
 */
	dfa_t();
	
/** @brief Constructor principal que solo llamara a "build(char )".
 *
 * @param char[] Utilizado para recibir el nombre del fichero que
 * usara el usuario en nuestro NFA.
 */
	dfa_t(char[]);

/** @brief Constructor de copia.
 *
 * @param dfa_t Recibe la clase para crear una copia de si misma.
 */
	dfa_t(const dfa_t &dfa);

/** @brief Destructor.
 */
	virtual ~dfa_t();

/** @brief Constructor que usaremos realmente para esta clase,
 * usado para poder cargar archivos dinamicamente.
 *
 * @param char[] Utilizado para recibir el nombre del fichero que
 * usara el usuario en nuestro NFA.
 */
	void build(char []);

/** @brief Destructor que usaremos realmente para esta clase,
 * se encarga de hacer un clear a todo atributo que lo necesite e
 * inicializar las demas variables. Para leer archivos de forma dinamica.
 */
	void destroy();


//////////////////////////////////////////////////////////////////////////////Get's

/** @brief Devuelve la variable global a la clase error_ para manejarlo
 * posteriormente.
 *
 * @return la variable error_.
 */
	bool get_error() const;

/** @brief Devuelve la variable global a la clase error_ para manejarlo
 * posteriormente.
 *
 * @return la variable error_.
 */
	bool get_error();

/** @brief Devuelve el atributo nstates_
 *
 * @return la variable nstates_
 */
	int get_nstates();

/** @brief Devuelve el atributo nstates_
 *
 * @return la variable nstates_
 */
	int get_nstates() const;

/** @brief Devuelve el atributo qstart_
 *
 * @return la variable qstart_
 */	
	int get_qstart();

/** @brief Devuelve el atributo qstart_
 *
 * @return la variable qstart_
 */	
	int get_qstart() const;

/** @brief Devuelve el atributo error_state_
 *
 * @return la variable error_state_
 */	
	int get_error_state();

/** @brief Devuelve el atributo error_state_
 *
 * @return la variable error_state_
 */	
	int get_error_state() const;

/** @brief Devuelve el atributo type_error_
 *
 * @return la variable type_error_
 */	
	int get_type_error();

/** @brief Devuelve el atributo type_error_
 *
 * @return la variable type_error_
 */	
	int get_type_error() const;

/** @brief Devuelve el atributo alphabet_
 *
 * @return la variable alphabet_
 */	
	std::set<char> get_alphabet();

/** @brief Devuelve el atributo alphabet_
 *
 * @return la variable alphabet_
 */	
	std::set<char> get_alphabet() const;

/** @brief Devuelve el atributo dfa_
 *
 * @return la variable dfa_
 */	
	std::set<state_t> get_dfa();

/** @brief Devuelve el atributo dfa_
 *
 * @return la variable dfa_
 */	
	std::set<state_t> get_dfa() const;

/** @brief Devuelve el estado que recibe por parametro
 * 
 * @param int identificador del estado "id_"
 * 
 * @return el estado donde se encuentra
 */	
	state_t get_state(int);


//////////////////////////////////////////////////////////////////////////////Set's

/** @brief poner a true o false a error_ con el correspondiente
 * tipo de error
 * 
 * @param bool coger y le asigna a error_ el valor
 * 
 * @param int asigna el tipo de error a type_error_
 */	
	void set_error(bool, int );

/** @brief asignar a nstates el numero de estados que recoge 
 * desde el fichero
 * 
 * @param int asigna el numero de estados a nstates_
 */	
	void set_nstates(int );

/** @brief asignar a qstart el numero donde se empieza check_user() 
 * 
 * @param int asigna el comienzo a qstart_
 */	
	void set_qstart(int );

/** @brief asignar a dfa_ los estados que recoge 
 * desde el fichero
 * 
 * @param std::set<state_t> asigna el valor a dfa_
 */	
	void set_dfa(std::set<state_t> );

/** @brief asignar a alphabet_ los simbolos diferentes con los
 * que se transita en el nfa reccogidos
 * desde el fichero
 * 
 * @param std::set<char> asigna el valor a alphabet_
 */	
	void set_alphabet(std::set<char> );

/** @brief asignar a error_state_ el estado que no existe en
 * el fichero
 * 
 * @param int asigna el valor a error_state_
 */	
	void set_error_state(int );


//////////////////////////////////////////////////////////////////////////////Checked

/** @brief comprueba que los estados que estan en el fichero
 * pueden transitar entre si y no lleven a uno que no existe 
 * 
 * @param std::set<state_t> se usa para comprobar todas las
 * transiciones que contiene cada state_t
 * 
 * @return si esta todo como es debido o no
 */	
	bool check_states(std::set<state_t> );

/** @brief comprueba que el formato basico del fichero es correcto
 * 
 * @param char[] el fichero que le envia el usuario
 * 
 * @return si esta todo como es debido o no
 */	
	bool check_format(char[] );

/** @brief Calcula los estados de muerte que contiene el
 * automata
 */	
	void dead_state();

/** @brief Llamada para que muestre por pantalla el tipo
 * de error que se ha manejado durante la ejecucion
 */	
	void error_menu();


//////////////////////////////////////////////////////////////////////////////Others

/** @brief Impresion de la clase
*/	
	void write();


//////////////////////////////////////////////////////////////////////////////Main

/** @brief funcion principal que muestra el menu y maneja
 * las opciones
 */	
	virtual void menu();

/** @brief funcion principal para analizar las cadenas
 * que envie el usuario para ver si son aceptadas por el
 * automata
 * 
 * @param std::string cadena a analizar
 */	
	virtual void check_user(std::string);
//Operator's


////////////////////////////////////////////////////////////////////////////// 2.0

/** @brief Funcion encargada de minimizar el automata
 * 
 *  @param dfa_t& automata que queremos minimizar, ya que no se guarda
 * 	la propia clase que se invoca.
 */
    void minimize(dfa_t&);

    std::set< std::set<state_t> > new_part( std::set< std::set<state_t> >);
    std::set< std::set<state_t> > divide( std::set<state_t>, std::set< std::set<state_t> >);
    std::set< std::set<state_t> > min_core( std::set<state_t>, char, std::set< std::set<state_t> >);


/** @brief imprimir las transiciones que hace el algoritmos
 *  con los simbolos del alfabeto
 * 
 *  @param std::set< std::set<state_t> > conjuntos divididos
 *  @param char simbolo del alfabeto a comprobar
 *  @param std::set< std::set<state_t> > el automata completo
 */
	void print ( std::set< std::set<state_t> > , char , std::set<state_t> , std::set< std::set<state_t> > );

/** @brief funcion encargada de construir el archivo exportable
 * 
 *  @param std::set< std::set<state_t> > conjuntos de estados distingibles
 *  @param int estado de inicio del automata
 *  @param int contador de elementos del conjunto
 *  @param std::set<char> alfabeto del automata
 */
	void build_dfa_min(std::set< std::set<state_t> > , int , int , std::set<char> );

/** @brief funcion encargada de la construccion del archivo que
 *  exporta el dfa minimizado
 */
	void build_file();
	
/** @brief Sobrecarga para que no se necesite crear otra
 * clase, sino reemplace esta.
 * 
 * @param char[] nombre del fichero con el que se carga
 */	
	void operator()(char[] );
};

/** @brief impresion del automata
 *
 * @param sts::ostream lo que usara para la impresion
 * 
 * @param dfa_t usado para la impresion
 * 
 * @return el buffer con la forma de impresion
 */	
std::ostream &operator<<(std::ostream &os, const dfa_t& co);

#endif /** DFA_H_ */