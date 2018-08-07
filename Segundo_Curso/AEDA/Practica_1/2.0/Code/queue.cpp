#include "queue.hpp"

queue::queue(){
    n_elem_ = 0;
}
queue::~queue(){
    
}
    
void queue::push(TDato n){
    data_.insert_end(n);
    n_elem_++;
}
TDato queue::pop(){
    TDato j = data_.get(0);
    data_.quit_begin();
    n_elem_--;
    return j;
}
    
bool queue::empty(){
    if(n_elem_ == 0) return true;
    return false;
}

void queue::print(){
    while(n_elem_ != 0){
        std::cout << this->pop() << ", ";
    }
    std::cout << std::endl;
}