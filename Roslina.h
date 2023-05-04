#ifndef PROJECTS_ROSLINA_H
#define PROJECTS_ROSLINA_H
#include <iostream>
#include "Organizm.h"

using namespace std;

class Swiat;
class Organizm;

class Roslina :public Organizm
{
protected:

    Organizm* StworzOrganizm(Swiat* swiat, int x, int y) override;

public:

    Roslina();
    Roslina(Swiat* swiat, int sila, int x, int y);

    virtual char getSymbol() = 0;
    virtual string getNazwa() = 0;

    void SetRuch(char ruch);

    void akcja() override;

    int getOstatniRuch() override;

    void kolizja(Organizm* atakujacy) override;

    bool czyRoslina() override;

};


#endif
