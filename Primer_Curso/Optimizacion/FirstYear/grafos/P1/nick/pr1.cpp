#include "grafo.h"

using namespace std;

int main()
{
    string aux;
    int opcion, fallo;

    cout<<"Introduzca el nombre del fichero"<<endl;
    cin>>aux;
    GRAFO gustavo(aux, fallo);
    if(!fallo)
    {
        while(opcion!=9)
        {
            cout<<"FICHERO CARGADO CORRECTAMENTE!"<<endl;
            cout<<"1. Cargar otro grafo"<<endl;
            cout<<"2. Mostrar informacion basica"<<endl;
            if(gustavo.Es_dirigido())
            {
                cout<<"3. Ver lista de sucesores"<<endl;
                cout<<"4. Ver lista de predecesores"<<endl;
            }
            else
            {
                cout<<"3. Mostar adyacencia"<<endl;
            }
            cout<<"9. Finalizar ejecucion"<<endl;
            cout<<" Introd. operación: "<<endl;
            cin>>opcion;
            switch(opcion)
            {
                case 1:
                    cout<<"Introd. nombre del fichero"<<endl;
                    cin>>aux;
                    gustavo.actualizar(aux,fallo);
                    break;
                case 2:
                    gustavo.Info_Grafo();
                    break;
                case 3:
                    gustavo.Mostrar_Listas(0);
                    break;
                case 4:
                    gustavo.ListaPredecesores();
                    gustavo.Mostrar_Listas(666);
                    break;
                case 9:
                    cout<<"hasta pronto ^^"<<endl;
                    break;
                default:
                    cout<<"No has elegido una operacion disponible."<<endl;
            }
        }
    }
    else
    {
        cout<<"Error cargando fichero, intentelo de nuevo"<<endl;
    }
}
