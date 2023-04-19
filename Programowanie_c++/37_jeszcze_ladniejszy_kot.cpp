//KOMPILACJA:
//g++ -std=c++11 mysz.cpp kot.cpp main.cpp -o nazwa pliku 

#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#include"Mysz.h"
#include"Kot.h"

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
