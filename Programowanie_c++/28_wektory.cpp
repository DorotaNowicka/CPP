//można też zadeklarować od  razu rozmiar: vector <int> v(5);
//wtedy v.push_back(1) doda jedynkę na szóstym miejscu (tym z indeksem 5)

#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;

	cout << "rozmiar przed dodaniem elementow: " << v.size() << endl;

	v.push_back(10);
v.push_back(5);
v.push_back(150);
v.push_back(150);
v.push_back(510);
v.push_back(105);

cout << "rozmiar po dodaniu elementow: " << v.size() << endl;

cout << "dziesiąty element [] : " << v[10]<<endl;
cout << "dziesiąty element at() : " << v.at(10)<< endl;
cout << "100000000000 [] : " << v[1000000000]<<endl;
cout << "100000000000 at : " << v.at(100000000000) << endl;


}
