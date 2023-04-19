#include <iostream>
#include <fstream>
#include<cmath>
//pozwala na ustalenie dokładności
#include <iomanip>
#include <cstdlib>
#include<vector>
#include <ctime>
#include "gnuplot_i.hpp"
using namespace std;



int main(){

/*
  string nazwa_pliku = "bilard_dane.dat";
  ofstream plik;
  double dt;
  plik.open(nazwa_pliku.c_str());
    if(plik.good()){
      plik >> dt;

    plik.close();
    }
    else{ cout << "error"<<endl;
    }
cout << dt<< endl;
  }
*/





  double dt;
  vector <double> kula;
  vector <vector <double> > kulki;

  ifstream plik;
  plik.open("bilard_dane.dat");
    if(plik.good()){
      plik >> dt;

      while(!plik.eof()){ //true gdy plik się kończy
        double a,b,c,d,e,f;

        plik>>a>>b>>c>>d>>e>>f;
        //  vector <double> kula={a,b,c,d,e,f};
    //      kulki.push_back(kula);

    cout << a << " " << b << " " << c << "  " << d << "  " << e << " " << f << endl;
      }
    plik.close();
    }
    else{ cout << "error"<<endl;
    }

}
