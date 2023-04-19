#include<iostream>
#include"15b_def.h"
using namespace std;

int main(){
	irn();	
	int N = 10;
	for(int i = 0; i < N; i++){
		cout << "Rzut " << i + 1 << "   " << ri(1,7) << endl;
	}
	return 0;
}

/*
kompilacja:
g++ 15c_wykorzystanie_def.cpp 15b_def.h 15b_def.cpp -o 15c_wykorzystanie_def
g++ nazwy wszystkich plików.cpp i .h -o nazwa programu
*/

