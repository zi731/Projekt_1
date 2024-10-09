#include <iostream>

struct elem {
    int war;
    elem *nas;
    elem *pop;
};

class lista {
private:
    int roz;
    elem *prz, *tyl;
public:
    lista(void);
    ~lista() {}
    elem *zwrot(int i);
    elem *dodprz(int i);
    elem *dodtyl(int i);
    elem *dodind(int i, int j);
    elem *usuprz();
    elem *usutyl();
    elem *usuind(int i);
    void wyswietl();
    void odwrot();
    void wyczy();
};

lista::lista(void) {
    roz = 0;
    prz = NULL;
    tyl = NULL;
}

elem *lista::zwrot(int i) {
    elem *a;
    if((i <= 0) || (i > roz)) return NULL;
    else if(i == roz) return tyl;
    else if(i < roz / 2) {
        a = prz;
        while(i > 0) {
            a = a->nas;
            i--;
        }
        return a;
    }
    else {
        a = tyl;
        while(i < roz) {
            a = a->pop;
            i++;
        }
        return a;
    }  
}

elem *lista::dodprz(int i) {
    elem *a = new elem;
    a->war=i;
    a->nas = prz;
    a->pop = NULL;
    if(prz) prz->pop = a;
    prz = a;
    if(!tyl) tyl = prz;
    roz++;
    return prz;
}

elem *lista::dodtyl(int i) {
    elem *a = new elem;
    a->war = i;
    if(tyl) tyl->nas = a;
    a->nas = NULL;
    a->pop = tyl;
    tyl = a;
    if(!prz) prz = tyl;
    roz++;
    return tyl;
}

elem *lista::dodind(int i, int j) {
    if (j > roz) return NULL;
    elem *a = new elem;
    a->war = i;
    elem *b = zwrot(j - 1);
    a->nas = b;
    a->pop = b->pop;
    b->pop = a;
    if(a->pop) a->pop->nas = a;
    else prz = a;
    roz++;
    return a;
}

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

elem *lista::usutyl() {
    elem *a;
    if(tyl) {
        a = tyl;
        if(a == prz) prz = tyl = NULL;
        else {
            tyl = tyl->pop;
            tyl->nas = NULL;
        };
        roz--;
        return a;
    }
    else return NULL;
}

elem *lista::usuind(int i) {
    elem *a = zwrot(i-1);
    if(a->pop) a->pop->nas = a->nas;
    else prz = a->nas;
    if(a->nas) a->nas->pop = a->pop;
    else tyl = a->pop;
    roz--;
    return a;
}

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

void lista::wyczy() {
    elem *a;
    while(prz) {
        a = prz->nas;
        delete prz;
        prz = a;
    }
}

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