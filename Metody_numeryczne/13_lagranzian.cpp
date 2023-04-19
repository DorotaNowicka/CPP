#include <iostream>
#include <fstream>
using namespace std;

double lagrint(double x, double *wezly, double *wartwwezl, int n){
  double  b=1;

  for(int i=0;i<n; i++){
    if(i!=n){
      b=b*(x-wezly[i])/(wezly[n]-wezly[i]);
    }
    else{b=b;}
  }

  if(n==0){
    return 0;
  }

  else{
  //cout <<  wartwwezl[n]*b << endl;
    return wartwwezl[n]*b+lagrint(x,wezly,wartwwezl,n-1);
  }
}

int main(){
  int N=10;
  double wezly [N];
  for(int i =0; i< N; i++){
  wezly [i]=-1+ i*0.1;
  cout << wezly[i]<< endl;
  }

  double wartwwezl [N];
  for(int i =0; i< N; i++){
  wartwwezl [i]= 1/(1+10*(wezly[i]-0.2)*(wezly[i]-0.2));
  }

cout << lagrint(-0.8, wezly, wartwwezl, N)<< endl;

for(int k=0; k<N; k++ ){
cout << -1+k*0.1  << "   "<< lagrint(-1+k*0.1, wezly, wartwwezl, N) << " " << wartwwezl[k] << endl;
}


double x = -1;
ofstream plik1("plik1.dat");
  for(int j=0; j<100; j++){
    plik1<< x+j*0.01 << " " << lagrint(x+j*0.01, wezly, wartwwezl, N) << endl;
  }
plik1.close();

ofstream wykres("wykres.gp");
wykres << "plot \"plik1.dat\" w d";
wykres.close();
system("gnuplot -persist wykres.gp");

  return 0;
}
