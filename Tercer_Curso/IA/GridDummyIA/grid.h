#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>


class grid_t
{
	private:

		std::vector<std::vector<int> > grid_;
		int height_;
		int width_;

	public:
	//constructores
		grid_t();	//constructor por defecto, grid 0x0.
		grid_t(int x, int y);	//constructor solo de la cuadricula, inicializa a 0 todo el grid
		grid_t(int x, int y, int colour);	//inicializar el grid con su height, width y tipo de la via
		grid_t(const grid_t &grid);	//el de copia
		virtual ~grid_t();
	//getters
		int get_height(void);		//alto del grid
		int get_width(void);		//ancho del grid
		int get(int x, int y);		//obtener el tipo que se encuentre en la via
	//setters
		void set(int x, int y, int colour);		//darle el tipo de via a una casilla.
		void resize(int height, int width);
		void resize(int height, int width, int colour);
		
	//imprimir la cuadricula, mirar como incluirlo en esta
	
		void write(void);	//modificar en el  cpp, esta hecho para la hormiga.

};