//funkcja wywołuje samą siebie aż kończy na return 0
#include<iostream>
using namespace std;

int sum(int n){
	cout << "Wywoływanie funkcji z argumentem " <<n<< "..."<< endl;
	if(n<0){
		return 0;
	}
	return n + sum (n-1);
}

int main(){
	int n;
	
	cout << "Podaj liczbę: ";
	cin>> n;
	cout<< "suma kolejnych l. naturalnych od 0 do " <<n<<" wynosi " << sum(n)<<endl;

	return 0;
} 
