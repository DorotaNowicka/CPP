#include <iostream>
#include <fstream>
#include<cmath>
//pozwala na ustalenie dokładności
#include <iomanip>
#include <cstdlib>
#include<vector>
#include <ctime>
using namespace std;

double monte(double N, double D){
  double iloczyn = 1;
  double fx=0;
  double suma = 0;


//tworzymy n Dwymiarowcyh wektorów
for(int m=0;m<N;m++){
  vector<double> x;
  for(int n=0;n<D;n++){
    x.push_back( -1 + 2*(double)rand()/RAND_MAX);
  }
  //dla każdego wektora obliczamy jego wartosc fx a w tym celu
    //obliczenie iloczynu
    for(int i=0; i<D; i++){
      iloczyn = iloczyn *x[i];
    }
    //obliczanie dlugosci
      double xx=0;
    for(int j=0; j<D;j++){
      xx=xx+x[j]*x[j];
      //cout << x[j] << "  ";
    }
  //  cout << xx << endl;
    //obliczanie wartosci
    if(xx<1){
    //  cout << "jestem" << endl;
        fx=exp(-(1+iloczyn)/(1-xx));
        suma = suma + fx;
      }

  }
  double V=pow((M_PI),(D/2))/(tgamma(D/2+1));
  return  V*suma/N;
}



//ZCZYTYWANIE N Z KONSOLI!
int main(int argc, char* argv[]){
srand( time( NULL ) );

double D =4;

int N = atoi (argv[1]);

  cout << N+1 << " "<< D << "  "<< monte(N,D) << endl;




return 0;
}
