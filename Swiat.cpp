#include "Swiat.h"
#include "Organizm.h"
#include <string>
#include "Reporter.h"

#include "Animals/Wilk.h"
#include "Animals/Owca.h"
#include "Animals/Lis.h"
#include "Animals/Leniwiec.h"
#include "Animals/Tygrys.h"

#include "Plants/Mlecz.h"
#include "Plants/Trawa.h"
#include "Plants/Guarana.h"

#include <ctime>

//PONIZEJ TRZEBA PODAC MAKSYMALNA ILOSC ORGANIZMU

#define ileWilkow 2
#define ileOwiec 3
#define ileLisow 4
#define ileLeniwcow 2
#define ileTygrysow 2
#define ileMleczy 3
#define ileTraw 2
#define ileGuarany 2

// NIE MOZNA PRZEKRACZAC ROZMIARU PLANSZY ( N * N )


#define komentarzeWlaczone 1
// 1 - ON , 0 - OFF



Swiat::Swiat(int n)
{
    this->N = n;

    tura = 0;
    iloscOrganizmow = 0;
    organizmyBezNowych = 0;

    komentarze = new string[1000];
    iloscKomentarzy = 0;

    raport = new Reporter;

    organizmy = new Organizm *[N * N]; // maksymalnie n^2 organizmow

    plansza = new Organizm **[N];

    for (int i = 0; i < N; i++)
    {
        plansza[i] = new Organizm * [N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            plansza[i][j] = nullptr; // y,x
        }
    }
}

void Swiat::stworzOrganizmy() // METODA ODPOWIEDZIALNA ZA TWORZENIE ORGANIZMOW NA PLANSZY
{

    int x = 0;
    int y = 0;

    // Sprawdzenie dzialania Guarany na przykladowym organizmie
    /*
    Organizm* wilk1 = new Wilk(this, 3, 3);
    dodajOrganizm(wilk1);
    Organizm* guarana1 = new Guarana(this, 2, 3);
    dodajOrganizm(guarana1);
    Organizm* guarana2 = new Guarana(this, 4, 3);
    dodajOrganizm(guarana2);
    Organizm* guarana3 = new Guarana(this, 3, 2);
    dodajOrganizm(guarana3);
    Organizm* guarana4 = new Guarana(this, 3, 4);
    dodajOrganizm(guarana4);
    */


    // Sprawdzenie dzialania rozmnazania organizmu tego samego gatunku
    /*
    Organizm* wilk1 = new Wilk(this, 2, 3);
    dodajOrganizm(wilk1);
    Organizm* wilk2 = new Wilk(this, 3, 3);
    dodajOrganizm(wilk2);
    Organizm* wilk3 = new Wilk(this, 3, 2);
    dodajOrganizm(wilk3);
    Organizm* wilk4 = new Wilk(this, 3, 4);
    dodajOrganizm(wilk4);
    Organizm* wilk5 = new Wilk(this, 4, 3);
    dodajOrganizm(wilk5);
    */

    // Sprawdzenie dzialania akcji dla roznych zwierzat obok siebie
    /*
    Organizm* owca1 = new Owca(this, 4, 3);
    dodajOrganizm(owca1);
    Organizm* wilk1 = new Wilk(this, 2, 3);
    dodajOrganizm(wilk1);
    Organizm* lis1 = new Lis(this, 3, 3);
    dodajOrganizm(lis1);
    Organizm* leniwiec1 = new Leniwiec(this, 3, 2);
    dodajOrganizm(leniwiec1);
    Organizm* tygrys1 = new Tygrys(this, 3, 4);
    dodajOrganizm(tygrys1);
    */

    // Sprawdzenie czy lis poruszy sie na pole z organizmem o wiekszej sile niz on
    /*
    Organizm* lis2 = new Lis(this, 3, 3);
    dodajOrganizm(lis2);
    Organizm* owca1 = new Owca(this, 2, 3);
    dodajOrganizm(owca1);
    Organizm* owca2 = new Owca(this, 3, 2);
    dodajOrganizm(owca2);
    Organizm* owca3 = new Owca(this, 3, 4);
    dodajOrganizm(owca3);
    Organizm* owca4 = new Owca(this, 4, 3);
    dodajOrganizm(owca4);
    */


    for (int i = 0; i < ileWilkow; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* wilk = new Wilk(this, x, y);
        dodajOrganizm(wilk);
    }

    for (int i = 0; i < ileOwiec; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* owca = new Owca(this, x, y);
        dodajOrganizm(owca);
    }

    for (int i = 0; i < ileLisow; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* lis = new Lis(this, x, y);
        dodajOrganizm(lis);
    }

    for (int i = 0; i < ileLeniwcow; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* leniwiec = new Leniwiec(this, x, y);
        dodajOrganizm(leniwiec);
    }

    for (int i = 0; i < ileTygrysow; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* tygrys = new Tygrys(this, x, y);
        dodajOrganizm(tygrys);
    }

    for (int i = 0; i < ileMleczy; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* mlecz = new Mlecz(this, x, y);
        dodajOrganizm(mlecz);
    }

    for (int i = 0; i < ileTraw; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* trawa = new Trawa(this, x, y);
        dodajOrganizm(trawa);
    }

    for (int i = 0; i < ileGuarany; i++)
    {
        x = losuj();
        y = losuj();

        Organizm* guarana = new Guarana(this, x, y);
        dodajOrganizm(guarana);
    }
}


int Swiat::losuj()
{
    int los = 100;

    while (los >= N)
    {
        los = rand() % N;
    }
    return los;
}

void Swiat::dodajOrganizm(Organizm* organizm)
{
    string tresc;

    if ((iloscOrganizmow < (N * N)) && (plansza[organizm->getY()][organizm->getX()] == nullptr))
    {
        organizmy[iloscOrganizmow] = organizm;
        iloscOrganizmow++;

        if (iloscOrganizmow > 0) // zamiany organizmow w tabeli w zaleznosci od inicjatywy
        {
            Organizm* temp;
            int i = 0;
            while (i < iloscOrganizmow && organizmy[i]->getInicjatywa() >= organizm->getInicjatywa())
            {
                i++;
            }
            for (int j = iloscOrganizmow - 2; j >= i; j--)
            {
                temp = organizmy[j];
                organizmy[j] = organizmy[j + 1];
                organizmy[j + 1] = temp;
            }
        }

        organizm->rysowanie();

        if (komentarzeWlaczone == 1)
        {
            raport->raportNarodziny(organizm->getNazwa(), organizm->getX(), organizm->getY());
        }


    }
    else if (iloscOrganizmow < (N * N) && plansza[organizm->getY()][organizm->getX()] != nullptr)
    {
        delete organizm;
        return;
    }
    else if (iloscOrganizmow >= (N * N))
    {
        if (komentarzeWlaczone == 1)
        {
            raport->dodajRaport(tresc);
        }
    }
}

void Swiat::UsunOrganizm(Organizm* organizm)
{
    string tresc;
    Organizm* temp;
    Organizm* atakowany;

    atakowany = plansza[organizm->getY()][organizm->getX()];

    if (atakowany == organizm)
    {
        plansza[organizm->getY()][organizm->getX()] = nullptr;
    }
    for (int i = 0; i < iloscOrganizmow; i++) // w miejsce usuwanego organizmu wpisywany jest nullptr
    {
        if (organizmy[i] == organizm)
        {
            organizmy[i] = nullptr;
            for (int j = i; j < iloscOrganizmow - 1; j++)
            {
                temp = organizmy[j];
                organizmy[j] = organizmy[j + 1];
                organizmy[j + 1] = temp;
            }
            i = iloscOrganizmow;
        }
    }
    iloscOrganizmow--;
    organizmyBezNowych--;

    tresc = "[SMIERC]  " + organizm->getNazwa() + " na polu: (" + to_string(organizm->getX()) + "," + to_string(organizm->getY()) + ")";

    if (komentarzeWlaczone == 1)
    {
        raport->dodajRaport(tresc);
    }

    delete organizm;
}

void Swiat::rysujSwiat()
{
    raport->mow("Tura numer ", false);
    cout << getTura() << "\n";

    cout << "Organizmy:\n";
    cout << " O - Owca        W - Wilk\n L - Lis         X - Leniwiec\n T - Tygrys      t - trawa\n m - mlecz       g - guarana \n\n";

    cout << "Wcisnij enter by rozpoczac ture\n";
    cout << "Wcisnij Q by wyjsc z gry\n\n";

    for (int i = 0; i < iloscOrganizmow; i++)
    {
        organizmy[i]->rysowanie();
    }

    cout << "|    |";

    for (int i = 0; i < N; i++)
    {
        if (i < 10)
        {
            cout << "|  " << i << " |";
            continue;
        }
        cout << "| " << i << " |"; // numeracja pozioma
    }

    cout << endl;


    for (int i = 0; i < N; i++)
    {
        if (i < 10)
        {
            cout << "|  " << i << " |";
        }
        if (i >= 10)
        {
            cout << "| " << i << " |";
        }								// numeracja pionowa

        for (int j = 0; j < N; j++)
        {
            if (getPole(j,i) == nullptr)
            {
                cout << "|  " << "  |";
            }
            else
            {
                cout << "|  ";
                cout << getPole(j, i)->getSymbol();
                cout << " |";
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < raport->getIloscRaportow(); i++)
    {
        if (komentarzeWlaczone == 1)
        {
            cout << raport->getRaport(i) << endl;
        }
    }
    raport->setIloscRaportow(0);
}

void Swiat::wykonajTure()
{
    Organizm* organizm1;
    Organizm* organizm2;
    string tresc;

    organizmyBezNowych = iloscOrganizmow;

    for (int i = 0; i < organizmyBezNowych; i++)
    {
        organizm1 = organizmy[i];

        if (organizm1->getNazwa() == "Leniwiec" && getTura() % 2 == 0)
        {
            continue;
        }

        int stareX = organizm1->getX();
        int stareY = organizm1->getY();

        organizm1->akcja(); // ma juz wspolrzedne gdzie pojdzie ( zwierze )

        organizm2 = plansza[organizm1->getY()][organizm1->getX()]; // wczytujemy drugi organizm na ktory chce przejsc organizm1 // Y X

        if (organizm1->getNazwa() == "Lis" && organizm1->getWiek() > 0 && organizm2 != nullptr)
        {
            if (organizm2->getSila() > organizm1->getSila()) // RUCH LISA GDY JEGO SILA MNIEJSZA OD organizmu2
            {
                ustawOrganizm(organizm1, stareX, stareY);
                organizm1->rysowanie();

                tresc = "[ RUCH ]  " + organizm1->getNazwa() + "a powstrzymany! Organizm ma wieksza sile od lisa";
                raport->dodajRaport(tresc);
                continue;
            }
        }


        if (organizm2 == nullptr && organizm1->getOstatniRuch() == 0 || organizm1->czyRoslina() == true && organizm2->czyRoslina() == true)
        {
            organizm1->rysowanie();
        }
        else
        {
            organizm2->kolizja(organizm1);
        }
    }

    for (int i = 0; i < organizmyBezNowych; i++) // zwiekszenie wieku istniejacych organizmow
    {
        organizm1 = organizmy[i];
        organizm1->setWiek(organizm1->getWiek() + 1);
    }
    tura++;
}

int Swiat::getTura()
{
    return tura;
}

void Swiat::setTura(int tura)
{
    this->tura = tura;
}

int Swiat::getN()
{
    return N;
}

int Swiat::getIloscOrganizmow()
{
    return iloscOrganizmow;
}

void Swiat::ustawOrganizm(Organizm* organizm, int x, int y)
{
    plansza[y][x] = organizm;
}

Organizm* Swiat::getOrganizm(int i)
{
    return organizmy[i];
}

void Swiat::dodajRaportreporterowi(string tresc)
{
    raport->dodajRaport(tresc);
}

Organizm* Swiat::getPole(int x, int y)
{
    if (x < (N + 1) && y < (N + 1))
    {
        return plansza[y][x];
    }
    return nullptr;
}


string Swiat::menuGlowne()
{
    string opcja;

    cout << "    ---    Michal Dudziak 190309    ---" << "\n";
    cout << "    ---    ---------------------    ---" << "\n";
    cout << "    ---         MENU GLOWNE         ---" << "\n";
    cout << "    ---    1. Rozpocznij nowa gre   ---" << "\n";
    cout << "    ---    2. Wyjdz z gry           ---" << "\n";
    cout << "\n";
    cout << "Wybierz i wpisz cyfre zatwierdzajac enterem: ";
    cin >> opcja;

    return opcja;
}

int Swiat::losuj(int n)
{
    int liczba;

    liczba = rand() % n;


    return liczba;
}

void Swiat::nowyPunkt(int X, int Y, int* nowex, int* nowey, int *stworzyc)
{
    bool udane = true;

    while (udane)
    {
        int nowey1 = losuj(30);
        int nowex1 = losuj(30);


        if (Y - 1 != -1 && nowey1 > 15 && plansza[Y - 1][X] == nullptr) // gora
        {
            *nowey = Y - 1;
            *nowex = X;
            udane = false;
            *stworzyc = 1;
        }
        else if (Y + 1 < getN() && nowey1 <= 15 && plansza[Y + 1][X] == nullptr) // dol
        {
            *nowey = Y + 1;
            *nowex = X;
            udane = false;
            *stworzyc = 1;
        }
        else if (X - 1 != -1 && nowex1 > 15 && plansza[Y][X - 1] == nullptr) // lewo
        {
            *nowey = Y;
            *nowex = X - 1;
            udane = false;
            *stworzyc = 1;
        }
        else if (X + 1 < getN() && nowex1 <= 15 && plansza[Y][X + 1] == nullptr) // prawo
        {
            *nowey = Y;
            *nowex = X + 1;
            udane = false;
            *stworzyc = 1;
        }
        else
        {
            *stworzyc = 0;
            udane = false;
        }
    }
}

Swiat::~Swiat()
{
    delete[] organizmy;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete plansza[i];
        }
    }
}