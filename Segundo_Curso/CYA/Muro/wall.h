/*
 * wall.h
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */
#pragma once

#include "row.h"

#include <algorithm>
#include <numeric>
#include <iostream>
#include <unistd.h>	//sleep

#ifndef WALL_H_
#define WALL_H_

class wall_t
{
	private:

		int width_, height_, type_brick_, total_wall_;	//ancho, alto, tipos de bloque, respectivamente.
		std::vector<row_t> fila_,wallrow_;	//para acumular las filas posibles y las finales.
		std::vector<int> size_brick_user/*tama�o de los bloques que le pediremos al usuario*/, comb_;

	public:

		wall_t();
		wall_t(int width, int height);
		virtual ~wall_t();

		//User ask
		void ask_NxM();
		void ask_type_brick();	//cuantos bloques diferentes(?), se llama a ask_size_brick
		void ask_size_brick(int i);	//se llama implicitamente(ask_type_brick), con un for que guarda todos los tama�os

		int get_type_brick();
		int get_size_brick(int i);
		int get_height();
		int get_width();
		int get_fila_size();
		row_t get_row(int pos);

		//Security
		bool check_row(row_t a, row_t b);
		bool check_wall(std::vector<row_t> row);
		void check_all(int height, std::vector<int> possible_wall);
		void save(std::vector<int> v);


		//Principal functions
		void RowSecureRecursive(int sz, int total, std::vector<int> brick);
		void generate_possible_wall(int height, std::vector<int> possible_wall);
		void start(void);


		//Auxiliary
		void print_data();
		std::ostream& write(std::ostream& os);
		void pruebas();
};

std::ostream &operator<<(std::ostream &os, wall_t& wall);

#endif /* WALL_H_ */
