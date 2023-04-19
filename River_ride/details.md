 **RIVER RIDE**



***Autorzy: Dorota Nowicka, Łukasz Popek***

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


Najważniejsze funkcje gry realizowane są w pliku z metodami `Game.cpp`. Przy nazwach
klas została uwzględniona osoba za nią odpowiedzialna.


### 1. Klasa Player (Łukasz Popek)

Klasa Player jest odpowiedzialna za generowanie obiektu, który będzię odpowiadał ruchom gracza podczas gry i przechowywał jego cechy.
dziedziczy po klasach Qobject i QGraphicsPixmapItem. Posiada Konstruktor `Player(QGraphicsItem* parent = 0);` i odpowiednie funkcje:

Funkcje publiczne:

* `void keyPressEvent(QKeyEvent* event)` - powoduje efekt w postaci ruchu lub strzelania

Sloty publiczne(funkcje, które w bibliotece QT mogą być używane w funkcji `connect`, wywołującej inne funkcje):

* `void spawn(QKeyEvent* event)` - powoduje losowe pojawianie się wrogów  z góry planszy
* `void rand_petrol();` - powoduje losowe pojawianie się stacji paliw

### 2. Health (Łukasz Popek)
Obiekty klasy Health przechowują informacje o liczbie punktów życia gracza. Dziedziczone po QGraphicsTextItem. Posiad Konstruktor `Health(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Atrybuty:
* `int health`- liczba punktów życia

Funkcje (publiczne):
* `void decrease()` - obniża wartość liczby punktów życia w przypadku == 0 odsyła do zakończenia gry
* `int get_health()` - zwraca wartość livczby punktów życia 


### 3. Score (Dorota Nowicka)
Obiekty klasy przechowują informacje o wyniku gracza.
Dziedziczone po QGraphicsTextItem. Posiada Konstruktor `Score(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Atrybuty:
* `int score`- liczba punktów gracza

Funkcje (publiczne):
* `void increase()` - zwieksza wynik gracza przy zestrzeleniu wroga
* `int get_score()` - zwraca wartość wyniku



### 4. Fuel (Dorota Nowicka)
Obiekty klasy przechowują informacje o paliwie gracza.
Dziedziczone po QGraphicsTextItem. Posiada Konstruktor `Fuel(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Atrybuty (publiczne):
* `int fuel` - ilość paliwa dostepna w danym momencie

Funkcje (publiczne):
* `void increase(int value)` - zwiększa ilość paliwa o zadaną wartość

Sloty (publiczne):

* `void decrease()` - zmniejsza liczbe paliwa w czasie 


### 5. Bullet (Dorota Nowicka)

Klasa odpowiedzialna za generowanie wystrzelonego pocisku przez gracza, który nacisnął spacje. 
Dziedziczone po  public QObject i public QGraphicsPixmapItem. Posiada Konstruktor` Bullet(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Sloty (Publiczne):
*  `void move();` - przesuwa pocisk na mapie. W przypadku kolizji z obiektem klasy enemy, oba są usuwane
i zwiększany jest wynik gracza.


### 6. Velocity (Dorota Nowicka)
Obiekty klasy przechowują informacje o paliwie gracza.
Dziedziczone po QGraphicsTextItem. Posiada Konstruktor` Velocity(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Atrybuty (publiczne):
*  `int velocity` - przesuwa pocisk na mapie. Wprzypadku kolizji z obiektem klasy enemy oba sa usuwane
i podnosznony jest wynik gracza

Funkcje (publiczne):

*  `void decrease()` - służy do obniżania predkości gracza

*  `void increase()` - służy do podwyższania predkosci gracza

### 7. Enemy (Łukasz Popek)
Klasa odpowiedzialna za generowanie obiektu przeciwnika, który zagraża graczowi. 
Dziedziczone po  public QObject i public QGraphicsPixmapItem. Posiada Konstruktor `Enemy(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Atrybuty (publiczne):
*  `QTimer* timer_in_enemy` - obiekt przechowujaćy zegar dla ruchu wroga. Po kazdym 
przebiegu zegara nastepuje wywołąnie funkcji move()

Funkcje (publiczne):

*  `void move()` - służy do przemiesczana obiektu enemy w dół ekranu. Zapobiega nakladaniu
się na siebie 2 obrazków na scenie. W przypaku dojścia do granicy sceny zadawane są obrażenia graczowi


### 8. PetrolStation (Dorota Nowicka)
Klasa odpowiedzialna za generowanie obiektu przeciwnika, który pozwoli uzupełnić wartosc paliwa. 
Dziedziczone po  public QObject i public QGraphicsPixmapItem. Posiada Konstruktor `PetrolStation(QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Funkcje (publiczne):

*  `void move()` - służy do przemiesczana obiektu enemy w dół ekranu. Zapobiega nakladaniu
się na siebie 2 obrazków na scenie. W przypaku dojścia do granicy sceny znika. W przypdaku
natrafinia na obiekyt graficzny gracza na scenie uzupełnia wartość paliwa 

### 9. Fire (Łukasz Popek)
Klasa odpowiedzialna za generowanie obiektu wybuchu, który jest odwzorowaniem trafienia wroga. 
Dziedziczone po  public QObject i public QGraphicsPixmapItem. Posiada Konstruktor ` Fire(int pos_x, int pos_y, QGraphicsItem* parent = 0);` i 
odpowiednie funkcje:

Funkcje (publiczne):

*  `void burn()` - Funkcja wywoływana w przypadku gdy graczowi zostanie zadane obrażenie lub gracz trafi 
wroga. Powoduje wyświetlenie sie na scenie na krótki czas grafiki ognia 

### 10. CoastLine (Łukasz Popek)
Klasa odpowiedzialna za generowanie zielonych boków sceny aby gra faktycznie odbywała się na rzece, a nie na morzu. 
Dziedziczone po  public QObject i public QGraphicsPixmapItem. Posiada Konstruktor `CoastLine(QGraphicsItem* parent = 0);`.

### 11. Button (Praca Wspólna)
Klasa odpowiedzialna za generowanie przycisków w oknach Menu i GameOver
Dziedziczone po  public QObject i public QGraphicsRectItem. Posiada Konstruktor `Button(QString name, QGraphicsItem* parent = NULL);`  i 
odpowiednie funkcje:

Funkcje (publiczne):

*  `void mousePressEvent(QGraphicsSceneMouseEvent* event)` - pozwala nadać sygnał kliknięcie programowi
*  `void hoverEnterEvent(QGraphicsSceneHoverEvent* event)` - pozwala nadać eneter sygnał programowi żeby zaszło wciśniecie przycisku

Sygnały(publiczne): 
*  `void clicked()`  - tworzy sygnał kliknięcie pozwalajacy kontunować wybaną opcje 

### 12. Game (Praca Wspólna)
Najważniejsza klasa całego programu tworząc obiekt game który jest inicjalizowany w 
funkcji main(). Dziedziczy po klasie QGraphicsView. Konstruktor:`Game(QWidget* parent = 0)`

Atrybuty Publiczne: 
* `QGraphicsScene* scene` - atrybut przechowujący wskaźnik do sceny na której sa dodawane elementy
graficzne całej gry takie jak tło, obrazek gracza itd.
* `Player* player` - przechowujący wskaźnik do obiektu gracza 
* `Score* score` -  przechowujący wskaźnik do obiektu score
* `Health*  health` - przechowujący wskaźnik do obiektu zdrowie gracz
* `Velocity* velocity` - przechowujący wskaźnik do obiektu predkość
* `Fuel* fuel;` - przechowujący wskaźnik do obiektu fuel
* `CoastLine* left_coast`- przechowujący wskaźnik do obiektu odpowiadajcego za
wizualizajcje lewego brzegu mapy;
* `CoastLine* right_coast` przechowujący wskaźnik do obiektu odpowiadajcego za
wizualizajcje prawego brzegu mapy;
* `QTimer\* timer\_fuel`; `QTimer\* timer\_petrol`; `QTimer\* timer\_enemy`; `QTimer\* timer\_enemy\_move` - sa wskaźnikami do zegarów odpowiadającyh za pojawianie się obiektów u góry mapy
*`bool is_over = false ` - służy do sparawdznia czy gra sie zakończyłą

Funkcje Publiczne: 
* `void game_over()` - służy do zakończenia rozgrywki w przypadku gdy gracz otrzyma za dużo obrażeń lub straci paliwo
* `void display\_game\_over_window(QString textToDisplay)` - wyrzuca komunikat graczowi np. o zakańczeniu rozgrywki
* void menu();
* `void display()` - **najważniejsza funkcja. Umieszcza w atrybucie *scene wszystkie obiekty graficzne**

Sloty Publiczne:
* `void start()` - rozpoczyna grę 
* `void restart()` - restartuje grę po wcisńieciu przycisku button

Funkcje Prywatne:
* `void drawPanel(int x, int y, int width, int height, QColor color, double opacity)` - 
teorzy panel na ekranie o zadnym rozmiarze kolorze, rozmiarze ect. służy do oprawy graficznej
zakończenia






## Gra River Ride jako projekt zaliczeniowy
Gra River Ride powstała jako projekt z przedmiotu PROI, a jej fragmenty są realizacją zadań zaliczeniowych.


### Zadanie 3
Zaprojektowano i stworzono klasy, zgodnie z poniższą tabelą.

| Klasa | Atrybuty | Funkcje | Kto |
| ------ | ------ | ------ | ------ |
| samolot | paliwo, życie, przebyta droga, aktualny tor, prędkość | zmiana prędkości, strzelanie, zmiana ilości paliwa, zmiana toru, zderzenie | Łukasz |
| wrogowie | życie, położenie | strzelanie, ruch, utrata życia | Dorota |
| stacja paliw | położenie, ilość dodawanego paliwa | | Dorota |
| przeszkody terenowe | położenie | | Dorota |
| mapa | ... | kreowanie terenu/ poziomu | Łukasz |
| grafika | ... | ... | - |
| silnik aplikacji | ... | kontrola z klawiatury, obsługa aplikacji | Łukasz |
| obiekt mapy | położenie, typ | -(klasa rodzic) | Dorota |
| pocisk | położenie starowe, wartość niszcząca, prędkość | tor_pocisku, zadanie_obrażeń | Łukasz |
| main | | | Łukasz |

Aktualna funkcja main przedstawia wspólne działanie stworzonych klas.
Wypisuje na ekranie mapę 8 torową mapę oraz tworzy plik ruch gracza.txt,
w który wpisuje aktualne cechy gracza w kolejnych krokach czasu.
(Aktualna funkcja main służy przetestowaniu klas, dlatego nie zainicjalizowano
w niej jeszcze prawidłowo generacji liczb losowych)

### Zadanie 4
W ramach zadania:
* klasy ze zmienną strukturą obiektów - dynamiczna alokacja pamięci:
klasa `Map`
* dziedziczenie: klasy `PetrolStation`, `TerrainObstacles`, `Enemy` dziedziczą
po klasie `MapObject`
* przeciążenia - funkcje `lukasz_overload_function` i `accion` omówione poniżej
* poniżej omówiony projekt `Testy_river_ride` zawierający testy wszystkich klas i metod.
* diagram klas (na końcu pliku)

#### OPIS FUNKCJI PRZECIĄŻONYCH

#### Funkcja `lukasz_overload_function`
funkcja pzowala wyprintwoać rózny komunikat w przypadku wpowadznia różnego typu argumentu. Pozwala to zaobserować przeciążenie funkcji.

#### Funkcja `accion`
Funkcję `accion` można wywołać na cztery sposoby:
- `accion(Player john, Enemy enem)`
- `accion(Player john, PetrolStation station)`
- `accion(Player john, TerrainObstacle rock)`
- `accion(int symbol_1, int symbol_2)`

Wywołania przyjmujące jako argumenty obiekty skutkują wyświetlniem informacji o tym, co stało się graczowi.
Wywołanie od liczb typu int skutkuje wyświetleniem informacji na jaki symbol powinien pojawić się na mapie `display`.

#### OPIS TESTÓW JEDNOSTKOWYCH
Testy powinny zostać automatycznie dodane do rozwiązania w Visual Studio.
Jeśli tak się nie stanie, należy dodać do rozwiązania gotowy projekt `Testy_river_ride.vcxproj`
znajdujący się w folderze o takiej samej nazwie.

#### Testy klasy Enemy (autor: DNowicka)
1. Test metody `init` sprawdza, czy po użyciu koknstruktora atrybuty mają przewidywane wartości.
2. Test metody `get_demage` sprawdza, czy atrybut `current_life` zostaje prawidłowo zmieniony także wtedy, gdy liczba punktów obrażeń jest większa od liczby punktów życia gracza.

#### Testy `game_engine` (autor: DNowicka)
1. Test metody `read_player_movement` sprawdza czy atrybuty gracza zmieniają się prawidłowo, zgodnie z wprowadzoną komendą.
2. Test metody `display_function` sprawdza, czy dwuwymiarowa tablica generowana przez funkcję `display` jest zgodna z oczekiwaniami (zgodna z mapą poziomu i ze zdarzeniami).

#### Testy klasy Map (autor: ŁPopek)
1. Test metody `get_map_of_objects` sprawdza, czy na wygenerowanej dla poziomu o zadanej trudności i różnorodności mapie pojawia się oczekiwana liczba obiektów danego typu. Sprawdzane jest czy liczba ta nie jest większa niż oczekiwana, ze względu na prawdopodobieństwo, że zostanie wylosowane 2 razy to samo miejsce.

#### Testy klasy MapObject (autor: DNowicka)
1. Test metody `init` sprawdza poprawne działanie konstruktora, poruwnując wartości atrybutów utworzonego obiektu z oczekiwanymi.

#### Testy klasy Missle (autor: DNowicka)
1. Test metody `missle_trayectory` sprawdza czy położenie pocisku zmienia się zgodnie z jego prędkością.
2. Test metody `give_demage_to_enemy` sprawdza czy liczba punktów życia wroga zmniejsza się o wartość atrybutu pocisku `demage_value`.

#### Testy klasy PetrolStation (autor: DNowicka)
1. Test metody `init` sprawdza poprawne działanie konstruktora, poruwnując wartości atrybutów utworzonego obiektu z oczekiwanymi, w szczególności czy typ obiektu mapy jest równy 1.

#### Testy klasy Player (autor: ŁPopek)
1. Test metody `init` sprawdza poprawne działanie konstruktora, poruwnując wartości atrybutów utworzonego obiektu z oczekiwanymi.
2. Test `is_player_alive` sprawdza, czy funkcja `is_alive` zwraca False, gdy liczba punktów życia gracza wynosi 0.
3. Test metody `change_direction` sprawdza prawidłowość zmiany toru przez gracza.
4. Test `get_demage` sprawdza czy liczba punktów życia gracza zmienia się zgodnie z liczbą punktów zniszczenia, że nie jest mniejsza od 0 i sprawdza, wynik funkcji `is_alive`.
5. Test metody `move_forward` sprawdza, czy gracz przesuwa się po mapie zgodnie z prędkością.
6. Test metody `refuel` sprawdza poprawność uzupełniania paliwa i czy jego ilość nie przekracza maksymalnej wartości
7. Test metody `increase_velocity` sprawdza poprawność przyspieszenia samolotu gracza.
8.  Test metody `decrease_velocity` sprawdza poprawność spowolnienia samolotu gracza.


#### Test klasy TerrainObstacles (autor: DNowicka)
1. Test metody `init` sprawdza poprawne działanie konstruktora, poruwnując wartości atrybutów utworzonego obiektu z oczekiwanymi.

### Diagram Dziedzicznia klas (autor: ŁPopek)
Diagram został wygenerowny za pomocą strony https://app.genmymodel.com/. Link do diagramu: https://app.genmymodel.com/api/projects/_PEmGwI9iEeqwvcm2LAkYWA/diagrams/_PEmGw49iEeqwvcm2LAkYWA/svg
