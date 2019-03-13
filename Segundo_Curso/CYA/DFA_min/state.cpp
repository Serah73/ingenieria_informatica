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
std::set<int> state_t::get_transition(char str) const
{
	std::set<int> setty;

	for ( int i = 0; i < transition_.size(); i++)
		if ( transition_[i].get_symbol() == str)
			setty.insert(transition_[i].get_next());

	return setty;
}
std::set<int> state_t::get_transition(char str)
{
	std::set<int> setty;

	for ( int i = 0; i < transition_.size(); i++)
		if ( transition_[i].get_symbol() == str)
			setty.insert(transition_[i].get_next());

	return setty;
}
std::set<int> state_t::get_clausura() const
{
	std::set<int> setty;

	for ( int i = 0; i < transition_.size(); i++)
		if ( ( transition_[i].get_symbol() == '~') || ( transition_[i].get_symbol() == '&') )
			setty.insert(transition_[i].get_next());

	return setty;
}
std::set<int> state_t::get_clausura()
{
	std::set<int> setty;

	for ( int i = 0; i < transition_.size(); i++)
		if ( ( transition_[i].get_symbol() == '~') || ( transition_[i].get_symbol() == '&') )
			setty.insert(transition_[i].get_next());

	return setty;
}

//Set's


void state_t::set_id( int id )
{
	id_ = id;
}


void state_t::set_state( int state )
{
	state_ = state;
}


void state_t::set_transition( std::vector< transition_t > v )
{
	transition_ = v;
}


void state_t::set_push_transition( transition_t t )
{
	transition_.push_back( t );
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

bool state_t::check_imp()
{	   
    bool d = false;
    int i = 0;
    
    if(state_ == 1)
        return true;  
    else
	{
        while((i < transition_.size()) && (d == false))
		{
            if ( (transition_[i].get_symbol() != '~') && (transition_[i].get_symbol() != '&') )
                return true;
            else  
                i++;
        }
        return false;
    }
	return false;
}

//Main

int state_t::get_next_state(char c)
{
    for (int i = 0; i < transition_.size(); i++)       
        if(transition_[i].get_symbol() == c)
            return transition_[i].get_next();

    return -1;
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
