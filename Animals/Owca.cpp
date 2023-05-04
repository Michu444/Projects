#include "../Swiat.h"
#include "../Organizm.h"
#include "../Zwierze.h"
#include "Owca.h"

Owca::Owca() : Zwierze()
{
    sila = 4;
    inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y)
        : Zwierze(swiat, 4, 4, x, y)
{}

void Owca::SetRuch(char ruch)
{
    Zwierze::SetRuch(ruch);
}

int Owca::getOstatniRuch()
{
    return Zwierze::getOstatniRuch();
}

char Owca::getSymbol()
{
    return symbol;
}

string Owca::getNazwa()
{
    return "Owca";
}

void Owca::akcja()
{
    Zwierze::akcja();
}

void Owca::kolizja(Organizm* atakujacy)
{
    Zwierze::kolizja(atakujacy);
}
