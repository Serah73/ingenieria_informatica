#include <iostream>
using namespace std;

int main(void)
{
    const int m =4; //filas de la matriz
    const int n =5; //col de la matriz
	
    int matriz [m][n] = {{1,2,3,4,5},
                         {2,3,4,5,6},
                         {3,4,5,6,7},
                         {4,5,6,7,8}};

	int col;  //columna a mostrar
  	cout<<"Introduzca la columna:";
    cin>>col;
    bool ordenada=true;
    int i=0;
    while((i<m-1) && ordenada)
	{
        if(matriz[i][col]<=matriz[i+1][col])
            i++;
        else {
            cout << "desordenada" << endl;
            ordenada=false;
        }
	}
    if (ordenada)
            cout << "ordenada" << endl;
}