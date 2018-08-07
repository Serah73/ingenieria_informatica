#ifndef simbolo_t_H_
#define simbolo_t_H_

#include<iostream>


using namespace std;


class simbolo_t {

private:

	char c_;

public:

	simbolo_t(void);
	simbolo_t(char c);
	simbolo_t(const simbolo_t& simb);
	~simbolo_t(void);

	char get_s(void);
	void set_s(char c);

	ostream& write(ostream& os);
	istream& read(istream& is);
};


#endif
