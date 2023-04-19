#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;


double pierwbis(double (*func)(double), double x1, double x2, double xacc){
  if((*func)(x1)*(*func)(x2)>0){
    cout << "przedział nie zapewnia pierwiastka" << endl;
    return 0;
  }
  else{
    double xp=(x1+x2)/2;

    if((*func)(xp)<xacc and (*func)(xp)>-1*xacc){
      return xp;
    }

    else{
      if((*func)(xp)*(*func)(x2)<0){
        return  pierwbis(func, xp ,x2, xacc);
      }
      else{
        return  pierwbis(func, x1 ,xp, xacc);
      }

    }



  }

}

double f(double x){
  return tan(x)-x;
}

/*
//funkcja na dowolny typ, szablon
template<typename T>
T funkcja(T x){
  return x*x;
}
//wywołujemy w innej funkcji funkcja<T>(argument)

*/


int main (){
double x1, x2, x0;
double xacc =1e-8;
cout << xacc << endl;
for(int i =0; i<11; i++){
  x1=M_PI*i/3;
  x2=M_PI*i/3+M_PI/6;
  x0=pierwbis(f, x1,  x2, xacc);
  cout << i << "  " << x0 << "  " << f(x0) << endl;
}
  return 0;
}
