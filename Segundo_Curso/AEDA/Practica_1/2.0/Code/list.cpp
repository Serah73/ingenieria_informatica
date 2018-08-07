#include "list.hpp"

list::list(){
    final_ = NULL;
    inicial_ = NULL;
    nnode_ = 0;
}
list::~list(){
    while(inicial_ != NULL){
        quit_begin();
    }
}
    
void list::quit_end(){
    if(nnode_ > 1){
        node* aux = final_->get_prev();
        aux->set_next(NULL);
        final_->destroy();
        final_ = aux; 
    }else{
        if(nnode_ == 1){
            final_->destroy();
            //delete[] inicial_;
            //delete[] final_;
            inicial_ = NULL;
            final_ = NULL;
        }
    }
    nnode_--;
}
void list::quit_begin(){
    if(nnode_ > 1){
        node* aux = inicial_->get_next();
        aux->set_prev(NULL);
        inicial_->destroy();
        inicial_ = aux;
    }else{
        if(nnode_ == 1){
            inicial_->destroy();
            //delete[] inicial_;
            //delete[] final_;
            inicial_ = NULL;
            final_ = NULL;
        }
    }
    nnode_--;
    
}

void list::insert_end(TDato n){
    if(nnode_ == 0){
        node* aux = new node(n);  
        final_ = aux;
        inicial_ = aux;
    }else{
        node* aux = new node(n);
        aux->set_prev(final_);
        final_->set_next(aux);
        final_ = aux;
    }
    nnode_++;
}
void list::insert_begin(TDato n){
    if(nnode_ == 0){
        node* aux = new node(n);
        inicial_ = aux;
        final_ = aux;
    }else{
        node* aux = new node(n);
        aux->set_next(inicial_);
        inicial_->set_prev(aux);
        inicial_ = aux;
    }
    nnode_++;
    
}

TDato list::get(int allocat){
    node* aux = inicial_;
    for(int i = 0; i < allocat; i++){
        aux = aux->get_next();
    }
    return aux->get_data();
}
void list::set(TDato n, int allocat){
    node* aux = inicial_;
    for(int i = 0; i < allocat; i++){
        aux = aux->get_next();
    }
    aux->set_data(n);
}

bool list::empty(){
    if(nnode_ == 0) return true;
    return false;
}
void list::print(){
    std::cout << this->get(0);
    for(int i = 1; i < nnode_; i++){
        std::cout << " -> " << this->get(i);
    }
    std::cout << std::endl;
}

int list::get_nnode(){
    return nnode_;
}