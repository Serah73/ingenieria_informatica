/*
 *  prob.cpp - Libreria para la lectura y resolucion de un PL <=
 *
 *
 *  Autor : 
 *  Fecha : 
 */


#include "prob.h"


//Completo! 
PROBLEM::~PROBLEM() {			//destructor.
	unsigned i;
	for (i=0;i<m;i++) A[i].resize(0);
	A.resize(0);
	ivb.resize(0);
	c.resize(0);
	b.resize(0);
}


//Completo! 
PROBLEM::PROBLEM(char nombrefichero[85])		//constructor.
{
	unsigned i, j;
	double dummy;
	ifstream textfile;
	
	textfile.open(nombrefichero);
    if (textfile.is_open()) {
		textfile >> (char *) clase >> (unsigned &) n >> (unsigned &) m;
		A.resize(m);    //m filas

		//Leemos la fila de los costes
		for (i=0;i<n; i++) {
			textfile >> (double &) dummy;
			c.push_back(dummy);  //coste originales
		}

		nh = m;
		//Extendemos el vector c a tama�o n+nh
		for(i=0;i<nh;i++) c.push_back(0.0); // costes originales variables de holgura
		Vo = 0.0; //Inicializamos del valor de la funci�n objetivo.

		//Leemos la m restricciones y asignamos A, b, ivb
		for (i=0;i<m;i++) {
			for (j=0;j<n;j++) {
				textfile >> (double &) dummy;
				A[i].push_back(dummy);
			}
			textfile >> (double &) dummy;
			b.push_back(dummy);
			if (dummy < CERONEG){
				cout << "Lado derecho negativo, Modifique problema" << endl;
				exit(0);
			}
			A[i].resize(n+nh);  //Extendemos la fila a tama�o n+nh
			A[i][n+i] = 1.0;  //Ponemos un 1 en la columna n+i, correspondiente a la var. de holgura de la fila i
			ivb.push_back(n+i); //La var. b�sica asociada a la fila i es n+i
		}	
		textfile.close();
	}
	else {
		cout << "Fichero no reconocido"<< endl;
		Formato_fichero();			//si quieres poner "algo".
		exit(0);					//se acaba el programa.
	}
}


//Muestra por pantalla el formato que debe tener un fichero de entrada para este problema 
void Formato_fichero()
{
    cout<<"tipo_problema"<<setw(20)<<"n_variables"<<setw(30)<<"m_restricciones"<<endl;
    cout<<"c1"<<setw(22)<<"c2"<<setw(26)<<"cn"<<endl;
    cout<<"a1"<<setw(22)<<"a2"<<setw(26)<<"an"<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"am1"<<setw(22)<<"am2"<<setw(26)<<"amn"<<endl;
}



void PROBLEM::Volcar_problema()
{
    int numero=1;
    cout<<"Z = ";
    cout<<clase;
    for(int i=0; i<n; i++){								//MIRAR BUCLE
        cout<<setw(3)<<c[i]<<"x"<<numero;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<setw(3)<<A[i-1][j-1]<<"x"<<i;
        }
        cout<<setw(2)<<"<="<<setw(3)<<b[i]<<endl;
    }
}



void PROBLEM::volcar_tabla()
{
    cout<<setw(5)<<endl;
    for(int i=1; i<=n; i++){
        cout<<"x"<<i<<setw(7);
    }
	for(int i=1; i<=nh; i++){
	   cout<<"h"<<i<<setw(7);
	}
	cout<<setw(6)<<"b"<<endl;
	cout<<"-------------------------------------------"<<endl;
	for(int i=1; i<=nh; i++){
		cout<<"h"<<i<<"|"<<setw(7);
	   	for(int j=1; j<=(n+nh); j++){
        	cout<<A[i-1][j-1];
	   	}
	   	cout<<setw(7)<<b[i]<<endl;
	}
}



void PROBLEM::mostrar_solucion()    //muestra el vector b y las variables basicas(ivb) con el vector b1
{
	cout<<setw(40)<<"SOLUCION"<<endl;
	for(int i=0; i<nh; i++){
		cout<<ivb[i]<<setw(2)<<"="<<setw(2)<<b[i]<<setw(4);
	}
	cout<<endl<<setw(42)<<"FIN"<<endl;
}

unsigned PROBLEM::entrante()
{
	int pos=UERROR;
	double compare=INFR;
	if(strcmp(clase,"min")==0){
		for(int i=0; i<(n+nh); i++){
			if(c[i]<CERONEG && c[i]<compare){
				pos=i;
				compare=c[i];
			}
		}
	}else{
		compare= -INFR;
		for(int i=0; i<(n+nh); i++){
			if(c[i]>CERONEG && c[i]>compare){
				pos=i;
				compare=c[i];
			}
		}
	}
	return(pos);
}



unsigned PROBLEM::saliente(unsigned s)
{
	int pos=UERROR;
	double compare=INFR;
	if(strcmp(clase,"min")==0){
		for(int i=0; i<m; i++){
			if(A[i][s] >CEROPOS && (b[i]/A[i][s])<compare){
				pos=i;
				compare=(b[i]/A[i][s]);
			}
		}
	}else{					//cout max.
		compare=INFR;
		for(int i=0; i<m; i++){
			if(A[i][s] >CEROPOS && (b[i]/A[i][s])<compare){
				pos=i;
				compare=(b[i]/A[i][s]);
			}
		}
	}
	return(pos);
}



// OJO!! Trozos en psuedo-c�digo que hay que escribir
void PROBLEM::actualizar_valores(unsigned s, unsigned r)			//acabar de escribir el pseudo-codigo del guion. 1ºcosa declarar variables que aqui no estan.
{
	ivb[r] = s;
	double temp = A[r][s];

// actualizar fila A[r]

    for(int i=0; i<(n+nh); i++){
        A[r][i]/=temp;
    }
    b[r]/=temp;
    for(int i=0; i<m; i++){
        if((i!=r)&&(A[i][s] !=0)){          //para toda la fila i, con i!=r, A[i][s] !=0, hacemos lo siguiente
            temp=A[i][s];
            for(int j=0; j<n+nh; j++){
                A[i][j]-= A[r][j]*temp;
            }
            b[i]-=b[r]*temp;
        }
    }
    Vo-=b[r]*c[s]; //Actualizamos Vo
    
    for(int i=0; i<n+nh; i++){
        if(i!=s)
        	c[i] -= c[s]*A[r][i]; // para todo i != s
    }
	c[s]= 0;
}

void PROBLEM::Simplex_Light()								/////////////////Completo ahora.
{
	char c;
	unsigned s,r,i;
	while ((s = entrante())!= UERROR) {
		volcar_tabla();
		r = saliente(s);
		if (r == UERROR) {
			cout<<"PROBLEMA NO ACOTADO"<<endl;
		}
		else 
			actualizar_valores(s,r);
	}
	volcar_tabla();
	mostrar_solucion();
}