#pragma once

#include <cstring>
#include <cassert>

using namespace std;

#define N_BITS_WORD (8 * sizeof(T))



template <class T, size_t N>
class bitset_t
{
	private:
		T* block_;
		int sz_;
	
	public:
		bitset_t(void):
			block_(NULL),
			sz_(N/N_BITS_WORD){

			if ((N % N_BITS_WORD) != 0)
				sz_ ++;
		
			block_ = new T[sz_];

			for(int i = 0; i < sz_; i++)
				block_[i] = 0;
		};

		bitset_t(const bitset_t& bs):
		block_(NULL),
		sz_(bs.sz_)
		{
			block_ = new T[sz_];	

			for(int i = 0; i < sz_; i++)
				block_[i] = bs.block_[i];		
		}

		~bitset_t(void) {
			if (block_) delete [] block_;
		}

		void insert(int i){

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			block_[pos] |= (T(0x1) << offset);
		}

		void remove(int i){

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			block_[pos] &= ~(T(0x1) << offset);
		}

		bool contains(int i) const
		{

			assert(i <= N);
			assert(i >= 1);

			i--;

			const int pos    = i/N_BITS_WORD;
			const int offset = i%N_BITS_WORD;

			return (block_[pos] & (T(0x1) << offset)) != T(0x0);  
		}

		void insert(const bitset_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] |= bs.block_[i];
		}

		void remove(const bitset_t& bs)
		{
			for(int i = 0; i < sz_; i++)
				block_[i] &= ~bs.block_[i];
		}

		bool contains(const bitset_t& bs) const
		{	
			bool contains_set = true;

			int i = 0;

			while ((i < sz_) && (contains_set)){
				contains_set = contains_set && ((block_[i] & bs.block_[i]) == bs.block_[i]);
				i++;
			}

			return contains_set;		
		}
		
	///////Fase 2
	void union_set(const bitset_t& B, bitset_t& C) const{
		
		for(int i = 0; i < sz_ ; i++){
			C.block_[i] = block_[i] | B.block_[i];	
		}
			
	}
	
	void intersec_set(const bitset_t& B, bitset_t& C) const{
		
		for(int i = 0; i < sz_ ; i++){
			C.block_[i] = block_[i] & B.block_[i];	
		}
		
	}
	
	void diferencia_set(const bitset_t& B, bitset_t& C) const{
		
		for(int i = 0 ; i < sz_ ; i++){
			C.block_[i] = block_[i] & -B.block_[i];	
		}
		
	}
	//Mod
	void insersect_set_clase(const bitset_t& B, bitset_t& C){
		
		for(int i = 0 ; i < sz_ ; i++){
			C.block_[i] = (block_[i] | B.block_[i]) & -(block_[i] & B.block_[i]);
		}
		
	}
	///////Fin fase 2
	
	///////Fase 3		
	int cardinality(void){
		
		int i=  0;
		int cardinal = 0;
		string cadena;
		to_string(cadena);
		
		while( i < cadena.size() ){
			
			if(cadena[i] == '1'){
				
				cardinal++;
				
			}
			i++;
			
		}
		
		return cardinal;
		
	}
	
	
	int first_item(void) const{
		
		string bloque;
		to_string(bloque);
		
		int i = 0;
		int indice = 0;
		bool aux = false;
		
		while( (i < bloque.size() ) && (!aux) ){
			
			if(bloque[i] == '1'){
				
				aux = true;
				indice = i+1;
				
			}
			
			i++;
			
		}
		
		return indice;
		
	}
		
		
	int last_item(void) const{
		
		string bloque;
		to_string(bloque);
		
		int i = bloque.size();
		int indice = 0;
		bool aux = false;
		
		while( (i > 0) && (!aux) ){
			
			if(bloque[i] == '1'){
				
				aux = true;
				indice = i+1;
				
			}
			
			i--;
			
		}
		
		return indice;
		
	}
	////Fin fase 3
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int n_pares(void){			//método que hace un producto AND de 2 conjuntos y al resultado le hallamos la cardinalidad
		
		T aux= 0x1;     														//hay que fabricarlo
		T aux2;
		
		for(int i = 1; i <= BIT_SET_SIZE; i++){
			aux |= T(0x1);
			aux <<=2;
		}
	
		aux2 = aux & block_[0];
		
		return cardinality(aux2);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
		ostream& write(ostream& os) const 
		{

			string s;
			to_string(s);
			os << s;

			return os;
		}

	private:
	
	int cardinality(T block){
		const T aux = 0x1;
		const int sz= N_BITS_WORD;
		int card=0;
		for(int i = 0; i < sz; i++){
			card+= block & aux;
			block >>=1;
		}
		return card;
		
	}
	
		 void to_string(string& s) const 
		 {
			for(int j = 0; j < sz_; j++){

				const int sz = min(N_BITS_WORD, N - j * N_BITS_WORD);

				T block = block_[j];		

				for(int i = 0; i < sz; i++)
				{
					const char c = '0' + (block & T(0x1));
					s.insert(s.begin(),c); 
					block >>= 1;
				}
			}
		 }
};

ostream& operator<<(ostream& os, const bitset_t<long int, 80>& bs)
{
	bs.write(os);
	return os;
}



