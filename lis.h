struct elem {
    int war;
    elem *nas;
    elem *pop;
};

class lista {
private:
    int roz;
    elem *prz;
    elem *tyl;
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
    void zwrotnas(int i);
    void zwrotpop(int i);
    void wyczy();
};