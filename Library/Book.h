#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book
{
protected:

    string name_of_the_book;
    string name_author;
    string book_genre;
    string publisher;
    string year_issue;
    string number_of_pages;
    string find;
    int count;

public:

    void show_books(fstream& file);

    void show_authors(fstream& file);

    void show_genre_publisher(fstream& file);

    void add_book(fstream& file);

    void delete_book(fstream& file);


};

#endif
