#include<iostream>
void mover(int* v, int a, int b)
{
    int c, d;
    for(int i=0;i<5;i++)
    {
        if(i==a)
            c=v[i];
        if(i==b)
            d=v[i];
    }
    for(int i=0;i<5;i++)
    {
        if(i==a)
            v[i]=d;
        if(i==b)
            v[i]=c;
    }
}

int main(void)
{
    int a, b;
    int v[5]={1, 2, 3, 4, 5};
    std::cout<<"posicion 1"<<std::endl;
    std::cin>>a;
    std::cout<<"posicion 2"<<std::endl;
    std::cin>>b;
    mover(v, a, b);
    for(int i=0; i<5; i++)
    {
        std::cout<<v[i]<<","<<" "<<std::endl;
    }
    return (0);
}