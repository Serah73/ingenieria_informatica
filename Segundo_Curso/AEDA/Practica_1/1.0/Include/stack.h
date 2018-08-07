#include "list_s.h"

    class stack
    {
    
        private:
    
            lista_s data_;
        
        public:
    
            stack();
            ~stack();
        
            void push(TDATO dato);
            TDATO pop();
        
            int size(void);
            bool empty();
            void print();
    };