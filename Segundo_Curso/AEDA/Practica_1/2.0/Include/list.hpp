#include "node.hpp"

class list{
    private:
    node* inicial_;
    node* final_;
    int nnode_;
    
    public:
    
    list();
    ~list();
    
    void quit_end();
    void quit_begin();
    
    void insert_end(TDato n);
    void insert_begin(TDato n);
    
    TDato get(int allocat);
    void set(TDato n, int allocat);
    
    bool empty();
    void print();
    int get_nnode();
};