#pragma once

#include "state.h"
#include "transition.h"
#include <set>


class dfa_t {

private:

	int num_states_;
	int state_ini_;
	set<state_t> states_;
	set<char> alpha_;

public:

	dfa_t(void);
	dfa_t(const dfa_t& dfa);
	~dfa_t(void);


	bool define(void);
	void clear(void);
	void state_death(void);
	void check_string(const string& cadena, ostream& os) const;

	istream& read(istream& is);
	ostream& write(ostream& os);

};