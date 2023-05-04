#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"

#include "Plants/Mlecz.h"
#include "Plants/Trawa.h"
#include "Plants/Guarana.h"

#include <string>

Roslina::Roslina()
        :Organizm()
{}

Roslina::Roslina(Swiat* swiat, int sila, int x, int y)
        :Organizm(swiat,sila, 0, x, y)
{}

int Roslina::getOstatniRuch()
{
    return 0;
}

bool Roslina::czyRoslina()
{
    return true;
}

void Roslina::akcja()
{
    string tresc;

    int nowex = X;
    int nowey = Y;
    int stworzyc = 0;

    swiat->nowyPunkt(X, Y, &nowex, &nowey, &stworzyc); // wspolrzedne nowego i pustego miejsca na planszy gdzie rozprzestrzeni sie organizm

    //ROZPRZESTRZENIANIE SIE ROSLIN

    if (stworzyc == 1)
    {
        tresc ="[ ROZPRZESTRZENIENIE ]  " + this->getNazwa() + ": z pola (" + to_string(X) + ", ";

        Organizm* nowy = this->StworzOrganizm(swiat, nowex, nowey);
        swiat->dodajOrganizm(nowy);

        tresc += to_string(Y) + ") na pole (" + to_string(nowex) + ", " + to_string(nowey) + ")";

        swiat->dodajRaportreporterowi(tresc);
    }
}

Organizm* Roslina::StworzOrganizm(Swiat* swiat,int x, int y)
{
    if (this->getNazwa() == "Trawa")
    {
        Trawa* trawa = new Trawa(swiat,x,y);
        return trawa;
    }
    else if (this->getNazwa() == "Mlecz")
    {
        Mlecz* mlecz = new Mlecz(swiat,x,y);
        return mlecz;
    }
    else if (this->getNazwa() == "Guarana")
    {
        Guarana* guarana = new Guarana(swiat,x,y);
        return guarana;
    }
}

void Roslina::SetRuch(char ruch)
{}

void Roslina::kolizja(Organizm* atakujacy)
{
    string raport = "[ ATAK NA ROSLINE ]  " + atakujacy->getNazwa() + " na " + this->getNazwa();
    swiat->dodajRaportreporterowi(raport);

    swiat->ustawOrganizm(atakujacy,this->getX(), this->getY());
    swiat->UsunOrganizm(this);
    atakujacy->rysowanie();
}