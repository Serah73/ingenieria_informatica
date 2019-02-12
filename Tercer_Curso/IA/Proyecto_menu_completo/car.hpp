#pragma once

#include "grid.h"
#include "ant.h"



#include <iostream>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cfloat>

#include <thread>  

class car_t: public ant_t   
{
    private:
        std::vector<int> destiny_;   
        std::vector< std::vector<int> > possible_move_; 
        std::vector<int> status_; 
        std::vector<std::vector<int> > recorrido_;
        bool callejon;
        std::vector<int> callejon_v;
        int contador_estrella;
        int nodos_generados;

        
    public: 
        car_t();
        car_t(int x, int y);
        ~car_t();
        
        // setters
        void set_destiny(int x, int y);     
        void set_status(std::vector<int> v);  
        void set_callejon_false();
        void set_callejon_true();
        void set_contador_estrella(int x);
        void set_nodos_generados();
        
        // getters
        std::vector<int> get_destiny() const;
        int get_x_destiny() const;  
        int get_y_destiny() const;
        
        int get_size_recorrido() const;
        int get_recorrido_x(int i) const;
        int get_recorrido_y(int i) const;
        
        bool get_callejon();
        int get_callejon_v_x();
        int get_callejon_v_y();
        
        int get_nodos_generados();
        



        //Security
        std::vector<std::vector <int> > check_compass(int width, int height); 
        std::vector< std::vector<int> > check_ut(int width, int height, std::vector<std::vector<int>>& v); 
        bool check(int width, int height, std::vector<int> v);
        bool check_destiny();
    
        //Auxiliary
        std::vector<int> north();
        std::vector<int> south();
        std::vector<int> west();
        std::vector<int> east();
        
        void prunning_nearbours(void);
        void insertar_recorrido(int x, int y);
        void extraer_recorrido();
        
        //Principal
        int move(int width, int height, int opt);
        float euclidiana(int x, int y);         
        float manhattan(int x, int y);             

        void print_data_test();
};
