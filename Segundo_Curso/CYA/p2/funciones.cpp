#include "funciones.hpp"



lenguaje_t::lenguaje_t(void)
{}

cadena_t::cadena_t()
{
	sum = "";
}

cadena_t::cadena_t(const char* cadena)
{
	std::ostringstream tmp;
	int sum=0;
	s+= cadena;	
	for (int i=0; i<s.length();i++)
		sum+= (int) s[i];
        tmp << sum;
	this->sum = tmp.str();
}


cadena_t::cadena_t(const cadena_t &copyin)   // Copy constructor to handle pass by value.
{                             
   sum = copyin.sum;
}

ostream &operator<<(ostream &output, const cadena_t &bbb)
{
   output << "Hash: " << bbb.sum << " Cadena:" << bbb.s << endl;
   return output;
}

cadena_t& cadena_t::operator=(const cadena_t &rhs)
{
   this->sum = rhs.sum;
   return *this;
}

int cadena_t::operator==(const cadena_t &rhs) const
{
   if( this->sum != rhs.sum) return 0;
   return 1;
}

// This function is required for built-in STL list functions like sort
// o para containers de tipo ordinal como <set>

int cadena_t::operator<(const cadena_t &rhs) const
{
   if( this->sum < rhs.sum ) return 1;
   return 0;
}

cadena_t::~cadena_t()
{
}

//LENGUAJE


istream& lenguaje_t::read(istream& is) {
	string reading;
	getline(is, reading);

	if((reading[0] == '{') && (reading[1] == '}'))
		chain_empty = true;

	else if(reading[0] == '{') {
		chain_empty = false;
		int j = 1;
		while(reading[j] != '}') {
			if(reading[j] == '&') {
				lenguaje_.insert('&');									///aksdhfupiashdpuig
			}
			else if((reading[j] != ',') && (reading[j] != ' ')) {
					lenguaje_.insert(reading[j]);
			}
			j++;
		}
	}
	else {
		string s = reading;
		reading += ' ';
		cadena_t Cempty;
		cadena_t aux(1);
		lenguaje_t tmp;
		lenguaje_t tmp2;

		int j = 0;

		for(int i = 0; i < s.size(); i++) {										//PARO CARDIACO
			if(reading[i] == '*') {
				aux.set_simb(0, reading[i-1]);
				tmp.lenguaje_.insert(aux);
				tmp.chain_empty = false;
				lenguajes[j][tamanos[j]].kleene(tmp);
				tamanos[j]++;
				tmp.clear();
			}
			else if((reading[i] != ' ') && (reading[i] != '|') && (reading[i+1] != '*')) {
				aux.set_simb(0, reading[i]);
				lenguajes[j][tamanos[j]].lenguaje_.insert(aux);
				lenguajes[j][tamanos[j]].chain_empty = false;
				tamanos[j]++;
			}
			else if(reading[i] == '|') {
				j++;
			}
		}

		lenguaje_t* lenguajes2 = new lenguaje_t [reading.size()];
		for(int i = 0; i <= j; i++) {
			tmp.lenguaje_.insert(Cempty);
			for(int l = 0; l < tamanos[i]; l++) {
				tmp2.concatenacion(tmp, lenguajes[i][l]);
				tmp = tmp2;
				tmp2.clear();
			}
			lenguajes2[i] = tmp;
			tmp.clear();
		}

		for(int i = 0; i <= j; i++) {
			tmp2.unir(lenguajes2[i], tmp);
			tmp = tmp2;
			tmp2.clear();
		}
		
		lenguaje_ = tmp.lenguaje_;
		infinito_ = tmp.infinito_;
		exp_reg_ = s;
	}
}
