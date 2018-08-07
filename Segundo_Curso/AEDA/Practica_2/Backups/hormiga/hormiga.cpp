#include "hormiga.hpp"

hormiga::hormiga(int x, int y) {
	x_ = x;
	y_ = y;
	orientation_ = '^';
}

hormiga::~hormiga() {
	x_ = 0;
	y_ = 0;
	orientation_ = null;
}

void hormiga::right() {
	set_x(get_x() + 1);
	set_orientation('>');
}

void hormiga::left() {
	set_x(get_x() - 1);
	set_orientation('<');
}

void hormiga::up() {
	set_y(get_y() - 1);
	set_orientation('^');
}

void hormiga::down() {
	set_y(get_y() + 1);
	set_orientation('v');
}

void hormiga::set_x(int x) {
	x_ = x;
}

void hormiga::set_y(int y) {
	y_ = y;
}

void hormiga::set_orientation(char orientation) {
	orientation_ = orientation;
}

int hormiga::get_x() {
	return x_;
}

int hormiga::get_y() {
	return y_;
}
char hormiga::get_orientation() {
	return orientation_;
}