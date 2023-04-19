/*
Wypisywanie pierwszych kilku liczb naturalnych na 3 sposoby.
*/
//przykłady pętli
//i++ to to samo co i=i+1
#include<iostream>
using namespace std;

int main(){
	// ile liczb wypisać:
	int N = 5;
	int n;
	//pętla while
	n = 0;
	cout << "Pętla while: " << endl;
	while(n < N){
		cout << n << endl;
		n = n + 1; // n += 1	lub i++	
	}
	//pętla do while
	n = 0;
	cout << "Pętla do-while: " << endl;
	do{
		cout << n << endl;
		n += 1;
	}
	while (n < N);
	// pętla for
	cout << "Pętla for: " << endl;
	for (n = 0; n < N; n += 1){
		cout << n << endl;
	}

	return 0;
}
