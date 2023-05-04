#ifndef PROJECTS_TYGRYS_H
#define PROJECTS_TYGRYS_H
#include "../Zwierze.h"

// Tygrys poluje podwojnie - wykonuje dwa ruchy w ciagu jednej tury

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Tygrys :public Zwierze
{
    const char symbol = 'T';

public:

    Tygrys();
    Tygrys(Swiat* swiat, int x, int y);


    void SetRuch(char ruch) override;

    int getOstatniRuch() override;

    char getSymbol() override;

    string getNazwa() override;

    void akcja() override;




};


#endif
