#pragma once

#include "grid.h"
#include "ant.h"
//include "utilidad.hpp"


#include <iostream>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cfloat>

//////
#include <thread>  

class car_t: public ant_t   ///si llega al fin de la cuadricula no puede hacer ese movimiento, esta prohibido.
{
    private:
        std::vector<int> destiny_;  //guardamos donde tiene que llegar. Usaremos el atributo destiny_ para usarlo de destino y que el coche sepa en donde se encuantra el destino
        std::vector< std::vector<int> > possible_move_; // contenedor de nearbours
        std::vector<int> status_; // vector de valores para un vector de coordenadas
        std::vector<std::vector<int> > recorrido_;
        bool callejon;
        std::vector<int> callejon_v;
        int contador_estrella;

        
    public: 
        car_t();
        car_t(int x, int y);
        ~car_t();
        
        void insertar_recorrido(int x, int y);
        void extraer_recorrido();
        void set_contador_estrella(int x);
        
        // setters
        void set_destiny(int x, int y);     //introducimos el destino de forma manual, no hay ninguno predeterminado, daría error.
        void set_status(std::vector<int> v);        
        
        // getters
        int get_x_destiny() const;  
        int get_y_destiny() const;
        int get_size_recorrido() const;
        std::vector<int> get_destiny() const;       //devuelve el vector con el destino;
        int get_recorrido_x(int i) const;
        int get_recorrido_y(int i) const;
        int get_callejon_v_x();
        int get_callejon_v_y();
        
        // Poda
        void prunning_nearbours(void);
        void set_callejon_false();
        bool get_callejon();
        void set_callejon_true();
      
        //Security
        std::vector<std::vector <int> > check_compass(int width, int height);  // NOMBRE PROVISIONAL // busca el recorrido óptimo usando las heurísticas para almacenar las casillas de dicho recorrido en un vector, pila, set, ...
        std::vector< std::vector<int> > check_ut(int width, int height, std::vector<std::vector<int>>& v); 
        bool check(int width, int height, std::vector<int> v);
        bool check_destiny();
    
        //Auxiliary
        std::vector<int> north();
        std::vector<int> south();
        std::vector<int> west();
        std::vector<int> east();
        
        //Principal
        int move(int width, int height, int opt);
        float euclidiana(int x, int y);            // raiz cuadrada de la suma de las diferencias de las coordenadas al cuadrado
        float manhattan(int x, int y);             // suma del valor absoluto de la diferencia de las coordenadas

        void print_data_test();
};
