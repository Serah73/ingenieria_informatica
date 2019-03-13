/*
 * state.cpp
 *
 *  Created on: 16 nov. 2018
 *      Author: Serah
 */

#include "state.h"

state_t::state_t():
id_(0),
state_(0)
{}


state_t::state_t(std::string str)
{
	id_ = 0, state_ = 0;
	int num, aux_n;
	char aux;

	std::istringstream ss(str);

	   ss >> (int &)id_ >> (int &)state_ >> (int &)num;
	    //cout << "Traza: " << id_ << " " << acept_ << " " << num_t;
	    for (int i = 0; i < num; i++)
	    {
	        ss >> (char &) aux >> (int &)aux_n;

	        transition_t temp(aux, aux_n);

	        transition_.push_back(temp);
	    }
}


state_t::~state_t() {}

//Get's
int state_t::get_id() const
{
	return id_;
}
int state_t::get_id()
{
	return id_;
}

int state_t::get_state() const
{
	return state_;
}
int state_t::get_state()
{
	return state_;
}

std::vector<transition_t> state_t::get_transition() const
{
	return transition_;
}

std::vector<transition_t> state_t::get_transition()
{
	return transition_;
}


//Checked
bool state_t::check_dead()
{
    int i = 0;
    int size = transition_.size();

    if(state_ == 1)
        return false;
    else
        while( i < size )
        {

            if(id_ != transition_[i].get_next())
                return false;
            else
                i++;
        }

    return true;
}

//Main
std::vector<char> state_t::walk_transition()
{
	std::vector<char> v; v.clear();

	int size = transition_.size();

	for (int i = 0; i < size; i++)
	{
		char aux;

		aux = transition_[i].get_symbol();
		v.push_back(aux);
	}

	return v;
}

std::vector<int> state_t::states_transition()
{
	std::vector<int> v; v.clear();

	int size = transition_.size();

	for (int i = 0; i < size; i++)
	{
		char aux;

		aux = transition_[i].get_next();
		v.push_back(aux);
	}

	return v;
}

//Operator's
state_t& state_t::operator=(const state_t &state)
{
	this->id_ = state.id_;
	this->state_ = state.state_;
	this->transition_ = state.transition_;

	return *this;
}

bool state_t::operator==(const state_t &state) const
{
	if (this->id_ == state.id_) return true;
	else
		return false;
}

bool state_t::operator<(const state_t &state) const
{
	if (this->id_ < state.id_) return true;
	else
		return false;
}

std::ostream &operator<<(std::ostream &os, const state_t& state)
{
	int size = state.get_transition().size();

	os << state.get_id() << " " << state.get_state() << " " << size << " ";

	 for (int i = 0; i < size; i++)
		 os << state.get_transition()[i];

	 return os;
}
