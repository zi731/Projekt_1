#include "lis.h"
#include <iostream>


int main(int argc, char const *argv[]) {
    lista li;
    std::cout << "Dodanie do listy liczb od 1 do 8:\n";
    for(int i = 8; i > 0; i--) {
        li.dodprz(i);
    }
    li.wyswietl();
    std::cout << "Dodanie do listy liczby 0 na koniec:\n";
    li.dodtyl(0);
    li.wyswietl();
    std::cout << "Dodanie do listy liczby 9 na drugie miejsce:\n";
    li.dodind(9, 2);
    li.wyswietl();
    std::cout << "Usuniecie z listy pierwszej liczby:\n";
    li.usuprz();
    li.wyswietl();
    std::cout << "Usuniecie z listy ostatniej liczby:\n";
    li.usutyl();
    li.wyswietl();
    std::cout << "Usuniecie z listy trzeciej liczby:\n";
    li.usuind(3);
    li.wyswietl();
    std::cout << "Wyswietlenie listy od tylu:\n";
    li.odwrot();
    std::cout << "Wartosc elementu po drugim: ", li.zwrotnas(2);
    std::cout << "Wartosc elementu przed drugim: ", li.zwrotpop(2);
    std::cout << "Wyczyszczenie listy:\n";
    li.wyczy();
    li.wyswietl();
    return 0;
}