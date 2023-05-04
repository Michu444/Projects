#ifndef PROJECTS_REPORTER_H
#define PROJECTS_REPORTER_H
#include <iostream>
#include <set>

using namespace std;


class Reporter
{
    string organizmy[8] = {"Wilk", "Owca", "Lis", "Leniwiec", "Tygrys", "Mlecz", "Guarana", "Trawa"};

    int iloscRaportow;
    string* zbiorRaportow;

public:


    Reporter();

    void mow(string tresc, bool newl);

    void rozpocznijGre();

    void raportNarodziny(string nazwa, int x, int y);

    void raportSmierc(string nazwa, int x, int y);

    void dodajRaport(string raport);

    int getIloscRaportow();

    void setIloscRaportow(int ilosc);

    string getRaport(int i);

    ~Reporter();
};

#endif
