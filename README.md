# Programowanie obiektowe i grafika komputerowa - Projekt

# TETRIS (RAYLIB) 
## Łukasz Kubik 193178 & Nikodem Kozak 193388 (ACiR 2)

### Krótki opis projektu:
Projekt gry Tetris został zrealizowany z użyciem języka C++ oraz biblioteki raylib, która jest popularnym narzędziem do tworzenia gier. Celem projektu było stworzenie funkcjonalnej gry Tetris, która zawiera podstawowe mechaniki gry, takie jak spadanie klocków, ich rotacja, sprawdzanie kolizji oraz usuwanie pełnych linii. Dodatkowo wprowadzono funkcję pauzy, aby umożliwić graczom wstrzymanie gry w dowolnym momencie.

### Funkcjonalności wykorzystane w projekcie (opis zawartości plików):
1. main.cpp - inicjalizujemy tworzenie okna dzięki bibliotece raylib oraz wyświetlanie gry dzięki metodzie game.Draw()
* Dodatkowo tworzymy dodatkowe elementy wizualne takie jak napisy, czy też wyświetlanie następnego bloku np. DrawTextEx() - dzięki bibliotece raylib
* Kontrola czasu dla stałego poruszania się bloku w dół - EventTrgiggered()
2. game.cpp i game.h - najważniejsze pliki projektu - odpowiadają za działanie gry – zawarta jest między innymi logika poruszania, sprawdzanie kolizji, generowanie bloków. Ta część odpowiada również za rysowanie elementów rozgrywki metodą Draw() korzystając z analogicznych metod wykorzystywanych w innych częściach projektu (grid.cpp, block.cpp)
Całość opiera się na klasie Game(), która zawiera swoje metody (opisane poniżej). Możemy wyróżnić kilka najważniejszych elementów:
* Kontrola poruszania za pomocą przycisków przez użytkownika. - HandleImput()
* Kontrola poruszania się bloku (wychodzenie poza plaszne, rotacja bloków, kolizje) - IsBlockOutside(), RotateBlock(), BlockFits()
* Generowanie nowego bloku po ustawieniu się poprzedniego na dole planszy – LockBlock()
* Sprawdzanie końca gry funkcją gameOver – na zasadzie sprawdzenia czy blok wychodzi poza plansze
* Zliczanie i aktualizowanie wyniku – UpdateScore()
* Dodanie efektów dźwiękowych - dla całej gry oraz dla obracania bloków i usuwania linii
* Dla zwiększania punktacji zwiększa się również poziom trudności poprzez zwiększenie prędkości spadania bloku
3. position.cpp i position.h - implementujemy kontrolę pozycji, dzięki wskaźnikowi (this ->) na kolumnę i wiersz.
4. grid.cpp i grid.h - implementujemy rysowanie oraz kontrolę siatki, na której odbywa się rozgrywka – tworzone są metody na podstawie których kontrolujemy ruchy w game.cpp np. Kontorla pełnego wiersza - IsRowFull()
* Dodatkowo ważną funkcją jest usuwanie wiesza, gdy się zapełni - ClearRow(), MoveRowDown(), ClearFullRows()
5. colors.cpp i colors.h - przez wielokrotne użycie kolorów w projekcie są one przechowywane w oddzielnym pliku w wektorze i zwracane w razie potrzebny
6. block.cpp i block.h - tworzymy klasy, które zawierają ogólne parametry bloków – z nich dziedziczymy w dalszych etapach projektu
7. blocks.cpp i block.h - tworzymy i zawieramy parametry, dla każdego z typów bloków - ich “id”, możliwe obroty, kolor danego bloku
