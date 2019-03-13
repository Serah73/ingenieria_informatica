/*
 * language.cpp
 *
 *  Created on: 10 nov. 2018
 *      Author: Serah
 */

#include "language.h"

language_t::language_t(){}

language_t::language_t(const language_t &lang):
language_(lang.language_)
{}

language_t::language_t(std::string str)
{
    std::string aux;
    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        if((str[i] != '{') && (str[i] != ' '))
        {
            if ((str[i] == ',') || (str[i] == '}'))
            {
                symbols_t temp(aux);
                //std::cout << "Añadimos a '" << temp << "' al set.\n";
                language_.insert(temp);
                std::cout << "Set: ";

                for (std::set<symbols_t>::iterator j = language_.begin(); j != language_.end(); j++)
                	std::cout << *j << " ";

                std::cout << "\n";
                aux.clear();
            }else{
                alphabet_.insert(str[i]);
                aux.push_back(str[i]);
            }

        }
    }
    std::cout << "\n";
}

language_t::~language_t(){}

std::set<symbols_t> language_t::get_language() const
{
	return language_;
}

std::set<symbols_t> language_t::get_language()
{
	return language_;
}


std::set<symbols_t>::iterator language_t::get_begin_language()
{
    std::set<symbols_t>::iterator reverse = language_.begin();
    
    return reverse;
}

std::set<symbols_t>::iterator language_t::get_begin_language() const
{
    std::set<symbols_t>::iterator reverse = language_.begin();
    
    return reverse;
}
	
std::set<symbols_t>::iterator language_t::get_end_language()
{
    std::set<symbols_t>::iterator reverse = language_.end();
    
    return reverse;    
}

std::set<symbols_t>::iterator language_t::get_end_language() const
{
    std::set<symbols_t>::iterator reverse = language_.end();
    
    return reverse;
}


std::set<symbols_t>::reverse_iterator language_t::get_begin_rlanguage()
{
	std::set<symbols_t>::reverse_iterator reverse = language_.rbegin();

	return reverse;
}

std::set<symbols_t>::reverse_iterator language_t::get_begin_rlanguage() const
{
	std::set<symbols_t>::reverse_iterator reverse = language_.rbegin();

	return reverse;
}

std::set<symbols_t>::reverse_iterator language_t::get_end_rlanguage()
{
	std::set<symbols_t>::reverse_iterator reverse = language_.rend();

	return reverse;
}

std::set<symbols_t>::reverse_iterator language_t::get_end_rlanguage() const
{
	std::set<symbols_t>::reverse_iterator reverse = language_.rend();

	return reverse;
}

std::set<symbols_t>::iterator language_t::find(symbols_t symb)
{
    std::set<symbols_t>::iterator it = language_.find(symb);
    
    return it;
}


std::set<char> language_t::get_alphabet() const
{
	return alphabet_;
}

std::set<char> language_t::get_alphabet()
{
	return alphabet_;
}

void language_t::set_symbol_lang(symbols_t symb)
{
	language_.insert(symb);
}

void language_t::set_symbol_alph(char symb)
{
	alphabet_.insert(symb);
}

void language_t::set_language(std::set<symbols_t> symb)
{
	language_ = symb;
}

void language_t::set_alphabet(std::set<char> symb)
{
	alphabet_ = symb;
}

void language_t::clear()
{
    language_.clear();
    alphabet_.clear();
}

void language_t::operator()(std::string str)
{
    std::string aux;
    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        if((str[i] != '{') && (str[i] != ' '))
        {
            if ((str[i] == ',') || (str[i] == '}'))
            {
                symbols_t temp(aux);
                //std::cout << "Añadimos a '" << temp << "' al set.\n";
                language_.insert(temp);
                std::cout << "Set: ";

                for (std::set<symbols_t>::iterator j = language_.begin(); j != language_.end(); j++)
                	std::cout << *j << " ";

                std::cout << "\n";
                aux.clear();
            }else{
                alphabet_.insert(str[i]);
                aux.push_back(str[i]);
            }

        }
    }
    std::cout << "\n";
}



std::ostream& operator<<(std::ostream &os, const language_t& lang){

    std::set<symbols_t> lang_aux = lang.get_language();
    std::set<symbols_t>::iterator end_langaux = lang_aux.end();

    std::set<char> alp_aux = lang.get_alphabet();
    std::set<char>::iterator end_alpaux = alp_aux.end();

    end_langaux--; end_alpaux--;
    os << "{";
    for (std::set<symbols_t>::iterator u = lang_aux.begin(); u != lang_aux.end(); u++)
    {
    	if (end_langaux == u)
    	{
    		os << *u;
    	}
    	else
    	{
    		os << *u << ", ";
    	}
    }
    os << "} / Alfabeto:{";
    for (std::set<char>::iterator i = alp_aux.begin(); i != alp_aux.end(); i++)
    {
    	if (end_alpaux == i) os << *i;
        else
        	os << *i << ", ";
    }
    os << "}\n";
    return os;
}
