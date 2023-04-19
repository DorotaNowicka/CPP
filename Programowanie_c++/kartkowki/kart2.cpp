#include<iostream>
using namespace std;

int main(){

	int a, b;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
if(b==0){
cout<<"nie dzielę przez 0"<< endl;}
else{
	
if(a % b == 0){
		cout << "a = " << a << ", b = " << b << ": b jest dzielnikiem a" << endl;
	}
	else{
		cout << "a = " << a << ", b = " << b << ": b nie jest dzielnikiem a" << endl;
	}
}
	return 0;
}
