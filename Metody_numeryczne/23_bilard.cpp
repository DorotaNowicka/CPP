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

class Kula{
public:
  double m;
  double r;
  double x;
  double y;
  double vx;
  double vy;
  Kula(double m1,double r1,double x1,double y1,double vx1,double vy1){
    m=m1;
    r=r1;
    x=x1;
    y=y1;
    vx=vx1;
    vy=vy1;
  }
  void Print(){
    cout << m << "  "<< r << "  "<< x << "  "<< y << "  "<< vx << "  " << vy << endl;
  }
};


class Stol{
public:
    vector<Kula> kulki;
    double t;
    double i;
    double dt;


    bool WczytajDane(string nazwa_pliku){
      ifstream plik;
      plik.open(nazwa_pliku.c_str());
        if(plik.good()){
          plik >> dt;
          t=0;
          i=0;
          while(!plik.eof()){ //true gdy plik się kończy
            double a,b,c,d,e,f;

        		plik>>a>>b>>c>>d>>e>>f;
              Kula kula(a,b,c,d,e,f);
        		kulki.push_back(kula);
        	}
        plik.close();
        }
        else{ cout << "error"<<endl;
        }
      return true;
      }
      Stol(string nazwa_pliku){
        WczytajDane(nazwa_pliku);
      }
      void Print(){
        cout << i << "  "<< t << "  "<< dt << "  "<< endl;
        for(int j=0;j<kulki.size();j++){
          kulki[j].Print();
        }
      }

    void  Propagacja(){
        for(int j=0;j<kulki.size();j++){
          kulki[j].x= kulki[j].x+kulki[j].vx*dt;
//          cout << j << " " << kulki[j].x << "  " << kulki[j].vx << endl;
          kulki[j].y= kulki[j].y+kulki[j].vy*dt;
        }
      }



      void Zderzenie(int j, int k){
        cout << "Zderzenie" << j<<k<< endl;
        double g1 =  (kulki[j].vx-kulki[k].vx)*(kulki[j].x-kulki[k].x);
        double g2 =  (kulki[j].vy-kulki[k].vy)*(kulki[j].y-kulki[k].y);
        double d1=  (kulki[j].x-kulki[k].x)*(kulki[j].x-kulki[k].x);
        double d2=  (kulki[j].y-kulki[k].y)*(kulki[j].y-kulki[k].y);


        kulki[j].vx=kulki[j].vx-2*kulki[k].m*(g1+g2)*(kulki[j].x-kulki[k].x)/((kulki[j].m+kulki[k].m)*(d1+d2));
        kulki[j].vy=kulki[j].vy-2*kulki[k].m*(g1+g2)*(kulki[j].y-kulki[k].y)/((kulki[j].m+kulki[k].m)*(d1+d2));
        double ag1 =  (-kulki[j].vx+kulki[k].vx)*(-kulki[j].x+kulki[k].x);
        double ag2 =  (-kulki[j].vy+kulki[k].vy)*(-kulki[j].y+kulki[k].y);
        double ad1=  (-kulki[j].x+kulki[k].x)*(-kulki[j].x+kulki[k].x);
        double ad2=  (-kulki[j].y+kulki[k].y)*(-kulki[j].y+kulki[k].y);

        kulki[k].vx=kulki[k].vx-2*kulki[j].m*(ag1+ag2)*(kulki[k].x-kulki[j].x)/((kulki[j].m+kulki[k].m)*(ad1+ad2));
        kulki[k].vy=kulki[k].vy-2*kulki[j].m*(ag1+ag2)*(kulki[k].y-kulki[j].y)/((kulki[j].m+kulki[k].m)*(ad1+ad2));
      }

    void  CzyKontakt(){
        for(int j=0;j<kulki.size();j++){
          for(int k=0;k<kulki.size();k++){
            if(j!=k){
              double a = kulki[j].x-kulki[k].x;
              double b = kulki[j].y-kulki[k].y;
              if((a*a+b*b)<( kulki[j].r*kulki[j].r+kulki[k].r*kulki[k].r)){
                Zderzenie(j,k);
            }
          }
          }
        }
      }

    void  Stopklatka(){

      }


    void  Runda(int z){
        Propagacja();
        CzyKontakt();

      }

    void  Ewolucja(int ilosc){
        for(i;i<ilosc;i++ ){
          Runda(i);
        }

      }

      bool ZapiszDane(string plik_zapisu){
        ofstream plik;
        plik.open(plik_zapisu.c_str());
          if(plik.good()){
              plik << t<< " "<< i<< " "<<endl;
              for(int j=0;j<kulki.size();j++){
                cout << kulki[j].x << " "<< kulki[j].y << " "<< kulki[j].vx << " " << kulki[j].x << endl;

            }
          plik.close();
          }
          else{ cout << "error"<<endl;
          }
      return true;
      }

};


int main(){
  Stol stolik1("bilard_dane.dat");

stolik1.Print();



  stolik1.Ewolucja(2);
  stolik1.ZapiszDane("nowy.dat");
stolik1.Print();
}
