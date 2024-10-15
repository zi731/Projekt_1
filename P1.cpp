#include <iostream>
#include "lis.h"

int main(int argc, char const *argv[]) {
    lista li;
    for(int i = 8; i > 0; i--) {
        li.dodprz(i);
    }
    li.wyswietl();
    li.dodtyl(0);
    li.wyswietl();
    li.dodind(9,2);
    li.wyswietl();
    li.usuprz();
    li.wyswietl();
    li.usutyl();
    li.wyswietl();
    li.usuind(3);
    li.wyswietl();
    li.odwrot();
    li.wyczy();
    li.wyswietl();
    return 0;
}