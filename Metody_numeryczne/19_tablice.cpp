#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void *bubble(double *tab, int N){
  int d=2;
  while(d!=0){
    int LP = 0;
  for(int i=0; i<N-1; i++){
    if(tab[i]<tab[i+1]){
      double a= tab[i];
      tab[i]=tab[i+1];
      tab[i+1]=a;
      LP=LP+1;
    }
    d=LP;
  }

}

}

int main(){
  int N;


    double *tab = new double[N];

int b;
cout << "b: ";
cin >> b;
  int a = 0;

if(b==0){

  double c=2;
  while(c!=0){
    cin >> c;
    tab[a]=c;
    a++;
  }
}
else if(b==1){
  ifstream plik;
  plik.open("dane.txt");

  while(!plik.eof())
      {
        plik >> tab[a];
        a++;
      }
      plik.close();
  }
  else{cout << "nope"<< endl;}

/*else if(b==1){
  ifstream plik;         //te dwie linijki da się zapisać na raz:
  plik.open("dane.txt");
double d;
  for(int a=0; a<N; a++){
    cin > d;
    tab[a]=d;
  }

	plik.close();
}
*/
  bubble(tab,a);

for(int i=0; i<a-1; i++){
  cout << tab[i] << "  ";
}
cout << endl;

}
