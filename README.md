# Zestaw5
## 1. KRÓTKI OPIS
#### Program tworzy obrazki w formie plikow ASCII.
Na podstawie danych ze specjalnego pliku konfiguracyjnego (którego nazwa jest parametrem programu) tworzona jest plansza o zadanych wymiarach, wypełniona wybranym znakiem. Na tak powstałej planszy rysowane są figury poprzez wypełnienie odpowiednich pól planszy wybranymi dla danego kształtu znakami. Możliwe do narysowania są figury: koło, kwadrat, prostokąt, trójkąt prostokątny równoramienny. Powstały obrazek wyświetlany jest w terminalu oraz zapisywany w pliku tekstowym. Nazwa tego pliku wraz z odpowiednio zdefiniowanymi i określonymi figurami do narysowania(nazwa, współrzędne, wymiary, znak do wypełnienia figury) również powinny zostać określone w pliku konfiguracyjnym.

## 2. ŚCIĄGNIĘCIE REPOZYTORIUM, KOMPILACJA, WYKONYWANIE (Linux)
```
git clone git@github.com:gabrielaoracz/Zestaw5.git
```   
```
cd Zestaw5
```   
```
g++ -std=c++20 main.cpp fun.cpp canvas.cpp -o canvas
```   
```
./canvas [nazwa pliku konfiguracyjnego]
```   

Dla przykładowego pliku konfiguracyjnego z repozytorium:   
```
./canvas konfig.txt
```   

## 3. POPRAWNY PLIK KONFIGURACYJNY
#### Aby móc bezproblemowo korzystać z programu, konieczne jest przygotowanie poprawnego pliku konfiguracyjnego, który będzie bazą do wykonania obrazka. Nazwę tego pliku należy podać jako parametr programu.
#### Wzór pliku konfiguracyjnego:
```
szerokość_planszy wysokość_planszy 'znak_tla_planszy'
nazwa_pliku_wynikowego
```
W kolejnych liniach szczegóły dotyczące figur do narysowania. Wzory dla poszczególnych figur:   
```
prostokat wspolrzedne_lewego_dolnego_wierzcholka dlugosc_boku_a dlugosc_boku_b 'znak_wypelnienia_figury'
kwadrat wspolrzedne_lewego_dolnego_wierzcholka dlugosc_boku 'znak_wypelnienia_figury'
trojkat wspolrzedne_wierzcholka_kata_prostego dlugosc_ramienia 'znak_wypelnienia_figury'
kolo wspolrzedne_srodka dlugosc_promienia 'znak_wypelnienia_figury'
```
   
##### ***Przyklad poprawnie określonej figury:***   
kolo 3 4 5 'f' -> Kolo o współrzędnych środka(3,4), promieniu 5, wypełnione symbolami 'f'.    

## 4. UWAGI
- nazwa figury powinna byc zapisana  wyłącznie małymi lub dużymi literami bez polskich znaków (dozwolone: kolo/KOLO, ale niepoprawne, np. Kolo);
- Znak spacji zdefiniowany jest jako ' '. Pozostale znaki podobnie, np. 'w', '(', '8'.
- współrzędnymi mogą być dowolne liczby całkowite z przedziału 0<=x<szerokość_planszy, 0<=y<wysokość_planszy;

Plansza interpretowana jest analogicznie do kartezjanskiego ukladu wspolrzednych.     
##### ***Przyklad:***    
plansza 5x3 wypełniona symbolami '#':    

     #####
     #A###
     #####
gdzie liczba_znaków_w_linii(Szerokość planszy) interpretowana jest jako oś 'x': 0<=x<5, a liczba_linii(wysokość planszy) jako oś 'y': 0<=y<3. Punkt A ma zatem współrzędne (1,1).
