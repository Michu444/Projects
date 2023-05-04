#ifndef PROJECTS_OWCA_H
#define PROJECTS_OWCA_H
#include "../Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Owca :public Zwierze
{
    const char symbol = 'O';

public:

    Owca();
    Owca(Swiat* swiat, int x, int y);


    void SetRuch(char ruch) override;

    int getOstatniRuch() override;

    char getSymbol() override;

    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

};


#endif
