#include "Reporter.h"
#include <string>


Reporter::Reporter()
{
    iloscRaportow = 0;
    zbiorRaportow = new string[1000];
}

void Reporter::mow(string tresc, bool newl)
{
    if (newl == true)
    {
        cout << "Reporter: ";
        cout << tresc << "\n";
    }
    else
    {
        cout << "Reporter: ";
        cout << tresc;
    }
}

void Reporter::rozpocznijGre()
{
    mow("Witam serdecznie w grze planszowej Organizmy!", true);
    mow("Organizmy wystepujace podczas rozgrywki: ", true);

    for (auto i = 0; i < 8; i++)
    {
        cout << organizmy[i] << "\n";
    }

    mow("Czas zaczac rozgrywke!", true);
}

void Reporter::raportNarodziny(string nazwa, int x, int y)
{
    string tresc;

    tresc = "[ NARODZINY ]  " + nazwa + " na polu(" + to_string(x) + "," + to_string(y) + ")";

    dodajRaport(tresc);
}

void Reporter::raportSmierc(string nazwa, int x, int y)
{
    string tresc;
    tresc = "[ SMIERC ]  " + nazwa ;

    dodajRaport(tresc);
}

void Reporter::dodajRaport(string raport)
{
    zbiorRaportow[iloscRaportow] = raport;
    iloscRaportow++;
}


int Reporter::getIloscRaportow()
{
    return iloscRaportow;
}

void Reporter::setIloscRaportow(int ilosc)
{
    iloscRaportow = ilosc;
}

string Reporter::getRaport(int i)
{
    return zbiorRaportow[i];
}

Reporter::~Reporter()
{
    delete zbiorRaportow;
}




