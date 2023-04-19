
#include<iostream>
using namespace std;

double volume(double x, double y, double z){
  return x*y*z;
}

int main() {
  double a = 1.5, b = 3.5, c = 2.5;

  cout << "Objetosc prostopadloscianu o bokach " << a << ", " << b << ", " << c << " wynosi " << volume(a,b,c) << endl;

  return 0;
}

