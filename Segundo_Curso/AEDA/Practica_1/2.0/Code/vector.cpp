#include "vector.hpp"

vector::vector(){
    data_ = new TDato[0];
    size_ = 0;
    
}
vector::vector(int n){
    data_ = new TDato[n];
    size_ = n;
}
vector::~vector(){
    if(data_ != NULL){
        //delete[] data_;
        //data_ = NULL;
    }
}
    
 
TDato vector::get_data(int n){
    return data_[n];
}
void vector::set_data(TDato x, int n){
    data_[n] = x;
}

bool vector::insertable(int n){
    if(n < size_) return true;
    return false;
}

void vector::print(){
    std::cout << "{ " << data_[0];
    for(int i = 1; i < size_; i++){
        std::cout << ", " << data_[i];
    }
    std::cout << " }" << std::endl;
}