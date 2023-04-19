#include<iostream>
using namespace std;

void convert_temp(double tK){
	if(tK<0){
		cout << "za zimno" << endl;
}
	else{
		cout <<  tK+273.15<<endl;
		cout << (tK*1.8) - 459.67<< endl;
	}
}
int main(){
	double tK;
	cout << "podaj temperaturę w Kelwinach: ";
	cin >> tK;
 convert_temp(tK);

	return 0;
}
