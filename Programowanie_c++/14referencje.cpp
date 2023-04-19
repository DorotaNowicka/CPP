#include<iostream>
using namespace std;

	void f(int&x){
	//sprawi  że x zmieni wartość (przekazywanie argumentu przez referencje ;)
		x=10;
	}

int main(){
	x=5;
	f(x);
	cout<< x;
	//wypisze się 10
	return 0;
}
