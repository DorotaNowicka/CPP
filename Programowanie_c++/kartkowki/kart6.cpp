
#include<iostream>
using namespace std;

//tu wpisz definicje funkcji
bool fun(int x, int y, int z){
	return(x*x+y*y==z*z or x*x+z*z==y*y or y*y+z*z==x*x);
}

int main(){

    //ta linijka nie musisz sie przejmowac, chodzi o to
    //zeby zmienne typu bool wypisywaly sie jako "true"/"false"
    //(domyslnie wypisuja sie jako "1"/"0")
    cout.flags(ios::boolalpha);


    //przypadek pierwszy - ponizsze linijki powinny wypisac:
    //5, 4, 3: true
    //4, 3, 5: true   itd.
    int a=5, b=4, c=3;
    cout << a <<", " << b << ", " << c << ": " << /*wywolanie dla a, b, c*/fun(a,b,c) << endl;
    cout << b <<", " << c << ", " << a << ": " << /*wywolanie dla b, c, a*/fun(a,b,c) << endl;
    cout << c <<", " << a << ", " << b << ": " << /*wywolanie dla c, a, b*/fun(a,b,c) << endl;

    //przypadek drugi
    //1, 2, 2: false    itd.
    int d=1, e=2, f=2;
    cout << d <<", " << e << ", " << f << ": " <</*wywolanie dla d, e, f*/ fun(a,b,c)<< endl;

    return 0;
}

