//metody klasy solver
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"dnsolver.h"
#include"dnparameters.h"
#include"dnequation.h"
using namespace std;

class Parameters;
class Equation;


//konstruktor 
Solver::Solver(Equation eq, Parameters pa){
  rownanko = eq;
  parametry = pa;
}

//metoda rozwiązująca równanie
vector <vector<double>> Solver::solve(){
    vector <vector <double>> rozwiazania;
    double n = rownanko.dlugosc();
    vector <double> uxt;
  
    int t =0;

  //pierwszy wiersz rozwiązań:
  for(int i = 0; i<n; i++){
    uxt.push_back(rownanko.getv()[i][0]);
  }

  rozwiazania.push_back(uxt);

    //krok czasowy:
  double dt;
  dt= (parametry.delta_x*parametry.delta_x)/(2*rownanko.max_alpha());
  //
  int j=1;
  while(true){
      vector <double> rozw_dla_ti;
      rozw_dla_ti.push_back(rozwiazania[j-1][0]);
          for(int i=1; i<n-1; i++){
            double u1 = rozwiazania[j-1][i]+dt*rownanko.getv()[i][2];
            double u2 = dt*rownanko.getv()[i][1]*(rozwiazania[j-1][i+1]-2*rozwiazania[j-1][i]+rozwiazania[j-1][i-1])/(parametry.getdelta_x()*parametry.getdelta_x());
            rozw_dla_ti.push_back(u1+u2);
          }
      rozw_dla_ti.push_back(rozwiazania[j-1][n-1]);
      rozwiazania.push_back(rozw_dla_ti);


      double sumka =0;
      for(int i =0; i<n; i++){
        sumka=sumka+(rozwiazania[j][i]-rozwiazania[j-1][i])*(rozwiazania[j][i]-rozwiazania[j-1][i]);
      }
      if(sumka<=parametry.getepsilon()){break;}
      j++;
  }

    return rozwiazania;
}


//metoda zapisująca rozwiązanie do pliku
void Solver::saveSolution(string plikdladanych){
    vector <vector <double>> rozwiazania = solve();

  ofstream plik2;
  plik2.open(plikdladanych.c_str());
  if(plik2.good()){
      for(int i =0; i<rozwiazania.size(); i++){
        if(i%(int)parametry.M==0){
        for(int j=0; j<(rozwiazania.at(i)).size();j++){
          plik2 << rozwiazania[i][j]<< "  ";
        }
        plik2 << endl;
      }
    }
      plik2.close();
    }

  else{
    plikdladanych = "solution.dat";
    plik2.open(plikdladanych);
  }
  for(int i =0; i<rozwiazania.size(); i++){
    for(int j=0; j<(rozwiazania.at(i)).size();j++){
      plik2 << rozwiazania[i][j]<< "  ";
    }
    plik2 << endl;
  }
  plik2.close();
}
