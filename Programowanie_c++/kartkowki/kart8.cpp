#include<iostream>
using namespace std;

int main(){

int x = 3;

int *w = &x;

*w=10* (*w);
cout << "liczba pod adresem wskaźnika: " << *w << endl;

return 0;
}

