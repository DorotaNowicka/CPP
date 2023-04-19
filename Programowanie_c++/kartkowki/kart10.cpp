#include<iostream>
#include<vector>
using namespace std;

int main(){
    //deklaracja vectora v pustego lub od razu o dlugosci 10
    vector <int> v;
    //wypelnianie
    int b;
    for(int i = 0; i < 10; i++){
        b = i * i * 2;
        /*przypisanie wartosci v_i i-temu elementowi vectora
         za pomoca push_back lub nawiasow kwadratowych albo at
         - wybierz jeden ze sposobow odpowiedni dla Twojej deklaracji v.*/
         v.push_back(b);
    }
for(int i =0; i<10; i++){
cout << v[i] << "   ";

}
cout << endl;
}

