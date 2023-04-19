#include<iostream>
using namespace std;

int main(){
const int N = 5;
int tab [N];
for(int i =0; i< N; i++){
cin >> tab [i];
}
for(int j =0; j<= N; j++){
cout << tab [N-j] << endl;
}

return 0;
}
