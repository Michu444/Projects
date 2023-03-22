//
// Created by mmdud on 22.03.2023.
//
#include "Reports.h"

void Reports_Book::show_by_same_author(fstream& file)
{

    file.open("file.txt", ios::in);

    cout << "Type Author: ";
    cin.ignore();
    getline(cin, search);

    system("cls");
    cout << "BOOKS BY '" << search << "' :" << endl;
    cout << endl;


    while (!file.eof())
    {
        getline(file, line);

        if (search == line)
        {
            cout << searching << endl;
        }

        searching = line;

    }

    Sleep(3000);
    system("cls");

    file.close();
}

void Reports_Book::show_by_genre_publisher(fstream& file)
{
    string genre;
    string publisher;
    int lines = 0;


    file.open("file.txt", ios::in);

    cin.ignore();
    cout << "Type Genre: ";
    getline(cin, genre);
    cout << "Type Publisher: ";
    getline(cin, publisher);
    cout << endl;

    while (!file.eof())
    {
        getline(file, line);
        lines++;

        if (lines % 7 == 1)
        {
            searching = line;
        }

        if (genre == line)
        {
            for (int i = 0; i < 2; i++)
            {
                getline(file, line);
                lines++;
            }

            if (publisher == line)
            {
                cout << searching << endl;
            }
            else
            {
                cout << "There are no any books with this Genre and Publisher. " << endl;
                break;
            }
        }
    }

    Sleep(3000);
    system("cls");

    file.close();
}

void Reports_Book::show_by_max_quantity(fstream& file)
{
    vector <string> publisher;
    string searching;
    string finding_publisher;
    vector <int> duplicate_publisher;
    int lines = 0;
    int iterator = 5;
    int min = 0;
    int max = 0;


    file.open("file.txt", ios::in);

    while (!file.eof()) // finding and adding publishers to container
    {
        getline(file, line);
        lines++;


        if (lines == iterator)
        {
            publisher.push_back(line);
            iterator += 7;
        }
    }

    sort(publisher.begin(), publisher.end()); // sort publishers


    for (int i = 0; i < publisher.size(); i++)
    {
        searching = publisher[i];

        for (int j = 0; j < publisher.size(); j++)
        {
            if (searching == publisher[i])
            {
                min++;
                publisher.erase(publisher.begin(), publisher.begin() + j);
            }

            if (min > max)
            {
                finding_publisher = searching;
                max = min;
                min = 0;
            }
        }
    }

    cout << "Publisher with the maximum quantity of the books is: " << finding_publisher;

    Sleep(4000);
    system("cls");

    file.close();
}

void Reports_Book::show_top_three(fstream& file)
{
    vector <string> genre;
    vector <string> sorted_genre;
    string searching;
    string finding_genre;
    vector <int> index_genre;
    int lines = 0;
    int iterator = 3;
    int iter = 0;


    file.open("file.txt", ios::in);

    while (!file.eof()) // finding and adding publishers to container
    {
        getline(file, line);
        lines++;

        if (lines == iterator)
        {
            genre.push_back(line);
            iterator += 7;
        }
    }

    sort(genre.begin(), genre.end()); // sort publishers

    while (genre.size() != 0)
    {
        searching = genre[0];
        sorted_genre.push_back(searching);
        index_genre.push_back(0);

        while (genre.size() != 0)
        {
            if (searching == genre[0])
            {
                index_genre[iter]++;
                genre.erase(genre.begin());
            }
            else
            {
                break;
            }
        }
        iter++;
    }

    if (index_genre.size() != 0)
    {
        if (index_genre.size() >= 1)
        {
            cout << "TOP 1: " << sorted_genre[0] << " " << index_genre[0] << " TIMES!" << endl;
            cout << endl;
        }
        if (index_genre.size() >= 2)
        {
            cout << "TOP 2: " << sorted_genre[1] << " " << index_genre[1] << " TIMES!" << endl;
            cout << endl;
        }
        if (index_genre.size() >= 3)
        {
            cout << "TOP 3: " << sorted_genre[2] << " " << index_genre[2] << " TIMES!" << endl;
        }
    }
    else
    {
        cout << "There are no any genres :(";
    }



    Sleep(4000);
    system("cls");

    file.close();
}
