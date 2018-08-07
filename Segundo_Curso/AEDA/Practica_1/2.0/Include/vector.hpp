#include <iostream>

typedef int TDato;

class vector{
    private:
        TDato* data_;
        int size_;
    
    public:
        vector();
        vector(int n);
        ~vector();
        
     
        TDato get_data(int n);
        void set_data(TDato x, int n);
        
        bool insertable(int n);
        void print();
        
};