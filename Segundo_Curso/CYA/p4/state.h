#pragma once

#include "transition.h"

#include<iostream>
#include<vector>

using namespace std;


class state_t {

private:

	int id_;
	int acceptance_;
	vector<transition_t> next_;								

public:

	state_t (void);
	state_t(int id);
	state_t (const state_t& state);
	~state_t (void);

	int get_id (void) const;
	int num_transitions (void) const;
	char get_symb (int a) const;

	int acceptance (void) const;
	bool stateDeath (void) const;

	bool check_sym (char sym) const;
	int get_next (char sym) const;

	istream& read (istream& is);
	ostream& write (ostream& os) const;

	state_t& operator= (const state_t& state);
	bool operator== (const state_t& state) const;
	bool operator< (const state_t& state) const;

};