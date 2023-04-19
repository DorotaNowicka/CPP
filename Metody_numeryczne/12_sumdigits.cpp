#include <iostream>
using namespace std;

int sumDigits(int n){
  if(n<10){
    return n;
  }
  else{
    return n%10  + sumDigits(n/10);
  }
}

int main(){

cout << sumDigits(57);


}
