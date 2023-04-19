#include<iostream>
using namespace std;

	void sort(int&x1, int&x2){
		if(x1 > x2){
		int a;
		a = x1;
		x1= x2;
		x2= a;
		}
		else{
		}
	}

int main(){

int x1, x2;
cin>> x1>>x2;
sort(x1, x2);

cout << "Mniejsza jest"  << x1 << ", a większa"<< x2;

return 0;
}
