#pragma once

#include <iostream>

class transition_t{
		
		char symb_;
		int est_;
	
	public:
		transition_t(void);
		transition_t(const transition_t& transition);
		~transition_t(void);

		char get_symb_(void) const;
		int get_est_(void) const;
		void set_symb_(char);
		void set_est_(int);
};