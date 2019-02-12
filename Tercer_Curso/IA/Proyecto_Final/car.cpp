#include "car.hpp"


car_t::car_t()
{
    insertar_recorrido(0,0);
    destiny_.resize(2);
}
car_t::car_t(int x, int y)
{
	set_x(x);
	set_y(y);
	set_way('^');
	
	recorrido_.clear();
	
    insertar_recorrido(x,y);
    destiny_.resize(2);
}
car_t::~car_t(){}


///SET
void car_t::set_destiny(int x, int y)
{
    destiny_[0] = x;
    destiny_[1] = y;
}
void car_t::set_status(std::vector<int> v) 
{
    status_.clear();
    
    for(int i = 0; i < v.size(); ++i)
        status_.push_back(v[i]);
}
void car_t::set_callejon_false()
{
    callejon = false;
}
void car_t::set_callejon_true()
{
    callejon = true;
}
void car_t::set_contador_estrella(int x)
{
    contador_estrella = x;
}
void car_t::set_nodos_generados()
{
    nodos_generados = 0;
}



// GETTERS
std::vector<int> car_t::get_destiny() const
{
    return destiny_;
}
int car_t::get_x_destiny() const 
{
    return destiny_[0];
}
int car_t::get_y_destiny() const
{
    return destiny_[1];
}


int car_t::get_size_recorrido() const
{
    return recorrido_.size();
}
int car_t::get_recorrido_x(int i) const
{
    return recorrido_[i][0];
}
int car_t::get_recorrido_y(int i) const
{
    return recorrido_[i][1];
}

bool car_t::get_callejon()
{
    return callejon;
}
int car_t::get_callejon_v_x()
{
    return callejon_v[0];
}
int car_t::get_callejon_v_y()
{
    return callejon_v[1];
}

int car_t::get_nodos_generados()
{
    return nodos_generados;
}



//Security
std::vector<std::vector <int> > car_t::check_compass(int width, int height) 
{
    possible_move_.clear();   
    return check_ut(width, height, possible_move_);                                                             
}

std::vector< std::vector<int> > car_t::check_ut(int width, int height, std::vector<std::vector<int> >& v)  
{
    possible_move_.clear();
    
    if(check(width, height, north() ) ) v.push_back(north() );
    if(check(width, height, south() ) ) v.push_back(south() );
    if(check(width, height, west() ) ) v.push_back(west() ) ;
    if(check(width, height, east() ) ) v.push_back(east() ) ;
    
    return v;
}

bool car_t::check(int width, int height, std::vector<int> v) 
{
    if ( (v[0] >= width)  || (v[0] < 0) ) return false;
    if ( (v[1] >= height) || (v[1] < 0) ) return false;
    else
        return true;
}

bool car_t::check_destiny()
{
    if ( ( get_x_destiny() == get_x() ) && ( get_y_destiny() == get_y() ) )
        return true;
    return false;
    
}


//Auxiliary
std::vector<int> car_t::north()
{
    std::vector<int> v;
    v.clear();
    
    v.push_back(get_x());
    v.push_back(get_y() - 1);
    
    return v;
}

std::vector<int> car_t::south()
{
    std::vector<int> v;
    v.clear();
    
    v.push_back(get_x());
    v.push_back(get_y() + 1);
    
    return v;
}

std::vector<int> car_t::west()
{
    std::vector<int> v;
    v.clear();
    
    v.push_back(get_x() - 1);
    v.push_back(get_y());
    
    return v;   
}

std::vector<int> car_t::east()
{
    std::vector<int> v;
    v.clear();
    
    v.push_back(get_x() + 1);
    v.push_back(get_y());
    
    return v;    
}

void car_t::prunning_nearbours()
{
    for(int i=possible_move_.size()-1; i >= 0 ; i--)
    {
        if(status_[i] == 1 || status_[i] == 2 || status_[i] == 6 ) possible_move_.erase(possible_move_.begin()+i);
    }
}

void car_t::insertar_recorrido(int x, int y)
{
   	std::vector<int> v;
	v.push_back(x);
	v.push_back(y);
	recorrido_.push_back(v); 
	v.clear();
}

void car_t::extraer_recorrido()
{
    recorrido_.pop_back();
}

void car_t::print_data_test()
{
    std::cout << "existo: " << status_.size()<< "\n";
    for ( int i = 0; i < status_.size(); i++)
        std::cout << "estado del camino: " << status_[i];
    std::cout << "\n";
}

float car_t::euclidiana(int x, int y)
{
   return (sqrt(((get_x_destiny() - x)*(get_x_destiny() - x))+((get_y_destiny() - y)*(get_y_destiny() - y))));
}

float car_t::manhattan(int x, int y)
{
    return ((abs(get_x_destiny() - x)) + (abs(get_y_destiny() - y)));
}


/// Principal
int car_t::move(int width, int height, int opt) 
{

    float mejor_distancia = FLT_MAX, current = 0;
    std::vector<int> mejor_vecino; mejor_vecino.clear(); 
    
    nodos_generados += possible_move_.size();
    
    if(possible_move_.size() == 1)
    {
        for(int i = 0; i < recorrido_.size(); ++i)
        {
            if( (possible_move_[0][0] == recorrido_[i][0] ) && ( possible_move_[0][1] == recorrido_[i][1] ) )
            {
                if(callejon_v.empty()){
                    callejon_v.push_back(get_x());
                    callejon_v.push_back(get_y());
                }
                else{
                    callejon_v[0] = get_x();
                    callejon_v[1] = get_y();
                    
                }
                recorrido_.pop_back();
                set(recorrido_[recorrido_.size() - 1][0], recorrido_[recorrido_.size() - 1][1]);
                return 5;
            }
        }
    }
    else{
        
        bool c2 = false;
        if(possible_move_.size() == 2)
            c2 = true;
            
        for(int i = possible_move_.size()-1; i >= 0; --i)
        {
            if(opt == 0){
                current = manhattan(possible_move_[i][0], possible_move_[i][1]);
                current += contador_estrella;
            }
            else if(opt == 1){
                current = euclidiana(possible_move_[i][0], possible_move_[i][1]);
                current += contador_estrella;
            }
            if(current < mejor_distancia)
            {   
                mejor_distancia = current;
                mejor_vecino    = possible_move_[i];
            }
            possible_move_.pop_back();      
        }
        
        if (c2)
        {
            for(int j = 0; j < recorrido_.size(); ++j)
            {
                if((mejor_vecino[0] == recorrido_[j][0] ) && (mejor_vecino[1] == recorrido_[j][1]))
                {
                    if(callejon_v.empty()){
                        callejon_v.push_back(get_x());
                        callejon_v.push_back(get_y());
                    }
                    else{
                        callejon_v[0] = get_x();
                        callejon_v[1] = get_y();
                    }
                    recorrido_.pop_back();
                    set(recorrido_[recorrido_.size() - 1][0], recorrido_[recorrido_.size() - 1][1]);
                    return 5;
                }   
            }
            
        }
        
        insertar_recorrido(mejor_vecino[0], mejor_vecino[1]);
            
        set(mejor_vecino[0], mejor_vecino[1]); 
        contador_estrella++;
        return 0;
    }
}

void car_t::operator()(int x, int y)
{
    this->set_x(x);
	this->set_y(y);
	this->set_way('^');
	
	this->recorrido_.clear();
	
    this->insertar_recorrido(x,y);
    this->destiny_.resize(2);
}
