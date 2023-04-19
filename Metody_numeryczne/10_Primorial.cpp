#include <iostream>
using namespace std;

int czyPierwsza(int N){
  int a=1;
  for(int i=2;i<N;i++){
    if(N%i==0){
      a=0;
    }
  }
  return a;
}

int Primorial(int N){
  static int a=1;
 if(N!=1){
if(czyPierwsza(N)==1){
  a=a*N;
}
Primorial(N-1);
}
return a;
}

int main(){
  int N;
  cout <<"podaj N: ";
  cin >> N;
  cout << "Czy pierwsza? " << czyPierwsza(N)<<endl;
  cout<< "Primorial: " << Primorial(N)<<endl;
}
