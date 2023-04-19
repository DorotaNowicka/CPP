//deklaracja klasy parametrs
#ifndef __dnparameters__
#define __dnparameters__
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

class Solver;

class Parameters{
  double delta_x;
  double M;
  double epsilon;
public:
  Parameters();
  Parameters(double a, double b, double c);
  Parameters(string plik_do_wczytania);
  double getdelta_x();
  double getM();
  double getepsilon();
  ~Parameters(){}
  friend class Solver;
};

#endif
/////
