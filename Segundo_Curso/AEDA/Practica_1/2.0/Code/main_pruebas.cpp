#include <iostream>
#include "vector.hpp"
//#include "lista.hpp"
#include "queue.hpp"
//#include "cola.hpp"
using namespace std;



void menu(){
    cout << "Elija la estructura para trabajar:"<< endl;
    cout << "1.Vector" << endl;
    cout << "2.Lista" << endl;
    cout << "3.Pila" << endl;
    cout << "4.Cola" << endl;
    cout << "5.Salir" << endl;
}

void vmenu(vector vect){
    cout << "Elija una opción:" << endl;
    cout << " >> 1.Mostrar vector" << endl;
    cout << " >> 2.Insertar" << endl;
    cout << " >> 3.Extraer" << endl;
    cout << " >> 4.Mostrar estado" << endl;
    cout << " >> 5.Regresar al menú" << endl;
}

void lmenu(list lista){
    cout << "Elija una opción:" << endl;
    cout << " >> 1.Insertar dato por el final" << endl;
    cout << " >> 2.Insertar dato por el principio" << endl;
    if(!lista.empty()){
        cout << " >> 3.Mostrar principio" << endl;
        cout << " >> 4. Mostrar final" << endl;
        cout << " >> 5.Mostrar lista" << endl;
    }
    cout << " >> 6.Mostrar estado" << endl;
    cout << " >> 7.Regresar al menú" << endl;
}

void pmenu(stack pila){
    cout << "Elija una opción:" << endl;
    cout << " >> 1.Push" << endl;
    if(!pila.empty()){
        cout << " >> 2.Pop" << endl;
        cout << " >> 3.Mostrar pila" << endl;
    }
    cout << " >> 4.Mostrar estado" << endl;
    cout << " >> 5.Regresar al menú" << endl;
}

void cmenu(queue cola){
    cout << "Elija una opción:" << endl;
    cout << " >> 1.Push" << endl;
    if(!cola.empty()){
        cout << " >> 2.Pop" << endl;
        cout << " >> 3.Mostrar cola" << endl;
    }
    cout << " >> 4.Mostrar estado" << endl;
    cout << " >> 5.Regresar al menú" << endl;
}

int main(){
    int tamvec;
    cout << "Introduzca el tamaño del vector: ";
    cin >> tamvec;
    vector estructura1(tamvec);
    list estructura2; 
    stack estructura3;
    queue estructura4;
    int opcion_general = 0;
    do{
        menu();
        cin >> opcion_general;
        switch(opcion_general){
            case 1:
                int opcion_vector;
                do{
                    vmenu(estructura1);
                    cin >> opcion_vector;
                    switch(opcion_vector){
                        int n;
                        case 1:
                            estructura1.print();
                        break;
                        case 2:
                            cout << " -Introduzca la posición del dato a insertar: ";
                            cin >> n;
                            if(estructura1.insertable(n)){
                                cout << " -Introduzca el dato a insertar: ";
                                TDato x;
                                estructura1.set_data(x,n);
                            }else{
                                cout << "ERROR: Posición no accesible " << endl;
                            }
                        break;
                        case 3:
                            cout << " -Introduzca la posición del dato: ";
                            cin >> n;
                            if(estructura1.insertable(n))
                            cout << estructura1.get_data(n) << endl;
                        break;
                        case 4:
                            cout << " No vacío " << endl;
                        break;
                        case 5:
                        break;
                        default:
                            cout << "Opción no reconocida, vuelva a intentarlo" << endl;
                    }
                }while(opcion_vector != 5);
            break;
            case 2:
                int opcion_lista;
                do{
                    lmenu(estructura2);
                    cin >> opcion_lista;
                    switch(opcion_lista){
                        TDato n;
                        case 1:
                            cout << " -Introduzca el dato: ";
                            cin >> n;
                            estructura2.insert_end(n);
                        break;
                        case 2:
                            cout << " -Introduzca el dato: ";
                            cin >> n;
                            estructura2.insert_begin(n);
                        break;
                        case 3:
                            estructura2.get(0);
                            cout << endl;
                        break;
                        case 4:
                            estructura2.get(estructura2.get_nnode() - 1);
                            cout << endl;
                        break;
                        case 5:
                            estructura2.print();
                        break;
                        case 6:
                            if(estructura2.empty())
                            cout << " Vacía " << endl;
                            else 
                            cout << " No vacía " << endl;
                        break;
                        case 7:
                        break;
                        default:
                            cout << "Opción no reconocida, vuelva a intentarlo" << endl;
                    }
                }while(opcion_lista != 5);
            break;
            case 3: 
                int opcion_pila;
                do{
                    pmenu(estructura3);
                    cin >> opcion_pila;
                    switch(opcion_pila){
                        TDato ains;
                        case 1:
                            cout << "Introduzca el dato:";
                            cin >> ains;
                            estructura3.push(ains);
                        break;
                        case 2:
                            cout << estructura3.pop() << endl;
                        break;
                        case 3:
                            estructura3.print();
                        break;
                        case 4:
                            if(estructura3.empty())
                            cout << " Vacía" << endl;
                            else 
                            cout << " No vacía" << endl;
                        break;
                        case 5:
                        break;
                        default:
                            cout << "Opción no reconocida, vuelva a intentarlo" << endl;
                    }
                }while(opcion_pila != 5);
            break;
            case 4:
                int opcion_cola;
                do{
                    cmenu(estructura4);
                    cin >> opcion_cola;
                    switch(opcion_cola){
                        TDato ains;
                        case 1:
                            cout << "Introduzca el dato:";
                            cin >> ains;
                            estructura4.push(ains);
                        break;
                        case 2:
                            cout << estructura4.pop() << endl;
                        break;
                        case 3:
                            estructura4.print();
                        break;
                        case 4:
                            if(estructura4.empty())
                            cout << " Vacía" << endl;
                            else 
                            cout << " No vacía" << endl;
                        break;
                        case 5:
                        break;
                        default:
                            cout << "Opción no reconocida, vuelva a intentarlo" << endl;
                    }
                }while(opcion_cola != 5);
            break;
            case 5:
            break;
            default:
                cout << "Opción no reconocida, vuelva a intentarlo" << endl;
        }
    }while(opcion_general != 5);
}