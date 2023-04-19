#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Uczen{
vector<int> oceny;
string imie;
public:
Uczen(string I){imie=I;}
//utworzy się wektor pusty, co jest okay
void dodaj_oceny(int O){oceny.push_back(O);}
double srednia();
//zaprzyjaźmniamy z operatorem (zaprzyjaźnione funkcje mają dostęp do private)
friend ostream& operator<< (ostream& , Uczen);
};

ostream& operator<< (ostream& strumien, Uczen U){
	strumien << "Uczeń: " << U.imie << ....<< endl;
return strumien;
}

//srednia metodą auto, pętla zakresowa
double Uczen::srednia(){
double suma = 0;
for(auto ocena: oceny) //<-śmieszny napis, a działa jak powinien, auto zgaduje sobie typ 
suma += ocena;
return suma/oceny.size();
}

/*konstruktor kopiujący zespolona(const zespolona& Wzor){re=Wzor.re; im= Wzor.im;}


