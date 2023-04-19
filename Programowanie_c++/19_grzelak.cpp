//napisy - typ string
//wczytywanie napisow i liczenie sredniej dlugosci slowa
#include<iostream>
#include <string>
using namespace std;

int main(){
    string word;
    int total_length = 0; //suma dlugosci wszystkich slow
    int number_of_words = 0;

    while (cin >> word) {
        total_length += word.length();
        number_of_words++;
    }
    //przerwanie petli: ctrl + D
    double average_length = (double)total_length/number_of_words;
    cout << "Liczba znakow: " << total_length << endl;
    cout << "Liczba slow: " << number_of_words << endl;
    cout << "Srednia dlugosc slowa: " << average_length << endl;

}




