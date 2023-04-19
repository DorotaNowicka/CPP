#include<fstream>
#include<iostream>
using namespace std;
int main(){

int a =12;
ofstream plik;

plik.open("mojPlik.txt"); //utworzy w obecnym katalogu plik mojPlik.txt
if(plik.good()){ //zwraca true, jeśli wszystko jest ok i udało się otworzyć
plik<<a; //wypisze a w programie
plik.close();
}
else{ cout << "error"<<endl;
}
}

//cat "mojPlik.txt" wpisane w temrinalu otwiera go w nim
