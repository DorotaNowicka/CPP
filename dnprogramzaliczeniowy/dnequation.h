//deklaracja klasy equation

#ifndef __dnequation__
#define __dnequation__
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

class Solver;


class Equation{
    vector <vector <double>> v;
public:
 Equation();
 Equation(string plik_z_f);
 double dlugosc();
 vector <vector <double>> getv();
 double max_alpha();
 void print();
 ~Equation(){}
 friend class Solver;
};

#endif
