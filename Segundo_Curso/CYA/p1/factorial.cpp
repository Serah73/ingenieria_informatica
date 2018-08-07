#include <iostream>

using namespace std;
int n;
int sumaNumeros (int n);
int main()

{

cout << "Digite un numero para saber su sumatoria:" <<'\n';
cin >> n;
cout << sumaNumeros (n)<<'\n';
return 0;
}

int sumaNumeros (int n)
{
if (n==0)
return (1);
else
return (n*sumaNumeros(n-1));
}


