#include<iostream>
using namespace std;

	double calc_power(double x, int n){
		double pow=1;
		for(int i=1; i<=n; i++){
		pow = pow * x;
		}

	return pow;
	}

int main(){
double a;
int b;
cin>>a;
cin>>b;
cout << calc_power(a,b) << endl;

return 0;
}
