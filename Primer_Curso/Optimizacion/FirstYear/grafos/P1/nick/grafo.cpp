#include "grafo.h"

using namespace std;



GRAFO::GRAFO(string nombrefichero, int &errorapertura)
{
    ifstream fe(nombrefichero.c_str());
    if(!fe.is_open())
        errorapertura=1;
    else
        errorapertura=0;
    fe>>n;
    LS.resize(n);
    LP.resize(n);
    fe>>m;
    fe>>dirigido;
    for(int i=0; i<m;i++)
    {
        ElementoLista dummy;
        int aux;
        fe>>aux;
        fe>>dummy.j;
        --dummy.j;
        LS[aux-1].push_back(dummy);
    }

}

void GRAFO::actualizar(string nombrefichero, int &errorapertura)
{
    n=0;
    m=0;
    dirigido=0;
    LP.clear();
    LS.clear();
    ifstream fe(nombrefichero.c_str());
    if(!fe.is_open())
        errorapertura=1;
    else
        errorapertura=0;
    fe>>n;
    LS.resize(n);
    LP.resize(n);
    fe>>m;
    fe>>dirigido;
    for(int i=0; i<m;i++)
    {
        ElementoLista dummy;
        int aux;
        fe>>aux;
        fe>>dummy.j;
        --dummy.j;
        LS[aux-1].push_back(dummy);

    }
    if(!dirigido)
    {
        LP=LS;
    }
}

void GRAFO::Info_Grafo()
{
    cout<<endl<<"Grafo";
    if(dirigido==1)
        cout<<" dirigido";
    else
        cout<<" no dirigido";
    cout<<" de "<<n<<" nodos y "<<m<<" arcos"<<endl;
}

void GRAFO::Mostrar_Listas(int l)
{
    if(dirigido=1)
    {
        if(l==0)
        {
            for(int j=0;j<n;j++)
            {
                cout<<endl<<"Los sucesores de "<<j+1<<"son:";
                for(int i=0; i<LS[j].size();i++)
                    cout<<" "<<LS[j][i].j+1;
            }
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                cout<<endl<<"Los predecesores de "<<j+1<<"son:";
                for(int i=0; i<LP[j].size();i++)
                    cout<<" "<<LP[j][i].j+1;
            }
        }
    }else{
        for(int j=0;j<n;j++)
        {
            cout<<endl<<"Los adyacentes a "<<j<<" son:";
            for(int i=0; i<LS[j].size();i++)
                cout<<" "<<LS[j][i].j;
        }
    }
    cout<<endl;
}

void GRAFO::ListaPredecesores()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<LS[i].size(); j++)
        {
            ElementoLista dummy;
            dummy.j=i;
            LP[LS[i][j].j].push_back(dummy);
        }
}

GRAFO::~GRAFO()
{
    n=0;
    m=0;
    dirigido=0;
    LP.clear();
    LS.clear();
}
