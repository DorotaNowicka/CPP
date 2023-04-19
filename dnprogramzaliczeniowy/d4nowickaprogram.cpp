//g++ -std=c++11 dnparameters.cpp dnquation.cpp dnsolver.cpp d4nowickaprogram.cpp -o dnowickaprogram
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"dnparameters.h"
#include"dnequation.h"
#include"dnsolver.h"
using namespace std;

int main(){
  //wywołanie klasy parameters, do podania odpowiedniej decyzji
  Parameters p(1, 1, 1);
  while(true){
    cout << "Czy chcesz uruchomić program dla parametrów domyślnych? " << endl;
    cout <<  "<tak - 1/nie i użyj wartości z pliku -0/" << endl;
    cout << " nie i użyj innych wartości - 2> "<< endl;
    int decyzja1;
    cin >> decyzja1;
    if(decyzja1==1){
        Parameters tmp;
        p = tmp;
        break;
    }
    if(decyzja1==0){
      cout << "Podaj nazwę pliku z wartościami parametrów: "<< endl;
      string plik_do_wczytania;
      cin >> plik_do_wczytania;
      Parameters tmp(plik_do_wczytania);
      p=tmp;
      break;
    }
      if(decyzja1==2){
          cout << "Podaj parametry:" << endl;
          double p1,p2, p3;
          cout << "krok przestrzenny: ";
          cin >> p1;
          cout << "co ile iteracji zapisać wynik: ";
          cin >> p2;
          cout << "dokładność: ";
          cin >> p3;
        Parameters temp(p1,p2,p3);
        p=temp;
        break;
      }
        else{
          cout<<"nieprawidłowa wartość"<< endl;
        }

}
//wywołanie klasy Equation, do podania odpowiedniej decyzji
Equation rown;
while(true){
  cout << "Czy chcesz wykorzystać domyślny warunek początkowy, rozkład " << endl;
  cout << "dyfuzyjności termicznej i źródeł ciepła? <tak - 1/ nie 0> " << endl;
  int decyzja2;
  cin >> decyzja2;
  if(decyzja2==1){
   Equation tmp;
   rown=tmp;

    break;
  }
  if(decyzja2==0){
    string plik_z_f;
    cout << "Podaj nazwę pliku z którego wczytam wartości: ";
    cin >> plik_z_f;
    Equation tmp(plik_z_f);
    rown=tmp;
    break;
  }
  else{
    cout << "nieprawidłowa wartość"<< endl;
  }
}

Solver solv(rown, p);
//zapis pliku
cout << "Wpisz nazwę pliku do którego zapisać rozwiązanie: "<< endl;
string nazwaplikuzapis;
cin >> nazwaplikuzapis;

cout << "rozwiązuję:"<< endl;
solv.saveSolution(nazwaplikuzapis);

cout << "użyj w programie gnuplot polecenia: set xtics 0, " << p.getdelta_x() << ", " << (rown.dlugosc())*p.getdelta_x() << endl;

  return 0;
}
