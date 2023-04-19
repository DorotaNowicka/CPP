#include<iostream>

using namespace std;

int main(){
	string wyraz;
	while(true){
	cout << "Podaj słowo" << endl;
	cin >> wyraz;
	int dl;
	dl = wyraz.length();
	cout << "długość " << dl << endl; 
	if(dl%2==0){
	continue;
	}
	else{
	cout<<"l.np"<<endl;
	if(dl == 7){
	cout << "długość równa 7" << endl;
	break;
	}}
	}
return 0;
}
