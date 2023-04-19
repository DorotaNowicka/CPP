#include <iostream>
#include <cmath>
using namespace std;

int main()
{

  double a,b,c;

  //komunikacja z uzytkownikiem
	cout << "Podaj równanie kwadratowe: współczynnik przy x^2 ";
	cin >> a;
  cout << "współczynnik przy x: ";
  cin >> b;
  cout << "wyraz wolny: ";
  cin >> c;

cout <<" Przyjąłem " << a <<"x^2 + " <<b<< "x + " << c << endl;

  if(a!=0){

      double delta;
      delta = b*b - 4*a*c;
      cout << delta<<endl;
      if(delta>0){
        double x1, x2;
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        cout << "Rozwiązania to: " << x1 << ", " << x2 << endl;
      }
      if(delta==0){
        double x;
        x=(-b)/(2*a);
        cout << "rozw. to " << x << endl;
      }
      if(delta<0){
        cout << "brak rozw rzeczywistych" << endl;
      }
    }


if(a==0){
  if(b==0){
    if(c==0){
      cout << "równanie nieoznaczone" << endl;
    }
    else{
      cout << "równanie sprzeczne"<< endl;
    }
  }
  if(b!=0){
    double y;
    y=(-c)/b;
    cout<< "rozwiązanie to " << y << endl;
  }
}


return 0;
}
