//overload
#include<iostream>
using namespace std;

double area(double a){
	return a*a;
}
double area(double a, double b){
	return a*b;
}
double area(double a, double b, double c){
	return 2*a*b+2*a*c+2*b*c;
}



	int main(){
	cout << "Dostałem jedną liczbę obliczam: " << area (5)<< endl;
	cout << "Dostałem dwie liczby obliczam: " << area (3,5)<< endl;
	cout << "Dostałem trzy liczby obliczam: " << area (3,4,5)<< endl;
	return 0;
	}
 
