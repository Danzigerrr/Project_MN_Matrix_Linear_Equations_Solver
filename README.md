Metody Numeryczne Projekt 2 – Układy równań liniowych

Krzysztof Nazar, 184698  16 kwietnia 2022 

1. **Wstęp** 

Celem  projektu  jest  implementacja  metod  iteracyjnych  (Jacobiego  i  Gaussa-Seidla) i bezpośrednich (faktoryzacja LU) rozwiazywania układów równań liniowych. Układy równań są kluczowe  w  dalszym  rozwoju  nauki  w  obszarze  wielu  dziedzin,  na  przykład  biomechanika, symulacje  odkształceń,  dynamika  płynów  i  wiele  innych.  Mimo,  że  w  praktyce  stosuje  się macierze przechowywane w tak zwanym rzadkim formacie, w tym projekcie będę stosował macierz zapisaną w formacie pełnym.  

Implementacja  metod  rozwiązywania  układów  równań  została  wykonana  w  języku  C++ w środowisku Visual Studio. Wykresy zostały stworzone z wykorzystaniem programu MS Excel. 

2. **Podstawa teoretyczna** 
1. **Konstrukcja układu równań** 

Układ równań liniowych przedstawiony jest formułą: 

 

gdzie: 

- macierz systemowa, np. obwód elektroniczny, karoserię samochodu, turbinę, itp. 
- wektor pobudzenia, np. impuls elektroniczny, wektor siły, fala dźwiękowa itp. 
  - wektor  rozwiązań  reprezentujących  szukaną  wielkość  fizyczną,  np.  rozkład  pola 

w przestrzeni, natężenie dźwięku itp. 

2. **Wektor residuum** 

Podczas  wykorzystywania  algorytmów  iteracyjnych  istotne  jest  określenie  iteracji,  w  której algorytm powinien przestać się wykonywać. W tym celu korzysta się z tak zwanego wektora residuum. Dla k-tej iteracji wektor residuum można wyznaczyć za pomocą poniższego wzoru: 

( ) =  ( ) −  

Aby  obliczyć  jaki  błąd  wnosi  wektor  ( )  należy  wyznaczyć  normę  euklidesową  z  wektora residuum w  k-tej  iteracji.  Wektor  powinien  być  wektorem zerowym,  jeśli  algorytm zbiegnie do dokładnego  rozwiązania.  Zwykle  jako  kryterium  stopu  przyjmuje  się  normę  euklidesową z wektora residuum o wartość mniejszej niż 10−6. 

3. **Zadanie projektowe** 

3.1. **Zadanie A** 

W  tym  zadaniu  macierz   jest  macierzą  kwadratową  o  rozmiarze  ×  gdzie  = 998. Macierz A składa się z wyrazów  ,  oraz   , gdzie 

![obraz](https://user-images.githubusercontent.com/72522808/163672375-d7cbda86-3328-4f27-8b6b-9c8e96d48583.png)

Macierz A przedstawiona została poniżej. 
![obraz](https://user-images.githubusercontent.com/72522808/163672369-d9306d15-bbdf-4b2d-9a9f-4e75cfcf1fa4.png)

Wektor  ma długość  . Jego n-ty element ma wartość  
![obraz](https://user-images.githubusercontent.com/72522808/163672381-9c8e8256-2867-4e37-a7cb-e1ab1a3cd68b.png)

Wektor b przedstawiony został poniżej. 
![obraz](https://user-images.githubusercontent.com/72522808/163672385-aa6fc0b7-911d-4705-b4a6-6c719986f534.png)


3.2. **Zadanie B**  

Celem tego zadania była implementacja metod iteracyjnych rozwiązywania układów równań liniowych: Jacobiego i Gaussa–Seidla. 

Podczas  obliczeń  przy  pomocy  obydwu  metod  wykorzystuje  funkcje  wyznaczające  wartość residuum oraz normę wektora. Ich implementacje umieściłem poniżej. 

Najpierw zaimplementowałem metodę Jacobiego.  


Następnie zaimplementowałem metodę Gaussa-Seidla. 



Program zwraca poniższe informacje. 

![obraz](https://user-images.githubusercontent.com/72522808/163672399-4b72a285-039c-4815-9f24-1d67687ccd46.png)

Rozwiązanie układu równań uzyskuje się szybciej przy użyciu metody Gaussa-Seidla. Istotny jest także fakt, że przy użyciu metody Jacobiego potrzebna jest większa liczba iteracji aby obliczyć wynik. W tym przypadku, różnice pomiędzy metodami są mało znaczące.  

3.3. **Zadanie C** 

W tym zadaniu macierz A składa się z wyrazów  1,  2 oraz   3, gdzie 

![obraz](https://user-images.githubusercontent.com/72522808/163672406-2bac862e-15a4-43f6-8fd4-27646f79c2b0.png)

Macierz A przedstawiona została poniżej. 

![obraz](https://user-images.githubusercontent.com/72522808/163672409-742d1b20-9d5c-4812-bdc4-68568582c711.png)

Wartości w wektorze b o długości N nie zmieniają się.
![obraz](https://user-images.githubusercontent.com/72522808/163672414-a486241f-16d5-4322-b8dd-3ac0f3ed804d.png)

W funkcjach obliczających rozwiązanie układu równań zgodnie z metodą Jacobiego oraz Gaussa- Seidlera wprowadziłem warunek, aby kończyły się gdy liczba iteracji osiągnie 5000. Dzięki temu można uniknąć nieskończonej pętli w przypadku gdy układ nie ma dokładnego rozwiązania.  

![obraz](https://user-images.githubusercontent.com/72522808/163672419-0d8e6f5b-5501-4cef-91f8-5054e2616146.png)

Metody  iteracyjne  dla  analizowanego  układu  nie  zbiegają  się.  Na  konsoli  widoczne  jest, że norma  wektora  osiąga  wartość  -*nan(ind)*.  Skrót  *NAN*  w  języku  angielskim  oznacza „Not A Number”, a więc nie otrzymaliśmy dokładnego rozwiązania. Można z tego wyciągnąć wniosek, że pętla została przerwana przez warunek sprawdzający ilość wykonanych iteracji. 

3.4. **Zadanie D** 

Do  wyznaczenia  rozwiązania  układu  równań  została  wykorzystana  implementacja  metody faktoryzacji LU. Kod umieszczam poniżej. 

Analizowane były macierze takie same jak w zadaniu C, w którym metody iteracyjne nie zbiegły się. Jednak używając metody faktoryzacji LU otrzymaliśmy dokładny wynik. 

![obraz](https://user-images.githubusercontent.com/72522808/163672428-ff677648-f27e-4b34-84e4-c3e849f764d9.png)

Wartość  residuum  osiągnęła  wartość  około  6,11 ∙ 10-13.  Czas  wykonywania  algorytmu  był relatywnie krótki – około 1,5 sekundy. 

3.5. **Zadanie E** 

Stworzyłem tablice  *NArray* zawierającą kilka liczb całkowitych – są to kolejno analizowane rozmiary macierzy A. 

int NArray[] = { 500, 1000, 2000, 3000, 4000, 5000}; 

Dzięki  klasie  *CSVWriter*  informacje  o  ilości  niewiadomych  w  danym  przypadku  oraz  czasie rozwiązywania  układu  równań  zapisywane  są  do  plików  CSV:  *JacobiTimeVsSize.csv*  oraz *GaussSeidlTimeVsSize.csv*.  Na  podstawie  uzyskanych  danych,  w  programie  Microsoft  Excel stworzyłem w wykresy przedstawiające zależności pomiędzy rozmiarem macierzy a czasem rozwiązywania układu równań. Wykresy zamieściłem poniżej. 

![obraz](https://user-images.githubusercontent.com/72522808/163672443-9ca5a1e3-0b96-4ef3-aafa-044edc5c4519.png)

![obraz](https://user-images.githubusercontent.com/72522808/163672448-e78c9805-4061-4f32-8973-837a02883f03.png)


3.6. **Zadanie F - Wnioski** 

Po wykonaniu zadań nie potrafię stwierdzić która metoda jest najlepsza. Zadanie B pokazuje, że metody iteracyjne wykonują się bardzo szybko. Jednak zadania D oraz E ilustrują przypadek gdy  metoda  bezpośrednia  ma  znaczącą  przewagę  nad  metodami  iteracyjnymi.  Uważam, że równania powinno się najpierw rozwiązywać metodami iteracyjnymi, a jeśli nie będą zbiegać, wtedy zastosować metodę bezpośrednią, na przykład metodę faktoryzacji LU. Na podstawie wyników funckji „Trendilne” w MS Excel, można powiedzieć, że zależność pomiędzy czasem wykonywania algorytmu a liczba niewiaodmych w równaniu rośnie potęgowo. 
