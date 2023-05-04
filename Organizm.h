#ifndef PROJECTS_ORGANIZM_H
#define PROJECTS_ORGANIZM_H

class Swiat;

class Organizm
{
protected:

    int sila;
    int inicjatywa;
    int X, Y;
    int wiek;
    Swiat* swiat;

    virtual Organizm* StworzOrganizm(Swiat* swiat, int x, int y) = 0;

public:

    Organizm();
    Organizm(Swiat* swiat, int sila, int inicjatywa, int x, int y);


    int getSila();
    int getInicjatywa();
    int getX();
    int getY();
    int getWiek();
    void rysowanie();
    Swiat *getSwiat();

    void setSila(int sila);
    void setInicjatywa(int inicjatywa);
    void setWiek(int wiek);

    virtual void akcja() = 0;
    virtual string getNazwa() = 0;
    virtual char getSymbol() = 0;
    virtual int getOstatniRuch() = 0;
    virtual void SetRuch(char ruch) = 0;
    virtual void kolizja(Organizm* ruszajacy) = 0;
    virtual bool czyRoslina() = 0;
};

#endif
