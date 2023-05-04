#ifndef LIBRARY_REPORTS_H
#define LIBRARY_REPORTS_H


#include "Book.h"

class Reports_Book :public Book
{
protected:
    string search;
    string line;
    string searching;

public:

    void show_by_same_author(fstream& file);

    void show_by_genre_publisher(fstream& file);

    void show_by_max_quantity(fstream& file);

    void show_top_three(fstream& file);


};

#endif //LIBRARY_REPORTS_H
