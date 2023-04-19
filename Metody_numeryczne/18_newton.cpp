#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;


double pochodna(double (*func)(double), double x,double h){
  return ((*func)(x+h)-(*func)(x-h))/(2*h);

}

template<typename T>
double pierwnet(T (*func)(double), T x0, T x1, T h, T xacc){
  if((*func)(x0)*(*func)(x1)>0){
    cout << "przedział nie zapewnia pierwiastka" << endl;
    return 0;
  }
  else{
    if((*func)(x0)<xacc and (*func)(x0)>-xacc){
      cout << " jestem " << (*func)(x0) << endl;
      return x0;
    }
    else{
      double xn=x0;
      int n=0;
      while((*func)(xn)>=xacc or (*func)(xn)<=-xacc){
        xn=xn-(*func)(xn)/pochodna((*func),xn,h);

        n++;

      }
      return xn;
    }

    }
  }
//ABS -moduł
double f(double x){
  return log(3*x)-x;
}

int main(){

  double a=0.001;
  double b=1;
  double h=1e-5;
  double xacc=1e-10;

  double y = pierwnet<double>(f,a,b,h,xacc);
  cout << "punkt: " <<  y << ",  faktyczna wartość: "<< f(y)<< endl;

  return 0;

}
