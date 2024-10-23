/// @file met.cpp Definicja metod listy

#include "lis.h"
#include <iostream>

/// @brief Konstruktor listy
lista::lista(void) {
    roz = 0;
    prz = NULL;
    tyl = NULL;
}

/// @brief Zwraca element o podanym indeksie
/// @param i - Indeks elementu do zwrócenia
elem *lista::zwrot(int i) {
    elem *a;
    if((i < 1) || (i > roz)) return NULL;
    else if(i == roz) return tyl;
    else if(i == 1) return prz;
    else {
        a = tyl;
        while(i < roz) {
            a = a->pop;
            i++;
        }
        return a;
    }  
}

/// @brief Dodaje element na przód listy
/// @param i - Wartość dodawanego elementu
elem *lista::dodprz(int i) {
    elem *a = new elem;
    a->war = i;
    a->nas = prz;
    a->pop = NULL;
    if(prz) prz->pop = a;
    prz = a;
    if(!tyl) tyl = prz;
    roz++;
    return prz;
}

/// @brief Dodaje element na tył listy
/// @param i - Wartość dodawanego elementu
elem *lista::dodtyl(int i) {
    elem *a = new elem;
    a->war = i;
    a->nas = NULL;
    a->pop = tyl;
    if(tyl) tyl->nas = a;
    tyl = a;
    if(!prz) prz = tyl;
    roz++;
    return tyl;
}

/// @brief Dodaje element na podany indeks listy
/// @param i - Wartość dodawanego elementu
/// @param j - Indeks elementu
elem *lista::dodind(int i, int j) {
    if (j < 1 || j > roz) return NULL;
    elem *a = new elem;
    a->war = i;
    elem *b = zwrot(j);
    a->nas = b;
    a->pop = b->pop;
    b->pop = a;
    if(a->pop) a->pop->nas = a;
    else prz = a;
    roz++;
    return a;
}

/// @brief Usuwa element z przodu listy
elem *lista::usuprz() {
    elem *a;
    if(prz) {
        a = prz;
        prz = prz->nas;
        if(!prz) tyl = NULL;
        else prz->pop = NULL;
        roz--;
        return a;
    }
    else return NULL;
}

/// @brief Usuwa element z tyłu listy
elem *lista::usutyl() {
    elem *a;
    if(tyl) {
        a = tyl;
        tyl = tyl->pop;
        if(!tyl) prz = NULL;
        else tyl->nas = NULL;
        roz--;
        return a;
    }
    else return NULL;
}

/// @brief Usuwa element o podanym indeksie
/// @param i - Indeks elementu
elem *lista::usuind(int i) {
    elem *a = zwrot(i);
    if(a->pop) a->pop->nas = a->nas;
    else prz = a->nas;
    if(a->nas) a->nas->pop = a->pop;
    else tyl = a->pop;
    roz--;
    return a;
}

/// @brief Wypisuje wszystkie elementy listy
void lista::wyswietl() {
    elem *a;
    if(!prz) std::cout << "BRAK" << std::endl;
    else {
        a = prz;
        while(a) {
            std::cout << a->war << " ";
            a = a->nas;
        }
        std::cout << std::endl;
    }
}

/// @brief Wypisuje wszystkie elementy listy, w odwrotnej kolejności
void lista::odwrot() {
    elem *a;
    if(!prz) std::cout << "BRAK" << std::endl;
    else {
        a = tyl;
        while(a) {
            std::cout << a->war << " ";
            a = a->pop;
        }
        std::cout << std::endl;
    }
}

/// @brief Wypisuje wartość elementu o indeksie większym o 1 od podanego
/// @param i - Indeks elementu
void lista::zwrotnas(int i) {
    elem *a = new elem;
    a = zwrot(i + 1);
    std::cout << a->war << "\n";
}

/// @brief Wypisuje wartość elementu o indeksie miniejszym o 1 od podanego
/// @param i - Indeks elementu
void lista::zwrotpop(int i) {
    elem *a = new elem;
    a = zwrot(i - 1);
    std::cout << a->war << "\n";
}

/// @brief Wyczyszcza zawartość listy
void lista::wyczy() {
    elem *a;
    while(prz) {
        a = prz->nas;
        delete prz;
        prz = a;
    }
}