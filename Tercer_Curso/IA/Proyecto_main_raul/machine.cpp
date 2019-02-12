#include "machine.h"


machine_t::machine_t(car_t car, grid_t rejilla)
{
	coche_ = car;
	rejilla_ = rejilla;
}

machine_t::~machine_t()
{}

void machine_t::start(void)
{
	coche_.set_callejon_false(); std::this_thread::sleep_for (std::chrono::milliseconds(550));
	std::cout << "\t-¿Que tipo de calculo quieres usar? manhattan(0), euclidia(1): ";
	int opt;
	std::cin >> opt;
	if(opt != 0 && opt != 1){
		std::cout << "Introduzca una opcion valida" << std::endl;
		start();
	}
	std::cout << "\n";
	coche_.set_nodos_generados();
	
	int cont = 0;
	coche_.set_contador_estrella(0);
	
	while((coche_.get_x() >= 0) 
	&& (coche_.get_x() < rejilla_.get_width()) 
	&& (coche_.get_y() >= 0) 
	&& (coche_.get_y() < rejilla_.get_height())
	&& (coche_.check_destiny() == false))
	{
		cont++;
		eyecar();														
		
		coche_.prunning_nearbours();	
		
		if (coche_.move(rejilla_.get_width(), rejilla_.get_height(), opt ) == 5)
			rejilla_.set(coche_.get_callejon_v_x(), coche_.get_callejon_v_y(), 6);
		
		if(cont == 200) coche_.set(coche_.get_x_destiny(), coche_.get_y_destiny());
	}

}


void machine_t::write(void)	
{
	rejilla_.set(coche_.get_x_destiny(), coche_.get_y_destiny(), 9);
	std::cout << termcolor::on_yellow << termcolor::bold; 
	int height = rejilla_.get_height();
	int width = rejilla_.get_width();
	
	for(int k = 0; k < coche_.get_size_recorrido(); ++k)
	{
		system ("clear");
		for(int y = height - 1; y >= 0; y--) 
		{
			for(int x = 0; x < width; x++) 
			{
				if((coche_.get_recorrido_x(k) == x) && (coche_.get_recorrido_y(k) == y))
				{
					rejilla_.set(x,y,3);
					std::cout << "   ";
				}
				else	
					switch(rejilla_.get(x, y)) 
					{
						case 0:
							std::cout << ' ' << "  ";
							break;
						case 1: //Obstaculo
							std::cout<< termcolor::on_red << " 1 " << termcolor::on_yellow ;
							break;
						case 2: //Persona
							std::cout << termcolor::on_blue << " 2 " << termcolor::on_yellow ;
							break;
						case 3: // coche
							std::cout << termcolor::on_white << " " << "o " << termcolor::on_yellow ;
							rejilla_.set(x,y,4);
							break;
						case 4: // estela
							std::cout << termcolor::on_green << "   " << termcolor::on_yellow ;
							break;
						case 6:
							std::cout << ' ' << "  ";
							break;
						case 9:
							std::cout<< termcolor::on_white << " 1 " << termcolor::on_yellow ;
							break;
						
						default:
							std::cout << "esto no se puede imprimir";
							break;
					}
					
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		std::this_thread::sleep_for (std::chrono::milliseconds(150));
	}
	std::cout << termcolor::reset;
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "Nodos generados: " << coche_.get_nodos_generados() << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "Longitud del camino: " << coche_.get_size_recorrido() << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;

}

void machine_t::random_obstacles(int cantidad)	
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> obstacle(1,2);
	
	std::uniform_int_distribution<int> x_gen(0, rejilla_.get_width() - 1);
	std::uniform_int_distribution<int> y_gen(0, rejilla_.get_height() - 1);
	
	for(int i = 0; i < cantidad; ++i)
	{
		int x_val = x_gen(generator), y_val = y_gen(generator);
		if(rejilla_.get(x_val,y_val) == 0)
			rejilla_.set(x_val, y_val, obstacle(generator));
		else
			--i;
	}
}

void machine_t::random_obstacles(float porcentaje)
{ 
	int cantidad = porcentaje*(rejilla_.get_height()*rejilla_.get_width());
	random_obstacles(cantidad);
}

void machine_t::manual_obstacles(int option)
{
	if (option == 1)	std::cout << "¿Cuantos obstaculos ";
	else if (option == 2)	std::cout << "¿Cuantas personas ";
	else
	{
		std::cout << "No contemplanos esa opcion\n";
		exit(-1);
	}
	std::cout << "quieres meter en total?: ";
	
	int size;
	std::cin >> size;	std::cout << "\n";
	
	for (int i = 0; i < size; i++)
	{
		int x = 0, y = 0;
		std::cout << "Introduce un punto x, y: ";
		std::cin >> x >> y;
		std::cout << "\n";
		rejilla_.set(x, y, option);	
	}
}


void machine_t::eyecar()
{
	int aux;	
	std::vector<int> v;	
	
	v.clear();
	
	std::vector< std::vector <int> > ut;
	
	ut = coche_.check_compass(rejilla_.get_width(), rejilla_.get_height());
	
	for ( int i = 0; i < ut.size(); i++)	
	{
		std::vector<int> test;
		test.clear();
		
		test.push_back(ut[i][0]);
		test.push_back(ut[i][1]);
		
		aux = rejilla_.get(test[0], test[1]);
		v.push_back(aux);
	}
	coche_.set_status(v);
}