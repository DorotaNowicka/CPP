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
  Mysz(){
    x = 19;
    y = 19;
    czyZyje = true;
  }
  void skacz(){
    x = rand()%20;
    y = rand()%20;
  }
  int getX(){return x;}  //dostają się do danych, bez zmieniania ich na publik
  int getY(){return y;}
  bool getczyZyje(){return czyZyje;}
  void zostan_zlapana(){czyZyje=false;}
}; //ważny średnik <-

class Kotek{
  string imie;
  int x;
  int y;
  int ileZjadlem;
  int liczbaskokow;
  public:
  Kotek(string imietegokotka){
    x=0;
    y=0;
    liczbaskokow=0;
    imie = imietegokotka;
    ileZjadlem = 0;
  }
  void skacz(){
    x = rand()%20;
    y = rand()%20;
    liczbaskokow++;
  }
  void raportuj(){
    cout<< "jestem " << imie << " zjadłem " << ileZjadlem << "myszy. Skoczyłem "<< liczbaskokow << " razy" << endl;
  }
  void zlap(Mysz &mysz){ //ten & sporawia, że zabijamy mysz, a nie jej kopię
      mysz.zostan_zlapana();
      ileZjadlem++;
  }
  int getX(){return x;}
  int getY(){return y;}
  int getliczbaskokow(){return liczbaskokow;}
  int getileZjadlem(){return ileZjadlem;}
};

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
