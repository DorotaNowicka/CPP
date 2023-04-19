PROI Zadanie 2: Histogram i statystki.

Autor: Dorota Nowicka

Wykorzystane środowisko: Visual Studio Code

kompilacja programu w terminalu poza środowiskiem:
g++ zad2.cpp -o statistics vector_functions.cpp statistic_functions.cpp histogram_functions.cpp -std=c++17

Uruchomienie: ./statistics

Program poprosi o podanie nazwy pliku z danymi liczbowymi. 
Jeśli plik o podanej nazwie istnieje, program wczyta dane z niego i stworzy 
z nich wektor. W przeciwnym razie program wykorzysta dane z pliku "defaultdata.txt".

Efektem działania programu jest utworzenie plików: "histogram.txt" i "statistics.txt".

Plik "histogram.txt" zawiera poziomy histogram danych z pliku. Liczba "X" 
w wierszu określa ilość danych mniejszych (lub równych) od liczby na pionowej 
osi do liczby pod nią.
Przykładowo histogram:

range
1   X  X  
2   
3   X
    1  2
  amount

oznacza, że wśród danych znajdują się dwie liczby z przedziału [1,2), 
żadna liczba z przedziału [2,3) i jedna z przedziału [3,4).


Plik "statistics.txt" zawiera wyniki funkcji statystycznych:
-średnią (arytmetyczną),
-odchylenie (standardowe),
-średnią geometryczną,
-medianę.
W przypadku danych ujemnych średnia geometryczna przyjmie wartość -1, 
a użytkownik zostanie o tym powiadomiony w konsoli.
Plik zawiera także wykres pionowy, na którym zaznaczone są wartości 
obliczonych funkcji.


