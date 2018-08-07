#include "lenguaje.hpp"


lenguaje_t::lenguaje_t(void) {
	vacio_ = true;
	infinito_ = false;
}


lenguaje_t::lenguaje_t(const lenguaje_t& leng) {
	lenguaje_ = leng.lenguaje_;
	exp_reg_ = leng.exp_reg_;
	vacio_ = leng.vacio_;
	infinito_ = leng.infinito_;
}


lenguaje_t::~lenguaje_t(void) {
	clear();
}


lenguaje_t& lenguaje_t::unir(lenguaje_t& leng1, lenguaje_t& leng2) {
	if((leng1.infinito_) || (leng2.infinito_))
		infinito_ = true;

	if((!leng1.exp_reg_.empty()) && (!leng2.exp_reg_.empty()))
		exp_reg_ = '(' + leng1.exp_reg_ + ") | (" + leng2.exp_reg_ + ')';

	else {
		for(set<cadena_t>::iterator i = leng1.lenguaje_.begin(); i != leng1.lenguaje_.end(); i++)
			lenguaje_.insert(*i);
		for(set<cadena_t>::iterator i = leng2.lenguaje_.begin(); i != leng2.lenguaje_.end(); i++)
			lenguaje_.insert(*i);
	}

	if(!lenguaje_.empty())
		vacio_ = false;

	return *this;
}


lenguaje_t& lenguaje_t::interseccion(lenguaje_t& leng1, lenguaje_t& leng2) {
	if((!leng1.exp_reg_.empty()) && (!leng2.exp_reg_.empty()))
		exp_reg_ = '(' + leng1.exp_reg_ + ") ∩ (" + leng2.exp_reg_ + ')';

	else {
		set<cadena_t>::iterator j = leng1.lenguaje_.begin();
		set<cadena_t>::iterator k = leng2.lenguaje_.begin();
		while((j != leng1.lenguaje_.end()) && (k != leng2.lenguaje_.end())) {
			if((*j) < (*k))
				j++;
			else if((*j) == (*k)) {
				lenguaje_.insert(*j);
				j++; k++;
			}
			else
				k++;
		}
	}

	if(!lenguaje_.empty())
		vacio_ = false;	

	return *this;
}


lenguaje_t& lenguaje_t::inversa(lenguaje_t& leng) {
	if(leng.infinito_)
		infinito_ = true;

	cadena_t aux;

	for(set<cadena_t>::iterator i = leng.lenguaje_.begin(); i != leng.lenguaje_.end(); i++) {
		aux.inversa(*i);
		lenguaje_.insert(aux);
	}

	if(!lenguaje_.empty())
		vacio_ = false;	
}


lenguaje_t& lenguaje_t::concatenacion(lenguaje_t& leng1, lenguaje_t& leng2) {
	if(((leng1.infinito_) && (!leng2.vacio_)) || ((leng2.infinito_) && (!leng1.vacio_)))
		infinito_ = true;

	if((!leng1.exp_reg_.empty()) && (!leng2.exp_reg_.empty()))
		exp_reg_ = '(' + leng1.exp_reg_ + ")(" + leng2.exp_reg_ + ')';

	else {
		cadena_t aux;

		for(set<cadena_t>::iterator i = leng1.lenguaje_.begin(); i != leng1.lenguaje_.end(); i++) {
			for(set<cadena_t>::iterator j = leng2.lenguaje_.begin(); j != leng2.lenguaje_.end(); j++) {
				aux.concat((*i), (*j));
				lenguaje_.insert(aux);
			}
		}
	}

	if(!lenguaje_.empty())
		vacio_ = false;	

	return *this;
}


lenguaje_t& lenguaje_t::diferencia(lenguaje_t& leng1, lenguaje_t& leng2) {
	if((leng1.infinito_) && !(leng1.igualdad(leng2)))
		infinito_ = true;

	if((!leng1.exp_reg_.empty()) && (!leng2.exp_reg_.empty()))
		exp_reg_ = '(' + leng1.exp_reg_ + ") - (" + leng2.exp_reg_ + ')';

	else {
		for(set<cadena_t>::iterator i = leng1.lenguaje_.begin(); i != leng1.lenguaje_.end(); i++)
			lenguaje_.insert(*i);
		for(set<cadena_t>::iterator i = leng2.lenguaje_.begin(); i != leng2.lenguaje_.end(); i++)
			lenguaje_.erase(*i);
	}

	if(!lenguaje_.empty())
		vacio_ = false;	

	return *this;
}


void lenguaje_t::sublenguajes(void) {
	cout << "{}" << endl;

	for(set<cadena_t>::iterator i = lenguaje_.begin(); i != lenguaje_.end(); i++) {
		cout << '{';
		i->write(cout) << '}' << endl;
	}

	for(set<cadena_t>::iterator i = lenguaje_.begin(); i != lenguaje_.end(); i++) {
		if(i != lenguaje_.begin()) {
			cout << '{';
			i--;
			i->write(cout) << ", ";
			i++;
			i->write(cout) << '}' << endl;
		}
	}

	write(cout);
}


bool lenguaje_t::igualdad(lenguaje_t& leng) {
	return((lenguaje_ == leng.lenguaje_) && (vacio_ == leng.vacio_) && (infinito_ == leng.infinito_));
}


lenguaje_t& lenguaje_t::potencia(lenguaje_t& leng, int n) {

	if(n < 0)
		cout << "Exponente no valido" << endl;
	else if(n == 0) {
		cadena_t aux;
		lenguaje_.insert(aux);
		vacio_ = false;
	}
	else {
		if(leng.infinito_)
			infinito_ = true;

		lenguaje_t temp;
		lenguaje_t temp2;
		cadena_t aux;
		temp.lenguaje_.insert(aux);

		for(int i = 1; i <= n; i++) {
			temp2.concatenacion(temp, leng);
			temp = temp2;
			temp2.clear();
		}

		lenguaje_ = temp.lenguaje_;
		vacio_ = temp.vacio_;
		
	
		return *this;
	}
}


lenguaje_t& lenguaje_t::kleene(lenguaje_t& leng) {
	cadena_t aux;
	
	if(!leng.exp_reg_.empty())
		exp_reg_ = '(' +  leng.exp_reg_ + ")*";

	else {
		if((leng.vacio_) || ((leng.lenguaje_.size() == 1) && (*leng.lenguaje_.begin() == aux))) {
			lenguaje_.insert(aux);
			vacio_ = false;
		}

		else {
			lenguaje_t temp;
			temp.lenguaje_.insert(aux);
			lenguaje_t temp2;
			while(temp.lenguaje_.size() < 15) {
				temp2.concatenacion(temp, leng);
				temp = temp2;
			}
			lenguaje_t temp3;
			temp3.lenguaje_.insert(aux);
			unir(temp, temp3);
			infinito_ = true;
		}
	}	
}


ostream& lenguaje_t::write(ostream& os) {
	if(!exp_reg_.empty())
		os << "Expresion regular: " << exp_reg_ << endl;
	else {
		os << '{';
		for(set<cadena_t>::iterator i = lenguaje_.begin(); i != lenguaje_.end(); i++) {
			i->write(os);
			os << ", ";
		}
		if(infinito_)
			os << "...";
		os << '}' << endl;
	}
}


istream& lenguaje_t::read(istream& is) {
	string str;
	getline(is, str);

	if((str[0] == '{') && (str[1] == '}'))
		vacio_ = true;

	else if(str[0] == '{') {
		vacio_ = false;
		int j = 1;
		cadena_t aux;
		cadena_t aux2;
		while(str[j] != '}') {
			if(str[j] == '&') {
				lenguaje_.insert(aux2);
			}
			else if((str[j] != ',') && (str[j] != ' ')) {
				int k = j;
				do {
					k++;
				} while((str[k] != ',') && (str[k] != ' ') && (str[k] != '}'));
				aux.resize(k - j);
				int m = 0;
				do {
					aux.set_simb(m, str[j]);
					m++; j++;
				} while(j != k);
				lenguaje_.insert(aux);
				j--;
			}
			j++;
		}
	}
	else {
		string s = str;
		str += ' ';
		cadena_t vacia;
		cadena_t aux(1);
		lenguaje_t temp;
		lenguaje_t temp2;

		lenguaje_t** lenguajes = new lenguaje_t* [str.size()];
		int* tamanos = new int [str.size()];
		for(int i = 0; i < str.size(); i++) {
			lenguajes[i] = new lenguaje_t [str.size()];
			tamanos[i] = 0;
		}
		int j = 0;

		for(int i = 0; i < str.size()-1; i++) {
			if(str[i] == '*') {
				aux.set_simb(0, str[i-1]);
				temp.lenguaje_.insert(aux);
				temp.vacio_ = false;
				lenguajes[j][tamanos[j]].kleene(temp);
				tamanos[j]++;
				temp.clear();
			}
			else if((str[i] != ' ') && (str[i] != '|') && (str[i+1] != '*')) {
				aux.set_simb(0, str[i]);
				lenguajes[j][tamanos[j]].lenguaje_.insert(aux);
				lenguajes[j][tamanos[j]].vacio_ = false;
				tamanos[j]++;
			}
			else if(str[i] == '|') {
				j++;
			}
		}

		lenguaje_t* lenguajes2 = new lenguaje_t [str.size()];
		for(int i = 0; i <= j; i++) {
			temp.lenguaje_.insert(vacia);
			for(int l = 0; l < tamanos[i]; l++) {
				temp2.concatenacion(temp, lenguajes[i][l]);
				temp = temp2;
				temp2.clear();
			}
			lenguajes2[i] = temp;
			temp.clear();
		}

		for(int i = 0; i <= j; i++) {
			temp2.unir(lenguajes2[i], temp);
			temp = temp2;
			temp2.clear();
		}
		
		lenguaje_ = temp.lenguaje_;
		infinito_ = temp.infinito_;
		exp_reg_ = s;
	}
}


void lenguaje_t::clear(void) {
	if(!lenguaje_.empty())
		lenguaje_.clear();
	if(!exp_reg_.empty())
		exp_reg_.clear();
	bool vacio_ = true;
	bool infinito_ = false;
}
				






