#include<fstream>
#include<iostream>
using namespace std;
int main(){

ofstream plik2;
plik2.open("dane.txt");
if(plik2.good()){ 
plik2<<1<< '\n'; 
plik2<<4<< '\n';
plik2<<2.25<< '\n';
plik2<<"kkk"<< '\n';
plik2.close();
}
else{ cout << "error"<<endl;
}

double a,b,c;
string d;
ifstream plik;         //te dwie linijki da się zapisać na raz:
plik.open("dane.txt"); //ifstream plik("dane.txt")
if(plik.good()){
	plik >>a >>b >>c >>d;
	plik.close();
}
else{ cout << "nope" << endl;
}

}
