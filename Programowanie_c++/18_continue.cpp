//Dzialanie instrukcji continue
#include <iostream>
using namespace std;

int main(){
    //wypisywanie liczb naturalnych oprocz podzielnych przez 3 i 2 jednoczesnie
    //wersja 1
    for (int i = 0; i < 16; i++) {
        if((i%3 != 0) or (i%2 != 0)){
            cout << i << endl;
        }
    }

    //wersja 2 - z uzyciem continue
    for (int i = 0; i < 16; i++) {
            if(i%3 == 0 and i%2 == 0){
                continue;
            }
            std::cout << i << endl;
        }
    return 0;
}

