#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

class Solver;

//klasa parameters - sama działa
        class Parameters{
          double delta_x;
          double M;
          double epsilon;
        public:
          Parameters();
          Parameters(double a, double b, double c);
          Parameters(string plik_do_wczytania);
          double getdelta_x();
          double getM();
          double getepsilon();
          ~Parameters(){}
          friend class Solver;
        };
        /////
        Parameters::Parameters(){
          delta_x = 0.1;
          M = 20;
          epsilon = 0.001;
        }

        Parameters::Parameters(double a, double b, double c){
          delta_x = a;
          M = b;
          epsilon = c;
        }

        Parameters::Parameters(string plik_do_wczytania){
          fstream plik;
          plik.open(plik_do_wczytania);
          if(plik.good()){
            plik>> delta_x;
            plik >> M;
            plik >> epsilon;
            plik.close();
          }
          else{
            cout << "wystąpił problem z plikiem " << plik_do_wczytania << " . Wczytuję wartości domyślne."<<endl;
            delta_x = 0.1;
            M = 20;
            epsilon = 0.001;
          }
        }

        double Parameters::getdelta_x(){return delta_x;}
        double Parameters::getM(){return M;}
        double Parameters::getepsilon(){return epsilon;}


//klasa equation - sama działa
          class Equation{
              vector <vector <double>> v;
          public:
           Equation();
           Equation(string plik_z_f);
           double dlugosc();
           vector <vector <double>> getv();
           double max_alpha();
           void print();
           ~Equation(){}
           friend class Solver;
          };


                    Equation::Equation(){

                    for(int i =0; i<100; i++){
                      vector <double> w;
                      //pierwsze miejsce czyli u
                        if(i<61 and i>39){
                          w.push_back(100);
                        }
                        else{
                          w.push_back(0);
                        }
                      //drugie czyli alpha
                        if(i<50){
                          w.push_back(0.1);
                        }
                        else{
                            w.push_back(0.01);
                        }

                        //trezecie czyli f
                            w.push_back(0);
                    v.push_back(w);

                    }
                    }



                    Equation::Equation(string plik_z_f){
                      vector <vector <double>> v;
                      vector <double> w(3);
                      ifstream plik;
                      plik.open(plik_z_f);
                      if(plik.good()){
                        while(!plik.eof()){
                          double a, b, c;
                          plik >> a >> b >> c;
                          w[0]=a;
                          w[1]=b;
                          w[2]=c;
                          v.push_back(w);
                        }
                      }
                     else{
                       cout << "wystąpił błąd przy wczytywaniu pliku " << plik_z_f << ". Wczytuję wartości domyślne."<< endl;
                       vector <double> w;
                     for(int i =0; i<100; i++){
                       //pierwsze miejsce czyli u
                         if(i<61 and i>39){
                           w.push_back(100);
                         }
                         else{
                           w.push_back(0);
                         }
                       //drugie czyli alpha
                         if(i<50){
                           w.push_back(0.1);
                         }
                         else{
                             w.push_back(0.01);
                         }

                         //trezecie czyli f
                         for(int i=0; i<100; i++){
                             w.push_back(0);
                         }
                     v.push_back(w);

                     }
                    }
                    }

                    vector <vector <double>> Equation::getv(){
                      return v;
                    }

                    double Equation::dlugosc(){
                      return v.size();
                    }

                    void Equation::print(){
                      for(int i =0; i<v.size(); i++){
                        for(int j=0; j<(v.at(i)).size();j++){
                          cout << v[i][j]<< "  ";
                        }
                        cout << endl;
                      }
                    }

                    double Equation::max_alpha(){
                      double a = v[0][1];
                      for(int i =0; i<v.size(); i++){
                          if(a<v[i][1]){
                            a = v[i][1];
                      }
                      return a;
                    }
                  }

//a klasę solver próbuję ogarnąć:
    class Solver{
    Equation rownanko;
    Parameters parametry;

    public:
      Solver(Equation eq, Parameters pa);
      vector <vector <double>> solve();
      void saveSolution(string plikdladanych);
      void print_rozwiazania();
      ~Solver(){};
    };

    Solver::Solver(Equation eq, Parameters pa){
      rownanko = eq;
      parametry = pa;
    }


    vector <vector<double>> Solver::solve(){
        vector <vector <double>> rozwiazania;
        double n = rownanko.dlugosc();
        vector <double> uxt;
        vector <double> uxtplusdt;
        int t =0;

      //pierwszy wiersz rozwiązań:
      for(int i = 0; i<n; i++){
        uxt.push_back(rownanko.getv()[i][0]);
      }

      rozwiazania.push_back(uxt);

        //krok czasowy:
      double dt;
      dt= (parametry.delta_x*parametry.delta_x)/(2*rownanko.max_alpha());
      //
      int j=1;
      while(true){
          vector <double> rozw_dla_ti;
          rozw_dla_ti.push_back(rozwiazania[j-1][0]);
              for(int i=1; i<n-1; i++){
                double u1 = rozwiazania[j-1][i]+dt*rownanko.getv()[j][2];
                double u2 = dt*rownanko.getv()[j-1][i+1]*(rozwiazania[j-1][i+1]-2*rozwiazania[j-1][i]+rozwiazania[j-1][i-1])/(parametry.getdelta_x()*parametry.getdelta_x());
                rozw_dla_ti.push_back(u1+u2);
              }

          rozw_dla_ti.push_back(rozwiazania[j-1][n-1]);
          rozwiazania.push_back(rozw_dla_ti);

          cout<< endl;
          double sumka =0;
          for(int i =0; i<n; i++){
            sumka=sumka+(rozwiazania[j][i]-rozwiazania[j-1][i])*(rozwiazania[j][i]-rozwiazania[j-1][i]);
          }
          if(sumka<=parametry.getepsilon()){break;}
          j++;
      }

        return rozwiazania;
    }

    void Solver::print_rozwiazania(){
        vector <vector <double>> rozwiazania = solve();
      for(int i =0; i<rozwiazania.size(); i++){
        for(int j=0; j<(rozwiazania.at(i)).size();j++){
          cout << rozwiazania[i][j]<< "  ";
        }
        cout << endl;
      }
    }


    void Solver::saveSolution(string plikdladanych){
        vector <vector <double>> rozwiazania = solve();

      ofstream plik2;
      plik2.open(plikdladanych.c_str());
      if(plik2.good()){
        for(int i =0; i<rozwiazania.size(); i++){
          for(int j=0; j<(rozwiazania.at(i)).size();j++){
            plik2 << rozwiazania[i][j]<< "  ";
            cout << rozwiazania[i][j]<< "  ";
          }
          plik2 << endl;
        }
        plik2.close();
      }
      else{
        plikdladanych = "solution.dat";
        plik2.open(plikdladanych);
      }
      for(int i =0; i<rozwiazania.size(); i++){
        for(int j=0; j<(rozwiazania.at(i)).size();j++){
          plik2 << rozwiazania[i][j]<< "  ";
        }
        plik2 << endl;
      }
      plik2.close();
    }


int main(){
  //wywołanie klasy parameters;
  Parameters p(1, 1, 1);
  while(true){
    cout << "Czy chcesz uruchomić program dla parametrów domyślnych? " << endl;
    cout <<  "<tak - 1/nie i użyj wartości z pliku -0/" << endl;
    cout << " nie i użyj innych wartości - 2> "<< endl;
    int decyzja1;
    cin >> decyzja1;
    if(decyzja1==1){
        Parameters tmp;
        p = tmp;
        break;
    }
    if(decyzja1==0){
      cout << "Podaj nazwę pliku z wartościami parametrów: "<< endl;
      string plik_do_wczytania;
      cin >> plik_do_wczytania;
      Parameters tmp(plik_do_wczytania);
      p=tmp;
      break;
    }
      if(decyzja1==2){
          cout << "Podaj parametry:" << endl;
          int p1,p2, p3;
          cout << "krok przestrzenny: ";
          cin >> p1;
          cout << "co ile iteracji zapisać wynik: ";
          cin >> p2;
          cout << "dokładność: ";
          cin >> p3;
        Parameters temp(p1,p2,p3);
        p=temp;
        break;
      }
        else{
          cout<<"nieprawidłowa wartość"<< endl;
        }

}
//wywołanie klasy Equation
Equation rown;
while(true){
  cout << "Czy chcesz wykorzystać domyślny warunek początkowy, rozkład " << endl;
  cout << "dyfuzyjności termicznej i źródeł ciepła? <tak - 1/ nie 0> " << endl;
  int decyzja2;
  cin >> decyzja2;
  if(decyzja2==1){
   Equation tmp;
   rown=tmp;

    break;
  }
  if(decyzja2==0){
    string plik_z_f;
    cout << "Podaj nazwę pliku z którego wczytam wartości: ";
    cin >> plik_z_f;
    Equation tmp(plik_z_f);
    rown=tmp;
    break;
  }
  else{
    cout << "nieprawidłowa wartość"<< endl;
  }
}
rown.print();
cout << p.getdelta_x() << "  " << p.getM() << "  " << p.getepsilon() << endl;

cout << "no to rozwiązuję:"<< endl;

Solver solv(rown, p);

cout << "Wpisz nazwę pliku do którego zapisać rozwiązanie: "<< endl;
string nazwaplikuzapis;
cin >> nazwaplikuzapis;

solv.saveSolution(nazwaplikuzapis);
  return 0;
}
