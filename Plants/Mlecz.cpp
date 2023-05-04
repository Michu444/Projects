#include "../Swiat.h"
#include "../Organizm.h"
#include "../Roslina.h"
#include "Mlecz.h"

Mlecz::Mlecz()
        : Roslina()
{
    sila = 0;
}

Mlecz::Mlecz(Swiat* swiat,int x, int y)
        : Roslina(swiat, 0, x, y)
{}

char Mlecz::getSymbol()
{
    return symbol;
}

string Mlecz::getNazwa()
{
    return "Mlecz";
}

void Mlecz::akcja()
{
    int los = rand() % 100;
    if (los < prawdopodobienstwo)
    {
        Roslina::akcja();
        Roslina::akcja();
        Roslina::akcja();
    }
}

void Mlecz::kolizja(Organizm* atakujacy)
{
    Roslina::kolizja(atakujacy);
}