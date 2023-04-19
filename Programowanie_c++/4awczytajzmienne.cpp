//poprosi użytkownika i wypisze sume i iloczyn
//wynik bedzie int po intach. jesli dzielna bedzie double i iloraz double, to wyjdzie double
#include<iostream>
using namespace std;

int main(){
	int a;
	int b;	
	cin >> a;
	cin>>b;
	int suma = a + b;
	int iloczyn = a * b;
	double iloraz = a/b;
	int resztazdzielenia = a%b;
	cout << "suma: "<< suma;
	cout << "iloczyn: " <<iloczyn;
	cout << "iloraz: " <<iloraz;
	cout << "resztazdzielenia: "<<resztazdzielenia;
	return 0;
}
