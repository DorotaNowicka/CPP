#include <iostream>
using namespace std;

int main(){

	//deklaracja zmiennej n1 typu int i przypisanie jej wartosci 233:
	int n1 = 233;
	//wypisanie wartosci n1
	cout << "zmienna n1 =    "<<n1 << endl;
	//deklaracja zmiennej n2 typu int i przypisanie jej wartosci n1:
	int n2 = n1;
	//wypisanie adresu zmiennej n1 w pamieci
	cout << "adres zmiennej n1: " << &n1 << endl;
	//wypisanie adresu zmiennej n1 w pamieci
	cout << "adres zmiennej n2: " << &n2 << endl;
	//deklaracja wskaznika ptr do zmiennej typu int
	int *ptr;
	//ustawienie wskaznika ptr na zmienna n1
	ptr = &n1;
	//wypisanie wartosci wskaznika ptr
	cout << "wartość wskaźnika: " << ptr << endl;
	//wypisanie wartosci zmiennej na ktora pokazuje ptr
	cout << "wartość pod prt:   " <<*ptr << endl;
	//zmiana wartosci zmiennej o adresie w pamieci przechowywanym przez ptr na 235
	*ptr=235;
	//wypisanie wartosci zmiennej na ktora pokazuje ptr
	cout << "wartość pod prt nr2" <<*ptr << endl;
	//wypisanie wartosci zmiennej n1
	cout << "zmienna n1 =       "<< n1 << endl;
	//wypisanie wartosci n2
	cout << "zmienna n2 =       "<< n2 << endl;
	//dodanie 1 do wartosci zmiennej o adresie przechowywanym przez ptr
	*ptr=*ptr + 1;
	//wypisanie wartosci zmiennej na ktora pokazuje ptr
	cout << "wartość pod prt:   " <<*ptr << endl;
	//przestawienie wskaznika ptr na zmienna n2
	ptr = &n2;
	//wypisanie wartosci zmiennej na ktora pokazuje ptr
	cout << "wartość pod prt:   " <<*ptr << endl;

}

