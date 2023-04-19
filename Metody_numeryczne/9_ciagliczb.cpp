#include <iostream>
using namespace std;

int main(){

int a=-1;
int b=-1;
int nc;
int ilosc=1;
int imax =0;
while(b!=0){
  cin>>b;
  if(b==a){
    ilosc++;
  }
  else{a=b;
  ilosc=1;}

  if(ilosc>imax){
    nc=b;
    imax=ilosc;
  }


}

cout << " najdłuższa seria to " << imax << "razy z rzędu liczba " << nc << endl;

  return 0;
}
