#ifndef PROJECTS_LENIWIEC_H
#define PROJECTS_LENIWIEC_H
#include "../Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Leniwiec :public Zwierze
{
    const char symbol = 'l';

public:

    Leniwiec();
    Leniwiec(Swiat* swiat, int x, int y);


    void SetRuch(char ruch) override;

    int getOstatniRuch() override;

    char getSymbol() override;

    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

};

#endif
