#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int tab[5] = {2, 4, 6, 8, 10};
    int *wsk_tab = tab;

    //wypisanie elementow tablicy - wersja 1:
    cout << "Notacja tablicowa: " << endl;
    cout << endl;

    for(int i=0; i<5; i++){
        cout <<"tab["<<i<<"]="<< tab[i] <<", adres w pamieci: " << &tab[i] << endl;
    }
    cout << endl;

    //wypisanie elementow tablicy - wersja ze wskaznikami
    cout << "Notacja wskaźnikowa: " << endl;
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout <<"*wsk_tab=" << *wsk_tab <<", adres w pamieci: " << wsk_tab << endl;
        wsk_tab++;
    }
    cout << endl;

    //pomnozenie przez 2 kazdego z elementow tablicy i wypisanie nowej wartosci oraz adresu - wersja 1
    cout << "Przemnozenie wszystkich elementow tablicy przez 2: " << endl;
    cout << endl;

    for(int i=0; i<5; i++){
        tab[i] = 2*tab[i];
        cout <<"tab["<<i<<"]="<< tab[i] <<", adres w pamieci: " << &tab[i] << endl;
    }
    cout << endl;

    //DO UZUPELNIENIA

    //sprawdz, na co wskazuje teraz wskaznik wsk_tab - wypisz jego wartosc
	cout << "wskaźnik teraz wskazuje na liczbę: " << *wsk_tab << endl;
    //przesun wskaznik wsk_tab na poczatek tablicy tab
	wsk_tab = tab;
    //sprawdz, na co wskazuje teraz wskaznik wsk_tab - wypisz jego wartosc i sprawdz czy jest poprawna
	cout << "wskaźnik teraz wskazuje na liczbę: " << *wsk_tab<< endl;
    //kolejne pomnozenie przez 2 kazdego z elementow tablicy i wypisanie nowej wartosci oraz adresu - wersja ze wskaznikiem
    cout << "Kolejne przemnozenie wszystkich elementow tablicy przez 2: " <<endl;
    cout << endl;
    
     for(int i=0; i<5; i++){
        *wsk_tab = *wsk_tab*2;
	
        cout <<"tab["<<i<<"]="<< *wsk_tab <<", adres w pamieci: " << wsk_tab << endl;
	wsk_tab = wsk_tab + 1;
    	}
    cout << endl;

}

