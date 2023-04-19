//deklaracja klasy solver
#ifndef __dnsolver__
#define __dnsolver__
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"dnparameters.h"
#include"dnequation.h"
using namespace std;

class Parameters;
class Equation;


class Solver{
Equation rownanko;
Parameters parametry;

public:
  Solver(Equation eq, Parameters pa);
  vector <vector <double>> solve();
  void saveSolution(string plikdladanych);
  ~Solver(){};
};

#endif
