#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;
namespace AED {

	template <class T>
	class vector_t{
	private:
		T*      v_;
		int     sz_;

	public:

		vector_t(int sz):
			v_(NULL),
			sz_(sz) {

			crea_vector();
		}

		~vector_t(void){

			destruye_vector();
		}


		int get_sz(void) const
		{
			return sz_;
		}

		T operator[](int pos) const{
		
			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		T& operator[](int pos){

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		ostream& write(ostream& os) const{
	
			os << setw(5) <<  sz_ << endl;
			os << endl;

			for(int i = 0; i < sz_; i ++){
				v_[i].write(os);
				os << " ";
			}

			return os;
		}


	private:

		void crea_vector(void){
			v_ = new T[sz_];
		}

		void destruye_vector(void)
		{
			if (v_ != NULL){
				delete [] v_;
				v_ = NULL;
			}
		}



	};


	template <>
	ostream& vector_t<int>::write(ostream& os) const{

		for(int i = 0; i < sz_; i ++)
		 	os << setw(4)  << v_[i] << " ";


		return os;
	}	

}

ostream& operator<< (ostream& os, const AED::vector_t<int>& v)
{
	v.write(os);

	return os;
}




