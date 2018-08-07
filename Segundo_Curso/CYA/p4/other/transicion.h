#ifndef trasicion_t_H_
#define transicion_t_H_


class transicion_t {

private:

	int est;
	char simb;

public:

	transicion_t (void);
	transicion_t (int a, char c);
	transicion_t (const transicion_t& trans);

	int get_est (void);
	char get_simb (void);
	void set_est (int a);
	void set_simb (char c);
	transicion_t& operator= (const  transicion_t& trans);

};

#endif
