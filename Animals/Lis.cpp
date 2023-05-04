#include "../Swiat.h"
#include "../Organizm.h"
#include "../Zwierze.h"
#include "Lis.h"

Lis::Lis() : Zwierze()
{
    sila = 3;
    inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y)
        : Zwierze(swiat, 3, 7, x, y)
{}

void Lis::SetRuch(char ruch)
{
    Zwierze::SetRuch(ruch);
}

int Lis::getOstatniRuch()
{
    return Zwierze::getOstatniRuch();
}

char Lis::getSymbol()
{
    return symbol;
}

string Lis::getNazwa()
{
    return "Lis";
}

void Lis::akcja()
{
    Zwierze::akcja();
}

void Lis::kolizja(Organizm* atakujacy)
{
    Zwierze::kolizja(atakujacy);
}
