//równania kawadratowe

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double a, b, c;
	cin>> a;
	cin>> b;
	cin>> c;
	double delta;
	delta = b*b - 4*a*c;
	double sqrt_delta = sqrt(delta);
	cout << "pierwiastek z delty to " << sqrt_delta << endl;
	
	if(a==0){
		if(b!=0){
		cout<< "x = " << (-c)/b <<endl;
		}
		else{
			if(c==0){
			cout<<"równanie tożsamościowe"<<endl;}	
			else {cout<<"równanie sprzeczne"<<endl;}
		}}

else{
	
if(delta>0){
	cout << "x = " << (-b+ sqrt_delta)/(2*a) << "lub x = " << (-b - sqrt_delta)/(2*a)<<endl;
}
else if(delta==0){
	cout << "x = " << (-b)/(2*a) << endl;
}
else{
	cout << "brak rzeczywistych rozwiązań" << endl;
}
}
	return 0;
}
