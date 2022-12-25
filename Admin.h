#include <iostream>
#include <windows.h>
#include <string>
#include <dos.h>
#include <conio.h>
#include <fstream>

using namespace std;

fstream MovieFile;
struct Node
{
    string movie_name;
    string timetable;
    int price;
    Node *next, *prev;
};
void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct List
{
    int n;
    Node *head, *tail;
};

List *createEmptyList()
{
    List *ls = new List;

    ls->n = 0;
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}
void readMovie(List *ls)
{
    Node *movie;
    string nowShowing;
    MovieFile.open("Movie.txt", ios::in);
    if (MovieFile.is_open())
    {
        while (getline(MovieFile, nowShowing))
        {
            movie = new Node;
            movie->movie_name = nowShowing;
            if (ls->n == 0)
            {
                ls->head = movie;
                ls->tail = movie;
            }
            else
            {
                ls->tail->next = movie;
                movie->prev = ls->tail;
                ls->tail = movie;
            }
            ls->n = ls->n + 1;
        }
    }
    else
    {
        cout << "File not open\n";
        exit(1);
    }
    MovieFile.close();
}

void StoreNowShowing(List *ls)
{
    Node *tmp;
    tmp = ls->head;

    MovieFile.open("Movie.txt", ios::out);
    while (tmp != NULL)
    {
        MovieFile << tmp->movie_name << "\n";
        tmp = tmp->next;
    }
    MovieFile.close();
}

void Storeupcoming(List *ls)
{
    Node *tmp;
    tmp = ls->head;

    MovieFile.open("Upcoming.txt", ios::out);
    while (tmp != NULL)
    {
        MovieFile << tmp->movie_name << "\n";
        tmp = tmp->next;
    }
    MovieFile.close();
}

void insertMovie(List *ls, string nowShowing, int Cprice)
{
    Node *movie = new Node;
    movie->movie_name = nowShowing;
    movie->price = Cprice;
    movie->next = NULL;
    movie->prev = NULL;

    if (ls->n == 0)
    {
        ls->head = movie;
        ls->tail = movie;
    }
    else
    {
        ls->tail->next = movie;
        movie->prev = ls->tail;
        ls->tail = movie;
    }
    ls->n = ls->n + 1;
    StoreNowShowing(ls);
}

void insertTimetable(List *ls, string ctimetable)
{
    Node *movie = new Node;
    movie->timetable = ctimetable;
    movie->next = NULL;
    movie->prev = NULL;

    if (ls->n == 0)
    {
        ls->head = movie;
        ls->tail = movie;
    }
    else
    {
        ls->tail->next = movie;
        movie->prev = ls->tail;
        ls->tail = movie;
    }
    ls->n = ls->n + 1;
}

void insertUpcoming(List *ls, string Upcoming)
{
    Node *movie = new Node;
    movie->movie_name = Upcoming;
    movie->next = NULL;
    movie->prev = NULL;

    if (ls->n == 0)
    {
        ls->head = movie;
        ls->tail = movie;
    }
    else
    {
        ls->tail->next = movie;
        movie->prev = ls->tail;
        ls->tail = movie;
    }
    ls->n = ls->n + 1;
    Storeupcoming(ls);
}

void displayTimetable(List *ls)
{
    Node *tmp = ls->head;
    while (tmp != NULL)
    {

        cout << tmp->timetable << " | ";
        tmp = tmp->next;
    }
}

void displayNowShowing(List *ls)
{
    Node *tmp = ls->head;
    while (tmp != NULL)
    {

        cout << "\t\t\t\t\t" << tmp->movie_name << "\t " << tmp->price;
        displayTimetable(ls);
        tmp = tmp->next;
    }
}

void displayUpcoming(List *ls)
{
    Node *tmp = ls->head;
    while (tmp != NULL)
    {

        cout << "\t\t\t\t\t" << tmp->movie_name << " " << endl;
        tmp = tmp->next;
    }
}

void deleteMovie(List *ls, string search_name)
{
    int found = 0;
    Node *tmp1, *tmp, *tmp2;
    tmp = ls->head;

    while (tmp != NULL)
    {
        if (tmp->movie_name == search_name)
        { // At the Start
            if (tmp->prev == NULL)
            {
                ls->head = tmp->next;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
            else if (tmp->next == NULL)
            { // At the Tail
                ls->tail = tmp->prev;
                ls->tail->next = NULL;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
            else
            { // In between
                tmp1 = tmp->prev;
                tmp2 = tmp->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
        }
        tmp = tmp->next;
    }

    if (found == 1)
    {
        cout << "delete successful!" << endl;
        Sleep(1);
    }
    else
    {
        cout << "Information not correct." << endl;
        Sleep(1);
    }
    StoreNowShowing(ls);
}

void deleteUpcoming(List *ls, string search_name)
{
    int found = 0;
    Node *tmp1, *tmp, *tmp2;
    tmp = ls->head;

    while (tmp != NULL)
    {
        if (tmp->movie_name == search_name)
        { // At the Start
            if (tmp->prev == NULL)
            {
                ls->head = tmp->next;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
            else if (tmp->next == NULL)
            { // At the Tail
                ls->tail = tmp->prev;
                ls->tail->next = NULL;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
            else
            { // In between
                tmp1 = tmp->prev;
                tmp2 = tmp->next;
                tmp1->next = tmp2;
                tmp2->prev = tmp1;
                delete tmp;
                ls->n = ls->n - 1;
                found = 1;
                break;
            }
        }
        tmp = tmp->next;
    }

    if (found == 1)
    {
        cout << "delete successful!" << endl;
        Sleep(1);
    }
    else
    {
        cout << "Information not correct." << endl;
        Sleep(1);
    }
    Storeupcoming(ls);
}

void InputNowShowing(List *ls)
{
    string nameMovie;
    string timeAvailible;
    int n;
    int inPrice;
    cout << "\t\t\t\t\tPlease enter the movie that you want to add : ";
    getline(cin >> ws, nameMovie);
    cout << endl;
    cout << "\t\t\t\t\tPlease set the price for the of the ticket: ";
    cin >> inPrice;
    cout << "\t\t\t\t\tHow many time do you the movie put on screening: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "please the timetable for the movie screening: \n\t\t\t\t\t ";
        getline(cin >> ws, timeAvailible);
        insertTimetable(ls, timeAvailible);
    }

    insertMovie(ls, nameMovie, inPrice);
}

void InputUpcoming(List *ls)
{
    string upcoming_movie;

    cout << "\t\t\t\t\tPlease enter the name of upcoming movie : ";
    getline(cin >> ws, upcoming_movie);
    cout << endl;

    insertUpcoming(ls, upcoming_movie);
}

void MovieMenu()
{
    int Set[] = {12, 15, 15, 15, 15, 15, 15, 15, 6}; // 15 default value, last index use for block color
    int counter = 0, BlockSign = 254;
    char key;
    bool running = true;

    List *NowShowing = createEmptyList();
    List *Upcoming = createEmptyList();

    readMovie(NowShowing);

MainMenu:

    system("cls");
    while (running)
    {
        gotoXY(45, 5);
        color(11);
        cout << "------ ";
        color(3);
        cout << " Movie System";
        color(11);
        cout << "------";

        gotoXY(40, 8);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[0]);
        cout << " Add new movie";

        gotoXY(40, 9);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[1]);
        cout << " Add new upcoming movie";

        gotoXY(40, 10);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[2]);
        cout << " View most popular movie";

        gotoXY(40, 11);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[3]);
        cout << " View movies list";

        gotoXY(40, 12);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[4]);
        cout << " View upcoming list";

        gotoXY(40, 13);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[5]);
        cout << " Delete outdated movie";

        gotoXY(40, 14);
        color(Set[8]);
        cout << char(BlockSign);
        color(Set[6]);
        cout << " Delete upcoming list";

        gotoXY(40, 21);
        color(Set[7]);
        cout << "Back";

        key = _getch();

        Set[0] = 15; // reset color
        Set[1] = 15;
        Set[2] = 15;
        Set[3] = 15;
        Set[4] = 15;
        Set[5] = 15;
        Set[6] = 15;
        Set[7] = 15;

        if (key == 72 && (counter >= 1 && counter <= 8)) // 72 for up arrow
        {
            counter--;
            Set[counter] = 12;
            // cout<<counter;
        }

        else if (key == 80 && (counter >= 0 && counter <= 7)) // 80 for down arrow
        {
            counter++;
            Set[counter] = 12;
            //<<counter;
        }

        else
        {
            Set[counter] = 12;
            // cout<<counter;
        }

        if (key == '\r') // carriage return for "Enter" key
        {
            if (counter == 0)
            {
                system("cls");
                InputNowShowing(NowShowing);
                cout << endl;
                cout << "\t\t\t\t\t\tSuccessfully Added";
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                system("cls");
                goto MainMenu;
            }
            if (counter == 1)
            {
                system("cls");
                InputUpcoming(Upcoming);
                cout << endl;
                cout << "\t\t\t\t\t\tSuccessfully Added";
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                system("cls");
                goto MainMenu;
            }
            if (counter == 2)
            {
                system("cls");
            }
            if (counter == 3)
            {
                system("cls");
                cout << "\t\t\t\t\tTHIS IS THE LIST OF MOVIES YOU HAVE ADDED\n";
                displayNowShowing(NowShowing);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 4)
            {
                system("cls");
                cout << "\t\t\t\t\tTHIS IS THE LIST OF UPCOMING MOVIES YOU HAVE ADDED\n";
                displayUpcoming(Upcoming);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 5)
            {
                string search;
                system("cls");
                cout << "Please input the name of the movie that you want to delete : ";
                getline(cin >> ws, search);
                deleteMovie(NowShowing, search);
                cout << "\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 6)
            {
                string search;
                system("cls");
                cout << "Please input the name of the upcoming movie to delete it from the list:  ";
                deleteUpcoming(Upcoming, search);
                cout << "\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 7)
            {
                system("cls");
                break;
            }
        }
    }
}

void AdminMenu()
{
    int Set[] = {12, 15, 15, 15, 15, 6}; // 15 default value, last index use for block color
    int counter = 0, BlockSign = 254;
    char key;

    while (1)
    {
    adminMenu:

        gotoXY(45, 5);
        color(11);
        cout << "------ ";
        color(3);
        cout << "WELCOME";
        color(11);
        cout << "------";

        gotoXY(40, 8);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[0]);
        cout << " Movies";

        gotoXY(40, 9);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[1]);
        cout << " Food & Drink";

        gotoXY(40, 10);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[2]);
        cout << " Tickets";

        gotoXY(40, 11);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[3]);
        cout << " Purchase History";

        gotoXY(40, 21);
        color(Set[5]);
        cout << char(BlockSign);
        color(Set[4]);
        cout << " Log out";

        key = _getch();

        Set[0] = 15; // reset color
        Set[1] = 15;
        Set[2] = 15;
        Set[3] = 15;
        Set[4] = 15;

        if (key == 72 && (counter >= 1 && counter <= 4)) // 72 for up arrow
        {
            counter--;
            Set[counter] = 12;
            // cout<<counter;
        }

        else if (key == 80 && (counter >= 0 && counter <= 3)) // 80 for down arrow
        {
            counter++;
            Set[counter] = 12;
            //<<counter;
        }

        else
        {
            Set[counter] = 12;
            // cout<<counter;
        }

        if (key == '\r') // carriage return for "Enter" key
        {
            if (counter == 0)
            {
                system("cls");
                MovieMenu();
            }
            if (counter == 1)
            {
                system("cls");
            }
            if (counter == 2)
            {
                system("cls");
            }
            if (counter == 3)
            {
                system("cls");
            }
            if (counter == 4)
            {
                string confirm;
                system("cls");
                gotoXY(50, 5);
                cout << "Do you want to log out of admin mode[YES/NO]: ";
                getline(cin >> ws, confirm);

                if (confirm == "YES" || confirm == "yes")
                {
                    gotoXY(45, 8);
                    cout << "Pressed any key to continued" << getch();
                    system("cls");
                    AdminMenu();
                    return;
                }
                else if (confirm == "NO" || confirm == "no")
                {
                    goto adminMenu;
                    break;
                }
            }
        }
    }
}
