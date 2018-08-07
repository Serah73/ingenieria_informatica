#include "stack.h"

    stack::stack()
    {}
    
    stack::~stack()
    {}
    
    void stack::push(TDATO dato)
    {
        data_.insert_tail(dato);
    }
    
    TDATO stack::pop()
    {
        return data_.extract_tail();
    }
    
    int stack::size(void)
    {
        return data_.get_size();
    }
    
    bool stack::empty()
    {
        return size() ==0;
    }

    void stack::print()
    {
        while(size() != 0)
            std::cout << pop() << ", ";         //this->pop() es otra opcion, duda funcionamiento exacto del this
            
        std::cout << std::endl;
    }