#ifndef PROJECTS_GUARANA_H
#define PROJECTS_GUARANA_H
#include <iostream>
#include <string.h>
#include "../Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Guarana : public Roslina
{
private:
    const char symbol = 'g';
    const int prawdopodobienstwo = 30;
public:
    Guarana();
    Guarana(Swiat* swiat,int x, int y);

    char getSymbol() override;
    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;
};


#endif