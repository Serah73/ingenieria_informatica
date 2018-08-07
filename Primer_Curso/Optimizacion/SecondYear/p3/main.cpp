#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "grafo.hpp"


using namespace std;

int opcion = 0;



int main(int argc, char const *argv[]){

        int errorapertura = -1;
        char* nombrefichero;
        nombrefichero = new char[20];
        //char nombrefichero[20];

        cout << "Introduzca el nombre del fichero: " << endl;
	    cin >> nombrefichero;

        GRAFO HOLA(nombrefichero, errorapertura);

        if(errorapertura == 0){
            cout << "El fichero se ha cargado correctamente" << endl;

            bool pppp = false;

            //while(!pppp){


                    do{
                        if(HOLA.Es_dirigido() == 1){//Grafo dirigido
                        cout << "1. Carga grafo desde fichero" << endl;
                        cout << "2. Mostrar informacion básica del grafo" << endl;
                        cout << "3. Mostrar la lista de sucesores del grafo" << endl;
                        cout << "4. Mostrar la lista de predecesores del grafo" << endl;
                        cout << "5. Mostrar componentes conexas" << endl;
                        cout << "6. Dijkstra" << endl;
                        cout << "7. Bellman-End-Moore" << endl;
                        cout << "0. Finalizar programa" << endl;

                        cout << endl << "Introduzca la opción deseada: " << endl;

                        cin  >> opcion;

                        switch(opcion){

                        case 1:
                            cout << "Introduzca el nombre del fichero que desea volver a cargar" << endl;
                            cin >> nombrefichero;
                            HOLA.actualizar(nombrefichero, errorapertura);
                            break;

                        case 2:
                            HOLA.Info_Grafo();
                            break;

                        case 3:
                            HOLA.Mostrar_Listas(0);
                            break;

                        case 4:
                            HOLA.Mostrar_Listas(1);
                            break;

                        case 5:
                            HOLA.ComponentesConexas();
                            break;

                        case 6:
                            HOLA.Dijkstra();
                            break;

                        case 7:
                            HOLA.BellmanEndMoore();
                            break;

                        case 0:
                            cout << "Hasta la próxima" << endl;
                            exit (0);

                        default:
                            cout << "Opcion no valida" << endl;
                        }//Cierre del switch



                } //Cierre del IF grafo dirigido

                if(HOLA.Es_dirigido() == 0){ //Grafo no dirigido

                        cout << "1. Carga grafo desde fichero" << endl;
                        cout << "2. Mostrar informacion básica del grafo" << endl;
                        cout << "3. Mostrar la lista de adyacencia" << endl;
				        cout << "4. Mostrar componentes conexas." << endl;
                        cout << "0. Finalizar programa" << endl;

                        cout << endl << "Introduzca la opción deseada: " << endl;
                        cout << endl;

                        cin  >> opcion;

                        switch(opcion){

                        case 1:
                            cout << "Introduzca el nombre del fichero que desea volver a cargar" << endl;
                            cin >> nombrefichero;
                            HOLA.actualizar(nombrefichero, errorapertura);
                            break;

                        case 2:
                            HOLA.Info_Grafo();
                            break;

                        case 3:
                            HOLA.Mostrar_Listas(2);
                            break;

                        case 4:
                            HOLA.ComponentesConexas();
                            break;

                        case 0:
                            cout << "Hasta la próxima" << endl;
                            exit (0);

                        default:
                            cout << "Opcion no valida" << endl;
                        }//Cierre del switch

                    //}while(opcion <= 5);     //Cierre del DO WHILE de un grafo NO dirigido

                }//Cierre del IF Grafo no dirigido

                    }while(opcion <= 7);
            //}// cierre bucle WHILE

        }//Cierre error apertura

        else{
            cout << "ERROR EN LA APERTURA" << endl;
        }

    return 0;
}//Cierre del main
