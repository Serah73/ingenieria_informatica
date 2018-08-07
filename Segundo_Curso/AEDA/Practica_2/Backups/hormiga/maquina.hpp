#include "hormiga.hpp"
#include "cuadricula.hpp"

class maquina
{
private:
	hormiga hormiga;
	cuadricula grid;
public:
	maquina();
	~maquina();
	
	void write();
};