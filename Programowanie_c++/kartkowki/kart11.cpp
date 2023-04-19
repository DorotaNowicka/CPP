
#include<fstream>
#include<iostream>
using namespace std;

int main(){

    int liczba1 = 12;
    double liczba2 = 199.5;
    //deklaracja zmiennej mojPlik
    ofstream mojPlik;
    mojPlik.open("liczby.txt");
    if(mojPlik.good()){
        //wpisanie do pliku zmiennych liczba1 i w nowej linijce liczba2
        mojPlik << liczba1;
	mojPlik << '\n';
	mojPlik << liczba2;
        mojPlik.close();
    }
    else{
        cout << "Nie udalo sie utworzyc pliku" << '\n';
    }
}

