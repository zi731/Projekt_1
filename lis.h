/// @file lis.h Deklaracja metod listy

/// @brief Definicja pojedynczego elementu listy
struct elem {
    int war; ///< Wartość elementu
    elem *nas; ///< Wskaźnik do następnego elementu
    elem *pop; ///< Wskaźnik do poprzedniego elementu
};

///@brief Definicja listy, jej zmiennych i jej metod
class lista {
private:
    int roz; ///< Rozmiar listy
    elem *prz; ///< Element na przodzie listy
    elem *tyl; ///< Element na tyle listy
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