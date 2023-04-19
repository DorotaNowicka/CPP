#include<iostream>
#include<cmath>
using namespace std;

int main(){

    //prosimy o podanie rozmiaru:
    int N;
    cin >> N;
    //tworzymy tablice dlugosci N na liczby typu double
    double *tab = new double[N];
    //wypelniamy w petli wartosciami sin(i)
    for(int i=0; i<N; i++){
        tab[i]=sin(i);
    }
    //wypisujemy elementy
    for(int i=0; i<N; i++){
        cout << "tab[" << i << "]=" << tab[i] <<endl;
    }
    //zwalniamy pamiec
    delete [] tab;
}

