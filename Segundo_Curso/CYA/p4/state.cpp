#include "state.h"


state_t::state_t (void) {}

state_t::state_t (int id) 
{
	id_ = id;
}


state_t::state_t (const state_t& state) 
{
	id_ = state.id_;
	acceptance_ = state.acceptance_;
	next_ = state.next_;
}

state_t::~state_t(void) {}


int state_t::get_id (void) const 
{
	return id_;
}


int state_t::num_transitions (void) const 
{
	return next_.size();
}


char state_t::get_symb (int a) const 
{
	return next_[a].get_symb_();
}


int state_t::acceptance (void) const 
{
	return acceptance_;
}


bool state_t::stateDeath (void) const 
{
	bool st_death = true;

	if(acceptance_)
		st_death = false;

	else
	{
		int i = 0;

		while((i < next_.size()) && st_death) 
		{
			if(next_[i].get_est_() != id_)
				st_death = false;

			i++;
		}
	}

	return st_death;
}


bool state_t::check_sym (char sym) const 
{
	int adder = 0;
	bool sure;

	for(int i = 0; i < next_.size(); i++)
		if(next_[i].get_symb_() == sym)
			adder++;
	
	if(adder == 1) sure = true;

	else sure = false;

	return sure;
}


int state_t::get_next (char sym) const 
{
	bool found;
	int next = -1;
	int i = 0;

	do 
	{
		if(next_[i].get_symb_() == sym) 
		{
			next = next_[i].get_est_();
			found = true;
		}
		i++;
	} while((!found) && (i < next_.size()));

	return next;
}


istream& state_t::read (istream& is) 
{
	int sz, a;
	char c;
	is >> id_ >> acceptance_ >> sz;
	next_.resize(sz);

	for(int i = 0; i < next_.size(); i++) {
		is >> c >> a;
		next_[i].set_symb_(c);
		next_[i].set_est_(a);
	}

	return is;
}


ostream& state_t::write (ostream& os) const 
{
	os << id_ << ' ' << acceptance_ << ' ' << next_.size();
	for(int i = 0; i < next_.size(); i++)
		os << ' ' << next_[i].get_symb_() << ' ' << next_[i].get_est_();

	return os;
}


state_t& state_t::operator= (const state_t& state) 
{
	id_ = state.id_;
	acceptance_ = state.acceptance_;
	next_ = state.next_;
}


bool state_t::operator== (const state_t& state) const 
{
	return(id_ == state.id_);
}


bool state_t::operator< (const state_t& state) const 
{
	return(id_ < state.id_);
}