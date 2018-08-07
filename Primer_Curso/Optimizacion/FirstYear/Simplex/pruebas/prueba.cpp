void PROBLEM::volcar_tabla()
{
    int contar=1;
    cout<<setw(5)<<endl;
    for(int i=0; i<(n); i++){
        cout<<"x"<<contar<<setw(7);
        ++contar;
    }
    contar=1;
	for(int i=0; i<nh; i++){
	   cout<<"h"<<contar<<setw(7);
        ++contar;
	}
	cout<<setw(6)<<b<<endl;
	cout<<"-------------------------------------------"<<endl;
    contar=1;
	for(int i=0; i<nh; i++){
	   	for(int j=0; j<(n+nh); j++){
        	cout<<"h"<<contar<<"|"<<setw(7)<<A[i][j]<<setw(7)<<b[i]<<endl;
	   	}
	}
}