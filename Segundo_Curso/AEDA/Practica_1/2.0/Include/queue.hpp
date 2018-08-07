#include "stack.hpp"

class queue {
    private:
    list data_;
    int n_elem_;
    
    public:
    queue();
    ~queue();
    
    void push(TDato n);
    TDato pop();
    
    bool empty();
    void print();
};