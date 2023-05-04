#include <string>

#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"

#include "Animals/Wilk.h"
#include "Animals/Owca.h"
#include "Animals/Lis.h"
#include "Animals/Leniwiec.h"
#include "Animals/Tygrys.h"

Zwierze::Zwierze()
{
    ostatniRuch = NULL;
}

Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa, int x, int y)
        :Organizm(swiat, sila, inicjatywa, x, y)
{
    ostatniRuch = NULL;
}

int Zwierze::losuj()
{
    int losuj;

    losuj = rand() % 30;


    return losuj;
}

void Zwierze::akcja() //  2 2
{
    string tresc;

    swiat->ustawOrganizm(nullptr, X, Y); // aktualna pozycja - posprzatanie

    int nowex = X;
    int nowey = Y;

    int nowex1 = X;
    int nowey1 = Y;

    nowex1 = losuj();
    nowey1 = losuj();

    if (Y - 1 != -1 && nowey1 > 15) // gora
    {
        nowey = Y - 1;
        nowex = X;
    }
    if (Y + 1 < swiat->getN() && nowey1 <= 15) // dol
    {
        nowey = Y + 1;
        nowex = X;
    }
    if (X - 1 != -1 && nowex1 > 15) // lewo
    {
        nowey = Y;
        nowex = X - 1;
    }
    if (X + 1 < swiat->getN() && nowex1 <= 15) // prawo
    {
        nowey = Y;
        nowex = X + 1;
    }

    tresc = "[ RUCH ]  " + this->getNazwa() + " z pola (" + to_string(X) + ", " + to_string(Y) + ") na (";


    X = nowex;
    Y = nowey;

    tresc += to_string(X) + ", " + to_string(Y) + ")";

    swiat->dodajRaportreporterowi(tresc);
}

Organizm* Zwierze::StworzOrganizm(Swiat* swiat, int x, int y)
{
    if (this->getNazwa() == "Wilk")
    {
        Wilk* wilk = new Wilk(swiat, x - 1, y - 1);
        return wilk;
    }
    else if (this->getNazwa() == "Owca")
    {
        Owca* owca = new Owca(swiat,x - 1, y - 1);
        return owca;
    }
    else if (this->getNazwa() == "Lis")
    {
        Lis* lis = new Lis(swiat, x - 1, y - 1);
        return lis;
    }
    else if (this->getNazwa() == "Leniwiec")
    {
        Leniwiec* leniwiec = new Leniwiec(swiat, x - 1, y - 1);
        return leniwiec;
    }
    else if (this->getNazwa() == "Tygrys")
    {
        Tygrys* tygrys = new Tygrys(swiat,x - 1, y - 1);
        return tygrys;
    }
}


int Zwierze::getOstatniRuch()
{
    return ostatniRuch;
}

void Zwierze::SetRuch(char ruch)
{
    ostatniRuch = ruch;
}

bool Zwierze::czyRoslina()
{
    return false;
}


void Zwierze::kolizja(Organizm* atakujacy)
{
    string tresc;

    tresc = "[ ATAK ]  " + atakujacy->getNazwa() + " atakuje " + this->getNazwa() + " na (" + to_string(this->getX()) + "," + to_string(this->getY()) + ")";
    swiat->dodajRaportreporterowi(tresc);


    if (this->getNazwa() == atakujacy->getNazwa() && atakujacy->getWiek() >= 0)
    {
        this->rozmnazanie(atakujacy, swiat);
        tresc = "[ROZMNOZENIE]  " + atakujacy->getNazwa() + "(" + to_string(atakujacy->getX()) + "," + to_string(atakujacy->getY()) + ") z " + this->getNazwa() + "(" + to_string(this->getX()) + "," + to_string(this->getY()) + ")";
        //tresc = "Byloby rozmnozenie a jest zjedzenie.";
        swiat->dodajRaportreporterowi(tresc);
        //swiat->UsunOrganizm(atakujacy);

    }
    else if (this->getSila() > atakujacy->getSila())
    {
        swiat->UsunOrganizm(atakujacy);
    }
    else
    {
        swiat->ustawOrganizm(atakujacy,this->getX(), this->getY());
        swiat->UsunOrganizm(this);
        atakujacy->rysowanie();
    }
}

void Zwierze::rozmnazanie(Organizm* atakujacy, Swiat* swiat)
{
    int nowex = X;
    int nowey = Y;

    int stworzyc = 0;

    swiat->nowyPunkt(atakujacy->getX(), atakujacy->getY(), &nowex, &nowey, &stworzyc);

    Organizm* nowy = this->StworzOrganizm(swiat,nowex, nowey);
    swiat->dodajOrganizm(nowy);


}