#include <iostream>
#include <climits>

using namespace std;
#define POL
//#define ENG

#if !(defined(ENG) || defined(POL))
  #error niezdefiniowane żadne makro
#endif

#if (defined(ENG) && defined(POL))
  #error oba makra zdefiniowane
#endif

int main() {
int najdl = 0;
int dlmax = 0;
int najkr=0;
int dlmin=INT_MAX;
int N=1;


while(N!=0){
  #ifdef POL
  cout << "podaj liczbę: ";
  #endif
  #ifdef ENG
  cout << "enter int: ";
  #endif
   cin >> N;
   //const int dlmin = N;
   int lcyfr = 0;
   int reszta;
   reszta = N;

   while(reszta!=0){
       reszta = reszta/10;
       lcyfr = lcyfr+1;
   }


   if(lcyfr>dlmax){
     dlmax=lcyfr;
     najdl=N;
   }
   if(lcyfr<dlmin & N!=0){
     dlmin=lcyfr;
     najkr=N;

   }

}

#ifdef POL
cout << "najdłuższa liczba to: " << najdl << " ma " << dlmax << " cyfr" << endl;
cout << "najkrótsza liczba to: " << najkr << " ma " << dlmin << " cyfr" << endl;
#endif
#ifdef ENG
cout << "Max number of digits was " << dlmax << " for " << najdl << " cyfr" << endl;
cout << "Min numbers of digits was " << dlmin << " for " << najkr << " cyfr" << endl;
#endif




}
