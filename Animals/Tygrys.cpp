#include "../Swiat.h"
#include "../Organizm.h"
#include "../Zwierze.h"
#include "Tygrys.h"

Tygrys::Tygrys() : Zwierze()
{
    sila = 10;
    inicjatywa = 2;
}

Tygrys::Tygrys(Swiat* swiat, int x, int y)
        : Zwierze(swiat, 10, 2, x, y)
{}

void Tygrys::SetRuch(char ruch)
{
    Zwierze::SetRuch(ruch);
}

int Tygrys::getOstatniRuch()
{
    return Zwierze::getOstatniRuch();
}

char Tygrys::getSymbol()
{
    return symbol;
}

string Tygrys::getNazwa()
{
    return "Tygrys";
}

void Tygrys::akcja()
{
    Zwierze::akcja();
    Zwierze::akcja();
}
