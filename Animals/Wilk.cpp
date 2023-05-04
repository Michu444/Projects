#include "../Swiat.h"
#include "../Organizm.h"
#include "../Zwierze.h"
#include "Wilk.h"

Wilk::Wilk() : Zwierze()
{
    sila = 9;
    inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y)
        : Zwierze(swiat,9, 5, x, y)
{}

void Wilk::SetRuch(char ruch)
{
    Zwierze::SetRuch(ruch);
}

int Wilk::getOstatniRuch()
{
    return Zwierze::getOstatniRuch();
}

char Wilk::getSymbol()
{
    return symbol;
}

string Wilk::getNazwa()
{
    return "Wilk";
}

void Wilk::akcja()
{
    Zwierze::akcja();
}

void Wilk::kolizja(Organizm* atakujacy)
{
    Zwierze::kolizja(atakujacy);
}
