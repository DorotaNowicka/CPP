#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

vector<double> f(string d){
	vector<double> v;
	ifstream plik;
	plik.open(d);
	double x;	
	while(!plik.eof()){ //true gdy plik się kończy
		plik>>x;
		v.push_back(x);
	}
	plik.close();
return v;
}

void print_vec(vector<double> v){
	cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if (i < v.size()-1) cout << ", ";

	}
	cout << "}" << endl;
}

int main(){

vector <double> w;
w=f("zzz");
print_vec(w);

}
