#ifndef PROJECTS_WILK_H
#define PROJECTS_WILK_H
#include "../Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Wilk :public Zwierze
{
    const char symbol = 'W';

public:

    Wilk();
    Wilk(Swiat* swiat, int x, int y);


    void SetRuch(char ruch) override;

    int getOstatniRuch() override;

    char getSymbol() override;

    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;
};


#endif
