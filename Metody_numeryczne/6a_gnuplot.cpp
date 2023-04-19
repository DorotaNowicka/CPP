#include <iostream>
#include <fstream>


using namespace std;

int main(){
  double a;
  double x =0.01;


    ofstream plik2("simul.dat");

    for(a=0;a<=4;a=a+0.002){
      for(double i=0; i<400; i++){
        if(i>199){
        plik2<<a<< " "<<x<<endl;
        }
        x=a*x*(1-x);

      }
      plik2<<a<< " "<<x<<endl;
    }
    plik2.close();


  ofstream wykres("wykres.gp"); //tworzymy plik - skrypt Gnuplota
//ważne: \" żeby cudzysłów był napisem
  wykres << "plot \"simul.dat\" w d"; //wpisujemy tresc skryptu - wykres danych z "simul.dat"
// w lp czyli nz linią dopasowania, d czyli kropki
  wykres.close(); //zamykamy plik - skrypt
  system("gnuplot -persist wykres.gp"); //wykonujemy skrypt w Gnuplocie za pomoca komendy system()



  return 0;

}
