#ifndef PROJECTS_ZWIERZE_H
#define PROJECTS_ZWIERZE_H
#include <iostream>
#include "Organizm.h"

using namespace std;

class Swiat;
class Organizm;

class Zwierze :public Organizm
{
    int ostatniRuch;

    Organizm* StworzOrganizm(Swiat* swiat,int x, int y) override;

public:
    Zwierze();
    Zwierze(Swiat* swiat, int sila, int inicjatywa, int x, int y);

    void SetRuch(char ruch);

    virtual char getSymbol() = 0;
    virtual string getNazwa() = 0;
    int getOstatniRuch() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

    bool czyRoslina() override;

    int losuj();

    void rozmnazanie(Organizm* atakowany, Swiat* swiat);


};

#endif
