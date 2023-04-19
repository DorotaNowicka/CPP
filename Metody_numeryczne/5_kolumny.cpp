#include <iostream>

using namespace std;

int main()
{
	int i;
	int j;
	int k;
	double a,b,c;
	cout << "podaj 3 liczby: " << endl;
	cin >> a;
	cin >>b;
	cin >>c;
double x1,x2,x3;

if(a >= b && a >= c){
	if(b>=c){
		x1 = a;
		x2 = b;
		x3 = c;
	}
	if(c>b){
		x1 = a;
		x2 = c;
		x3 = b;
	}
}
if( b> a && b >= c){
	if(a>=c){
		x1 = b;
		x2 = a;
		x3 = c;
	}
	if(a<c){
		x1 = b;
		x2 = c;
		x3 = a;
	}
}
if( c> a && c>= b){
	if(b>=a){
		x1 = c;
		x2 = b;
		x3 = a;
	}
	if(b<a){
		x1 = c;
		x2 = a;
		x3 = b;
	}
}

double o=x2;
cout << x1 <<", "<<x2<<", "<<x3<<endl;

	for(i=x2; i<=x1; i++){
		cout << "*"<<endl;
	}
	for(j=x3; j<=x1 and j<x2; j++){
		cout << "* *"<<endl;
	}
for(k=1; k<=a and k<=b and k<=c;k++){
	cout << "* * *"<<endl;

}




	return 0;
}
