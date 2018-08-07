#include "node.hpp"

node::node(){
    next_ = NULL;
    prev_ = NULL;
    data_ = 0;
}
node::node(TDato n){
    next_ = NULL;
    prev_ = NULL;
    data_ = n;
}
node::~node(){
    next_ = NULL;
    prev_ = NULL;
    data_ = 0;
}
void node::destroy(){
    next_ = NULL;
    prev_ = NULL;
    data_ = 0;
}    
    
void node::set_data(TDato n){
    data_ = n;
}
void node::set_prev(node* n){
    prev_ = n;
}
void node::set_next(node* n){
    next_ = n;
}
    
node* node::get_prev(){
    return prev_;
}
node* node::get_next(){
    return next_;
}
TDato node::get_data(){
    return data_;
}