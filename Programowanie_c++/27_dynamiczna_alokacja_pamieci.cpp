#include<iostream>
using namespace std;

int suma_elementów_tablicy(int tab[N], int N){
	int suma=0;
	for(i=0;i<N,i++){
		suma=suma + tab[i];
	}
return suma;		

int N;
cout << "podaj dodatnie N:" << endl;
cin >> N;
double *tab = new double[N]
 //wypelniamy w petli wartosciami sin(i)
    for(int i=0; i<N; i++){
        tab[i]=sin(i);
    }
    //wypisujemy elementy
    for(int i=0; i<N; i++){
        cout << "tab[" << i << "]=" << tab[i] <<endl;
	}
cout << "wartość funkcji" << suma_elementów_tablicy(tab, N) << endl;
delete[]tab;
}

   
