#include "car.hpp"


car_t::car_t()
{
    insertar_recorrido(0,0);
    destiny_.resize(2);
    //contador_estrella = 0;
}
car_t::car_t(int x, int y)
{
	set_x(x);
	set_y(y);
	set_way('^');
    insertar_recorrido(x,y);
    destiny_.resize(2);
    //contador_estrella = 0;
    //Valores de prueba para ver un camino
/*  insertar_recorrido(3,5);
    insertar_recorrido(4,5);
    insertar_recorrido(4,6);
    insertar_recorrido(5,6);
    insertar_recorrido(5,7);
    insertar_recorrido(6,7);
    insertar_recorrido(6,8);
    insertar_recorrido(7,8);
    insertar_recorrido(8,8);
    insertar_recorrido(9,8);
    insertar_recorrido(10,8);
    insertar_recorrido(11,8);*/


}


car_t::~car_t(){}

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


///DESTINY
void car_t::set_destiny(int x, int y)
{
    destiny_[0] = x;
    destiny_[1] = y;
}
void car_t::set_status(std::vector<int> v) //done
{
    status_.clear();
    
    for(int i = 0; i < v.size(); ++i)
        status_.push_back(v[i]);
    
    
    /*for(int i = 0; i < v.size(); ++i)
    {
        std::cout << " posicion "<< i << ": " << v[i] << std::endl;
    }*/
}

// GETTERS

int car_t::get_x_destiny() const 
{
    return destiny_[0];
}
int car_t::get_y_destiny() const
{
    return destiny_[1];
}
std::vector<int> car_t::get_destiny() const
{
    return destiny_;
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

//Security
std::vector<std::vector <int> > car_t::check_compass(int width, int height) //done
{
    possible_move_.clear();   
    return check_ut(width, height, possible_move_);                                                             
}

std::vector< std::vector<int> > car_t::check_ut(int width, int height, std::vector<std::vector<int> >& v)   //done
{
    possible_move_.clear();
    
    if(check(width, height, north() ) ) v.push_back(north() );
    if(check(width, height, south() ) ) v.push_back(south() );
    if(check(width, height, west() ) ) v.push_back(west() ) ;
    if(check(width, height, east() ) ) v.push_back(east() ) ;

    //if(v.size() == 1) set_callejon_true();
    
    return v;
}

bool car_t::check(int width, int height, std::vector<int> v) //done
{
    if ( (v[0] >= width)  || (v[0] < 0) ) return false;
    if ( (v[1] >= height) || (v[1] < 0) ) return false;
    else
        return true;
}

bool car_t::get_callejon()
{
    return callejon;
}

void car_t::set_callejon_false()
{
    callejon = false;
}
void car_t::set_callejon_true()
{
    callejon = true;
}

bool car_t::check_destiny()
{
    if ( ( get_x_destiny() == get_x() ) && ( get_y_destiny() == get_y() ) )
        return true;
    return false;
    
}

void car_t::prunning_nearbours()    //done
{
    for(int i=possible_move_.size()-1; i >= 0 ; i--)
    {
        if(status_[i] == 1 || status_[i] == 2 || status_[i] == 6 ) possible_move_.erase(possible_move_.begin()+i);
        //prueba para contar las personas hasta un maximo
        //if( (persona_count == max) && (status_[i] == 2)) possible_move_.erase(possible_move_.begin()+i);
    }
    
    /*if(possible_move_.size() == 1) 
    {
        set_callejon_true();
        //for(int i=possible_move_.size()-1; i >= 0 ; i--)
        //    if(status_[i] == 6) possible_move_.erase(possible_move_.begin()+i);
    }*/
}
int car_t::get_callejon_v_x()
{
    return callejon_v[0];
}

int car_t::get_callejon_v_y()
{
    return callejon_v[1];
}

void car_t::set_contador_estrella(int x)
{
    contador_estrella = x;
}


//AuxiliaryDONE
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


/// MOVIMIENTO

int car_t::move(int width, int height, int opt) 
{

    float   mejor_distancia = FLT_MAX; // almacenará la menor distancia de entre los vecinos
    std::vector<int> mejor_vecino; mejor_vecino.clear();             // almacenará la coordenada de ese vecino
    float current = 0; // auxiliar de comparación de distancias
    
        if(possible_move_.size() == 1 /*|| possible_move_.size() == 2*/)
        {
            for(int i = 0; i < recorrido_.size(); ++i)
            {
                //std::cout << "Hola" << std::endl;
                if( (possible_move_[0][0] == recorrido_[i][0] ) && ( possible_move_[0][1] == recorrido_[i][1] ) )
                {
                    if(callejon_v.empty()){
                        callejon_v.push_back(get_x());
                        callejon_v.push_back(get_y());
                        std::cout << "Lo hice1" << std::endl;
                    }
                    else{
                        callejon_v[0] = get_x();
                        callejon_v[1] = get_y();
                        std::cout << "Lo hice2" << std::endl;
                        
                    }
                    recorrido_.pop_back();
                    set(recorrido_[recorrido_.size() - 1][0], recorrido_[recorrido_.size() - 1][1]);
                    return 5;
                }//else std::cout << "petas" << std::endl;
            }
        }
        else{
            
            bool c2 = false;
            if(possible_move_.size() == 2)
                c2 = true;
                
            for(int i = possible_move_.size()-1; i >= 0; --i)
            //for ( int i = 0; i  < possible_move_.size(); i++)
            {
                if(opt == 0){
                    //std::cout << contador_estrella << "\n";
                    current = manhattan(possible_move_[i][0], possible_move_[i][1]);
                    current += contador_estrella;
                }
                else if(opt == 1){
                    current = euclidiana(possible_move_[i][0], possible_move_[i][1]);
                    current += contador_estrella;
                }
                //std::cout << current << std::endl;
                //std::cout << "(" << possible_move_[i][0] << "," << possible_move_[i][1] << "): " << current << std::endl;
                if(current < mejor_distancia)
                {   
                    mejor_distancia = current;
                    mejor_vecino    = possible_move_[i];
                }
                possible_move_.pop_back();        // por cada vecino analizado, lo quito
            }
            
            //std::cout << "actualizo vecinos" << std::endl;
            if (c2)
            {

                    for(int j = 0; j < recorrido_.size(); ++j)
                    {
                        if((mejor_vecino[0] == recorrido_[j][0] ) && (mejor_vecino[1] == recorrido_[j][1]))
                        {
                            if(callejon_v.empty()){
                                callejon_v.push_back(get_x());
                                callejon_v.push_back(get_y());
                                std::cout << "Lo hice1" << std::endl;
                            }
                            else{
                                callejon_v[0] = get_x();
                                callejon_v[1] = get_y();
                                std::cout << "Lo hice2" << std::endl;
                            }
                            recorrido_.pop_back();
                            set(recorrido_[recorrido_.size() - 1][0], recorrido_[recorrido_.size() - 1][1]);
                            return 5;
                        }   
                    }
                
            }
            
            insertar_recorrido(mejor_vecino[0], mejor_vecino[1]);
        

        
        //Aqui es donde cambia y se mueve, entonces antes de hacer esto tiene que poner donde esta en 6
           /* if(callejon)
            {
                if(!callejon_v.empty())
                {
                    //mierda, que machine es el unico que puede modificar malla, su puta madre
                    callejon_v[0] = get_x();
                    callejon_v[1] = get_y();
                }
                else
                {
                    callejon_v.push_back(get_x());
                    callejon_v.push_back(get_y());
                    
                }
            }*/
            
                set(mejor_vecino[0], mejor_vecino[1]); 
                contador_estrella++;
                return 0;
            }
            //std::cout << "(" << mejor_vecino[0] << ", " << mejor_vecino[1] << ")" <<  std::endl;
            //std::this_thread::sleep_for (std::chrono::milliseconds(50));
}

// HEURISTICAS

float car_t::euclidiana(int x, int y)
{
   return (sqrt(((get_x_destiny() - x)*(get_x_destiny() - x))+((get_y_destiny() - y)*(get_y_destiny() - y))));
}


float car_t::manhattan(int x, int y)
{
    return ((abs(get_x_destiny() - x)) + (abs(get_y_destiny() - y)));
}



void car_t::print_data_test()
{
    std::cout << "existo: " << status_.size()<< "\n";
    for ( int i = 0; i < status_.size(); i++)
        std::cout << "estado del pinche puto: " << status_[i];
    std::cout << "\n";
}
