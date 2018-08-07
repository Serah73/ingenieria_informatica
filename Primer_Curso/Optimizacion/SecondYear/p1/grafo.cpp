#include "grafo.h"

using namespace std;

GRAFO::GRAFO(char nombrefichero[], int &errorapertura)			//constructor
{
	ifstream textfile;
	unsigned i,j,k;
	ElementoLista dummy;
	
	textfile.open(nombrefichero);

	if (textfile.is_open()){
	    
		//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){
			    
				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				
				dummy.j =--j;
				LS[--i].push_back(dummy);
				
                if ( (dirigido == 0) && (i!=j) ){
                    
				    dummy.j=i;                  //
				    LS[j].push_back(dummy);     // Añado i a LS[j]
			    }
			   
			}
			
			textfile.close();
			errorapertura=0;
			
			if(dirigido == 1){
			    ListaPredecesores();
			}
	}
	else {
	    errorapertura = 1;
	}
}

GRAFO::~GRAFO()			//destructor
{
	LS.clear();
	LP.clear();
}


void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{		    
		LS.clear();
		LP.clear();
	   /* 
	    ifstream textfile;
	    unsigned i,j,k;
    	ElementoLista dummy;
	
	    textfile.open(nombrefichero);
	    
	    if (textfile.is_open()){
	        
	        textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){
			    
				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				
				dummy.j =--j;
				LS[--i].push_back(dummy);
			}
			
                if ( (dirigido == 0) && (i!=j) ){
                    
				    dummy.j=i;
				    LS[j].push_back(dummy);
			    }
			    textfile.close();
			   
	    }
	    else{
	        errorapertura=1;
	    }*/
	    	ifstream textfile;
	unsigned i,j,k;
	ElementoLista dummy;
	
	textfile.open(nombrefichero);

	if (textfile.is_open()){
	    
		//errorapertura = 0;

			textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;

			LS.resize(n);

			for (k = 0; k < m; k++){
			    
				textfile >> (unsigned &)i;
				textfile >> (unsigned &)j;
				
				dummy.j =--j;
				LS[--i].push_back(dummy);
				
                if ( (dirigido == 0) && (i!=j) ){
                    
				    dummy.j=i;                  //
				    LS[j].push_back(dummy);     // Añado i a LS[j]
			    }
			   
			}
			
			textfile.close();
			errorapertura=0;
			
			if(dirigido == 1){
			    ListaPredecesores();
			}
	}
	else {
	    errorapertura = 1;
	}
}


unsigned GRAFO::Es_dirigido()
{
	return dirigido;
}


void GRAFO::Info_Grafo()
{
	cout << endl << "Información del grafo" << endl;
	cout << "numero de arcos: " << m << ";" << endl;
	cout << "numero de nodos: " << n << ";" << endl;
	cout << "El grafo es: ";
	
	if(dirigido == 0)    // 0 no lo es
		cout << "NO DIRIGIDO." << endl;
	else
		cout << "DIRIGIDO." << endl;
}


void GRAFO::Mostrar_Listas(int l)
{
	if(l == 0)																	//0 no lo es
	{
		cout << "Lista de Adyacencia" << endl << endl;
		
		for(int i = 0; i < n; i++)
		{
			cout << "Adyacente/s del nodo" << " ( " << i+1 << " ): ";
			
			for(int aux = 0; aux < LS[i].size(); aux++)
			{
				cout << LS[i][aux].j + 1;
			/*	
				if(aux == (LS[i].size()-2))
					cout << ".";
				else*/
					cout << "; ";
			}
			cout << endl;
		}
	}
	else if(l == 1)
	{
		cout << "Lista de Sucesores" << endl << endl;
		
		for(int i = 0; i < n; i++)
		{
			cout << "Sucesores del nodo" << " ( " << i+1 << " ): ";

				
			for(int aux = 0; aux < LS[i].size(); aux++)
			{
				cout << LS[i][aux].j + 1;
			/*	
				if(aux == (LS[i].size()-2))
					cout << ".";
				else*/
					cout << "; ";
			}
			cout << endl;
		}
	}else if(l == 2)
	{
		cout << "Lista de Predecesores" << endl << endl;
	
		for(int i = 0; i < n; i++)
		{
    	    cout << "Predecesores del nodo" << " ( " << i+1 << " ): ";
 
    	    for(int aux = 0; aux < LP[i].size(); aux++)
			{
				cout << LP[i][aux].j + 1;
			/*	
				if(aux == (LP[i].size()-2))
					cout << ".";
				else*/
					cout << "; ";
			}
			cout << endl;
		}
	}
	cout << endl << endl;
}


void GRAFO::ListaPredecesores()
{
	    LP.resize(n);															
		ElementoLista dummy;

		if (dirigido == 1){
			
			for (int i = 0; i < n; ++i){
				
				for (int k = 0; k < LS[i].size(); ++k){
					dummy.j=i;
					LP[LS[i][k].j].push_back(dummy);
				}
			}
		}
}


void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
	visitado[i] = true;
	cout << i+1 << ", ";
	
	for (unsigned j=0;j<LS[i].size();j++)
		
		if (visitado[LS[i][j].j] == false)
			dfs(LS[i][j].j, visitado);
}
