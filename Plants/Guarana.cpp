#include "../Swiat.h"
#include "../Organizm.h"
#include "../Roslina.h"
#include "Guarana.h"

#include <string>

Guarana::Guarana()
        : Roslina()
{
    sila = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y)
        : Roslina(swiat, 0, x, y)
{}

char Guarana::getSymbol()
{
    return symbol;
}

string Guarana::getNazwa()
{
    return "Guarana";
}

void Guarana::akcja()
{
    int losuj = rand() % 100;
    if (losuj < prawdopodobienstwo)
    {
        Roslina::akcja();
    }
}

void Guarana::kolizja(Organizm* atakujacy)
{
    string raport = "[ ATAK NA ROSLINE ]  " + atakujacy->getNazwa() + " na " + this->getNazwa();
    swiat->dodajRaportreporterowi(raport);

    atakujacy->setSila(atakujacy->getSila() + 3);

    raport = "[ WZMOCNIENIE ]  " + atakujacy->getNazwa() + " z pola (" + to_string(this->getX()) + "," + to_string(this->getY()) + ") zjadl " + this->getNazwa() + " i wzmocnilo go o 3 pkt!" + " Jego sila wynosi: " + to_string(atakujacy->getSila());

    swiat->dodajRaportreporterowi(raport);

    swiat->ustawOrganizm(atakujacy, this->getX(), this->getY());
    swiat->UsunOrganizm(this);

    atakujacy->rysowanie();
}