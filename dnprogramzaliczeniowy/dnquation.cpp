//metody klasy eqation
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"dnequation.h"
using namespace std;
//konstruktor domyślny
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


//konstruktor wczytujący z pliku
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
	//wczytanie wartości domyślnych
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

	//dostęp do cechy
          vector <vector <double>> Equation::getv(){
            return v;
          }
	
	//obliczanie długości wektora v
          double Equation::dlugosc(){
            return v.size();
          }

 
	//znajdowanie największej wartości
          double Equation::max_alpha(){
            double a = v[0][1];
            for(int i =0; i<v.size(); i++){
                if(a<v[i][1]){
                  a = v[i][1];
            }
            return a;
          }
        }
