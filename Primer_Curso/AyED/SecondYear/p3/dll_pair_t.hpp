#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include "dll_t.hpp"
#include "pair_t.hpp"

using namespace std;
using namespace AED;

namespace AED {

typedef pair_t<double> sparse_pair_t;

typedef dll_t<sparse_pair_t>      dll_pair_t;
typedef dll_node_t<sparse_pair_t> node_pair_t;

template <>
ostream& dll_node_t<sparse_pair_t>::write(ostream& os) const
{
	os << "[";
	data_.write(os);
	os << "]";
	return os;
}


typedef pair_t<dll_pair_t> raro_pair_t;

typedef dll_t<raro_pair_t>      dll_rara_pair_t;
typedef dll_node_t<raro_pair_t> node_raro_t;

template <>
ostream& dll_node_t<raro_pair_t>::write(ostream& os) const
{	
	os << endl;
	os << "[";
	data_.write(os);
	os << "]";
	os << endl;
	return os;
}

}

