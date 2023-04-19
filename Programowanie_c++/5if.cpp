//intrukcja warunkowa
//sprawdzając czy a=b: a==b; a>=b, a<=b

#include<iostream>
using namespace std;

int main(){
int a;
cin >> a;
	if(a<0){
	cout << "|a|=" << -a << endl;
	}
	else{
	cout << "|a|=" << a;
	}
return 0;
}
/*
if(a==5){...}
if(a==6){...}
if(a==5 or a==6){...}  logiczne lub (or, ||)
if(a>6 and a<10){} logiczne i (and, &&)
if(a>6 && a<10){}
else{...}
*/

