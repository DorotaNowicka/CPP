#include <iostream>
using namespace std;

int gcdRec(int a, int b){
  if(a==b){
    return a;
  }
  else if(a>b){
    gcdRec(a-b,b);
  }
  else{
    gcdRec(a, b-a);
  }
}

int sumDigits(int n){
  if(n<10){
    return n;
  }
  else{
    return n%10  + sumDigits(n/10);
  }
}

int numDigits(int n){
  if(n<10){
    return 1;
  }
  else{
    return 1 + numDigits(n/10);
  }
}

void printOddEven(int n){
  if(n>2){
      printOddEven(n-2);
  }
cout << n << "  ";
}

void hailstone(int n){
  cout << n << "  ";
  if(n!=1){
    if(n%2==0){
      hailstone(n/2);
    }
    else{
      hailstone(3*n+1);
    }
  }
}


int main(){
  std::cout << "gcdRec(12, 42) = " <<
  gcdRec(12, 42) << std::endl
  << "gcdRec(12, 25) = " <<
  gcdRec(12, 25) << std::endl;
  std::cout << "sumDigits(123) = " <<
  sumDigits(72) << std::endl
  << "sumDigits(971) = " <<
  sumDigits(971) << std::endl;
  std::cout << "numDigits(12345) = " <<
  numDigits(12345) << std::endl
  << "numDigits(971) = " <<
  numDigits(971) << std::endl;
  std::cout << "printOddEven(15): ";
  printOddEven(15);
  std::cout << std::endl;
  std::cout << "printOddEven(14): ";
  printOddEven(14);
  std::cout << std::endl;
  hailstone(13);
  std::cout << std::endl;

  return 0;
}
