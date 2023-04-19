/*
dopisywanie do pliku:
plik.open("zzz", ios::app);
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

vector<double> example_vector(int N){
	vector<double> result(N);
	for (int i = 0; i < result.size(); i++){
		result[i] = sin(i);
	}
	return result;
}

int main(){
	vector<double> v = example_vector(10);
	ofstream plik;
	plik.open("zzz");
if(plik.good()){
	for(int i =0; i<10; i++){
		plik << v[i]<< '\n';
	}
	
}

else{
	cout << "plik nie istnieje" << '\n';
}
//dopisywanie do pliku
plik.open("zzz", ios::app);
if(plik.good()){
	for(int i =0; i<10; i++){
		plik << v[i]<< '\n';
	}
	plik.close();
}

else{
	cout << "plik nie istnieje" << '\n';
}




}
