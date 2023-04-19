#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

int PodzielTablice(double *tab, int l, int r);
int WybierzPunktPodzialu(int l, int r);
void Zamien(double *tab, int i1, int i2);

void Quicksort(double *tab, int l, int r){
  if(l<r){
    int i = PodzielTablice(tab, l, r);
  //  cout << "i " << i << endl;
    Quicksort(tab,l,i-1);
    Quicksort(tab,i+1,r);
  }
/*  cout<< "w funkcji"<< endl;
  for(int i=0; i<11; i++){
    cout << tab[i] << "  ";
  }
  cout << endl;
*/
}

int PodzielTablice(double *tab, int l, int r){
  int indeksPodzialu=WybierzPunktPodzialu(l,r);
  double wartoscPodzialu=tab[indeksPodzialu];
  Zamien(tab, indeksPodzialu, r);
  int aktualnaPozycja=l;
  for(int i =l;i<r;i++){
    if(tab[i]<wartoscPodzialu){
      Zamien(tab,i,aktualnaPozycja);
      aktualnaPozycja=aktualnaPozycja+1;
    }
  }
  Zamien(tab, aktualnaPozycja, r);
  return aktualnaPozycja;
  cout << aktualnaPozycja<< endl;
}

int WybierzPunktPodzialu(int l, int r){
  return l+(r-l)/(2);
}

void Zamien(double *tab, int i1, int i2){
  double aux=tab[i1];
  tab[i1]=tab[i2];
  tab[i2]=aux;
}

int main(){
  srandom(time(0));
  	int N = 11;

double tab[N];

for(int i=0; i<N; i++){
double a = rand()%20;

  tab[i]=a;
}

for(int i=0; i<N; i++){
  cout << tab[i] << "  ";
}

cout << endl;

Quicksort(tab, 0, N-1);

for(int i=0; i<N; i++){
  cout << tab[i] << "  ";
}
cout << endl;

  return 0;
}
