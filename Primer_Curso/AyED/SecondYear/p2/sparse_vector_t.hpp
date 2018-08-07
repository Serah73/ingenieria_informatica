#pragma once

#include "pair_t.hpp"
#include "vector_pair_t.hpp"
#include "vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;

class sparse_vector_t{
private:
	vector_pair_t v_;    // Vector de pares
	int           sz_;   // Tamaño del vector original

public:
	sparse_vector_t(void):
		v_(),
		sz_(0) {}

	sparse_vector_t(const vector_t& v, double eps):
		v_(),
		sz_(v.get_sz()) {
			
		// Cuenta el número de elementos no nulos
		int nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
				nz ++;

		v_.resize(nz);

		nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
			{
				v_.get_set_v(nz).set(i, v.get_v(i));
				nz ++;
			}		

	}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const{
	
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}
	
	istream& read(istream& is)
	{
		is >> sz_;
		v_.read(is);
		return is;
	}

	ostream& write_dense(ostream& os) const
	{
		os<<"[ "<<setw(7)<<sz_<<" ";
		int indice_escaso=0;
		for(int i=0; i<sz_; i++)
		{
			if(v_.get_v(indice_escaso).get_inx()!=i)
				os<<" 0.0 ";
			else
			{
				os<<v_.get_v(indice_escaso).get_val()<<" ";
				if(j<v_.get_sz()-1)
					j++;
			}
		}
		os<<" ]";
		return os;
	}
	
	double scal_prod(const vector_t& v) const
	{
			double scal=0;
			if(v.get_sz != v_.get_sz()){
				cerr <<"Ups, tienen tamaños distintos los vectores"<<endl;
				return 0;
			}
			else
				for(int i=0; i<v_.get_sz(); i++)
					scal+= v_.get_v(i).get_val()*v.get_v(v_.get_v(i).get_inx());
	}
	
	double scal_prod(const sparse_vector_t& v) const
	{
			double scal=0;
			if(v.get_sz != v_.get_sz()){
				cerr <<"Ups, tienen tamaños distintos los vectores"<<endl;
				return 0;
			}
			else
			{
				int i=0, j=0;
				while((i<v_.get_sz())&&(j<v.get_sz())
				{
					if(v_.get_v(i).get_inx()==v.get_v(j).get_inx())
					{
						scal+= v_.get_v(i).get_val()*v.get_v(j).get_val());
						i++;j++;
					}
					else
					{
						if(v_.get_v(i).get_inx()<v.get_v(j).get_inx())
							i++;
						else
							j++;
					}
				}		
			}
	}
	
	
	
	
	

private:
	bool is_not_zero(double val, double eps) { return fabs(val) > eps;}

};

