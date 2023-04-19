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

int  find_id_min(double tab[], int N){
	double wartosc_min = tab[0];
	int indmin=0;
	for(int nrind = 0; nrind<N; nrind++){
		if(tab[nrind]<wartosc_min){
		wartosc_min = tab[nrind];
		indmin = nrind;
		}
	}
	return indmin;
}

int main(){
	irn();
	const int N= 15;
	double tab [N];
	
	for(int i=0;i<N;i++){
	tab[i]=rd(5.5,7.5);}

	print(tab,N);
	cout << find_id_min(tab,N)<< endl;


return 0;
}
