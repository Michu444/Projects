#include "../Swiat.h"
#include "../Organizm.h"
#include "../Zwierze.h"
#include "Leniwiec.h"

Leniwiec::Leniwiec() : Zwierze()
{
    sila = 2;
    inicjatywa = 1;
}

Leniwiec::Leniwiec(Swiat* swiat, int x, int y)
        : Zwierze(swiat, 2, 1, x, y)
{}

void Leniwiec::SetRuch(char ruch)
{
    Zwierze::SetRuch(ruch);
}

int Leniwiec::getOstatniRuch()
{
    return Zwierze::getOstatniRuch();
}

char Leniwiec::getSymbol()
{
    return symbol;
}

string Leniwiec::getNazwa()
{
    return "Leniwiec";
}

void Leniwiec::akcja()
{
    Zwierze::akcja();
}

void Leniwiec::kolizja(Organizm* atakujacy)
{
    Zwierze::kolizja(atakujacy);
}
