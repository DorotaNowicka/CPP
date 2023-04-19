 **RIVER RIDE**


***Autorzy: Dorota Nowicka, Łukasz Popek***


## Gra River Ride jako projekt zaliczeniowy
Gra River Ride powstała jako projekt z przedmiotu PROI, a jej fragmenty są realizacją zadań zaliczeniowych. Zaimplementowano w niej klasy, dziedziczenie klas, GUI z biblioteką Qt, klasy ze zmienną strukturą obiektów (dynamiczna alokacja pamięci), przeciążenia funkcji, testy jednostkowe, diagram klas. 


RiverRide to gra na podstawie klasycznej komputerowej gry z gatunku shoot'em up. Gracz, obserwujący akcję gry z perspektywy lotu ptaka,
kontroluje myśliwiec lecący nad rzeką i zdobywa punkty za zestrzelenie wrogich samolotów.
Zmieniając tor, unika przeszkód i uzupełnia paliwo.
Gracz przegrywa, gdy straci wszystkie punkty życia, gdy nie zestrzeli nadlatującego samolotu lub gdy wyczerpie się paliwo.


### INSTALACJA
Każdy z domyślnych sposobów otwierania projektów w Visual Studio powinien zadziałać.

#### Zalecany sposób:
Jeśli branch latest_version_1_05 istnieje, należy pobrać pliki z tej gałęzi klikając przycisk download.
1. Rozpakować folder zip na swoim komputerze.
2. Uruchomić program Visual Studio.
3. Wybrać opcję "Otwórz/Wczytaj projekt".
4. Wybrać ścieżkę do rozpakowanego folderu.
5. Wybrać River_ride.vcxproj.

Jeśli nie istnieje taka gałąź:
1. Skopiować adres URL tego repozytorium.
2. Uruchomić program Visual Studio.
3. Wybrać opcję "sklonuj lub wyewidencjonuj kod".
4. Wkleić adres URL tego repozytorium.
5. Nazwać rozwiązanie

A następnie:

6. Skompilować rozwiązanie.
7. Uruchomić program w trybie Lokalny Debuger Windows.

Ważne:

Ponieważ do projektu została dodana biblioteka QT, może być wymagane dodanie plików systemowych QT5Core.dll oraz 
QT5Widget.dll. Należy je pobrać ze strony https://www.dll-files.com/ i przenieść do katalogu o ścieżce:
C:\Windows\SysWOW64.

GUI zostało zaimplementowane przy użyciu biblioteki graficznej QT. Do edycji kodu niezbędna jest jej instalacja.

### Funkcjonalności RiverRide
#### Przebieg Rozgrywki
Grę uruchamia się klikając RiverRidewithGUI.exe.
Gracz wprowadza imię (w przypadku niewprowadznia, przyjmowana jest defaultowa nazwa Player).
Po czym gracz wybiera przycisk Play Game. Gra się toczy do momentu utraty wszystkich punktów życia
lub utraty paliwa. Z każdym trafionym wrogiem, wynik gracza zwiększa się o jeden punkt.
Gracz musi także przelatywać nad stacjami paliw w celu zbierania
paliwa. Po przegranej grze wyświetalny jet ekran końca rozgrywki, w któym gracz może wybrać ponowną
grę lub wyjście z progamu. 

#### Sterownie

Sterowanie samolotem odbywa się za pomocą klawiatury.

[strzałka w górę] - przyspieszenie

[strzałka w dół] - zwolnienie

[strzałka w lewo] - przejscie w lewo

[strzałka w prawo] - przejscie w prawo

[SPACJA] - strzał


## **STRUKTURA KODU**

Kod został podzielony na 12 klas:
1. Player
2. Health
3. Score
4. Fuel
5. Bullet
6. Velocity
7. Enemy
8. PetrolStation
9. Fire
10. CoastLine
11. Button
12. Game


