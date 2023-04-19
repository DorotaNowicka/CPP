#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void irn(){
srandom(time(0));
}
double rd(double a, double b){
return a + (b-a)*(double)rand()/RAND_MAX;
}


void print(double tab[], int N){
	 for(int i =0; i<N; i++){
	cout << tab[i] << endl;
	}
}

double suma_kwadrat

int main(){

	const N = 10;
	double tab [N];
		for(int i=0;i<N;i++){
		tab[i]=rd(0.,15.);}
	print(tab,N);
	
