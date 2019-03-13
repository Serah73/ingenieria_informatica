/*
 * wall.cpp
 *
 *  Created on: 25 oct. 2018
 *      Author: Serah
 */

#include "wall.h"

wall_t::wall_t():
width_(0),
height_(0),
total_wall_(0)
{
	ask_NxM();
	ask_type_brick();
	RowSecureRecursive(width_, 0, comb_);
}

wall_t::wall_t(int width, int height):
width_(width),
height_(height),
total_wall_(0)
{
	ask_type_brick();
	RowSecureRecursive(width_, 0, comb_);
}

wall_t::~wall_t() {}

//User ask
void wall_t::ask_NxM()
{
	std::cout << "¿Que tamaño tiene el muro? (ancho, altura)\n";
	std::cin >> width_ >> height_;
	std::cout <<"\n";
}

void wall_t::ask_type_brick()
{
	std::cout << "¿Cuantos bloques diferentes vas a introducir? "; //preguntar al usuario etc
	std::cin >> type_brick_;
	//std::cout << "\n";	//eclipse ya mete uno de por si al hacer el cout

	size_brick_user.clear();
	size_brick_user.resize(type_brick_);

	for (int i = 0; i < type_brick_; i++)
		ask_size_brick(i);

	std::cout << "\n";
}

void wall_t::ask_size_brick(int i)
{
	int aux;

	std::cout << "Tamaño del bloque " << i + 1 << ": ";
	std::cin >> aux;
	//std::cout << "\n";

	size_brick_user[i] = aux;

}

////////////////////////////////////////
int wall_t::get_type_brick()
{
	return type_brick_;
}
int wall_t::get_size_brick(int i)
{
	return size_brick_user[i];
}
int wall_t::get_height()
{
	return height_;
}
int wall_t::get_width()
{
	return width_;
}
int wall_t::get_fila_size()
{
	return fila_.size();
}
row_t wall_t::get_row(int pos)
{
	return fila_[pos];
}
////////////////////////////////////////
//Security
void wall_t::save(std::vector<int> v)
{
	row_t aux(v);
	fila_.push_back(v);
}

bool wall_t::check_row (row_t a, row_t b)	//checked
{
    if ( a.get_val(0) == b.get_val(0) )
        return false;

    if ( a.get_val( a.get_size() - 1 ) == b.get_val( b.get_size() - 1 ) )
        return false;

    int i = 0, j = 0, a_sum = 0, b_sum = 0;

    while ( ( i < a.get_size() ) && ( j < b.get_size() ) )
    {
        a_sum += a.get_val(i);
        b_sum += b.get_val(j);

        if( ( a_sum == b_sum ) && ( ( a_sum != get_width() ) || ( b_sum != get_width()) ) )
            return false;
        else
        {
            i++; j++;
        }
    }
    return true;
}

bool wall_t::check_wall(std::vector<row_t> row)
{
	int size_aux = row.size();

	for ( int i = 1; i < size_aux; i++ )
	{
		if( !(check_row(row[i - 1], row [i]) ) ) return false;
	}
	return true;
}

void wall_t::check_all(int height, std::vector<int> possible_wall)
{
	row_t aux;
	bool checked = false;

	for ( int i = 0; i < height; i++)
	{
		aux = get_row(possible_wall[i]);
		wallrow_.push_back(aux);
	}
	checked = check_wall(wallrow_);

	if ( checked )
	{
		total_wall_++;
		std::cout << "\n\t|Muro " << total_wall_ << "|\n";
		write(std::cout);
	}
	wallrow_.clear();
}


//Principal functions
void wall_t::RowSecureRecursive(int sz, int total, std::vector<int> brick)
{
	if ( total > sz )	brick.pop_back();

	else if ( total == sz )	save(brick);

	else
	{
		for ( int i = 0; i < get_type_brick(); i++)
		{
			brick.push_back(get_size_brick(i) );
			RowSecureRecursive(sz, total + get_size_brick(i), brick);
			brick.pop_back();
		}
	}
}

void wall_t::generate_possible_wall(int height, std::vector<int> possible_wall)
{
	int size_pw = possible_wall.size();

    if (size_pw > get_height())
    	possible_wall.pop_back();

    else if (size_pw == get_height() )
    	//tenemos que ver si es corrector el muro
    	check_all(get_height(), possible_wall);

    else
        for (int i = 0; i < get_fila_size(); i++)
        {
            possible_wall.push_back(i);
            generate_possible_wall(get_height(), possible_wall);
            possible_wall.pop_back();
        }
}

void wall_t::start(void)
{
	std::cin.ignore();
	std::cin.ignore();
	std::cout << "\t----------Arranque del generador----------\n";
	comb_.clear();
	generate_possible_wall(height_, comb_);

}
//Auxiliary
void wall_t::print_data()
{
	system("clear");
	std::cout << "El alto del muro es:\t" << height_ << "\n";
	std::cout << "El ancho del muro es:\t" << width_ << "\n";
	std::cout << "Tenemos " << type_brick_ << " tipos de bloque" << "\n";
	std::cout << "Con el tamaño:\n";

	int size_aux = size_brick_user.size();

	for ( int i = 0; i < size_aux; i++ )
	{
		std::cout << "\t| Bloque " << i << " --->" << get_size_brick(i) << " |\n";
	}

	std::cout << "\nNumero de filas posibles: " << get_fila_size() << "\n";

	for ( int i = 0; i < get_fila_size(); i++ )
		std::cout << "\t" << fila_[i] << "\n";
}

std::ostream& wall_t::write(std::ostream& os)
{
	os << "\t---------------\n";
	for ( int i = 0; i < get_height() ; i++)
		os << "\t  " << wallrow_[i] << "\n";
	os << "\t---------------\n";
	return os;
}

//// PRUEBAS PARA VER COMO FUNCIONAN LAS COSAS
void wall_t::pruebas()
{
	std::vector<int> b(10);
	std::vector<row_t> vr;

	for (int i = 0; i < 10; i++)
		b[i] = i;

	row_t a(b);

	vr.push_back(a);
	vr.push_back(a);

	std::vector<int> aux(10);
	int size_aux = aux.size();

	for (int i = 10; i > size_aux; i--)
			aux[i] = i;

	a = vr[b[1]];

	std::cout << "prueba 1:" << /*get_row(aux[1])*/ a/*[b[1]]*/ << "\n";
//	std::cout << "prueba 2:" << get_row(aux[8]) << "\n";
}

std::ostream &operator<<(std::ostream &os, wall_t& wall)
{
	row_t aux;

	for ( int i = 0; i < wall.get_fila_size(); i++)
	{
		aux = wall.get_row(i);
		os << "\t" << aux << "\n";
	}
	return os;
}
