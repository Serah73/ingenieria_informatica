#pragma once

#include <iostream>
#include <iomanip>

using namespace std;


class pair_t
{
private:
	int    inx_;
	double val_;
public:
	pair_t(void):
		inx_(-1),
		val_(0.0){} 

	pair_t(int inx, double val):
		inx_(inx),
		val_(val){}

	~pair_t(void) {}

	void set(int inx, double val){
	
		inx_ = inx;
		val_ = val;
	}

	int    get_inx(void) const {return inx_;}
	double get_val(void) const {return val_;}

	ostream& write(ostream& os) const {
	
		os << setw(7) << inx_ << " " << setw(5) << fixed << setprecision(2) << val_;
		return os;
	}

	istream& read(istream& is){
	
		is >> inx_ >> val_;
		return is;
	}
};