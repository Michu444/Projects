#ifndef PROJECTS_SWIAT_H
#define PROJECTS_SWIAT_H
#include <iostream>
#include "Reporter.h"
using namespace std;

class Organizm;

class Swiat
{
private:

    Organizm** organizmy;
    Organizm*** plansza;
    Reporter *raport;
    string* komentarze;

    int N;
    int iloscOrganizmow;
    int tura;
    int iloscKomentarzy;
    int organizmyBezNowych;


public:

    Swiat(int N);
    string menuGlowne();


    int getN();
    int getTura();
    Organizm* getPole(int x, int y);
    Organizm* getOrganizm(int i);
    int getIloscOrganizmow();

    void rysujSwiat();
    void stworzOrganizmy();
    void dodajOrganizm(Organizm* organizm);
    void ustawOrganizm(Organizm* organizm, int x, int y);
    void UsunOrganizm(Organizm* org);
    void setTura(int tura);
    void wykonajTure();
    int losuj();
    int losuj(int n);

    void nowyPunkt(int X, int Y, int* nowex, int* nowey, int *stworzyc);

    void dodajRaportreporterowi(string raport);


    ~Swiat();
};


#endif
