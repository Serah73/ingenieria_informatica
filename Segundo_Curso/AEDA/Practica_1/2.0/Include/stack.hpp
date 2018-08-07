#include "list.hpp"

class stack{
    private:
    list data_;
    int stack_pointer_;
    
    public:
    stack();
    ~stack();
    
    void push(TDato n);
    TDato pop();
    
    bool empty();
    void print();
};