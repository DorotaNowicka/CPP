#include <iostream>
using namespace std;

void rekur(){
  //!!! taka zmienna tworzy się tylko raz
  static int i = 0;
  cout << "wpisz liczbę całkowitą inną niż 0:"<< endl;
  double a;
  int b = i++;
  cin >> a;
  if(a!=0){
    rekur();
    cout << a << (b==0 ? '\n' : ' ');
  }

}



int main(){
  rekur();
}
