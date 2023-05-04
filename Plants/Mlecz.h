#ifndef PROJECTS_MLECZ_H
#define PROJECTS_MLECZ_H
#include <iostream>
#include <string.h>
#include "../Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Mlecz : public Roslina
{
private:
    const char symbol = 'm';

    const int prawdopodobienstwo = 35;
public:

    Mlecz();
    Mlecz(Swiat* swiat,int x, int y);

    char getSymbol() override;
    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;
};


#endif
