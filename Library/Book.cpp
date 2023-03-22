#include "Book.h"

void Book::show_books(fstream& file)
{
    int lines = 0;
    string line;

    file.open("file.txt", ios::in);

    cout << "Available Books:" << endl;

    while (!file.eof())
    {
        getline(file, line);
        lines++;

        if (lines % 7 == 1)
        {
            cout << line << endl;
        }
    }

    cout << endl;


    file.close();
    Sleep(3000);

}

void Book::show_authors(fstream& file)
{
    int lines = 0;
    string line;

    file.open("file.txt", ios::in);

    cout << "Saved authors:" << endl;

    while (!file.eof())
    {
        getline(file, line);

        if (lines % 7 == 1)
        {
            cout << line << endl;
        }
        lines++;
    }

    cout << endl;


    file.close();
    Sleep(1000);
}

void Book::show_genre_publisher(fstream& file)
{
    int lines = 0;
    int iterator = 5;
    string line;

    file.open("file.txt", ios::in);

    cout << "Available Genres:" << endl;

    while (!file.eof())
    {
        getline(file, line);
        lines++;

        if (lines % 7 == 3)
        {
            cout << line << endl;
        }
    }

    cout << endl;
    lines = 0;
    file.close();

    file.open("file.txt", ios::in);

    cout << "Available Publishers:" << endl;

    while (!file.eof())
    {
        getline(file, line);
        lines++;

        if (lines == iterator)
        {
            cout << line << endl;
            iterator += 7;
        }
    }

    cout << endl;

    file.close();
    Sleep(1000);

}

void Book::add_book(fstream& file)
{
    file.open("file.txt", ios::app | ios::out);

    cout << endl;
    cout << "ADDING BOOK\n" << endl;
    getline(cin, name_of_the_book);

    cout << "Type name of the book: ";
    getline(cin, name_of_the_book);
    file << name_of_the_book << endl;

    cout << "Type name of the author: ";
    getline(cin, name_author);
    file << name_author << endl;

    cout << "Type genre of the book : ";
    getline(cin, book_genre);
    file << book_genre << endl;

    cout << "Type year issue: ";
    getline(cin, year_issue);
    file << year_issue << endl;

    cout << "Type Publisher: ";
    getline(cin, publisher);
    file << publisher << endl;

    cout << "Type Number of pages: ";
    getline(cin, number_of_pages);
    file << number_of_pages << endl;

    file << "$" << endl;


    system("cls");
    cout << endl;
    cout << "You have sucessfully saved Book: " << endl;
    cout << endl;
    cout << "Name: " << name_of_the_book << endl;
    cout << "Author: " << name_author << endl;
    cout << "Genre: " << book_genre << endl;
    cout << "Year issue: " << year_issue << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Number of pages: " << number_of_pages << endl;

    file.close();

    Sleep(4000);
    system("cls");

}

void Book::delete_book(fstream& file)
{

    string to_remove;
    string line;
    fstream temp("temp.txt");
    int lenght;

    file.open("file.txt", ios::in | ios::out);

    temp.open("temp.txt", ios::out);

    cout << "DELETING SELECTED BOOK" << endl;
    getline(cin, to_remove);

    cout << "Please type the Title of Book: ";
    getline(cin, to_remove);

    while (!file.eof()) // skiping lines with informations about deleting book and adding other lines to different file
    {
        getline(file, line);

        if (to_remove == line)
        {
            for (int i = 0; i < 7; i++)
            {
                getline(file, line);
            }
        }

        temp << line << endl;

    }

    file.close();

    temp.close();

    remove("file.txt");
    rename("temp.txt", "file.txt");

    Sleep(1000);
    system("cls");

}