/*
 * dfa.h
 *
 *  Created on: 19 nov. 2018
 *      Author: Serah
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

	int nstates_, qstart_, error_state_;
	std::set<state_t> dfa_;
	std::set<char> alphabet_;

	bool error_;

public:

	dfa_t();
	dfa_t(char[]);
	dfa_t(const dfa_t &dfa);
	virtual ~dfa_t();

	void build(char []);

//Get's
	int get_nstates();
	int get_nstates() const;
	int get_qstart();
	int get_qstart() const;
	int get_error_state();
	int get_error_state() const;
	std::set<char> get_alphabet();
	std::set<char> get_alphabet() const;

	bool error();

	std::set<state_t> get_dfa();
	std::set<state_t> get_dfa() const;

	state_t get_state(int);

//Set's
	void set_error_state(int);

//Checked
	bool check_states(std::set<state_t>);
	bool check_format(char[]);
	void dead_state();
	void write();

//Main
	void menu();
	void check_user(std::string);
//Operator's
	void operator()(char[]);
};


std::ostream &operator<<(std::ostream &os, const dfa_t& co);

#endif /* DFA_H_ */


