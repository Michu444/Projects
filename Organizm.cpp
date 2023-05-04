#include "Swiat.h"
#include "Organizm.h"

Organizm::Organizm()
{
    this->sila = 0;
    this->inicjatywa = 0;
    this->X = 0;
    this->Y = 0;
    this->wiek = 0;
    this->swiat = nullptr;
}

Organizm::Organizm(Swiat *swiat,int sila, int inicjatywa, int x, int y)
{
    this->sila = sila;
    this->inicjatywa = inicjatywa;
    this->X = x;
    this->Y = y;
    this->wiek = 0;
    this->swiat = swiat;
}

void Organizm::rysowanie()
{
    swiat->ustawOrganizm(this, X, Y);
}

int Organizm::getSila()
{
    return sila;
}

int Organizm::getInicjatywa()
{
    return inicjatywa;
}

int Organizm::getX()
{
    return X;
}

int Organizm::getY()
{
    return Y;
}

int Organizm::getWiek()
{
    return wiek;
}

Swiat* Organizm::getSwiat()
{
    return swiat;
}

void Organizm::setSila(int sila)
{
    this->sila = sila;
}

void Organizm::setInicjatywa(int inicjatywa)
{
    this->inicjatywa = inicjatywa;
}


void Organizm::setWiek(int wiek)
{
    this->wiek = wiek;
}


