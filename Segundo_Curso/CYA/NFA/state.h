/**
 * state.h
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
 */

/** @file state.h
 *  @brief Clase state_t encargada de manejar los nodos de un automata.
 *
 *  Contiene los metodos para manejar la linea de fichero que le manda
 *  una clase superior(esta practica Nfa_t) para crear y catalogar 
 *  el estado.
 *
 *  @author Jose Ramon Rodriguez Hernandez
 */


#ifndef STATE_H_
#define STATE_H_

#pragma once

#include "transition.h"

#include <string>
#include <vector>
#include <set>


class state_t
{
private:

	int id_, state_;
	std::vector<transition_t> transition_;

public:

/** @brief Constructor
 */	
	state_t();

/** @brief Constructor parametrizado
 *
 * @param std::string recibe desde fichero
 */	
	state_t(std::string str);

/** @brief Destructor
 */	
	virtual ~state_t();

//Get's

/** @brief Devuelve la identidad del estado
 *
 * @return id_ identidad
 */	
	int get_id() const;

/** @brief Devuelve la identidad del estado
 *
 * @return id_ identidad
 */	
	int get_id();

/** @brief devuelve si es de aceptacion o no
 *
 * @return state_ aceptacion
 */	
	int get_state() const;

/** @brief devuelve si es de aceptacion o no
 *
 * @return state_ aceptacion
 */	
	int get_state();

	std::vector<transition_t> get_transition() const;
	std::vector<transition_t> get_transition();

	std::set<int> get_transition(char) const;
	std::set<int> get_transition(char);

	std::set<int> get_clausura() const;
	std::set<int> get_clausura();


////Checked

/** @brief Comprobacion de si se trata de un estado de muerte
 *
 * @return si se trata de uno.
 */
	bool check_dead();

/** @brief Comprobacion de si se trata de un estado importante
 *
 * @return si se trata o no.
 */
	bool check_imp();

////Useless

	std::vector<char> walk_transition();
	std::vector<int> states_transition();

////Operator's

/** @brief Sobrecarga al operador "=" para facilitar al uso
 * 
 * @param state_t se igualaran los atributos
 * 
 * @return resultado de la igualacion
 */
	state_t &operator=(const state_t &state);
	
/** @brief Sobrecarga al operador "==" para facilitar al uso
 * 
 * @param state_t comparar con sus atributos
 * 
 * @return resultado de la comparacion
 */
	bool operator==(const state_t &state) const;
	
/** @brief Sobrecarga al operador "<" para el uso de std::set
 * 
 * @param state_t comparar atributos
 * 
 * @return resultado de la comparacion
 */
	bool operator<(const state_t &state) const;
};

/** @brief impresion del estado
 *
 * @param sts::ostream lo que usara para la impresion
 * 
 * @param state_t usado para la impresion
 * 
 * @return el buffer con la forma de impresion
 */
std::ostream &operator<<(std::ostream &os, const state_t& co);

#endif /** STATE_H_ */
