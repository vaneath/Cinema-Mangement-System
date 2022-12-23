#include <iostream>
#include <windows.h>
#include <string>
#include <dos.h>
#include <conio.h>

using namespace std;

struct Element
{
    Element *next;
    string movieName;
    string upcoming;
};
struct Queue
{
    Element *Front, *Rear;
    int n;
};
Queue *createQueue()
{
    Queue *q1;
    q1 = new Queue;
    q1->Front = NULL;
    q1->Rear = NULL;
    q1->n = 0;
    return q1;
}
void AddMovie(Queue *q1, string movie)
{
    Element *e = new Element();

    e->next = NULL;
    e->movieName = movie;
    if (q1->n == 0)
        q1->Front = e;

    if (q1->n != 0)
        q1->Rear->next = e;

    q1->Rear = e;
    q1->n += 1;
}
void AddUpcoming(Queue *q1, string N_upcoming)
{
    Element *e = new Element();

    e->next = NULL;
    e->upcoming = N_upcoming;
    if (q1->n == 0)
        q1->Front = e;

    if (q1->n != 0)
        q1->Rear->next = e;

    q1->Rear = e;
    q1->n += 1;
}
void DeleteMovie(Queue *q1)
{
    Element *tmp = q1->Front;
    if (q1->n == 0)
    {
        cout << "there is no movie in the list yet" << endl;
        return;
    }
    if (q1->n == 1)
    {
        q1->Rear = NULL;
        cout << "delete successfully" << endl;
    }
    q1->Front = q1->Front->next;
    q1->n -= 1;
    delete tmp;
}

void DisplayMovie(Queue *q1)
{
    int i = 1;
    int BlockSign = 254;
    Element *tmp = q1->Front;
    if (tmp == NULL)
    {
        cout << "there is no movie in the list" << endl;
    }
    while (tmp != NULL)
    {
        cout << "\t\t\t\t\t\t" << (char)BlockSign << " " << tmp->movieName << endl;
        tmp = tmp->next;
    }
    cout << endl;
}

void DisplayUpcoming(Queue *q1)
{
    int i = 1;
    int BlockSign = 254;
    Element *tmp = q1->Front;
    if (tmp == NULL)
    {
        cout << "there is no movie in the list" << endl;
    }
    while (tmp != NULL)
    {
        cout << "\t\t\t\t\t\t" << (char)BlockSign << " " << tmp->upcoming << endl;
        tmp = tmp->next;
    }
    cout << endl;
}

void case1(Queue *q1)
{
    string nameMovie;

    cout << "\t\t\t\t\tPlease enter the movie that you want to add : ";
    getline(cin >> ws, nameMovie);
    cout << endl;

    AddMovie(q1, nameMovie);
}
void case2(Queue *q1)
{
    string upcoming_movie;

    cout << "\t\t\t\t\tPlease enter the name of upcoming movie";
    getline(cin >> ws, upcoming_movie);
    cout << endl;

    AddMovie(q1, upcoming_movie);
}
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

void MovieMenu()
{
    int Set[] = {12, 15, 15, 15, 15, 15, 15, 15, 6}; // 15 default value, last index use for block color
    int counter = 0, BlockSign = 254;
    char key;
    bool running = true;

    Queue *Q1 = createQueue();

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
                case1(Q1);
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
                case2(Q1);
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
                cout << "THIS IS THE LIST OF MOVIES YOU HAVE ADDED";
                DisplayMovie(Q1);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 4)
            {
                system("cls");
                cout << "THIS IS THE LIST OF UPCOMING MOVIES YOU HAVE ADDED";
                DisplayUpcoming(Q1);
                cout << "\n\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 5)
            {
                system("cls");
                DeleteMovie(Q1);
                cout << "\t\t\t\t\tSuccessfully Deleted";
                cout << "\t\t\t\t\t>>>>>>>Pressed any key to go back to main menu<<<<<<<<<<<<<<";
                getch();
                goto MainMenu;
            }
            if (counter == 6)
            {
                system("cls");
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
        cout << "WELCOME BACK SOLDIER";
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
