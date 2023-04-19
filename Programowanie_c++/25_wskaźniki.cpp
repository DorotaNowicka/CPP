#include<iostream>
using namespace std;

int main(){
	//deklaracja zmiennej liczba i przypisanie jej wartosci 144
		int liczba = 144; //i ta wartość siedzi w komórce, która ma adres szesnastkowy
	
	//deklaracja wskaznika w sluzacego do pokazywania na zmienna typu int
		int *wsk; //wsk wskazuje na zmienną typu int 
	
	//ustawienie wskaznika na zmienna liczba
		wsk = &liczba; //& - on uzyskuje adres w pamięci tej zmiennej 
	
	//wypisanie adresu w pamieci zmiennej liczba
		cout << "adres liczby   " << &liczba << endl;

	//wypisanie wskaznika
		cout << "wskaźnik       " << wsk << endl;

	//wypisanie wartosci zmiennej na ktora pokazuje wskaznik
		cout << "liczba pod wsk " << *wsk << endl;
}

