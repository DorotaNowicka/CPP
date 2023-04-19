//zadanie ciąg Fibonacci

#include<iostream>
using namespace std;
int main(){
int prev =0;
int curr=1;

int N;
cin>> N;
if(N<0){cout<<"niepoprawne"<<endl;}
else{
for(int i=0; i<N; i++){
	if(i<= 1){
	cout<< i << "   " << i << endl;
	}
	else{int next;
	next=prev+curr;
	prev=curr;
	curr = next;
	cout << i << "   " << next << endl;
	}
}}
return 0;
}
