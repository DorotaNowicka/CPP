#include <iostream>
#include <fstream>


using namespace std;

int main(){
  double a,n,x;

  ifstream plik1 ("params.dat");

  plik1>>x;
  plik1>>a;
  plik1>>n;

  plik1.close();

  if(a<0 or a>4 or x<0 or x>1){
    cout << "Błędne liczby" << endl;
  }
  else{
    ofstream plik2("simul.dat");
    plik2<<x<<endl;

    for(double i=0; i<n; i++){
      x=a*x*(1-x);
      plik2<<x<<endl;
    }
    plik2.close();
  }

  return 0;

}
