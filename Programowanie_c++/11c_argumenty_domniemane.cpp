#include<iostream>
using namespace std;

void print_nat(int b = 20, int a = 0){
	for(int i=0; i<b; i++){
	cout<< a << endl;
	a = a + 1;
	}
}

int main(){

cout<< "Wypisuję odp na *:"<<endl;
print_nat();

return 0;
}
