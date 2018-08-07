#include "transition.h"

transition_t::transition_t(void){}

transition_t::transition_t(const transition_t& transition)
{
    symb_=transition.symb_;
    est_=transition.est_;
}

transition_t::~transition_t(void){}
	
char transition_t::get_symb_(void) const
{
    return symb_;
}

int transition_t::get_est_(void) const
{
    return est_;
}

void transition_t::set_symb_(char c)
{
    symb_ = c;
}

void transition_t::set_est_(int a)
{
    est_ = a;
}