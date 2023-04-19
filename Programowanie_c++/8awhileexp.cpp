//przykład while na eksponensie

#include<iostream>
#include<cmath>
using namespace std;

int main(){

	double x;
	cin>>x;
	double eps = 0.0001;
	
	int i=1;
	double next=1;
	double result=1;
	
	while(abs(next)>eps){
	next= -1*next * x/i;
	result +=next;
	i+=1;
	}
cout <<result<<endl;
return 0;
}
