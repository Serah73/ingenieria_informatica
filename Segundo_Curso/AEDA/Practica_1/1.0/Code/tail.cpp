#include "tail.h"

    tail::tail()
    {}
    
    tail::~tail()
    {}
        
    void tail::push(TDATO dato)
    {
        data_.insert_tail(dato);
    }
    
    TDATO tail::pop()
    {
        return data_.extract_head();
    }
    
    int tail::size(void)
    {
        return data_.get_size();
    }
        
    bool tail::empty()
    {
        return size() == 0;
    }

    void tail::print()
    {
        while(size() != 0)
            std::cout << pop() << ", ";         // misma duda que en el stack
            
        std::cout << std::endl;
    }