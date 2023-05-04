// LIBRARY
// C++ Language
// Author: Michal Dudziak

#include "Reports.h"

void main_menu()
{
    cout << "     BOOK COLLECTION     " << endl;
    cout << "-------------------------" << endl;
    cout << "--------MAIN MENU--------" << endl;
    cout << "1. ADD BOOK" << endl;
    cout << "2. DELETE BOOK" << endl;
    cout << "---------REPORTS---------" << endl;
    cout << "3. SHOW SAVED BOOKS BY AUTHOR" << endl;
    cout << "4. SHOW SAVED BOOKS BY GENRE OR PUBLISHER" << endl;
    cout << "5. SHOW PUBLISHER WITH MAXIMUM QUANTITY OF THE BOOKS" << endl;
    cout << "6. SHOW TOP-3 GENRES" << endl;
    cout << endl;
    cout << "7. EXIT" << endl;
    cout << endl;
    cout << "Choose an option by entering the consecutive number and confirming with enter: ";
}

int main()
{
    int choice;

    fstream file;

    Book function;
    Reports_Book report;

    if (file.good())
    {

        while (true)
        {
            main_menu();

            cin >> choice;

            switch (choice)
            {
            case 1: // ADDING BOOK
            {
                system("cls");
                function.show_books(file);
                function.add_book(file);
                break;
            }

            case 2: // DELETING BOOK
            {
                system("cls");
                function.show_books(file);
                function.delete_book(file);
                break;
            }

            case 3: // REPORT #1
            {
                system("cls");
                function.show_authors(file);
                report.show_by_same_author(file);
                break;
            }

            case 4: // REPORT #2
            {
                system("cls");
                function.show_genre_publisher(file);
                report.show_by_genre_publisher(file);
                break;
            }

            case 5: // REPORT #3
            {
                system("cls");
                report.show_by_max_quantity(file);
                break;
            }

            case 6: // REPORT #4
            {
                system("cls");
                report.show_top_three(file);
                break;
            }

            case 7: // CLOSING PROGRAM
            {
                system("cls");
                cout << "Closing program.";
                Sleep(3000);
                return 0;
            }
            }
        }
    }
    else
    {
        cout << "There is problem with the file.txt file. Please check if file.txt exist and restart program.";
        return 0;
    }
}
