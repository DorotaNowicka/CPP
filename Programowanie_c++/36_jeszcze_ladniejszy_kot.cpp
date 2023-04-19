// KLASY I OBIEKTY
//klasa to opis cech obiektów
// YT: Pasja informatyki

#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>

class Mysz{
  int x;
  int y;
  bool czyZyje;
  public:
  Mysz();
  void skacz();
  int getX(); //dostają się do danych, bez zmieniania ich na publik
  int getY();
  bool getczyZyje(),
  void zostan_zlapana(),
}; //ważny średnik <-


  void Mysz::skacz(){
    x = rand()%20;
    y = rand()%20;
  }
  int Mysz::getX(){return x;} 
  int getY(){return y;}
  bool getczyZyje(){return czyZyje;}
  void zostan_zlapana(){czyZyje=false;}
  Mysz::Mysz(){
    x = 19;
    y = 19;
    czyZyje = true;
  }


class Kotek{
  string imie;
  int x;
  int y;
  int ileZjadlem;
  int liczbaskokow;
  public:
  Kotek(string imietegokotka);
  void skacz();
  void raportuj();
  void zlap(Mysz &mysz);
  int getX();
  int getY();
  int getliczbaskokow();
  int getileZjadlem();
};

Kotek::Kotek(string imie tego kotka){
    x=0;
    y=0;
    liczbaskokow=0;
    imie = imietegokotka;
    ileZjadlem = 0;
  }
void Kotek::skacz(){
    x = rand()%20;
    y = rand()%20;
    liczbaskokow++;
  }
  void Kotek::raportuj(){
    cout<< "jestem " << imie << " zjadłem " << ileZjadlem << "myszy. Skoczyłem "<< liczbaskokow << " razy" << endl;
  }
 void Kotek::zlap(Mysz &mysz){ //ten & sporawia, że zabijamy mysz, a nie jej kopię
      mysz.zostan_zlapana();
      ileZjadlem++;
int Kotek::getX(){return x;}
  int Kotek::getY(){return y;}
  int Kotek::getliczbaskokow(){return liczbaskokow;}
  int Kotek::getileZjadlem(){return ileZjadlem;}

int main(){
  srand(time(0));
//tworzymy kotka i myszki
  Kotek kot1("Stefek");
  Mysz mysz1, mysz2;

  while(true){
    kot1.skacz();
    mysz1.skacz();
    mysz2.skacz();
    if(kot1.getX()==mysz1.getX() and kot1.getY()==mysz1.getY() and mysz1.getczyZyje()){
      kot1.zlap(mysz1);
    }
    if(kot1.getX()==mysz2.getX() and kot1.getY()==mysz2.getY() and mysz2.getczyZyje()){
      kot1.zlap(mysz2);
    }
    if(kot1.getileZjadlem()==2){break;}
  }
  kot1.raportuj();
}
