#pragma once

#include "pair_t.hpp"
#include "vector_t.hpp"
#include <cstdio>

#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

typedef pair_t<double>                          pair_double_t;
typedef vector_t<pair_double_t>                 vector_pair_double_t ;
typedef pair_t<vector_pair_double_t>            pair_vector_t;
typedef vector_t<pair_vector_t>                 vector_pair_vp_t ;



template <>
ostream& vector_t<pair_t<double> >::write(ostream& os) const{

	os << setw(5) <<  sz_ << endl;

	for(int i = 0; i < sz_; i ++){
		v_[i].write(os);
		os << endl;
	}

	os << endl;

	return os;
}

template <>
istream& vector_t<pair_t<double> >::read(istream& is){
	
	is >> sz_;

	resize(sz_);

	for(int i = 0; i < sz_; i ++)
	 	v_[i].read(is);

	return is;
}
