//<cstdlib> ma funkcję rand () zwracającą całkowite liczby od 0 włącznie do rand_max
//RAND_MAX -> wartość. całkiem spora
//dlatego korzystamy z tego że reszta z dzielenia przez 10 <= 9 
(rand()%N)
//chcąc [n1, N[ -> 
n1+ rand()%(N-n1)

//(double)a zmienia typ a na double

//jak dostać wymierne z [0,1[: 
(double)rand()/RAND_MAX
//double od x1 do x2
x1 + (x2-x1)*double rand()/RAND_MAX


