//metody klasy parameters
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"dnparameters.h"
using namespace std;

class Solver;

//konstruktor domyślny
Parameters::Parameters(){
  delta_x = 0.1;
  M = 20;
  epsilon = 0.001;
}

//konstruktor - wartości z klawiatury
Parameters::Parameters(double a, double b, double c){
  delta_x = a;
  M = b;
  epsilon = c;
}

//konstruktor - wartości z pliku
Parameters::Parameters(string plik_do_wczytania){
  fstream plik;
  plik.open(plik_do_wczytania);
  if(plik.good()){
    plik>> delta_x;
    plik >> M;
    plik >> epsilon;
    plik.close();
  }
  else{
    cout << "wystąpił problem z plikiem " << plik_do_wczytania << " . Wczytuję wartości domyślne."<<endl;
    delta_x = 0.1;
    M = 20;
    epsilon = 0.001;
  }
}

//dostęp do cech
double Parameters::getdelta_x(){return delta_x;}

double Parameters::getM(){return M;}

double Parameters::getepsilon(){return epsilon;}
