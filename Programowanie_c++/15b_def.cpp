//to są definicje funkcji
#include"15b_def.h"

//zwraca inty z zakresu [a, b[
int ri(int a, int b){
return a + rand()%(b-a);
}
//zwaraca double z zakresu a - b
double rd(double a, double b){
return a + (b-a)*(double)rand()/RAND_MAX;
}
// init random nums, inicjalizacja
void irn(){
srandom(time(0));
}
