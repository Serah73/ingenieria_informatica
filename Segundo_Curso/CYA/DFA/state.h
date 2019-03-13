/*
 * state.h
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
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

	state_t();
	state_t(std::string str);
	virtual ~state_t();

//Get's
	int get_id() const;
	int get_id();

	int get_state() const;
	int get_state();

	std::vector<transition_t> get_transition() const;
	std::vector<transition_t> get_transition();


//Checked
	bool check_dead();

//Main
	std::vector<char> walk_transition();
	std::vector<int> states_transition();

//Operator's
	state_t &operator=(const state_t &state);
	bool operator==(const state_t &state) const;
	bool operator<(const state_t &state) const;
};

std::ostream &operator<<(std::ostream &os, const state_t& co);

#endif /* STATE_H_ */
