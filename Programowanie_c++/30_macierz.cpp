#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
int M=11;
int N=11;
vector<vector<int> > v;	//ta spacja jest ważna, żeby nie powstał >>

//do elementu w 2 wierszu, 3 kolumnie odwołujemy się v[1][2]

for(int i =0;i<M;i++){
	vector <int> v2;
	for (int j =0; j<N; j++){
		v2.push_back(i*j);	
	}
	v.push_back(v2);
}

for(int i =0; i<M; i++){
	for(int j=0; j<N; j++){
		cout << setw(4) << v[i][j];
	}
	cout << endl;
}
}
