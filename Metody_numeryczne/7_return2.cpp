#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main () {
	int n;
	double a, x;
	ifstream dane("params.dat"); //sczytujemy parametry z zewnetrznego pliku
	dane >> x;
	dane >> a;
	dane >> n;

	if(n < 0) {
		cout << "Zle dane!\n";
		return 1; }
	if(a < 0 || a > 4) {
		cout << "Zle dane!\n";
		return 2; }
	if(x < 0 || x > 1) {
		cout << "Zle dane!\n";
		return 3; }

	ofstream plik("simul.dat");

	for(int i = 0; i < n; i++) {
		plik << x << "\n"; //zapisujemy kolejne x do pliku
		x = a*x*(1-x); //obliczamy nowa wartosc x
	}

	plik.close();

	ofstream wykres("wykres.gp"); //tworzymy plik - skrypt Gnuplota
	wykres << "plot \"simul.dat\" w lp"; //wpisujemy tresc skryptu - wykres danych z "simul.dat"
	wykres.close(); //zamykamy plik - skrypt
	system("gnuplot -persist wykres.gp"); //wykonujemy skrypt w Gnuplocie za pomoca komendy system()
	
	return 0; }
