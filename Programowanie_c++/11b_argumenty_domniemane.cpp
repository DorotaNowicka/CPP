#include<iostream>
using namespace std;

	void print_nat(int a=-5, int b=10){
		for(int i=0; i<b; i++){
		cout<< a << endl;
		a = a + 1;
		}
		}

int main(){

cout<< "Wypisuję odp na 1:"<<endl;
print_nat(10,15);
cout<< "Wypisuję odp na 2:"<<endl;
print_nat(10);
cout<< "Wypisuję odp na 3:"<<endl;
print_nat();

return 0;
}
