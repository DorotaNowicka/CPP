#include <iostream>
using namespace std;

void rekur(){
  cout << "wpisz liczbę całkowitą inną niż 0:"<< endl;
  double a;
  cin >> a;
  if(a!=0){
    rekur();
    cout << a <<" ";
  }

}



int main(){
  rekur();
}
