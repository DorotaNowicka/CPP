#include<iostream>
#include<cmath>
using namespace std;

double volume(double r){
	return(4./3.)*M_PI*r*r*r; //kropki żeby 4/3 nie wyszło 1
}
 
int main(){
cout << "podaj promień kuli:";
double a;
cin>>a;
cout << "Objętość kuli to: " << volume(a) << endl;

return 0;
}
