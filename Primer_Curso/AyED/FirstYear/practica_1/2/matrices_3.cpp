#include "matrices_3.hpp"
#include <iomanip>

using namespace std;


//========================================================================================
// Métodos privados.
//========================================================================================



vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		cerr << "Error accediendo a matriz"<< endl;
		return 0;
        }
		return (i-1)*n_+j-1;
}

vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j) const
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		cerr << "Error accediendo a matriz"<< endl;
		return 0;
        }
		return (i-1)*n_+j-1;
}


void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		cerr << "Error creando matriz." << endl;
}		



void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}




void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}




//========================================================================================
// Métodos públicos.
//========================================================================================

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
}	




matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0)
{}		



matrix_t::~matrix_t(void)
{
	destruirMatriz();
}


matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j) const
{
	if(!traspuesta)
		return M_[pos(i,j)];
	else
		return M_[pos(j,i)];
}


void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}




matrix_inx_t matrix_t::get_m(void) const
{
	if(!traspuesta)
		return m_;
	else 
		return n_;
}




matrix_inx_t matrix_t::get_n(void) const
{
	if(!traspuesta)
		return n_;
	else 
		return m_;
}




istream& matrix_t::read(istream& is)
{
	int m,n;

	is >> m >> n;

	redimensiona(m,n);

	const int sz=m*n;

	for(int i=0;i<sz;i++)
		is >> M_[i];
	
}



ostream& matrix_t::write(ostream& os) const
{

	os << setw(10) << get_m() << setw(10) << get_n() << endl;

	for(int i=1;i <= get_m();i++){

		for(int j=1;j <= get_n() ;j++)
			os << setw(10) << fixed << setprecision(6) << get_matrix_item(i,j);
		
		os << endl;
	}
}

void matrix_t::write(void) const 
{

	for(int i=1;i <= get_m();i++){
		cout << "|";
		for(int j=1;j <= get_n();j++)
			cout << setw(10) << fixed << setprecision(6) << get_matrix_item(i,j);
		cout << " |";
		cout << endl;
	}

	cout << endl;
}

bool matrix_t::igual(matrix_item_t a, matrix_item_t b, double ppp){
	return( (fabs(a-b)<ppp)? true : false);
}
bool matrix_t::mayor(matrix_item_t a, matrix_item_t b, double ppp){
	return (((a-b)>ppp)? true : false);
} 

bool matrix_t::menor(matrix_item_t a, matrix_item_t b, double ppp){
	return (((b-a)>ppp)? true : false);
}

bool matrix_t::zero(matrix_item_t a, double ppp){
	return ((fabs(a)<ppp)? true : false);
}


void matrix_t::filtra(matrix_t& M, matrix_item_t it, double ppp){
	M.redimensiona(get_m(), get_n());
	for(int i=1; i<=get_m(); i++){
		for(int j=1; j<=get_n(); j++){
			if(igual(get_matrix_item(i, j), it, ppp))
				M.set_matrix_item(i,j, get_matrix_item(i,j));
			else
				M.set_matrix_item(i,j, 0.0);
		}
	}
}

void matrix_t::trasponer(void){
	/*if(!traspuesta)
		traspuesta=true;
	else
		traspuesta=false;
	*/
	!traspuesta? traspuesta=true : traspuesta=false;
}
