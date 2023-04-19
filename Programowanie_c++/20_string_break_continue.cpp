#include<iostream>
#include <string>
using namespace std;

int main(){

	string word = "słowo";
	int dlugosc = 0;
	
while(true){
cout << "wpisz hasło: " << endl;
string s;
getline(cin, s);
dlugosc = s.length();
cout << dlugosc<<endl;
if(dlugosc>=5){cout<< "hasło prawidłowe"<<endl;
break;}
else{cout<< "hasło za krótkie" << endl;}
}

return 0;
}
