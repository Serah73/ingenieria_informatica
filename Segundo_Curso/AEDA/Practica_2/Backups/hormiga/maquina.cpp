#include "maquina.hpp"
#include <iostream>
using namespace std;

maquina::maquina(hormiga ant_, cuadricula grid_) {
	hormiga = ant_;
	grid = grid_;
}
maquina::~maquina() {}


maquina::write() {
	for(int i = 0; i < grid.get_height(); i++) {
		for(int j = 0; j < grid.get_width(); j++) {
			if(hormiga.get_x() == i && hormiga.get_y() == j) cout << hormiga.get_orientation();
			else switch(grid.get(i, j)) {
				case 0:
				cout << "x";
				break;
				case 1:
				cout << "o";
				break;
			}
		}
		cout << endl;
	}
}

maquina::step() {
	switch(grid.get(hormiga.get_x(), hormiga.get_y())) {
		case 0:	//blanco
		switch(hormiga.get_orientation) {
			case '^':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 1);
				hormiga.left();
			break;
			case '>':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 1);
				hormiga.up();
			break;
			case '<':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 1);
				hormiga.down();
			break;
			case 'v':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 1);
				hormiga.right();
			break;
		}
		break;
		case 1:	//negro
		switch(hormiga.get_orientation) {
			case '^':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 0);
				hormiga.right();
			break;
			case '>':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 0);
				hormiga.down();
			break;
			case '<':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 0);
				hormiga.up();
			break;
			case 'v':
				grid_.set(hormiga.get_x(), hormiga.get_y(), 0);
				hormiga.left();
			break;
		}
		break;
	}
}

maquina::run() {
	while(hormiga.get_x() > 0 && hormiga.get_x() < grid.get_width() && hormiga.get_y() > 0 && hormiga.get_y() < grid.get_height()) {
		write();
		step();
	}
}