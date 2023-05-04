#ifndef PROJECTS_LIS_H
#define PROJECTS_LIS_H
#include "../Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Lis :public Zwierze
{
    const char symbol = 'L';

public:

    Lis();
    Lis(Swiat* swiat, int x, int y);


    void SetRuch(char ruch) override;

    int getOstatniRuch() override;

    char getSymbol() override;

    string getNazwa() override;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

};

#endif
