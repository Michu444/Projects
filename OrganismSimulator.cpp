// OrganismSimulator
// C++ Language
// Author: Michal Dudziak

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Swiat.h"


using namespace std;

#define ENTER 13
#define Q 113


int main()
{
    int N = 20;
    string wybor_opcji, opt2;
    char opt3 = NULL;

    Swiat* swiat = new Swiat(N);

    do
    {
        wybor_opcji = swiat->menuGlowne();

        if (wybor_opcji == "1")  //ROZPOCZECIE NOWEJ GRY + ZMIANA ROZMIARU / ZOSTAWIC DOMYSLNY
        {
            system("cls");

            do
            {
                cout << "Czy chcesz zmienic rozmiar planszy? ( T / N )" << "\n";
                cin >> opt2;

                if (opt2 == "T" || opt2 == "t")
                {
                    cout << "Wpisz nowy rozmiar planszy: ";
                    cin >> N;
                    swiat = new Swiat(N);
                    swiat->stworzOrganizmy();
                    break;
                }
                else if (opt2 == "N" || opt2 == "n")
                {
                    swiat = new Swiat(N);
                    swiat->stworzOrganizmy();
                    break;
                }
                else
                {
                    cout << "\n";
                    cout << "Wybrana opcja nie istnieje! Sprobuj ponownie...";
                    Sleep(2000);
                    system("cls");
                }

            } while (opt2 != "T" || opt2 != "t" || opt2 != "N" || opt2 != "n");

            system("cls");

            cout << "Rozmiar planszy: " << N << "x" << N << "\n";
            cout << "Wczytuje gre...\n";
            Sleep(2000);
            system("cls");

            swiat->rysujSwiat();

            do
            {
                opt3 = _getch();

                switch (opt3)
                {
                    case ENTER:
                    {
                        swiat->wykonajTure();
                        system("cls");
                        swiat->rysujSwiat();
                        break;
                    }
                    case 'q':
                    {
                        system("cls");
                        cout << "Koniec gry." << "\n";
                        exit(0);
                    }
                    default:
                    {
                        cout << "Tylko enter wykonuje kolejna ture, sprobuj jeszcze raz!\n";
                    }
                }
            } while (true);
        }
        else if (wybor_opcji == "2") // KONIEC
        {
            system("cls");
            cout << "Koniec gry." << "\n";
            exit(0);
        }
        else
        {
            cout << "\n";
            cout << "Wybrana opcja nie istnieje! Sprobuj ponownie";
            Sleep(1000);
            system("cls");
        }

    } while(wybor_opcji != "1" || wybor_opcji != "2" || wybor_opcji != "3");

    return 0;
}

