#include <iostream>
using namespace std;

int main(){

int lc=0;
int b;
int ilosc=1;
while(b!=0){
  cin>>b;
  if(b==lc){
    ilosc++;
  }
  else{lc=b}
}

  return 0;
}
