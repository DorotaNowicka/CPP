#include<iostream>
using namespace std;

	double calc_power(double x, int n){
		double pow=1;
		for(int i=1; i<=n; i++){
		pow = pow * x;
		}

	return pow;
	}

	void printpower(double x, int n){
		if(x>=0){
			cout<< x << " ^ " << n << " = " << calc_power(x,n) <<endl;
		}
		else{ cout << "(" << x << ") ^ " << n << " = " << calc_power(x,n) <<endl;
		}
	}

int main(){
double a;
int b;
cin >> a;
	int n = 0;
	int i = 1;
	do{
	cout << "podaj n: ";	
	cin >> b;
	i++;	
	}
	while (b < 0 and i<4);
if(b>0){
printpower(a,b);}
else{cout<<"błędne n" << endl;
}

return 0;
}
