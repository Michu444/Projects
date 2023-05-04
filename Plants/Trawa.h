#ifndef PROJECTS_TRAWA_H
#define PROJECTS_TRAWA_H
#include <iostream>
#include "../Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Trawa : public Roslina
{
private:
    const char symbol = 't';
    const int prawdopodobienstwo = 50;
public:
    Trawa();
    Trawa(Swiat* swiat,int x, int y);

    char getSymbol() override;
    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;
};



#endif
