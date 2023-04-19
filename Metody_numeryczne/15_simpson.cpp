#include <iostream>
#include <fstream>
#include<cmath>
//pozwala na ustalenie dokładności
#include <iomanip>

using namespace std;

double funkcja(double x){
  return exp(x);
}


double simpson(double (*funkcja)(double), double a, double b, int n){

double h = (b-a)/(2*n);
//cout << h << endl;

double ncaleczka=0;
double y=0;

for(int i=0; i<(2*n+1); i++){
    y=funkcja(a+i*h);
  //  cout << y << "  ";

    if(i==0 or i==2*n){
      ncaleczka=ncaleczka+y;
    //  cout<< "zerowa lub ostatnia" << endl;
    }
    else if(i%2==1){
      ncaleczka=ncaleczka+4*y;
    //  cout << "nieparzysta" << endl;
    }
    else{
      ncaleczka=ncaleczka+2*y;
    //  cout << "parzysta<"<< endl;
    }

  }

return ncaleczka * h/3;

}





int main(){

double a=0;
double b=1;

//cout  << simpson(funkcja, a, b, 9) << endl;


for(int n=2; n<10; n++){
  cout << n << "  " << setprecision(10) << simpson(funkcja, a, b, n) << endl;
}





  return 0;
}
