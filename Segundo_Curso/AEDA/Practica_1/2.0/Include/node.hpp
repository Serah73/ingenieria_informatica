#include <iostream>

typedef int TDato;

class node{
    private:
    node* next_;
    node* prev_;
    TDato data_;
    
    public:
    node();
    node(TDato n);
    ~node();
    void destroy();
    
    void set_data(TDato n);
    void set_prev(node* n);
    void set_next(node* n);
    
    node* get_prev();
    node* get_next();
    TDato get_data();
    
};