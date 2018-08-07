#include "stack.hpp"

stack::stack(){
    stack_pointer_ = -1;
}
stack::~stack(){
    
}
    
void stack::push(TDato n){
    data_.insert_end(n);
    stack_pointer_++;
}
TDato stack::pop(){
    //std::cout << stack_pointer_ << std::endl;
    TDato j = data_.get(stack_pointer_);
    data_.quit_end();
    stack_pointer_--;
    return j;
}
    
bool stack::empty(){
    if(stack_pointer_ == -1) return true;
    return false;
}

void stack::print(){
    while(stack_pointer_ != -1){
        std::cout << this->pop() << ", ";
    }
    std::cout << std::endl;
}