#include "../Swiat.h"
#include "../Organizm.h"
#include "../Roslina.h"
#include "Trawa.h"

Trawa::Trawa()
        : Roslina()
{
    sila = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y)
        : Roslina(swiat,0, x, y)
{

}

char Trawa::getSymbol()
{
    return symbol;
}

string Trawa::getNazwa()
{
    return "Trawa";
}

void Trawa::akcja()
{
    int los = rand() % 100;
    if (los < prawdopodobienstwo)
    {
        Roslina::akcja();
    }
}

void Trawa::kolizja(Organizm* atakujacy)
{
    Roslina::kolizja(atakujacy);
}