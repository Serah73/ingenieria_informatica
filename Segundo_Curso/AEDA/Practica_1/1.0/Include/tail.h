#include "stack.hpp"

    class tail
    {
        private:
        
            list data_;
   
        public:
        
            tail();
            ~tail();
    
            void push(TDATO dato);
            TDATO pop();
    
            int size(void);
            bool empty();
            void print();
};