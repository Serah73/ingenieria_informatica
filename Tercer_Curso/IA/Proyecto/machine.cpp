#include "machine.h"


machine_t::machine_t(car_t car, grid_t rejilla)
{
	coche_ = car;
	rejilla_ = rejilla;
}

machine_t::~machine_t()
{}

//review
void machine_t::start(void)
{
	//std::cout << "mantenimiento\n";
	coche_.set_callejon_false(); std::this_thread::sleep_for (std::chrono::milliseconds(550));
	std::cout << "Que quieres usar? manhattan(0), euclidia(1): ";
	int opt;
	std::cin >> opt;
	if(opt != 0 && opt != 1){
		std::cout << "Introduzca una opcion valida" << std::endl;
		start();
	}
	std::cout << "\n";
	
	//std::cout << "get_x: " << coche_.get_x() << std::endl; std::this_thread::sleep_for (std::chrono::milliseconds(350));
	//std::cout << "get_y: " << coche_.get_y() << std::endl; std::this_thread::sleep_for (std::chrono::milliseconds(350));
	//std::cout << "bool destiny: " << coche_.check_destiny() << std::endl; std::this_thread::sleep_for (std::chrono::milliseconds(350));
	int cont = 0;
	coche_.set_contador_estrella(0);
	
	while((coche_.get_x() >= 0) 
	&& (coche_.get_x() < rejilla_.get_width()) 
	&& (coche_.get_y() >= 0) 
	&& (coche_.get_y() < rejilla_.get_height())
	&& (coche_.check_destiny() == false))
	{
		cont++;
		//std::cout << "compass\n"; std::this_thread::sleep_for (std::chrono::milliseconds(550));
		eyecar();		//done													// recargo status_
		//std::cout << "callejon: " << coche_.get_callejon() << std::endl;
		
		coche_.prunning_nearbours();	//done
		
		if (coche_.move(rejilla_.get_width(), rejilla_.get_height(), opt ) == 5)
			rejilla_.set(coche_.get_callejon_v_x(), coche_.get_callejon_v_y(), 6);
			
		/*if(coche_.get_callejon())
		{  
			//std::cout << "X: "<< coche_.get_callejon_v_x() << "Y: " << coche_.get_callejon_v_y() << std::endl;
			rejilla_.set(coche_.get_callejon_v_x(), coche_.get_callejon_v_y(), 6);
		}*/
		
		//if(cont == 121) coche_.set(coche_.get_x_destiny(), coche_.get_y_destiny());
	}

}

//review
void machine_t::write(void)	//falta impresion del camino/coche
{
	rejilla_.set(coche_.get_x_destiny(), coche_.get_y_destiny(), 9);
	std::cout << termcolor::on_yellow << termcolor::bold; // << termcolor::white;
//	std::cout << "--------------------------------------------------------------------" << std::endl;
	int height = rejilla_.get_height();
	int width = rejilla_.get_width();
	
	for(int k = 0; k < coche_.get_size_recorrido(); ++k)
	{
		system ("clear");
		for(int y = height - 1; y >= 0; y--) 
		{
			for(int x = 0; x < width; x++) 
			{
				// impresion del coche
				//if((coche_.get_x() == x) && (coche_.get_y() == y))
					//std::cout << termcolor::white << coche_.get_way() << termcolor::on_yellow << "  ";
				//else
				if((coche_.get_recorrido_x(k) == x) && (coche_.get_recorrido_y(k) == y))
				{
					//std::cout << "X: " << x << "Y: " << y << std::endl;
					//std::cout << termcolor::white << " " << coche_.get_way() << termcolor::on_yellow < " "; 
		
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
							std::cout << termcolor::on_white << " " << /* coche_.get_way() */ "o " << termcolor::on_yellow ;
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
	//std::cout << "--------------------------------------------------------------------" << std::endl;

}

////////////////////done//////////////////////////////
void machine_t::random_obstacles(int cantidad)	//semilla, siempre la misma
{
	//Cambio de semilla // Comprobar
	
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

void machine_t::random_obstacles(float porcentaje)//done
{ 
	int cantidad = porcentaje*(rejilla_.get_height()*rejilla_.get_width());
	random_obstacles(cantidad);
}

void machine_t::manual_obstacles(int option)//done
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
		rejilla_.set(x, y, option);	//va poniendo en la casilla el tipo de la opcion, en los puntos que ponga el usuario
	}
}
///////////////////////////////////////////////////

void machine_t::eyecar()	//done
{
	int aux;	//pasarle al car(0,1,2)
	std::vector<int> v;	//quien vas a mandar al car
	
	v.clear();
	
	std::vector< std::vector <int> > ut;
	
	ut = coche_.check_compass(rejilla_.get_width(), rejilla_.get_height());
	
	for ( int i = 0; i < ut.size(); i++)	//eje x
	{
		std::vector<int> test;
		test.clear();
		
		test.push_back(ut[i][0]);
		test.push_back(ut[i][1]);
		
		aux = rejilla_.get(test[0], test[1]);
		v.push_back(aux);
	}
	for (int i = 0; i < v.size(); i++)
		std::cout << " posicion "<< i << ": " << v[i] << std::endl;
	
	coche_.set_status(v);
	
	//Testeo
	//coche_.print_data_test();
}